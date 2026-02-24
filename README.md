# Tic_Tac_Toe
Game of tic-tac-toe

Hello everyone!

    My goal was to recreate the board game that everyone loves... TICTACTOE!!
At the moment you are only able to see the board fill up as you input your positions, but the implementation for winning is in the workshop right now!! Regardless I hope you will enjoy the game as it is right now and appreciate the hardwork I put in. I know this program is probably not as efficient as it could be, but my goal is not to be super efficient but to find really weird and interesting solutions to obstacles I encounter. Let me know your thoughts and advice would be greatly helpful to me and my future endeavors with this project. Of course if you find bugs please let me know. 

The way it works?

First you will be prompted with Hello World!, and then an empty board! This is just there so you know what it looks like as an empty board.
Next you will be prompted with "What position would you like P1?" and then you are able to put whatever number you want but my program will only accept numbers from 1-9 and then my program will translate them into something the program can read for the array. After putting a valid position, the program will spit out two more boards, one for each you and the other player/computer. I did it this way so I can better see whats going on when debugging. I might change it later so that its a bit more readbable but we shall see. With each board it should show he spot you chose and the spot the computer chose with your spot included. Filling up the board, you will notice that there is no win condition, once again I am working on that. But the other thing you will notice is that I took precaution and didn't allow the (only the player at the moment) to overwrite any existing spots. You can check this by inputting a position that has already been selected by you or the other player/computer, it will then tell you "Invalid spot!" and force you to pick another spot. This can better be tested when you fill the entire board and have the ability to attempt to pick any spot on the board. 

Things I am working on?

For the last time LOL, I am working on the win condition, but not only that I want to first work on what happens when you tie. That way if no one wins by the end you are still able to exit/restart the board and play again. Another thing I am working on, is making it to where you can play against your friends, 1v1 style.

How do I play?

Well depending on your device, you might either have to download gcc, clang, or run it in a compiler like onlinegdb. The best and easy way to play my version of tictactoe is to create a codespace. This can be done by creating a fork of my repository and then going to the main branch or simply by going back to where you clicked on the cloned/forked repository and then when your there, you should see a big green button that says code. Clicking it will pop up a display with two tabs, local and codespaces. Click on codespaces and then you will see another big green button that says "Create codesapces on main". After this you should be brought to a page that looks familiar to most, vscode, if you don't know what that is, it is a programming software that makes a lot programmers lives easier. After this if there is not a little window at the bottom of your screen that has more tabs that show "Problems, Output, Terminal, Debug Console, and Ports" then that is no problem. All you need to do is hover over the top of the bar at the bottom (usually blue but sometimes purple and maybe other colors) and your cursor should change and then drag it up a bit or all the way. You will want to be in the terminal tab and then you will type " gcc -g TicTacToe.c " (do not include the quotations) and then " ./a.out " Those two lines are for if you make changes at all, you shouldn't need to type the gcc part but if something happens you will get an error with that line and hopefully debug it. If not contact me and I will try to help you. the " ./a.out " part is what actually runs the game. I will have that file already inside the repository ready to go for you. 

This implementation is brought to you by saladbarcodes (name still in the workshop) might drastically change who knows
