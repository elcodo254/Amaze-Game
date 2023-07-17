# AMAZE GAME
### A simple 3D maze game using raycasting and SDL2
![textured_1](https://github.com/elcodo254/Amaze-Game/blob/7a961ff54af931a03e3aa1986aee6f1f3b95e045/screenshots/textured_1.png)
### Installation
- [SDL2](https://www.libsdl.org/download-2.0.php) is required to compile and use this program
- Compile with `gcc 4.8.4` with the following flags:
    ``gcc -g -Isrc/headers *.c -lSDL2 -lm -o maze `sdl2-config --cflags --libs` `` OR `make all`
- Run the maze: `./maze`

-----

### Usage
This 3D maze uses raycasting to draw the maze walls, utilizing [LodeV's](http://lodev.org/cgtutor/raycasting.html) method of using vectors to calculate ray length. Currently the maze has flat colors and textured walls/floors.Texturing can be turned on and off.

#### Movement
- `W` : move forward
- `S` : move backward
- `A` : rotate camera left
- `D` : rotate camera right
- `Q` : strafe left
- `E` : strafe right
- `ESC` : quit

![flat_maze](https://github.com/elcodo254/Amaze-Game/blob/7a961ff54af931a03e3aa1986aee6f1f3b95e045/screenshots/flat_maze.png)

#### Maps
The maps are defined in 2D arrays in text files, which are parsed when passed as an argument to the maze executable. `0` represents open space, all other integers are drawn as walls.

Example:
```
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 2 2 2 2 2 0 0 0 0 3 0 3 0 3 0 0 0 1
1 0 0 0 0 0 2 0 0 0 2 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 2 0 0 0 2 0 0 0 0 3 0 0 0 3 0 0 0 1
1 0 0 0 0 0 2 0 0 0 2 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 2 2 0 2 2 0 0 0 0 3 0 3 0 3 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 4 4 4 4 4 4 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 0 4 0 0 0 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 0 0 0 0 5 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 0 4 0 0 0 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 0 4 4 4 4 4 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 4 4 4 4 4 4 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
```

### Improvements
Although the method used to draw the walls has been improved on over the years, using the vertical method was the most comprehensive albeit slow.Since the project is still a work in progress, using the horizontal method of raycasting and adding more features will be embarked on.

### Links
- [Youtube](https://youtu.be/_fwLmxxiLsM)
- [Github repo](https://github.com/elcodo254/Amaze-Game.git)
- [Github pages](https://elcodo254.github.io/Amaze-Game/)
- [blog]

### Resources
- [SDL2 API](https://wiki.libsdl.org/CategoryAPI)
- [LazyFoo Beginning Game Programming](http://lazyfoo.net/tutorials/SDL/index.php)
- [Ray-Casting Tutorial For Game Development And Other Purposes by F. Permadi](http://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
- [LodeV Raycasting Tutorial](http://lodev.org/cgtutor/raycasting.html)
- [Game Engine Black Book](https://www.amazon.com/Game-Engine-Black-Book-Wolfenstein/dp/1539692876)
