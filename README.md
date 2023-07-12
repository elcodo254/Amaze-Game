# AMAZED GAME
### Creating a 3D maze game using raycasting and SDL2

-----

### How to Compile and Run
- [SDL2](https://www.libsdl.org/download-2.0.php) is required to compile and use this program
- Compile with `gcc 4.8.4` with the following flags:
    ``gcc -O2 -g -w -Isrc/headers *.c -lSDL2 -lm -o maze `sdl2-config --cflags --libs` `` OR `make -f Makefile`
- Run the maze: `./maze

-----

### Synopsis
This 3D maze uses raycasting to draw the maze walls, utilizing [LodeV's](http://lodev.org/cgtutor/raycasting.html) method of using vectors to calculate ray length. Currently the maze has flat colors and textured walls/floors are still in the works.

#### Movement
- `W` : move forward
- `S` : move backward
- `A` : rotate camera left
- `D` : rotate camera right


#### Maps
The maps are defined in 2D arrays in text files, which are parsed when passed as an argument to the maze executable. `0` represents open space, all other integers are drawn as walls.


### Improvements
Although the method used to draw the walls has been improved on over the years, using the non-horizontal method was the most comprehensive.Since the project is still a work in progress, using the new method and adding more feautures will be embarked on.
### Resources
- [SDL2 API](https://wiki.libsdl.org/CategoryAPI)
- [LazyFoo Beginning Game Programming](http://lazyfoo.net/tutorials/SDL/index.php)
- [Ray-Casting Tutorial For Game Development And Other Purposes by F. Permadi](http://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
- [LodeV Raycasting Tutorial](http://lodev.org/cgtutor/raycasting.html)
- [Game Engine Black Book](https://www.amazon.com/Game-Engine-Black-Book-Wolfenstein/dp/1539692876)
