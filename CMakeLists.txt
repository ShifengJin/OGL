cmake_minimum_required(VERSION 3.1.0)

project(OGL)

set(CORE_ROOT ./)
set(Src ${CORE_ROOT}main.cpp
        ${CORE_ROOT}DrawBox.cpp
        ${CORE_ROOT}DrawLines.cpp
        ${CORE_ROOT}DrawPoint.cpp
        ${CORE_ROOT}DrawTexture.cpp
        ${CORE_ROOT}Shader.cpp
        ${CORE_ROOT}DrawBox.h
        ${CORE_ROOT}DrawLines.h
        ${CORE_ROOT}DrawPoint.h
        ${CORE_ROOT}DrawTexture.h
        ${CORE_ROOT}Shader.h
        ${CORE_ROOT}Common.h)

find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR}
                    ${GLEW_INCLUDE_DIRS}
                    ${GLEW_INCLUDE_DIRS}/GL)

add_executable(${PROJECT_NAME} ${Src})

target_link_libraries(${PROJECT_NAME} ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES})