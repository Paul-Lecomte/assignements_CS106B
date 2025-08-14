cmake_minimum_required(VERSION 3.16)
project(SierpinskiTriangle)
set(CMAKE_CXX_STANDARD 17)

# Chemin vers le package SFML 2.6.2
set(SFML_DIR "${CMAKE_SOURCE_DIR}/libs/SFML-2.6.2/lib/cmake/SFML")

# Recherche SFML 2.x avec les composants nécessaires
find_package(SFML 2 REQUIRED COMPONENTS graphics window system)

# Création de l'exécutable
add_executable(fractal main.cpp)

# Inclusion des headers
target_include_directories(fractal PRIVATE "${CMAKE_SOURCE_DIR}/libs/SFML-2.6.2/include")

# Lien avec les bibliothèques SFML
target_link_libraries(fractal sfml-graphics sfml-window sfml-system)