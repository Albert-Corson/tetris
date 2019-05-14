# Tetris
A recode of the [Tetris](https://en.wikipedia.org/wiki/Tetris_(Game_Boy)) game using the ncurses library

*This is a school project and it may only work under a Unix environment*

#### Description
The goal of this project was to recreate the [Tetris](https://en.wikipedia.org/wiki/Tetris_(Game_Boy)) game in a Unix terminal, with the Gameboy version rules.
It had to be done using the ncurses library and the game pieces (the tetriminos) had to be described in text files (contained in the `tetriminos/` folder)

#### Tetriminos
The tetriminos files are composed in the following way:
- On the first line, the size and color of the piece in this format: `width height color\n` (the number of the color corresponds to the ncurses capacity’s color numbers)
- On the `height` following lines, the piece’s shape composed with asterisks (`*`) and spaces (` `)

*You can now create your own tetrimino by placing your file in the tetriminos folder adding `.tetrimino` at the end of its name*

#### Flags
Multiple optional flags are available, you can take a look at the `.legend` file to learn more, or simply execute this command (if the source files are already compiled):

`./tetris --help`

#### How to test it
To test out the game, you must first compile the source files using the `make` command.

Now you may simply execute the binary to have the game run:

`./tetris [options]`

*If you don't know what the keybinds are to play the game, you may execute `./tetris --help`*
