cmake_minimum_required(VERSION 3.14)
project(MineSweeperAlgorithm)

include(FetchContent)
FetchContent_Declare(
        malena
        GIT_REPOSITORY https://github.com/daversmith/Malena.git
        GIT_TAG v0.2.3
)
FetchContent_MakeAvailable(malena)

add_executable(${PROJECT_NAME}
        main.cpp
        MineSweeperAlgorithm/Node.h
        MineSweeperAlgorithm/Node.cpp
        MineSweeperAlgorithm/Backtracking.h
        MineSweeperAlgorithm/Backtracking.cpp
        MineSweeperAlgorithm/MineSweeperGrid.h
        MineSweeperAlgorithm/MineSweeperGrid.cpp
        MineSweeperAlgorithm/TextureSlicingDemo.h
        MineSweeperAlgorithm/TextureSlicingDemo.cpp
        MineSweeperAlgorithm/Model.h
        MineSweeperAlgorithm/Model.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE Malena::Malena)