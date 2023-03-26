#ifndef LOGGER_HPP // include guard
#define LOGGER_HPP
#include <iostream>

// définition de la macro pour activer le logger
// #define ENABLE_LOGGER
// TODO :Replace with variadic template
// Enable set at compile time
#define ENABLE_LOGGER // TODO A la compil
#ifdef ENABLE_LOGGER
#define LOG(level, message) std::cout << "Log level : " << level << " (" << __LINE__ << "): " << message << std::endl
#else
#define LOG(level, message) // ne fait rien
#endif
#endif