#include "Includes.hpp"
#include "Utils.hpp"

using namespace std;

int main(int argc, char *const argv[]) {
    
    auto * o = new vector<string>();

    Utils::runCmd("echo haha", o);
    
    for(const string i : *o) {
        Utils::print(i);
    }

    return 0;
}