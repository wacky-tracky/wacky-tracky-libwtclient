cmake_minimum_required (VERSION 2.6)
project (libwtclient)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

add_library(wtclient SHARED src/util.cpp src/wtRequest.cpp src/wtResponse.cpp src/wtSession.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -std=c++11 ")

target_link_libraries(wtclient curl jsoncpp ssl)

install(TARGETS wtclient DESTINATION lib)

include_directories(src)

add_executable(test_authenticate test/test_authenticate.cpp)
target_link_libraries(test_authenticate wtclient)

add_executable(test_greeting test/test_greeting.cpp)
target_link_libraries(test_greeting wtclient)

add_executable(test_hashPassword test/test_hashPassword.cpp)
target_link_libraries(test_hashPassword wtclient)
