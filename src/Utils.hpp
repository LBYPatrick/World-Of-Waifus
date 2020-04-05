#include "Includes.hpp"

using namespace std;

//This is a singleton class
class Utils {
private:

    const string B64_INDEX = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    Utils();

    static Utils * getInstance();

    static Utils * instance;

    static void markLink(string &entryPath, string &sourcePath, string &targetPath);
public:

    //Console
    static void print(string msg);
    static void printLn(string msg);
    static void reportEvent(string category, string text);

    //IO
    static bool runCmd(string cmd);
    static bool runCmd(string cmd, vector<string> * outputBuffer);
    static void readFile(string filePath, vector<string> & buffer);
    static bool markLink(string & sourcePath, string & targetPath);
    static vector<string> getFolderList(string sourcePath);

    //Misc
    static string SubString(string str, int start, int end);
    static string SubString(string str, int start);
    static string fixPath(string path);
};