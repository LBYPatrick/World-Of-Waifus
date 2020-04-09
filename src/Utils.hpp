#pragma once
#include "Includes.hpp"

using namespace std;

//This is a singleton class
class Utils {
private:

    const string B64_INDEX = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    Utils();

    static Utils * getInstance();

    static Utils * instance;

    std::chrono::time_point<std::chrono::system_clock> start_time;

    vector<string> cmdQueue;

    static void markLink(string &entryPath, string &sourcePath, string &targetPath);
public:

    static void pushCmdQueue(string cmd);
    static void flushCmdQueue();

    //Console
    static void print(string msg);
    static void printLn(string msg);
    static void reportEvent(string category, string text);

    //IO
    static bool runCmd(string cmd);
    static bool runCmd(string cmd, vector<string> * outputBuffer);

    static void flushCmdQueue(vector<string> &queue);
    static void pushCmdQueue(string cmd, vector<string> &queue);

    static void readFile(string filePath, vector<string> & buffer);
    static bool markLink(string sourcePath, string targetPath);
    static vector<string> getFolderList(string sourcePath);
    static void createDirectory(string path);

    //Misc
    static string SubString(string str, int start, int end);
    static string SubString(string str, int start);
    static string fixPath(string path, bool isLinux);
    static string fixPath(string path);

    static chrono::duration<double> getElaspedTime();

    static double getElaspedTimeSeconds();
    static string truncateDouble(double value, int decimal);
    static string getPrintableTime();
};