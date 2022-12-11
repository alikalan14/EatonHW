# EatonHW

This solution simulates multiple devices sending data to one machine. Devices are run in different threads, and the machine reads the messages, counts them and print them out to the standard output in a thread-safe way using standard C++ library features.

There is already a simulator that runs on 3 threads, and each thread represents a device and sends data to the machine between 0 and 5 seconds frequency. The random number generator generates the frequency.

To run the project, we can use CMake. After downloading the source code and navigating to the "src" folder on the command prompt, we can use the following commands to create the executable.

cmake -S . -B ..\build

cmake --build ..\build --config Release

After running these, the executable would be under ${ROOT}\build\Release
