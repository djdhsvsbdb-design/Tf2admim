cmake_minimum_required(VERSION 3.20)
project(TF2AdminTools LANGUAGES CXX)

if(NOT WIN32)
    message(FATAL_ERROR "TF2 Admin Tools currently supports Windows only.")
endif()

add_executable(TF2AdminTools Installer/main.cpp)
target_compile_features(TF2AdminTools PRIVATE cxx_std_17)
target_compile_definitions(TF2AdminTools PRIVATE UNICODE _UNICODE)
