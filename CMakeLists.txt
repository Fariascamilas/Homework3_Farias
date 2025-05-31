cmake_minimum_required(VERSION 3.28.3) # La defino igual que aparece en c_cpp_properties.json
project("Homework3")
set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES1 "ej1/source/*.cpp")
list(APPEND SOURCES1 "ej1/main1.cpp")

file(GLOB SOURCES2 "ej2/source/*.cpp")
list(APPEND SOURCES2 "ej2/main2.cpp")

add_executable(mediciones ${SOURCES1})
add_executable(figuras ${SOURCES2})
add_executable(json "ej3/main3.cpp")