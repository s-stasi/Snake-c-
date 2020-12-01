-- premake5.lua
workspace "Snake-c-"
   configurations
   {
      "Debug",
      "Release"
   }

   platforms
   {
      "x86",
      "x86_64"
   }

   startproject "Snake-c-"

-- Include directories
IncludeDir = {}
IncludeDir["SfmlAPI"] = "%{wks.location}/Snake-c-/vendor/SfmlAPI/include"
IncludeDir["jsoncpp"] = "%{wks.location}/Snake-c-/vendor/jsoncpp/include"
IncludeDir["imgui"] = "%{wks.location}/Snake-c-/vendor/imgui/include"
IncludeDir["sfml"] = "%{wks.location}/Snake-c-/vendor/sfml/include"
IncludeDir["loguru"] = "%{wks.location}/Snake-c-/vendor/loguru"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


group "dependencies"
	include "Snake-c-/vendor/SfmlAPI"
	include "Snake-c-/vendor/loguru"
	include "Snake-c-/vendor/jsoncpp"
	include "Snake-c-/vendor/imgui"
group ""


include "Snake-c-"