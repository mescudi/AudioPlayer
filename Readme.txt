----- Imaginary Player Project  for Devialet exercise -----

This project's goal is to show my capacity to design and code a scalable and maintanable project.
I wanted to do a Cpp 17 project based on duck typing rather than inheritance

Even if Units Tests are 50% of a software project, unfortunately I could not include them here as I put all the efforts in design and implementing functions. 



I use VSCode with built-in Cmake support for my project :
Compiler : MSVC 19.30.30709.0

To generate build files and execute the player :
1 Install CMake: If you haven't already installed CMake on your machine, download and install the latest version from the official CMake website.
2 Open a terminal or command prompt: You will need to open a terminal or command prompt to run CMake commands.
3 Navigate to the project directory: In the terminal, navigate to the root directory of your project.
4 Create a build directory: In the project directory, create a new directory called "build" (or any other name you prefer). This is where CMake will generate the build files.
5 Generate build files: In the terminal, navigate to the build directory and run the CMake command to generate the build files. For example: cmake ..
6 Build the project: Once the build files have been generated, run the command to build the project. For example: make
7 Run the executable Cpp_devialet_player : After successfully building the project, you can now run the executable file that was generated in the build directory.



option during Cmake To activate debug logs -DENABLE_LOGGER=ON


Guilhem Gerbault