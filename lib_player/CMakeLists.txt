cmake_minimum_required(VERSION 3.0.0)
project(lib_player VERSION 0.1.0)

# Include directories
set(INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/Command
    ${CMAKE_CURRENT_SOURCE_DIR}/Configuration
    ${CMAKE_CURRENT_SOURCE_DIR}/Input/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Output/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Output/interface
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayerContext/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayerContext/interface
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayerExecutor/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayerExecutor/interface
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayerManager/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayerManager/interface
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayerStateMachine/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayingModeStrategy/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/PlayList/inc
)
# Source files
file(GLOB_RECURSE all_SRCS
    "${CMAKE_CURRENT_SOURCE_DIR}/Input/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Output/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/PlayerContext/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/PlayerExecutor/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/PlayerManager/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/PlayerStateMachine/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/PlayingModeStrategy/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/PlayList/*.cpp"
)

# Main library
add_library(lib_player STATIC ${all_SRCS})

# Link against libraries
target_link_libraries(lib_player
    Logger
    Match
    OutputWriter
    SystemFiles
    Time
)

target_include_directories(lib_player PUBLIC ${INCLUDE_DIRS})
