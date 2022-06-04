# Tests need to be added as executables first
add_executable(EndToEndTest EndToEndTest.cpp)

# I'm using C++17 in the test
target_compile_features(testlib PRIVATE cxx_std_17)

add_custom_target(
    e2e
    COMMAND EndToEndTest
    COMMENT "Running EndToEndTest"
)