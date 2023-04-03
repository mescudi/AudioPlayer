#ifndef LOGGER_HPP // include guard
#define LOGGER_HPP
#include <iostream>

// definition of macro to activate logger
// #define ENABLE_LOGGER
// TODO :Replace with variadic template
// Enable set at compile time in Cmake
#ifdef ENABLE_LOGGER
#define LOG(level, message) std::cout << "Log [" << level << "]" \
                                      << " (" << __FUNCTION__ << ") " << message << std::endl
#else
#define LOG(level, message) // ne fait rien
#endif
#endif