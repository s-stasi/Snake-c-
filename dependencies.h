#pragma once
#define VERSION "0.0.2 beta"
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

/// My Headers

#include "MainMenu.h"
#include "ModMenu.h"
#include "Apple.h"
#include "Version.h"
#include "setUser.h"
#include "points.h"
#include "snake.h"

/// My API

#include "SfmlAPI.hpp"