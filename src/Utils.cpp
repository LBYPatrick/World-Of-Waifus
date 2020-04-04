#include "Utils.hpp"

#include <utility>

Utils::Utils() {
    std::ios_base::sync_with_stdio(false);
}

Utils * Utils::getInstance() {
    if(instance == nullptr) {
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

void Utils::print(string msg) {
    printf(msg.c_str());
}

void Utils::reportEvent(string category, string text) {

}

void Utils::readFile(string filePath, vector<string> &buffer) {

}
