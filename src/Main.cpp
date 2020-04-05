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


    vector<ThreadHolder> threadPool;
    //Get WOWS Mod Path

    string modPath = getModPath();

    if(modPath.length() == 0) {
        Utils::printLn("Failed to Locate paths.xml!");
        return 1;
    }

    //Get Mods List & Load
    if(fs::exists("mods")) {

        int numMods = Utils::getFolderList("mods").size();

        for(auto & i : fs::directory_iterator("mods")) {

            bool isDone = false;

            string source = i.path().u8string(),
                    target = modPath;

            Utils::printLn(Utils::truncateDouble(Utils::getElaspedTimeSeconds(), 2)
                           + "s  "
                           + "Mounting "
                           + Utils::SubString(source, source.rfind("\\") + 1)
                           + ".");


            /*
            thread t([&] {

                Utils::markLink(source, target);

                isDone = true;
            });
             */

            threadPool.push_back({thread([&] {Utils::markLink(source, target);isDone = true;}),isDone});

            threadPool.back().t.join();

        }
    }

    while(true) {

        bool isAllDone = true;

        for(auto & i : threadPool) {
            if(i.isDone == false) {
                isAllDone = false;
                break;
            }
        }

        if(isAllDone) break;
    }

    Utils::printLn(Utils::truncateDouble(Utils::getElaspedTimeSeconds(), 2) + "s  " + "All done.");

    return 0;
}