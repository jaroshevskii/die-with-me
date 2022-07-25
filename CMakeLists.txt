cmake_minimum_required(VERSION 3.0.0)
project(ProjectVoid VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# add_subdirectory(temp)

# Add sources files.
add_executable(${PROJECT_NAME}
  ${PROJECT_SOURCE_DIR}/sources/Main.cpp
  ${PROJECT_SOURCE_DIR}/sources/Game.cpp
  ${PROJECT_SOURCE_DIR}/sources/Screen.cpp
  ${PROJECT_SOURCE_DIR}/sources/Window.cpp
  ${PROJECT_SOURCE_DIR}/sources/Settings.cpp
)

# Add headers files.
target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

if (WIN32)
  INCLUDE_DIRECTORIES(C:/Dev/vcpkg/installed/x86-windows/include)
  LINK_DIRECTORIES(C:/Dev/vcpkg/installed/x86-windows/lib)
endif (WIN32)

# Add libraries.
target_link_libraries(${PROJECT_NAME} raylib)

# Set the asset path macro.
target_compile_definitions(${PROJECT_NAME}
  PUBLIC
    # Path for debug mode.
    ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/"
    # Path for release mode.
    # ASSETS_PATH = "./"
)