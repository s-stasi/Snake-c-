project "Snake-c-"
   kind "ConsoleApp"
   language "C++"
   cppdialect "c++11"
   systemversion "latest"

   targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
   objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

   includedirs
   {
      "%{IncludeDir.SfmlAPI}",
      "%{IncludeDir.jsoncpp}",
      "%{IncludeDir.loguru}",
      "%{IncludeDir.imgui}",
      "%{IncludeDir.sfml}"
   }

   links
   {
      "jsoncpp",
      "loguru",
      "SfmlAPI",
      "opengl32"
   }

   files { "src/**.cpp", "src/**.h" }


   filter "platforms:x86"
      architecture "x86"

   filter "platforms:x86_64"
      architecture "x86_64"

----------------------------------------------------------------------
----------- Windows section ------------------------------------------
----------------------------------------------------------------------
   filter "system:Windows"
      characterset "MBCS"

   filter { "configurations:Debug", "system:Windows" }
      defines { "DEBUG" }
      symbols "On"
      links
      {
         "sfml-graphics-d.lib",
         "sfml-system-d.lib",
         "sfml-audio-d.lib",
         "sfml-network-d.lib",
         "sfml-window-d.lib"
      }

   filter {"configurations:Release", "system:Windows"} 
      defines { "NDEBUG" }
      optimize "On"
      links
      {
         "sfml-graphics.lib",
         "sfml-system.lib",
         "sfml-audio.lib",
         "sfml-network.lib",
         "sfml-window.lib"
      }

   filter { "platforms:x86", "system:Windows" }
      libdirs { "vendor/sfml/lib/msvc/x86/" }

   filter { "platforms:x86_64", "system:Windows" }
      libdirs { "vendor/sfml/lib/msvc/x64/" }

----------------------------------------------------------------------
----------- Linux section --------------------------------------------
----------------------------------------------------------------------
   filter { "configurations:Debug", "system:Linux" }
      defines { "DEBUG" }
      symbols "On"
      links
      {
         "sfml-graphics-d",
         "sfml-system-d",
         "sfml-audio-d",
         "sfml-network-d",
         "sfml-window-d"
      }

   filter {"configurations:Release", "system:Linux"} 
      defines { "NDEBUG" }
      optimize "On"
      links
      {
         "sfml-graphics",
         "sfml-system",
         "sfml-audio",
         "sfml-network",
         "sfml-window"
      }

   filter {"configurations:Debug", "platforms:x86", "system:Linux" }
      libdirs { "vendor/sfml/lib/gcc/x86" }

   filter {"configurations:Release", "platforms:x86_64", "system:Linux" }
      libdirs { "vendor/sfml/lib/gcc/x64" }