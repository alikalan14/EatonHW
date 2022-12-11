cmake_minimum_required (VERSION 3.10)

project(EatonHW)

add_library(Libs Device.cpp Device.h Measurement.cpp Measurement.h Observer.cpp Observer.h)
add_executable(EatonHW Eaton.cpp)
target_link_libraries(EatonHW PRIVATE Libs)