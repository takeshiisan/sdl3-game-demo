cmake_minimum_required(VERSION 3.10.0)
project(sdl2-demo VERSION 0.1.0 LANGUAGES C CXX)

add_executable(sdl2-demo src/main.cpp src/RenderWindow.cpp src/entity.cpp)

target_link_libraries(sdl2-demo SDL3 SDL3_image)

target_include_directories(sdl2-demo PRIVATE include)

