cmake_minimum_required(VERSION 3.0.0)
project(Cpp_devialet_player VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

add_subdirectory(common)
add_subdirectory(lib_player)

include_directories(
	${PROJECT_SOURCE_DIR}/inc
 ${PROJECT_SOURCE_DIR}/lib_player/PlayerManager/inc

)

file(GLOB all_SRCS
	"${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(Cpp_devialet_player ${all_SRCS})

target_link_libraries(Cpp_devialet_player lib_player)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
