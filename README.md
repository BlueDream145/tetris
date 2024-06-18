# tetris
Epitech Project, tetris with ncurses


![alt text](https://raw.githubusercontent.com/alexandre10044/tetris/master/example.png)


Subject:

The goal of this project is to recreate the Tetris game in a UNIX terminal, with the Gameboy version rules.
You have to use ncurses.
In the folder of your binary, there must be a tetriminos directory, which contains files that describe the game
pieces.

Usage:

./tetris --help | cat -e

Usage: ./tetris [options]$

Options:$

--help

Display this help$

-L --level={num}

Start Tetris at level num (def: 1)$

-l --key-left={K}

Move the tetrimino LEFT using the K key (def: left arrow)$

-r --key-right={K}

Move the tetrimino RIGHT using the K key (def: right arrow)$

-t --key-turn={K}

TURN the tetrimino clockwise 90d using the K key (def: top

arrow)$

-d --key-drop={K}

DROP the tetrimino using the K key (def: down arrow)$

-q --key-quit={K}

QUIT the game using the K key (def: ‘q’ key)$

-p --key-pause={K}

PAUSE/RESTART the game using the K key (def: space bar)$

--map-size={row,col} Set the numbers of rows and columns of the map (def: 20,10)$

-w --without-next

Hide next tetrimino (def: false)$

-D --debug

Debug mode (def: false)$
