cmake_minimum_required(VERSION 3.9)
project(AIA_gomoku_2019)
set(CMAKE_CXX_STANDARD 14)

include_directories(src/ include/)
add_executable(pbrain-gomoku-ai src/main.cpp src/IA.cpp src/process.cpp)
