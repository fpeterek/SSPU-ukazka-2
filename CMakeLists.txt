cmake_minimum_required(VERSION 3.14)
project(SSPU_ukazka_2)

set(CMAKE_CXX_STANDARD 11)

include_directories(include /usr/local/include)

link_directories(/usr/local/lib)
link_libraries(-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system)

add_executable(SSPU_ukazka_2 src/main.cpp src/engine.cpp include/engine.hpp src/player.cpp include/player.hpp src/projectile.cpp include/projectile.hpp src/enemy.cpp include/enemy.hpp src/aircraft.cpp include/aircraft.hpp include/entity.hpp src/entity.cpp include/texture_manager.hpp src/texture_manager.cpp include/static_entity.hpp include/movable_entity.hpp include/velocity.hpp)

file(COPY resources DESTINATION .)
