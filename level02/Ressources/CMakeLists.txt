cmake_minimum_required(VERSION 3.9)

project(pcap_reader)

set(CMAKE_C_FLAGS "-Wall -Werror -Wall")

SET(CMAKE_MODULE_PATH /Users/xem/Snowcrash/level02/Ressources)

File(GLOB_RECURSE SOURCE pcap_reader.c pcap_reader.h)

set(dir CMAKE_CURRENT_LIST_FILE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /Users/xem/Snowcrash/level02/Ressources)

#include(FindPCAP.cmake)#
find_package(PCAP REQUIRED)
add_executable(pcap_reader ${SOURCE})
target_link_libraries(pcap_reader ${PCAP_LIBRARY})

