cmake_minimum_required(VERSION 3.5) # CMake install : https://cmake.org/download/
project(OGL LANGUAGES CXX)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/home/alva/Qt5.14.2/5.14.2/gcc_64") # Qt Kit Dir
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED) # Qt COMPONENTS

aux_source_directory(./src srcs)
aux_source_directory(. srcs)

find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR}
                    ${GLEW_INCLUDE_DIRS}
                    ${GLEW_INCLUDE_DIRS}/GL
                    ./src)

# Specify MSVC UTF-8 encoding   
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_executable(${PROJECT_NAME}
    WIN32 # If you need a terminal for debug, please comment this statement 
    ${srcs} 
) 
# target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES}) # Qt5 Shared LibraryCMakeLists.txt
target_link_libraries(${PROJECT_NAME} Qt5::Widgets ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES}) # Qt5 Shared LibraryCMakeLists.txt