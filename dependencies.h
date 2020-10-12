#pragma once
#define VERSION "0.0.4 beta"
bool isGameWindowOpen = false;

/// Windows' libraries

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	#include <windows.h>
#endif

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
#include "strings.h"

/// My API

#include "SfmlAPI.hpp"

/// My Headers

#include "Connection.h"
#include "firstLaunch.h"
#include "Apple.h"
#include "Version.h"
#include "user.h"
#include "RenderHead.h"
#include "Points.h"
#include "snake.h"
