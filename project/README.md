# Project 3 - Graphical LCD Toy

## Introduction


## Run Instructions

Command used to compile and run the program:

**$ make load**

Command used to clean any unnecessary or temporary files from the project directory:

**$ make clean**

## Program Explained

The state machine starts at 0 state. To move between the states requires use
of buttons, 1-3, setting button 4 on the side for reset state functionality.
Led's are changed based on 2 things, for RED it is on when the CPU is turned
on, and GREEN is for blinking and dim functionality.
Below is a description of each state and the way to advance.

Pre-State Machine:
- Before any state can start, there is a 5 second loading screen that makes
laser sounds. 

0. Zero State
   - Green is fully lit
   - User is told to press button 1 to advance. (B1 in colored text)
   - Plays a continous tone when pressed
1. State 1
   - Green now blinks!
   - User is told to press button 2 to spawn triangle  (B2 in colored text)
   - Plays a continous *different* tone when pressed
2. State 2
   - Green is now off
   - Triangle has appeared :)
   - User is told to press button 3 double the size of triangle. (B3 in colored text)
   - Plays a continous *different* tone when pressed
2. State 3
   - Green is now dim
   - Triangle has doubled size :o
   - User is told to press button 3 AND button 1 to change the color of
   triangle and play a tune (B1, B3, and color are in colored text)
   - Plays a new little tune when pressed
4. State 4
   - Displays "Playing - Fall and Rise" (With each letter of fall and rise in
   a different color presenting a rainbow of colored text)
   - Automatically advances to state 0.
   - Then plays, "Fall and Rise"
5. Exit State (Whenever button 4 is pressed)
   - No LEDs on.
   - Auto advance to state 0.
   - Turns off buzzer.
   - Resets variables for clean game start.
   - Plays beep when done.
