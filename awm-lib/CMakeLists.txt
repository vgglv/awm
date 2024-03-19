message(STATUS "Generating awm-lib")

option(AWM_BUILD_TESTS "Build tests executable" OFF)
option(AWM_SAFETY_ON "Enable safety asserts when compiling" OFF)

file(GLOB_RECURSE SOURCES 
	"src/*.cpp"
	"src/*.h"
)
set(JSONCPP_WITH_POST_BUILD_UNITTEST OFF) #Automatically run unit-tests as a post build step
add_subdirectory(dependencies/jsoncpp)

add_library(awm-lib ${SOURCES})
target_include_directories(awm-lib PUBLIC "src")
target_link_libraries(awm-lib PRIVATE jsoncpp)

if (AWM_SAFETY_ON)
	target_compile_definitions(awm-lib PRIVATE AWM_SAFETY_ON)
endif(AWM_SAFETY_ON)

if (AWM_BUILD_TESTS)
	add_subdirectory(tests)
endif(AWM_BUILD_TESTS)
