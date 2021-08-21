cmake_minimum_required(VERSION 3.12.2)

project(Snake-c-)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release"
    CACHE STRING "Configuration types" FORCE)

add_executable(Snake-c-
  src/Apple.cpp
  src/Apple.h
  src/firstLaunch.h
  src/gameThread.h
  src/imgui/imconfig.h
  src/imgui/imconfig-SFML.h
  src/imgui/imgui.cpp
  src/imgui/imgui.h
  src/imgui/imgui_demo.cpp
  src/imgui/imgui_draw.cpp
  src/imgui/imgui_internal.h
  src/imgui/imgui_widgets.cpp
  src/imgui/imgui-SFML.cpp
  src/imgui/imgui-SFML.h
  src/imgui/imgui-SFML_export.h
  src/imgui/imstb_rectpack.h
  src/imgui/imstb_textedit.h
  src/imgui/imstb_truetype.h
  src/jsonParser/SavedData.cpp
  src/jsonParser/saveddata.h
  src/main.cpp
  src/net/connection.cpp
  src/net/connection.h
  src/Points.cpp
  src/Points.h
  src/RenderHead.cpp
  src/RenderHead.h
  src/Snake.cpp
  src/snake.h
  src/strings.h
  src/strings/strings_linux.h
  src/strings/strings_win.h
  src/user.h
  src/Version.cpp
  src/Version.h
)
# Additional include directories
set_property(TARGET Snake-c-
  APPEND PROPERTY INCLUDE_DIRECTORIES
  $<$<CONFIG:Debug>:
    vendor\SfmlAPI\include;
    vendor\jsoncpp\include;
    vendor\loguru;
    vendor\imgui\include;
    vendor\sfml\include>
  $<$<CONFIG:Release>:
    vendor\SfmlAPI\include;
    vendor\jsoncpp\include;
    vendor\loguru;
    vendor\imgui\include;
    vendor\sfml\include>
)

# Preprocessor definitions
target_compile_definitions(Snake-c- PRIVATE
  $<$<CONFIG:Debug>:_MBCS;DEBUG>
  $<$<CONFIG:Release>:_MBCS;NDEBUG>
)

# Minimal rebuild
if (MSVC)
  target_compile_options(Snake-c- PRIVATE
    "$<$<CONFIG:Debug>:/Gm->"
    "$<$<CONFIG:Release>:/Gm->"
  )
endif ()

# Precompiled header files
if (MSVC)
  target_compile_options(Snake-c- PRIVATE
    ""
  )
endif ()

# Additional library directories
if (MSVC)
  target_link_options(Snake-c- PRIVATE
    $<$<CONFIG:Debug>:
      /LIBPATH:vendor\sfml\lib\msvc\x86>
    $<$<CONFIG:Release>:
      /LIBPATH:vendor\sfml\lib\msvc\x86>
  )
else ()
  target_link_options(Snake-c- PRIVATE
    $<$<CONFIG:Debug>:
      -Lvendor\sfml\lib\msvc\x86>
    $<$<CONFIG:Release>:
      -Lvendor\sfml\lib\msvc\x86>
  )
endif ()

# Link libraries
set_property(TARGET Snake-c-
  APPEND PROPERTY LINK_LIBRARIES
  "$<$<CONFIG:Debug>:opengl32.lib;sfml-graphics-d.lib;sfml-system-d.lib;sfml-audio-d.lib;sfml-network-d.lib;sfml-window-d.lib>"
  "$<$<CONFIG:Release>:opengl32.lib;sfml-graphics.lib;sfml-system.lib;sfml-audio.lib;sfml-network.lib;sfml-window.lib>"
)
