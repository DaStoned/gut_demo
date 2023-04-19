# Build unit test
cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 20)
project(gut_sec)

# Download and set up googletest at configure time
cmake_policy(SET CMP0135 NEW) # Skip warning over DOWNLOAD_EXTRACT_TIMESTAMP
include(FetchContent)
FetchContent_Declare(
  googletest
  # Update to latest googletest release
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(
  "../src"
  "mocks"
)

# Add the unit test executable and link against googletest and our code
add_executable(gut
  gut_main.cpp
  ut_tag_codec.cpp
  ut_pet_sec.cpp
  ../src/pet_sec.cpp
)
target_link_libraries(gut_sec gtest_main gmock_main)
