cmake_minimum_required (VERSION 3.11)
SET(CMAKE_SYSTEM_NAME Generic)

project(nanostackeventloop)

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

target_include_directories(nanostackeventloop PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/nanostack-event-loop)
target_include_directories(nanostackeventloop PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/nanostack-event-loop/platform)
target_include_directories(nanostackeventloop PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/source)
