project "SfmlAPI"
   
   kind "StaticLib"

   language "C++"
   cppdialect "c++11"
   systemversion "latest"

   targetdir("bin/" .. outputdir .. "/%{prj.name}")
   objdir("bin-int/" .. outputdir .. "/%{prj.name}")

   includedirs
   {
      "include",
      "vendor/sfml/include"
   }

   files { "**.cpp" }


   filter "platforms:x86"
      architecture "x86"

   filter "platforms:x86_64"
      architecture "x86_64"

   filter { "configurations:Debug" }
      defines { "DEBUG" }
      symbols "On"

   filter { "configurations:Release" } 
      defines { "NDEBUG" }
      optimize "On"

----------------------------------------------------------------------
----------- Windows section ------------------------------------------
----------------------------------------------------------------------
   filter "system:Windows"
      characterset "MBCS"