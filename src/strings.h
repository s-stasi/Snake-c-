#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include "strings/strings_win.h"

#elif __linux__
#include "strings/strings_linux.h"
#elif __unix__
#include "strings/strings_linux.h"
#else
#   error "Unsupported Plattform"
#endif