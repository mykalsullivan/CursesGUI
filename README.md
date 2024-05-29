# CursesGUI
A Curses-based GUI library that aims to take the struggle out of making Curses-based programs

## Inspiration
This project started primarily out of the need to separate the graphics rendering from a Curses game I was working on, but also out of the desire to learn more about graphical programming.
...wait a minute... _graphical programming_? This is based on _Curses_! That isn't _graphical programming_!
Yes, it is based on _Curses_. You know, the terminal windowing library developed starting back in the _80s_? Yeah, that.
I chose to use Curses to create a modern C++ GUI library that can be used in the terminal kinda like Qt or JavaFX. While projects like this technically do exist, I don't believe any of them have truly took-off. It isn't my goal to make something everyone will use, but it will certainly make creating Curses-based programs easier and more fun.

## Dependencies
* EnTT (entity-component-system) https://github.com/skypjack/entt
* Ncurses (terminal graphics) https://invisible-island.net/ncurses/

## Compiling
To compile:
  1. Unzip source archive (.zip)
  2. Move into source directory
  3. Build makefile using `cmake -B .`
  4. Compile with `make`

## Plans
Right now, ensuring that graphical rendering works is the main concern.
As far as _real_ features goes:
* Adding panel elements, such as buttons, input boxes, check boxes, dropdown boxes, and such
* Keyboard/mouse input
* Input listeners
* Bitmap rendering
* __... other basic features that I'm sure other GUI libraries need to function.__

## Contributing
If you want to contribute, just fork the code and submit a pull request!
Bug-testing is super helpful. PLEASE... TRY TO BREAK MY PROGRAM!!!

## Contributers
Mykal Sullivan - Primary contributor (_well, THE contributor at the moment..._
