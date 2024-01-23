Sofia University St. Kliment Ohridski
Introduction to programming project 01 - Battleships
created by Antonio Gatovski

Table of contents:
1. Project description
2. Functionality
3. Project contents

   1. Project description:
      
      -Your task is to develop software for a game called "Battleships," where two players or a player and a computer can play against each other on a single local device. The game should provide options for placing ships, shooting, and announcing the result.
      
    2. Key functionalities:

Placing Ships:
The game should offer an option to place ships on the playing board. Ships can vary in size:

Boats: Size of 2 cells.
Submarines: Size of 3 cells.
Destroyers: Size of 4 cells.
Aircraft Carrier: Size of 5 cells.
Players should have the ability to place their ships with horizontal or vertical orientation.
Game Board:
The game should provide a visualization of the playing board for each player. You can use ASCII graphics to represent the maritime environment.

Moves:
Players take turns by shooting at specific cells on the opponent's playing board.
After each move, the result (hit, miss, or sink) is announced.

End of the Game:
A winner can be declared when all the opponent's ships are sunk.

    3. Additional functionalities:

Saving and Resuming the Game:
Include a feature to save the current state of the game, allowing players to continue later. This can involve saving the positions of the ships, the current player's turn, and other relevant game data.

Dynamic Game Board Size:
Allow for dynamic sizing of the playing board, providing players with the option to choose the dimensions of their playing field. This can add flexibility to the game and enhance the overall gaming experience.

These features contribute to the game's versatility and replay value, allowing players to customize their experience and save their progress for future sessions. 

     4. Project contents:

1. Libraries used:
- iostream
- random to generate random placement and shooting coordinates for the "Player versus computer" feature

2. Description of all functions:
- unsigned getStringLength() - returns the length of a char array
- unsigned convertCharToUnsigned() - converts a char to an unsigned int
- void printStartMenu() - prints the contents of the start menu
- void clearConsole() - clears the contents of the console
- char saveAndContinue() - saves the current state of the game and upon receiving a command the function lets the current game continue or restarts the game from the begining
- void printBoard() - prints on the console the contents of the matrix array which represents a player's board
- bool checkValidCoordinates() - returns true/false depending on whether or not the coordinates given by the player are valid for ship placement
- bool checkValidShootingCoordinates returns true/false depending on whether or not the coordinates given by the player are valid for shooting
- void loadMatrixPlayer() - loads the dynamic matrix array which represents a player's board
- void initializeShip() - depending on the input the function initializes a ship on the player's board. The ship could be any of the above-mentioned ones.
- void playPVCGame() - starts the "Player versus computer" game feature where a player and the computer take turns playing the game. Firstly, the player initializes his ships then the computer. After that, they take turns shooting until someone sinks all of the opponents' ships first.
- void playPVCGame() - starts the "Player versus player" game feature where two players take turns playing the game. Firstly, both players initialize their ships. After that, they take turns shooting until someone sinks all of the opponents' ships first.
