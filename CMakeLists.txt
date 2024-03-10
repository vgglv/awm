cmake_minimum_required(VERSION 3.28)
project(awm)

file(GLOB_RECURSE SOURCES 
	"src/*.cpp"
	"src/*.h"
	)

add_library(awm ${SOURCES})
target_include_directories(awm PUBLIC "src")

option(AWM_BUILD_TESTS "Build tests executable" OFF)

if (AWM_BUILD_TESTS)
	add_subdirectory(tests)
endif(AWM_BUILD_TESTS)
