cmake_minimum_required(VERSION 3.27)
project(wmenu)

set(CMAKE_CXX_STANDARD 14)

include_directories(sources/commandLine)
include_directories(sources/commandLine/options/font)
include_directories(sources/commandLine/options/prompt)
include_directories(sources/gui)
include_directories(sources/gui/comboBox)
include_directories(sources/gui/label)
include_directories(sources/gui/textBox)
include_directories(sources/util)

add_executable(wmenu
        sources/commandLine/options/font/font.cpp
        sources/commandLine/options/font/font.hpp
        sources/commandLine/options/prompt/prompt.cpp
        sources/commandLine/options/prompt/prompt.hpp
        sources/commandLine/commandLine.cpp
        sources/commandLine/commandLine.hpp
        sources/gui/comboBox/comboBox.cpp
        sources/gui/comboBox/comboBox.hpp
        sources/gui/label/label.cpp
        sources/gui/label/label.hpp
        sources/gui/textBox/textBox.cpp
        sources/gui/textBox/textBox.hpp
        sources/gui/gui.cpp
        sources/gui/gui.hpp
        sources/util/util.cpp
        sources/util/util.hpp
        sources/main.cpp)
