cmake_minimum_required(VERSION 3.16)
project(PortfolioApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add local FTXUI directory
add_subdirectory(ftxui)

# Add your source files (adjust paths if needed)
add_executable(portfolio
    main.cpp
    content.cpp
)

# Link with FTXUI
target_link_libraries(portfolio
    PRIVATE
    ftxui::screen
    ftxui::dom
    ftxui::component
)