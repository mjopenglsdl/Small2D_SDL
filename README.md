Small SDL 2D Game Framework (C++)
===========

A small C++ 2D framework with SDL2 library.
I started this project in 2011 and the origin purpose is to make an easy-to-use framework for fast game development in desktop environment. 
I will make the code simple with minimal use of external libraries.

Currently I have added support for both Windows<**Code::Block**> and Mac_OSX<**xCode**>. The better way to make it would be using **cmake** which I will integrate in furture releases.

Library that you will need in order to compile & link:
* SDL2: https://www.libsdl.org/download-2.0.php
* SDL2_image: https://www.libsdl.org/projects/SDL_image/
* SDL2_ttf: https://www.libsdl.org/projects/SDL_ttf/



The current features include:
* Concise code
* 3 stack-based game states 
* Move the player
* Basic collision detection
* Basic UI widgets: button, label

My Short Plans:
* MVC architecture
* Lua Integration
* XML based configuration file and loading
* Graphic improvement
* Shared pointer
* Makefile and cmake
* Separated engine code
* Doxygen comments 
* Optimize player jump
* Delta-time based timing

Further Considerations:
* OpenGL integration
* Unit Tests

I hope this will help you learn the basic ideas behind game development.
Any support would be highly appreciated :-)

![screenshot1](https://raw.githubusercontent.com/mjopenglsdl/Small2D_SDL/master/Images/screenshots/11.png)

![screenshot2](https://raw.githubusercontent.com/mjopenglsdl/Small2D_SDL/master/Images/screenshots/22.png)


All the images/fonts resource are **CC** licensed