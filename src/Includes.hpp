#pragma once

#define SOFTWARE_VERSION "0.0.1"
#define _CRT_SECURE_NO_WARNINGS

#define DEBUG_CONFIG false
#define DEBUG_IO false
#define DEBUG_ANALYZER false
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

#ifdef _WIN32

#define popen _popen
#define pclose _pclose

#endif

using namespace std;

namespace fs = std::filesystem;