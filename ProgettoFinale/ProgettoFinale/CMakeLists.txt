cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(CXX_STANDARD_REQUIRED 11)

project(ProgettoFinale)

add_library(lib_battaglia_navale

    include/Map.h
    include/Map.fwd.h
    src/Map.cpp

    include/AttackMap.h
    include/AttackMap.fwd.h
    src/AttackMap.cpp

    include/DefenceMap.h
    include/DefenceMap.fwd.h
    src/DefenceMap.cpp

    include/ControlDefence.h
    include/ControlDefence.fwd.h
    src/ControlDefence.cpp

    include/ControlAttack.h
    include/ControlAttack.fwd.h
    src/ControlAttack.cpp

    include/Game.h
    include/Game.fwd.h
    src/Game.cpp

    include/Player.h
    include/Player.fwd.h
    src/Player.cpp

    include/Sheet.h
    include/Sheet.fwd.h
    src/Sheet.cpp

    include/Ship.h
    include/Ship.fwd.h
    src/Ship.cpp

    include/Component.h
    src/Component.cpp

    include/Computer.h
    src/Computer.cpp

    include/ControlMap.h
    src/ControlMap.cpp

    include/Cruiser.h
    src/Cruiser.cpp

    include/GameState.h
    src/GameState.cpp

    include/Human.h
    src/Human.cpp

    include/LogManipulator.h
    src/LogManipulator.cpp

    include/PlacementGameState.h
    src/PlacementGameState.cpp

    include/PlayGameState.h
    src/PlayGameState.cpp

    include/Pos.h
    src/Pos.cpp

    include/ReplayGameState.h
    src/ReplayGameState.cpp

    include/Submarine.h
    src/Submarine.cpp

    include/Support.h
    src/Support.cpp
)

add_executable(battaglia_navale
    
    ${PATH_TO_DIRECTORY}/src/battaglia_navale.cpp
)

target_include_directories(battaglia_navale PRIVATE ${PATH_TO_DIRECTORY}/include)
target_include_directories(battaglia_navale PRIVATE ${PATH_TO_DIRECTORY}/src)


target_link_libraries(battaglia_navale
    lib_battaglia_navale
)