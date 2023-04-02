# Set library name as the current directory name
get_filename_component(LIBRARY_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" LIBRARY_NAME ${LIBRARY_NAME})

project(${LIBRARY_NAME} VERSION 1.0.0)

# Set sources for OutputWriter
set(SOURCES
  src/OutputWriter.cpp
)

# Add library target for OutputWriter
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/interface
  ${CMAKE_CURRENT_SOURCE_DIR}/inc

)
