#include "Includes.hpp"
#include "Utils.hpp"

using namespace std;

string getModPath() {

    if(fs::exists("bin64/paths.xml")) {
        ifstream i("bin64/paths.xml");

        string buffer;
        while(getline(i,buffer)) {
            if(buffer.find("res_mods") != string::npos) {
                return Utils::SubString(buffer,buffer.find("<Path>") + 9,buffer.find("</Path>") - 1);
                break;
            }
        }

    }
    return string();
}

int main(int argc, char *const argv[]) {


    //Get WOWS Mod Path

    string modPath = getModPath();

    if(modPath.length() == 0) {
        Utils::printLn("Failed to Locate paths.xml!");
        return 1;
    }

    //Get Mods List & Load
    if(fs::exists("mods")) {
        for(auto & i : fs::directory_iterator("mods")) {

            string source = i.path().u8string(),
                   target = modPath;

            thread([&] {
                Utils::markLink(source,target);
            }).join();
        }
    }

    /*
    auto * o = new vector<string>();

    Utils::runCmd("echo haha", o);
    
    for(const string i : *o) {
        Utils::print(i + "\n");
    }
    */

    string test = "ABCDE";

    string source = R"(test)";
    string target = R"(B)";

    Utils::markLink(source,target);

    system("pause");
    return 0;
}