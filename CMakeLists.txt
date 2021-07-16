cmake_minimum_required (VERSION 3.14)
SET(CMAKE_SYSTEM_NAME Generic)

include(FindUnixCommands)

project(nanostackeventloop)

option(enable_coverage_data "Enable Coverage data" OFF)

include(repositories.cmake)

# libservice is needed for ns-list and nsdynmem, so add dependencies
add_library(nanostackeventloop STATIC)
add_dependencies(nanostackeventloop nanostack-libservice)

target_sources(nanostackeventloop PRIVATE
    source/event.c
    source/event.h
    source/nanostack_eventloop.c
    source/nanostack_eventloop.h
    source/ns_timer.c
    source/ns_timer.h
    source/system_timer.c
    source/timer_sys.h
)

target_link_libraries(nanostackeventloop nanostack-libservice)

target_include_directories(nanostackeventloop PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(nanostackeventloop PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/nanostack-event-loop)
target_include_directories(nanostackeventloop PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/nanostack-event-loop/platform)
target_include_directories(nanostackeventloop PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/source)

# Tests after this line
enable_testing()

# GTest framework requires C++ version 11
#set_target_properties(ns_timer_test
#PROPERTIES
#    CXX_STANDARD 11
#)

include(GoogleTest)
#gtest_discover_tests(ns_timer_test)

if (enable_coverage_data AND ${CMAKE_PROJECT_NAME} STREQUAL "mbedcoap")
    file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/html")

    add_test(NAME coap_cov WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND ${BASH} -c "gcovr -r . -e ${CMAKE_CURRENT_SOURCE_DIR}/build -e '.*test.*' --html --html-details -o build/html/example-html-details.html"
    )
endif ()
