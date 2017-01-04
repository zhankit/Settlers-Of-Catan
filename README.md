## WATAN CS246 Final Project
Contributors: Ding Zhan Chia, h8qu, and z39jin

## Introduction
It is a video game student of Watan, which is variant of the game Settlers of Catan, with the board based on the Univeristy of Waterloo.

## Compilation 
Makefile bash script is included. 
Use the command `make` in unix environment. It will compiled with the program name **WATAN** and be excecuted by `./WATAN`

Connection for X11 is require for graphics

## Commands for Beginning of Turn
• load: sets the dice of the current student to be loaded dice<br />
• fair: sets the dice of the current student to be fair dice<br />
• roll: rolls the current student’s dice<br />

## Commands for End of Turn
• board: prints the current board<br />
• status: prints the current status of all students in order from student 0 to 3<br />
• criteria: prints the criteria the current student has currently completed<br />
• achieve `<goal\#>`: attempts to achieve the goal at `<goal\#>`<br />
• complete `<criterion\#>`: attempts to complete the criterion at `<criterion\#>`<br />
• improve `<criterion\#>`: attempts to improve the criterion at `<criterion\#>`<br />
• trade `<colour> <give> <take>`: attempts to trade with student `<colour>` giving one resource of type `<give>` and receiving one resource of type `<take>`<br />
• next: passes control onto the next student in the game.<br />
• save `<file>`: saves the current game state to `<file>`<br />
• help: prints out the list of commands

## Command-line interface
• -seed xxx sets the random number generator’s seed to xxx. <br />
• -load xxx loads the game saved in file xxx. <br />
• -board xxx loads the game with the board specified in the file xxx instead of using random
generation. <br />
• -graphics uses the -x11 feature to compile and display a simple graphic for this game<br />
