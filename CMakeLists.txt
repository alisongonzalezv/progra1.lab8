cmake_minimum_required(VERSION 3.20)
project(Lab8Progra1)

set(CMAKE_CXX_STANDARD 20)

# Detectar automáticamente todos los archivos .cpp en Classes/
file(GLOB SOURCES "Classes/*.cpp" "main.cpp")

add_executable(Lab8Progra1 ${SOURCES}
        Classes/CheeseRepository.cpp
        Headers/CheeseRepository.h)

# Incluir carpeta Headers
target_include_directories(Lab8Progra1 PRIVATE Headers)