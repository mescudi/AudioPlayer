# Définir le nom de la librairie comme le nom du répertoire courant
get_filename_component(LIBRARY_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" LIBRARY_NAME ${LIBRARY_NAME})

project(${LIBRARY_NAME} VERSION 1.0.0)

add_library(${LIBRARY_NAME} INTERFACE)

target_include_directories(${LIBRARY_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
