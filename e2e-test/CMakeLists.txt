# Testing library
FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.6)
FetchContent_MakeAvailable(catch)
# Adds Catch2::Catch2

# Tests need to be added as executables first
add_executable(EndToEndTest EndToEndTest.cpp)

# I'm using C++17 in the test
target_compile_features(EndToEndTest PRIVATE cxx_std_17)

target_link_libraries(EndToEndTest PRIVATE Catch2::Catch2)

add_dependencies(EndToEndTest app)

add_custom_target(
    e2e
    COMMAND EndToEndTest
    COMMENT "Running EndToEndTest"
)

add_test(NAME EndToEndTest COMMAND EndToEndTest)