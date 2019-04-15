project(AllocatorsLibTests)

add_subdirectory(lib/googletest-release-1.8.1)

include_directories(lib/googletest-release-1.8.1/googletest/include)
include_directories(lib/googletest-release-1.8.1/googlemock/include)

add_library(AllocatorsLibTests RunTests.h RunTests.cpp AllocatorsTests.cpp)

target_link_libraries(AllocatorsLibTests gtest gtest_main)
target_link_libraries(AllocatorsLibTests AllocatorsLib)
