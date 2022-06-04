
set(HEADER_LIST "${RandomGenerator_SOURCE_DIR}/include/RandomIntGenerator.hpp")

add_executable(app app.cpp ${HEADER_LIST})

# We need this directory
target_include_directories(app PRIVATE ../include)

target_compile_features(app PRIVATE cxx_std_17)

target_link_libraries(app PRIVATE fmt::fmt)
