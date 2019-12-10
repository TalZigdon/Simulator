cmake_minimum_required(VERSION 3.15)
project(Simulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Simulator main.cpp Command.cpp Command.h OpenServerCommand.cpp OpenServerCommand.h CommentCommand.cpp CommentCommand.h DefineVarCommand.cpp DefineVarCommand.h)