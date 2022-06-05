# Testing library
FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.6)
FetchContent_MakeAvailable(catch)
# Adds Catch2::Catch2

set(HEADER_LIST "${RandomGenerator_SOURCE_DIR}/src/RandomIntGenerator.hpp")
set(SOURCE_LIST "${RandomGenerator_SOURCE_DIR}/src/RandomIntGenerator.cpp")

# Tests need to be added as executables first
add_executable(UnitTest MainUnit.cpp RandomIntGeneratorTest.cpp ${HEADER_LIST} ${SOURCE_LIST})

target_include_directories(UnitTest PRIVATE ../src)

# I'm using C++17 in the test
target_compile_features(UnitTest PRIVATE cxx_std_17)

# Should be linked to the main library, as well as the Catch2 testing library
target_link_libraries(UnitTest PRIVATE Catch2::Catch2)

add_custom_target(
    utest
    COMMAND UnitTest
    COMMENT "Running All UnitTests"
)

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME UnitTests COMMAND UnitTest) # Command can be a target
