cmake_minimum_required(VERSION 3.2.2)

project(explorer)

set(EXPLORER_VERSION_MAJOR 0)
set(EXPLORER_VERSION_MINOR 1)
set(EXPLORER_VERSION_PATCH 0)
set(EXPLORER_VERSION_TWEAK 0)
set(EXPLORER_VERSION ${EXPLORER_VERSION_MAJOR}.${EXPLORER_VERSION_MINOR}.${EXPLORER_VERSION_PATCH}.${EXPLORER_VERSION_TWEAK})
set(EXPLORER_VERSION_STRING "v${EXPLORER_VERSION}")

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES main.cpp)
add_executable(explorer ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} -lboost_system -lboost_filesystem -pthread)

target_include_directories(explorer PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS explorer
    EXPORT explorer-config
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
install(EXPORT explorer-config DESTINATION cmake)

include(CPackConfig.cmake)
