#pragma once
#include <string>
#include "SfmlAPI.hpp"

using std::string;

static string icon_img = "C:/Users/" + SfmlAPI::getSystemUser() + "/AppData/Local/Snake/img/icon.bmp";
static string acc_confirm_file = "C:/Users/" + SfmlAPI::getSystemUser() + "/AppData/Local/Snake/src/firstAccess.confirm";
static string head_dir = "C:/Users/" + SfmlAPI::getSystemUser() + "/AppData/Local/Snake/img/heads";
static string font_arial_file = "Font/arial.ttf";
static string points_file = "C:/Users/" + SfmlAPI::getSystemUser() + "/AppData/Local/Snake/src/points";
static string username_file = "C:/Users/" + SfmlAPI::getSystemUser() + "/AppData/Local/Snake/src/username";