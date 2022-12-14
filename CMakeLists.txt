cmake_minimum_required(VERSION 3.22)
project(Eden)

# Använd C++ 17.
set(CMAKE_CXX_STANDARD 17)

# På skolans Linux-system finns två versioner av GCC. Se vilken som används:
if (DEFINED ENV{LOADEDMODULES} AND ("$ENV{LOADEDMODULES}" MATCHES ".*prog/gcc/6.1.0.*"))
    set(CMAKE_CXX_COMPILER /sw/gcc-6.1.0/bin/g++)

    if (DEFINED ENV{SFML_ROOT})
        list(APPEND CMAKE_MODULE_PATH "$ENV{SFML_ROOT}/share/SFML/cmake/Modules")
    endif()
endif()

if (DEFINED ENV{LOADEDMODULES} AND ("$ENV{LOADEDMODULES}" MATCHES ".*prog/gcc/7.1.0.*"))
    set(CMAKE_CXX_COMPILER /sw/gcc-7.1.0/bin/g++)

    if (DEFINED ENV{SFML_ROOT})
        list(APPEND CMAKE_MODULE_PATH "$ENV{SFML_ROOT}/share/SFML/cmake/Modules")
    endif()
endif()

# Välj vilka delar av SFML som ska användas.
set(SFML_MODULES network graphics window system)

# Försök att hitta SFML genom att anropa 'FindSFML.cmake'.
find_package(SFML 2 COMPONENTS ${SFML_MODULES})
include_directories(${SFML_INCLUDE_DIR})

# Om det inte gick hoppas vi att det är installerat i alla fall.
if (NOT (${SFML_FOUND} STREQUAL "TRUE"))
    set(SFML_LIBRARIES "")
    foreach(i ${SFML_MODULES})
        list(APPEND SFML_LIBRARIES "sfml-${i}")
    endforeach(i)
endif()

# Ange källfiler, lägg till de filer som ni behöver!
set(SOURCE_FILES main.cc)

# Säg till CMake att skapa en körbar fil som heter 'sfml'.
add_executable(Eden main.cpp Game.cpp Game.h Character.cpp Character.h Player.cpp Player.h Enemy.cpp Enemy.h MovingObject.cpp MovingObject.h Projectile.cpp Projectile.h Healthbar.cpp Healthbar.h Worm.h Worm.cpp Lilith.h Lilith.cpp Wall.h Wall.cpp SpriteObject.h SpriteObject.cpp level.txt suppressions.txt)

# Länka med biblioteken som vi hittade tidigare.
target_link_libraries(Eden ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
