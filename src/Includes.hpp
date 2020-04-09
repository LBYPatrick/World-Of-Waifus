#pragma once

#define DEBUG_CMDOUT false
#define READ_BUFFER_SIZE (16 * 1024) //16K

#include <filesystem>
#include <vector>
#include <string>
#include <array>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <thread>

#ifdef _WIN32

#define popen _popen
#define pclose _pclose

#endif

#define IS_DEBUG false

using namespace std;

namespace fs = std::filesystem;
namespace timer = std::chrono;
