cmake_minimum_required(VERSION 3.14)
project(SSPU_ukazka_2)

set(CMAKE_CXX_STANDARD 11)

include_directories(include /usr/local/include)

link_directories(/usr/local/lib)
link_libraries(-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system)

add_executable(SSPU_ukazka_2 src/main.cpp src/game.cpp include/game.hpp src/player.cpp include/player.hpp src/projectile.cpp include/projectile.hpp src/enemy.cpp include/enemy.hpp src/aircraft.cpp include/aircraft.hpp include/entity.hpp src/entity.cpp include/resource_manager.hpp src/resource_manager.cpp include/moveable.hpp include/random.hpp src/random.cpp include/enemy_factory.hpp src/enemy_factory.cpp include/projectile_factory.hpp src/projectile_factory.cpp include/weapon.hpp src/weapon.cpp include/weapon_factory.hpp src/weapon_factory.cpp)

file(COPY resources DESTINATION .)
