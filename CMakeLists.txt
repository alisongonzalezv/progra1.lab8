cmake_minimum_required(VERSION 3.20)
project(Lab8Progra1_2026 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluir la carpeta de cabeceras (.h)
include_directories(Headers)

# Agregar todos los archivos fuentes (.cpp)
file(GLOB SOURCES
        "main.cpp"
        "Classes/*.cpp"
)

# Crear el ejecutable
add_executable(Lab8Progra1_2026 ${SOURCES})