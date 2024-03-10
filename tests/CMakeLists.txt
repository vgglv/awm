message(STATUS "generating awm tests executable")

if (MACOS)
	set(CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE PRE_TEST)
endif(MACOS)
include(FetchContent)
FetchContent_Declare(googletest
		GIT_REPOSITORY https://github.com/google/googletest.git
		GIT_TAG        release-1.12.1
		)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
enable_testing()

file(GLOB_RECURSE TEST_SOURCES
	"${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
	)
set(TESTS_TARGET awm_unit_tests)
add_executable(
		${TESTS_TARGET}
		${TEST_SOURCES}
)

target_link_libraries(${TESTS_TARGET} gtest gmock awm)

include(GoogleTest)
gtest_discover_tests(${TESTS_TARGET})
