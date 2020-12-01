project "imgui"
   kind "StaticLib"
   language "C++"
   cppdialect "c++11"

   targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
   objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

   files { "src/**.cpp", "include/imgui/**.hpp" }
   includedirs { "include/imgui" }

   filter { "configurations:Debug" }
      defines { "DEBUG" }
      symbols "On"

   filter { "configurations:Release" } 
      defines { "NDEBUG" }
      optimize "On"