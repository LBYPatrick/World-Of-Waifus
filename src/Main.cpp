#include "Includes.hpp"
#include "Utils.hpp"

using namespace std;

int main(int argc, char *const argv[]) {

    /*
    for(auto & i : Utils::getFolderList("Code")) {
        Utils::printLn(i);
    }
     */

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