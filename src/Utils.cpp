#include "Utils.hpp"

Utils *Utils::instance = 0;

Utils::Utils() {
    std::ios_base::sync_with_stdio(false);
}

Utils * Utils::getInstance() {

    if(!instance) {
        instance = new Utils;
    }

    return instance;
}

bool Utils::runCmd(string cmd) {
    return runCmd(std::move(cmd), nullptr);
}

bool Utils::runCmd(string cmd, vector<string> * outputBuffer) {

    FILE * handler;
	string long_buffer;
	char buffer[READ_BUFFER_SIZE];

	handler = popen(cmd.c_str(), "r");

	if(!handler) return false;

	if (handler && outputBuffer) {

		if (DEBUG_CMDOUT) printf("Running %s\n", cmd.c_str());

		while (fgets(buffer, READ_BUFFER_SIZE, handler)) {

			if (strlen(buffer) == READ_BUFFER_SIZE && buffer[READ_BUFFER_SIZE - 1] != '\n') {
				long_buffer += buffer;
			}
			else if (buffer[strlen(buffer) - 1] == '\n') {
				
                
                outputBuffer->push_back(long_buffer + string(buffer).substr(0, strlen(buffer) - 1));
				long_buffer = "";
			}
			else {
				outputBuffer->push_back(long_buffer + string(buffer));
				long_buffer = "";
			}
		}
		if (!long_buffer.empty()) outputBuffer->push_back(long_buffer);
	}
	pclose(handler);

	return true;
}

void Utils::markLink(string & entryPath,string &sourcePath, string &targetPath) {
    for(auto & i : fs::directory_iterator(sourcePath)) {

        int len = entryPath.length();

        string source = fixPath(i.path().u8string());
        string target = fixPath(targetPath + SubString(source,len));

        if(!fs::exists(target) && !i.is_directory()) {

            thread([&] {
                runCmd("mklink /h " + target + " " + source);
                //print(source + ", " + target + "\n");
            }).join();
        }


        //If the current one is a directory, recursively do it as well
        if(i.is_directory()) {
            string path = i.path().u8string();

            if(!fs::exists(target)) {
                fs::create_directory(target);
            }

            markLink(entryPath,path,targetPath);
        }
    }
}

bool Utils::markLink(string sourcePath, string targetPath) {

    sourcePath = fixPath(sourcePath);

    if(fs::exists(sourcePath)) {
        markLink(sourcePath, sourcePath, targetPath);
        return true;
    }
    return false;
}

vector<string> Utils::getFolderList(string sourcePath) {

    sourcePath = fixPath(sourcePath);

    vector<string> r;

    if(fs::exists(sourcePath)) {
        for(auto & i : fs::directory_iterator(sourcePath)) {
            if(i.is_directory()) {
                r.push_back(i.path().u8string());
            }
        }
    }

    return r;
}

void Utils::print(string msg) {
    printf(msg.c_str());
}

void Utils::printLn(string msg) {
    print(msg + "\n");
}

void Utils::reportEvent(string category, string text) {

}

void Utils::readFile(string filePath, vector<string> & buffer) {

}

string Utils::fixPath(string path) {

    string out = path;

#ifdef _WIN32
    for(int i = 0; i < out.length(); ++i) {
        if(out[i] == '/') {
            out[i] = '\\';
        }
    }
#else
    for(int i = 0; i < out.length(); ++i) {
        if(out[i] == '\\') {
            out[i] = '/';
        }
    }

#endif
    return out;
}
string Utils::SubString(string str, int start) {
    return SubString(std::move(str), start, str.length() - 1);
}


string Utils::SubString(string str, int start, int end) {

    if(end >= str.length()) {
        end = str.length() - 1;
    }

    if(start > end) {
        return string();
    }

    return str.substr(start, end-start+1);
}
