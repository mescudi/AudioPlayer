cmake_minimum_required(VERSION 3.0.0)
project(Cpp_devialet_project VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)  # enable C++17 standard

include(CTest)
enable_testing()

include_directories(
		${PROJECT_SOURCE_DIR}/inc
               # ${PROJECT_SOURCE_DIR}/conf
		${PROJECT_SOURCE_DIR}/src
)
file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/inc/*"
        "${PROJECT_SOURCE_DIR}/src/*"
      #  "${PROJECT_SOURCE_DIR}/conf/*"

        )
#add_definitions(ENABLE_LOGGER)

add_executable(Cpp_devialet_project ${all_SRCS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
