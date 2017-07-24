cmake_minimum_required(VERSION 2.8)
INCLUDE(CMakeForceCompiler)
set(ARM_PREFIX arm-frc-linux-gnueabi)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_CXX_COMPILER ${ARM_PREFIX}-g++)
set(CMAKE_C_COMPILER ${ARM_PREFIX}-gcc)
set(CMAKE_CXX_FLAGS "-std=c++1y -Wformat=2 -Wall -Wextra -pedantic" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -g" CACHE STRING "" FORCE)
