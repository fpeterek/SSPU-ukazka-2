# Airplanes

A simple game written in C++ using SFML. Shoot attacking Boeing 747s and try to survive for as long as possible.

The code is by no means perfect, I didn't have the time to polish it as much as I wanted to.

###  Prerequisities

To successfully compile the game, you must first make sure you have a C++ compiler and SFML installed on your computer.

You can use `apt` to install both G++ and SFML

`sudo apt install build-essential libsfml-dev`

An easy way to install SFML on Mac OS is to use Homebrew and run

`brew install sfml`

### Compilation

You need to specify the include directiories so the compiler knows where to find header files, as well as which libraries
should be linked against the compiled binary. The following G++ invocation works both on Mac OS and on Ubuntu, unless you 
installed your include files and SFML binaries to a non-standard location, that is.

`g++ src/* -I include/ -I /usr/local/lib/ -O3 -o game -lsfml-system -lsfml-graphics -lsfml-window`

### Credits

**Airplane sprites** were stolen from https://flightradar24.com

**Explosion sprite sheet** was stolen from https://opengameart.org/content/pixel-explosion-12-frames

**Font** used in the game is called **LCD Solid**, is free for commercial and personal use, and can be found here https://www.fontspace.com/lcd-solid/lcd-solid

**Cloud** is mine, I made it for a different project of mine.
