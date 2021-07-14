cmake_minimum_required(VERSION 3.5)

if(MINGW)
    message("Hello Mingw!")
endif()

project(OpenGL_CPP VERSION 0.1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wno-invalid-source-encoding")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-invalid-source-encoding")
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")

add_executable(main
    src/main.cpp
    src/GLDrawble.h
    # src/MartrixUtil.h src/MatrixUtil.cpp
    src/MyRenderWindow.h src/MyRenderWindow.cpp
    src/Rectangle.h src/Rectangle.cpp
    src/RenderWindow.h src/RenderWindow.cpp
    src/ShaderUtil.h src/ShaderUtil.cpp
    src/TextureUtil.h src/TextureUtil.cpp
)
target_include_directories(main PRIVATE include)
target_link_directories(main PRIVATE lib)
target_link_libraries(main PRIVATE glfw3dll glad)
set_target_properties(main
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
)
