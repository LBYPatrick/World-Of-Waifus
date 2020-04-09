#include "Includes.hpp"
#include "Utils.hpp"
#include "Thread.hpp"

using namespace std;

string getModPath() {

    if (fs::exists("bin64/paths.xml")) {
        ifstream i("bin64/paths.xml");

        string buffer;
        while (getline(i, buffer)) {
            if (buffer.find("res_mods") != string::npos) {
                return Utils::SubString(buffer, buffer.find("<Path>") + 9, buffer.find("</Path>") - 1);
                break;
            }
        }

    }
    return string();
}

int main(int argc, char *const argv[]) {

    vector<Thread> threadPool;

    //Get WOWS Mod Path
    string modPath = getModPath();

    if (modPath.length() == 0) {
        Utils::printLn("Failed to find valid paths.xml!");
        return 1;
    }

    //Get Mods List & Load
    if (fs::exists("mods")) {

        //Purge res_mods/<version_number> and create a new one

        if(fs::exists(modPath)) {
            fs::remove_all(modPath);
        }

        Utils::createDirectory(modPath);

        int numMods = Utils::getFolderList("mods").size();

        Utils::printLn(Utils::getPrintableTime() + " " + to_string(numMods) + " mods found. Start Working.");

        for (auto &i : fs::directory_iterator("mods")) {

            string source = i.path().u8string(),
                    target = modPath;


            threadPool.push_back(Thread(thread([&] {
                Utils::markLink(source, target);
                Utils::printLn(Utils::getPrintableTime()
                               + " "
                               + "Finished Mounting "
                               + Utils::SubString(source, source.rfind("\\") + 1)
                               + ".");
            })));

            threadPool.back().run();

        }
    }

    Utils::printLn( "\n" + Utils::getPrintableTime() + " " + "All done. This window will close shortly.");

    std::this_thread::sleep_for(2s);

    return 0;
}