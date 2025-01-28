cmake_minimum_required(VERSION 3.10)
project(firstFreeglutSolution)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_C_COMPILER "C:/mingw64/bin/gcc.exe")
#set(CMAKE_CXX_COMPILER "C:/mingw64/bin/g++.exe")


# Ajouter le dossier des headers
include_directories(
        "${CMAKE_SOURCE_DIR}/Include"
)

# Ajouter le dossier des bibliothèques
link_directories(
        "${CMAKE_SOURCE_DIR}/Lib"
)

# Ajouter les fichiers sources de votre projet
add_executable(firstFreeglutSolution
        labyrinthe/main.cpp
        labyrinthe/Environnement.cpp
        labyrinthe/Wall.cpp
)

# Lier les bibliothèques nécessaires pour différentes configurations (Debug/Release)
target_link_libraries(firstFreeglutSolution
        debug "${CMAKE_SOURCE_DIR}/Lib/freeglutd.lib"  # Version debug de freeglut
        optimized "${CMAKE_SOURCE_DIR}/Lib/freeglutd.lib" # Version optimisée pour Release
        "${CMAKE_SOURCE_DIR}/Lib/glew32.lib"    # GLEW
        opengl32                                 # OpenGL (système)
)

# Copier les DLL nécessaires dans le répertoire de build après la compilation
add_custom_command(TARGET firstFreeglutSolution POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/DLL/freeglutd.dll"
        $<TARGET_FILE_DIR:firstFreeglutSolution>)

add_custom_command(TARGET firstFreeglutSolution POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/DLL/glew32.dll"
        $<TARGET_FILE_DIR:firstFreeglutSolution>)

link_directories(C:/mingw64/x86_64-w64-mingw32/lib)
target_link_libraries(firstFreeglutSolution
        opengl32     # Pour OpenGL
        glu32        # Pour GLU (gluOrtho2D)
        freeglutd    # Pour FreeGLUT (debug)
        glew32       # Pour GLEW
)
