#pragma once
#define VERSION "0.0.4 beta"
bool isGameWindowOpen = false;

/// Windows' libraries

#include <locale.h>
#include <Windows.h>

/// SFML libraries

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

/// Standard libraries

#include <time.h>
#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>
#include <future>

/// Res
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	#include "strings_win.h"

#elif __linux__
	#include "strings_linux.h"
#elif __unix__
	#include "strings_linux.h"
#else
	#   error "Unsupported Plattform"
#endif

/// My API

#include "SfmlAPI.hpp"
#include "Menu.hpp"

/// My Headers

#include "firstLaunch.h"
#include "MainMenu.h"
#include "ModMenu.h"
#include "Apple.h"
#include "Version.h"
#include "setUser.h"
#include "renderHead.h"
#include "points.h"
#include "snake.h"
