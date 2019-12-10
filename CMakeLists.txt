cmake_minimum_required(VERSION 3.15)
project(Simulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Simulator main.cpp commands/Command.cpp commands/Command.h commands/OpenServerCommand.cpp commands/OpenServerCommand.h)