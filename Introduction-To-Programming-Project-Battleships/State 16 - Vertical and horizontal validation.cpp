/**
*
* Solution to course project # 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author Antonio Todorov Gatovski
* @idnumber 6MI0600280
* @compiler VC
*
* <File with game functions>
*
*/

#include <iostream>
#include <fstream>
#include <windows.h>
#include <random>

const unsigned WIN = 16;

// Constraint for input validation
const unsigned MAX_STRING_SIZE = 2;
const unsigned MAX_SIZE = 100;

// Constants for ship sizes
const unsigned AIRCRAFT_CARRIER_SIZE = 5;
const unsigned BATTLESHIP_SIZE = 4;
const unsigned CRUISER_SIZE = 3;
const unsigned DESTROYER_SIZE = 2;

// Constants for ship letters
const char AIRCRAFT_CARRIER_LETTER = 'A'; 
const char BATTLESHIP_LETTER = 'B';
const char CRUISER_LETTER = 'C';
const char DESTROYER_LETTER = 'D';

// Constants for board space
const char EMPTY_SPACE = '*';
const char HIT_MARKER = '~';

// Constants for player and computer
const char PLAYER = 'P';
const char COMPUTER = 'C';

// Global variable which helps save the current state of the game or restart it
char RESTART_OPTION;

unsigned getStringLength(char* stringInput) {

    if (stringInput == nullptr) {
        return 0;
    }

    unsigned length = 0;

    while (*stringInput!='\0')
    {
        length++;
        stringInput++;
    }

    return length;
}

unsigned convertCharToUnsigned(char* stringInput) {

    if (stringInput == nullptr) {
        return 0;
    }

    unsigned length = getStringLength(stringInput);

    if (length == 1) {
        return (stringInput[length-1] - '0');
    }

    else return stringInput[length-1] - '0' + 10;
}
   
void printStartMenu() {

    std::cout << "Welcome to Battleships!" << std::endl;
    std::cout << std::endl;
    std::cout << "Choose game style" << std::endl;
    std::cout << std::endl;
    std::cout << "Press p for PVP" << std::endl;
    std::cout << "Press c for PVC" << std::endl;

}

void clearConsole() {  
    system("cls");
}

char saveAndContinue(char gameSave) {
    
    clearConsole();

    if (gameSave == 's' || gameSave == 'S') {
        // Save game state (you can implement saving logic here)
        std::cout << "Game state saved." << std::endl;

        // Prompt user for continuation or restart
        std::cout << "Press c to continue or r to restart the game..." << std::endl;
        do
        {
            std::cin >> gameSave;

            if ((gameSave != 'c' && gameSave != 'C') && (gameSave != 'r' && gameSave != 'R')) {
                std::cout << "Incorrect input!" << std::endl;
                std::cout << "Only valid commands are c and r! Try again!" << std::endl;

            }

        } while ((gameSave != 'c' && gameSave != 'C') && (gameSave != 'r' && gameSave != 'R'));

        return gameSave;
    }

    return gameSave;

}

void printBoard(char** playerBoard, unsigned boardSize) {

    for (unsigned i = 0; i < boardSize; i++)
    {
        for (unsigned j = 0; j < boardSize; j++)
        {
            std::cout << playerBoard[i][j] << ' ';;
        }
        std::cout << std::endl;
    }

}

bool checkValidCoordinates(char** playerBoard, unsigned boardSize, int indexStartingRow, int indexStartingColumn, char shipLetter, char direction) {
    int shipSize;

    // Set ship size based on ship letter
    switch (shipLetter) {
    case AIRCRAFT_CARRIER_LETTER:
        shipSize = AIRCRAFT_CARRIER_SIZE;
        break;
    case BATTLESHIP_LETTER:
        shipSize = BATTLESHIP_SIZE;
        break;
    case CRUISER_LETTER:
        shipSize = CRUISER_SIZE;
        break;
    case DESTROYER_LETTER:
        shipSize = DESTROYER_SIZE;
        break;
    default:
        return false; // Invalid ship letter
    }

    // Check if indexes are in the boundaries
    if (indexStartingRow < 1 || indexStartingRow > boardSize || indexStartingColumn < 1 || indexStartingColumn > boardSize) {
        return false;
    }

    // Check direction of positioning
    for (int i = 0; i < shipSize; ++i) {
        int row = direction == 'v' || direction == 'V' ? indexStartingRow + i : indexStartingRow;
        int col = direction == 'h' || direction == 'H' ? indexStartingColumn + i : indexStartingColumn;

        // Check if ship fits in the boundaries
        if (row < 1 || row > boardSize || col < 1 || col > boardSize) {
            return false;
        }

        // Check if there is free space for the ship
        if (playerBoard[row][col] != '*') {
            return false;
        }
    }

    return true;
}

bool checkValidShootingCoordinates(char** playerBoard, unsigned boardSize, int indexRow, int indexColumn) {

    if (indexRow<1 || indexRow>=boardSize) return false;

    if (indexColumn<1 || indexColumn>=boardSize) return false;

    return true;

}

void loadMatrixPlayer(char** playerBoard, unsigned boardSize) {

    playerBoard[0] = new char[boardSize];
    playerBoard[0][0] = ' ';

    for (unsigned i = 1; i < boardSize; i++)
    {
        playerBoard[0][i] = i - 1 + '0';

    }

    for (unsigned i = 1; i <= boardSize; i++)
    {
        playerBoard[i] = new char[boardSize];

        playerBoard[i][0] = i - 1 + '0';


        for (unsigned j = 1; j < boardSize; j++)
        {
            playerBoard[i][j] = '*';
        }
    }

}

void initializeShip(char** playerBoard, unsigned boardSize, char shipLetter, char gameMaster) {
    char directionOutsideScope;
    unsigned getDirectionLength;
    unsigned shipSize;
    

    // Set ship size based on ship letter
    switch (shipLetter) {
    case AIRCRAFT_CARRIER_LETTER:
        shipSize = AIRCRAFT_CARRIER_SIZE;
        break;
    case BATTLESHIP_LETTER:
        shipSize = BATTLESHIP_SIZE;
        break;
    case CRUISER_LETTER:
        shipSize = CRUISER_SIZE;
        break;
    case DESTROYER_LETTER:
        shipSize = DESTROYER_SIZE;
        break;
    default:
        return; // Invalid ship letter
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, boardSize - 1);

    // Determine ship direction
    if (gameMaster == PLAYER) {
        // Get user input for direction
        do {
            char* direction = new char[MAX_STRING_SIZE];
            std::cout << "Please select whether you want to place your ship vertically or horizontally! Type V for vertical and H for horizontal!" << std::endl;
            std::cin.getline(direction,MAX_SIZE);
             getDirectionLength = getStringLength(direction);
             directionOutsideScope = direction[0];

            if (getDirectionLength > 1 || (direction[0] != 'v' && direction[0] != 'h' && direction[0] != 'V' && direction[0] != 'H')) {
                std::cout << "Incorrect input! Type V or v for vertical and H or h for horizontal! Try again!" << std::endl;
                continue;
            }

            
            delete[] direction;
        } while (getDirectionLength > 1 || (directionOutsideScope != 'v' && directionOutsideScope != 'h' && directionOutsideScope != 'V' && directionOutsideScope != 'H'));
    }

    else {
        // Randomly determine direction for computer player
        directionOutsideScope = distribution(gen) % 2 == 0 ? 'v' : 'h';
    }

    int row, col;
    


    do
    {
        char* rowInput = new char[MAX_STRING_SIZE];
        char* colInput = new char[MAX_STRING_SIZE];

        if (gameMaster == PLAYER) {
            std::cout << "Type the index of the row you want to put your ship at!" << std::endl;

            std::cin.getline(rowInput, MAX_SIZE);
            unsigned rowInputLength = getStringLength(rowInput);

            if (rowInputLength != 1) {
               row = -1;
            }
            else {
               row = convertCharToUnsigned(rowInput);
            }
           
            row++;

            std::cout << "Type the index of the column from which the space the ship will be placed!" << std::endl;

            std::cin.getline(colInput, MAX_SIZE);
            unsigned colInputLength = getStringLength(colInput);

            if (colInputLength != 1) {
                col = -1;
            }
            else {
                col = convertCharToUnsigned(colInput);
            }
            col++;

            if (!checkValidCoordinates(playerBoard, boardSize, row, col, shipLetter, directionOutsideScope)) {
                std::cout << "Incorrect input! Please try again!" << std::endl; 
                continue;
            }


        }
        else {
            row = distribution(gen) + 1;
            col = distribution(gen) + 1;
        }


        delete[] rowInput;
        delete[] colInput;

    } while (!checkValidCoordinates(playerBoard, boardSize, row, col, shipLetter, directionOutsideScope));


    // Place the ship on the board
    for (int i = 0; i < shipSize; ++i) {
        int curRow = (directionOutsideScope == 'v' || directionOutsideScope == 'V') ? row + i : row;
        int curCol = (directionOutsideScope == 'h' || directionOutsideScope == 'H') ? col + i : col;
        playerBoard[curRow][curCol] = shipLetter;
    }

    // Print the board
    printBoard(playerBoard, boardSize);

  
    
}

void playPVCGame(unsigned boardSize) {
     
    while (true)
    {
        char* pressToContinueKey = new char[MAX_STRING_SIZE];
        char gameSave;

        std::cout << "You have chosen PVC game!" << std::endl;

        // Create a random number generator engine
        std::random_device rd;  // Used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()

        // Generate a random integer between 0 and boardSize (inclusive)
        std::uniform_int_distribution<int> distribution(0, boardSize - 2);
        std::uniform_int_distribution<unsigned> placement(0, 1);

        // Increase the board size by 1 so that in the matrix it is clearly visualized which column or row you are selecting
        boardSize++;
        char** playerBoard = new char* [boardSize];
        char** computerBoard = new char* [boardSize];
        char** opponentPlayerBoard = new char* [boardSize];
        char** opponentComputerBoard = new char* [boardSize];

        for (unsigned i = 0; i < boardSize; ++i) {
            playerBoard[i] = new char[boardSize];
            computerBoard[i] = new char[boardSize];
            opponentPlayerBoard[i] = new char[boardSize];
            opponentComputerBoard[i] = new char[boardSize];
        }

        // Load up the boards with custom elements
        loadMatrixPlayer(playerBoard, boardSize);
        loadMatrixPlayer(computerBoard, boardSize);
        loadMatrixPlayer(opponentPlayerBoard, boardSize);
        loadMatrixPlayer(opponentComputerBoard, boardSize);

        std::cout << "You have chosen your game settings!" << std::endl;
        std::cout << std::endl;
        std::cin.getline(pressToContinueKey, MAX_SIZE);
        if (pressToContinueKey[0] != '\0') {
            clearConsole();
        }

        // Initialize boats
        printBoard(playerBoard, boardSize);

        std::cout << "Player1. Now it's time to fill in your battleships!" << std::endl;
        initializeShip(playerBoard, boardSize, AIRCRAFT_CARRIER_LETTER, PLAYER);
        initializeShip(playerBoard, boardSize, BATTLESHIP_LETTER, PLAYER);
        initializeShip(playerBoard, boardSize, CRUISER_LETTER, PLAYER);
        initializeShip(playerBoard, boardSize, DESTROYER_LETTER, PLAYER);
        initializeShip(playerBoard, boardSize, DESTROYER_LETTER, PLAYER);

        std::cout << "You have filled all the needed spaces!" << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.getline(pressToContinueKey, MAX_SIZE);
        if (pressToContinueKey[0] != '\0') {
            clearConsole();
        }

        // Initialize ships for the computer
        printBoard(computerBoard, boardSize);

        std::cout << "Now the computer will fill its battleships!" << std::endl;

        initializeShip(computerBoard, boardSize, AIRCRAFT_CARRIER_LETTER, COMPUTER);
        initializeShip(computerBoard, boardSize, BATTLESHIP_LETTER, COMPUTER);
        initializeShip(computerBoard, boardSize, CRUISER_LETTER, COMPUTER);
        initializeShip(computerBoard, boardSize, DESTROYER_LETTER, COMPUTER);
        initializeShip(computerBoard, boardSize, DESTROYER_LETTER, COMPUTER);

        std::cout << "The computer has filled all the needed spaces!" << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.getline(pressToContinueKey, MAX_SIZE);
        if (pressToContinueKey[0] != '\0') {
            clearConsole();
        }

        unsigned hitsPlayer = 0;
        unsigned hitsComputer = 0;
        //char save;

        while (hitsPlayer != WIN && hitsComputer != WIN) {

            std::cout << "Hello Player! This is the computer's board at which you are aiming!" << std::endl;
            std::cout << "If you manage to hit a ship its index would appear on that spot!" << std::endl;
            std::cout << "However if you aim at the water a ~ would appear on that spot!" << std::endl;

            // Shooting logic for player and computer...
            printBoard(opponentPlayerBoard, boardSize);

            int rowIndex = 0;
            int colIndex = 0;
            char* rowIndexInput = new char[MAX_STRING_SIZE];
            char* colIndexInput = new char[MAX_STRING_SIZE];

            do
            {
                std::cout << "Type the index of the row where the space you want to hit is!" << std::endl;

                std::cin.getline(rowIndexInput, MAX_SIZE);
                const unsigned rowIndexInputLength = getStringLength(rowIndexInput);

                if (rowIndexInputLength != 1) {
                    rowIndex = -1;
                }
                else {
                    rowIndex = convertCharToUnsigned(rowIndexInput) + 1;
                }


                std::cout << "Type the index of the column where the space you want to hit is!" << std::endl;

                std::cin.getline(colIndexInput, MAX_SIZE);
                const unsigned colIndexInputLength = getStringLength(colIndexInput);

                if (colIndexInputLength != 1) {
                    colIndex = -1;
                }
                else {
                    colIndex = convertCharToUnsigned(colIndexInput) + 1;
                }

                if (checkValidShootingCoordinates(opponentPlayerBoard, boardSize, rowIndex, colIndex)) {


                    if (playerBoard[rowIndex][colIndex] == EMPTY_SPACE) {
                        std::cout << "You missed! Now its your opponents turn!" << std::endl;
                        opponentPlayerBoard[rowIndex][colIndex] = HIT_MARKER;
                    }

                    else if (opponentPlayerBoard[rowIndex][colIndex] == HIT_MARKER) {
                        std::cout << "You have already shot a missile at this space! " << std::endl;
                        std::cout << "Please choose another space!" << std::endl;
                        rowIndex = -1;
                        colIndex = -1;
                        continue;
                    }

                    else {
                        std::cout << "You managed to hit a ship! Good job! However, now its your opponents turn!" << std::endl;
                        opponentPlayerBoard[rowIndex][colIndex] = playerBoard[rowIndex][colIndex];
                        hitsPlayer++;
                    }

                }

                else {
                    std::cout << "Invalid coordinates! Try again!" << std::endl;
                }

            } while (!checkValidShootingCoordinates(opponentPlayerBoard, boardSize, rowIndex, colIndex));

            std::cout << "Press s to save..." << std::endl;
            std::cout << "Press any other key to continue..." << std::endl;

            std::cin.getline(pressToContinueKey, MAX_SIZE);
            if (pressToContinueKey[0] == 's' || pressToContinueKey[0] == 'S')  RESTART_OPTION = saveAndContinue(pressToContinueKey[0]);
            if (RESTART_OPTION == 'r' || RESTART_OPTION == 'R') break;

            if (pressToContinueKey[0] != '\0') {
                clearConsole();
            }
            

            std::cout << "This is the computer shooting! Just sit back and watch being beaten!" << std::endl;


            printBoard(opponentComputerBoard, boardSize);

            do
            {

                rowIndex = distribution(gen);
                rowIndex++;

                colIndex = distribution(gen);
                colIndex++;



                if (checkValidShootingCoordinates(opponentComputerBoard, boardSize, rowIndex, colIndex)) {


                    if (computerBoard[rowIndex][colIndex] == EMPTY_SPACE) {
                        std::cout << "The computer missed! Now its your  turn!" << std::endl;
                        opponentComputerBoard[rowIndex][colIndex] = HIT_MARKER;
                    }

                    else {
                        std::cout << "The computer managed to hit a ship! Now its your  turn!" << std::endl;
                        opponentComputerBoard[rowIndex][colIndex] = playerBoard[rowIndex][colIndex];
                        hitsComputer++;
                    }

                }

            } while (!checkValidShootingCoordinates(opponentComputerBoard, boardSize, rowIndex, colIndex));

            std::cout << "The index of the row at which the computer shot is!" << std::endl;
            std::cout << rowIndex << std::endl;
            std::cout << "The index of the column at which the computer shot is!" << std::endl;
            std::cout << colIndex << std::endl;

            std::cout << "Press s to save..." << std::endl;
            std::cout << "Press any other key to continue..." << std::endl;

            std::cin.getline(pressToContinueKey, MAX_SIZE);
            if (pressToContinueKey[0] == 's' || pressToContinueKey[0] == 'S')  RESTART_OPTION = saveAndContinue(pressToContinueKey[0]);
            if (RESTART_OPTION == 'r' || RESTART_OPTION == 'R') break;

            if (pressToContinueKey[0] != '\0') {
                clearConsole();
            }

            delete[] rowIndexInput;
            delete[]colIndexInput;

        }

        // Final result
        if (hitsPlayer == WIN) {
            std::cout << "Congratulations Player you win!" << std::endl;
        }

        else if (hitsComputer == WIN) {
            std::cout << "You lost to the computer!" << std::endl;
        }

        else {

            // Clean up memory
            for (unsigned i = 0; i < boardSize; ++i) {

                delete[] playerBoard[i];
                delete[] computerBoard[i];
                delete[] opponentPlayerBoard[i];
                delete[] opponentComputerBoard[i];
            }

            return;
          
        }


        // Clean up memory
        for (unsigned i = 0; i < boardSize; ++i) {

            delete[] playerBoard[i];
            delete[] computerBoard[i];
            delete[] opponentPlayerBoard[i];
            delete[] opponentComputerBoard[i];
        }

        delete[] playerBoard;
        delete[] computerBoard;
        delete[] opponentPlayerBoard;
        delete[] opponentComputerBoard;
        delete[] pressToContinueKey;
        return;

    }

}

void playPVPGame(unsigned boardSize) {

    while (true)
    {
        char* pressToContinueKey = new char[MAX_STRING_SIZE];
        char gameSave;
        unsigned hitsPlayer1 = 0;
        unsigned hitsPlayer2 = 0;

        std::cout << "You have chosen PVP game!" << std::endl;

        // Create a random number generator engine
        std::random_device rd;  // Used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()

        // Generate a random integer between 0 and boardSize (inclusive)
        std::uniform_int_distribution<int> distribution(0, boardSize - 2);
        std::uniform_int_distribution<unsigned> placement(0, 1);

        // Increase the board size by 1 so that in the matrix it is clearly visualized which column or row you are selecting
        boardSize++;
        char** player1Board = new char* [boardSize];
        char** player2Board = new char* [boardSize];
        char** opponentPlayer1Board = new char* [boardSize];
        char** opponentPlayer2Board = new char* [boardSize];

        for (unsigned i = 0; i < boardSize; ++i) {
            player1Board[i] = new char[boardSize];
            player2Board[i] = new char[boardSize];
            opponentPlayer1Board[i] = new char[boardSize];
            opponentPlayer2Board[i] = new char[boardSize];
        }

        // Load up the boards with custom elements
        loadMatrixPlayer(player1Board, boardSize);
        loadMatrixPlayer(player2Board, boardSize);
        loadMatrixPlayer(opponentPlayer1Board, boardSize);
        loadMatrixPlayer(opponentPlayer2Board, boardSize);

        std::cout << "You have chosen your game settings!" << std::endl;
        std::cout << std::endl;

        std::cin.getline(pressToContinueKey, MAX_SIZE);

        if (pressToContinueKey[0] != '\0') {
            clearConsole();
        }


        // Initialize boats
        printBoard(player1Board, boardSize);

        std::cout << "Player1. Now it's time to fill in your battleships!" << std::endl;
        initializeShip(player1Board, boardSize, AIRCRAFT_CARRIER_LETTER, PLAYER);
        initializeShip(player1Board, boardSize, BATTLESHIP_LETTER, PLAYER);
        initializeShip(player1Board, boardSize, CRUISER_LETTER, PLAYER);
        initializeShip(player1Board, boardSize, DESTROYER_LETTER, PLAYER);
        initializeShip(player1Board, boardSize, DESTROYER_LETTER, PLAYER);

        std::cout << "You have filled all the needed spaces!" << std::endl;
        std::cout << "Press any key to continue..." << std::endl;

        std::cin.getline(pressToContinueKey, MAX_SIZE);
        if (pressToContinueKey[0] != '\0') {
            clearConsole();
        }

      
        // Initialize ships for the computer
        printBoard(player2Board, boardSize);

        std::cout << "Player1. Now it's time to fill in your battleships!" << std::endl;

        initializeShip(player2Board, boardSize, AIRCRAFT_CARRIER_LETTER, PLAYER);
        initializeShip(player2Board, boardSize, BATTLESHIP_LETTER, PLAYER);
        initializeShip(player2Board, boardSize, CRUISER_LETTER, PLAYER);
        initializeShip(player2Board, boardSize, DESTROYER_LETTER, PLAYER);
        initializeShip(player2Board, boardSize, DESTROYER_LETTER, PLAYER);

        std::cout << "You have filled all the needed spaces!" << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.getline(pressToContinueKey, MAX_SIZE);
        if (pressToContinueKey[0] != '\0') {
            clearConsole();
        }

        while (hitsPlayer1 != WIN && hitsPlayer2 != WIN) {

            std::cout << "Hello Player 1! This is the opponents board at which you are aiming!" << std::endl;
            std::cout << "If you manage to hit a ship its index would appear on that spot!" << std::endl;
            std::cout << "However if you aim at the water a ~ would appear on that spot!" << std::endl;

            printBoard(opponentPlayer1Board, boardSize);

            int rowIndex=0;
            int colIndex=0;
            char* rowIndexInput = new char[MAX_STRING_SIZE];
            char* colIndexInput = new char[MAX_STRING_SIZE];

            do
            {
                std::cout << "Type the index of the row where the space you want to hit is!" << std::endl;

                std::cin.getline(rowIndexInput,MAX_SIZE);
                const unsigned rowIndexInputLength = getStringLength(rowIndexInput);

                if (rowIndexInputLength != 1) {
                   rowIndex = -1;
                } 
                else {
                    rowIndex = convertCharToUnsigned(rowIndexInput) + 1;                
                }
               

                std::cout << "Type the index of the column where the space you want to hit is!" << std::endl;

                std::cin.getline(colIndexInput, MAX_SIZE);
                const unsigned colIndexInputLength = getStringLength(colIndexInput);

                if (colIndexInputLength != 1) {
                    colIndex = -1;
                }
                else {
                    colIndex = convertCharToUnsigned(colIndexInput) + 1;
                }

                if (checkValidShootingCoordinates(opponentPlayer1Board, boardSize, rowIndex, colIndex)) {


                    if (player2Board[rowIndex][colIndex] == EMPTY_SPACE) {
                        std::cout << "You missed! Now its your opponents turn!" << std::endl;
                        opponentPlayer1Board[rowIndex][colIndex] = HIT_MARKER;
                    }

                    else if (opponentPlayer1Board[rowIndex][colIndex] == HIT_MARKER) {
                        std::cout << "You have already shot a missile at this space! " << std::endl;
                        std::cout << "Please choose another space!" << std::endl;
                        rowIndex = -1;
                        colIndex = -1;
                        continue;
                    }

                    else {
                        std::cout << "You managed to hit a ship! Good job! However, now its your opponents turn!" << std::endl;
                        opponentPlayer1Board[rowIndex][colIndex] = player2Board[rowIndex][colIndex];
                        hitsPlayer1++;
                    }

                }

                else {
                std::cout<<"Invalid cordinates! Try again!" << std::endl;
                }

            } while (!checkValidShootingCoordinates(opponentPlayer1Board, boardSize, rowIndex, colIndex));


            std::cout << "Press s to save..." << std::endl;
            std::cout << "Press any other key to continue..." << std::endl;
            
            std::cin.getline(pressToContinueKey, MAX_SIZE);
            if (pressToContinueKey[0] == 's' || pressToContinueKey[0] == 'S')  RESTART_OPTION = saveAndContinue(pressToContinueKey[0]);
            if (RESTART_OPTION == 'r' || RESTART_OPTION == 'R') break;

            if (pressToContinueKey[0] != '\0') {
                clearConsole();
            }

            std::cout << "Hello Player 2! This is the opponents board at which you are aiming!" << std::endl;
            std::cout << "If you manage to hit a ship its index would appear on that spot!" << std::endl;
            std::cout << "However if you aim at the water a ~ would appear on that spot!" << std::endl;

            printBoard(opponentPlayer2Board, boardSize);

            do
            {
                std::cout << "Type the index of the row where the space you want to hit is!" << std::endl;

                std::cin.getline(rowIndexInput, MAX_SIZE);
                const unsigned rowIndexInputLength = getStringLength(rowIndexInput);

                if (rowIndexInputLength != 1) {
                    rowIndex = -1;
                }
                else {
                    rowIndex = convertCharToUnsigned(rowIndexInput) + 1;
                }


                std::cout << "Type the index of the column where the space you want to hit is!" << std::endl;

                std::cin.getline(colIndexInput, MAX_SIZE);
                const unsigned colIndexInputLength = getStringLength(colIndexInput);

                if (colIndexInputLength != 1) {
                    colIndex = -1;
                }
                else {
                    colIndex = convertCharToUnsigned(colIndexInput) + 1;
                }

                if (checkValidShootingCoordinates(opponentPlayer1Board, boardSize, rowIndex, colIndex)) {


                    if (player2Board[rowIndex][colIndex] == EMPTY_SPACE) {
                        std::cout << "You missed! Now its your opponents turn!" << std::endl;
                        opponentPlayer1Board[rowIndex][colIndex] = HIT_MARKER;
                    }

                    else if (opponentPlayer1Board[rowIndex][colIndex] == HIT_MARKER) {
                        std::cout << "You have already shot a missile at this space! " << std::endl;
                        std::cout << "Please choose another space!" << std::endl;
                        rowIndex = -1;
                        colIndex = -1;
                        continue;
                    }

                    else {
                        std::cout << "You managed to hit a ship! Good job! However, now its your opponents turn!" << std::endl;
                        opponentPlayer1Board[rowIndex][colIndex] = player2Board[rowIndex][colIndex];
                        hitsPlayer1++;
                    }

                }

                else {
                    std::cout << "Invalid cOordinates! Try again!" << std::endl;
                }

            } while (!checkValidShootingCoordinates(opponentPlayer1Board, boardSize, rowIndex, colIndex));



            std::cout << "Press s to save..." << std::endl;
            std::cout << "Press any other key to continue..." << std::endl;

            std::cin.getline(pressToContinueKey, MAX_SIZE);
            if (pressToContinueKey[0] == 's' || pressToContinueKey[0] == 'S')  RESTART_OPTION = saveAndContinue(pressToContinueKey[0]);
            if (RESTART_OPTION == 'r' || RESTART_OPTION == 'R') break;

            if (pressToContinueKey[0] != '\0') {
                clearConsole();
            }

            delete[] rowIndexInput;
            delete[]colIndexInput;
        }


        //final result
        if (hitsPlayer1 == WIN) {
            std::cout << "Congratulations Player1 you win!" << std::endl;
        }

        else   if (hitsPlayer2 == WIN) {
            std::cout << "Congratulations Player2 you win!" << std::endl;
        }

        else {

            // Clean up memory
            for (unsigned i = 0; i < boardSize; ++i) {
                delete[] player1Board[i];
                delete[] player2Board[i];
                delete[] opponentPlayer1Board[i];
                delete[] opponentPlayer2Board[i];
            }

            continue;
        }


        // Clean up memory
        for (unsigned i = 0; i < boardSize; ++i) {
            delete[] player1Board[i];
            delete[] player2Board[i];
            delete[] opponentPlayer1Board[i];
            delete[] opponentPlayer2Board[i];
        }

        delete[] player1Board;
        delete[] player2Board;
        delete[] opponentPlayer1Board;
        delete[] opponentPlayer2Board;
        delete[] pressToContinueKey;
        return;

    }
}

int main()
{

    while (true) {

        char* gameStyle = new char[MAX_STRING_SIZE];
        unsigned gameStyleInputLength;

        unsigned boardSize=0;
        char* boardSizeInput = new char[MAX_STRING_SIZE];

        printStartMenu();

        //Get game style
        do
        {
            std::cin >> gameStyle;


             gameStyleInputLength = getStringLength(gameStyle);

            if (gameStyleInputLength>1 ||  (gameStyle[0] != 'p' && gameStyle[0] != 'c' && gameStyle[0] != 'P' && gameStyle[0] != 'C') ) {
                std::cout << "Incorrect input!" << std::endl;
                std::cout << "Only valid commands are p and c! Try again!" << std::endl;

            }

        } while (gameStyleInputLength > 1 || (gameStyle[0] != 'p' && gameStyle[0] != 'c' && gameStyle[0] != 'P' && gameStyle[0] != 'C')) ;

        // Player versus computer
        if (gameStyle[0] == 'c' || gameStyle[0] == 'C') {

            std::cout << "Please insert the size of the board(From 5 to 10)" << std::endl; 
            do
            {
                std::cin >> boardSizeInput;
                boardSize = convertCharToUnsigned(boardSizeInput);

                if (boardSize < 5 || boardSize>10) {
                    std::cout << "Incorrect input!" << std::endl;
                    std::cout << "Board size must be between 5 and 10! Try again!" << std::endl;

                }

            } while (boardSize < 5 || boardSize>10);

            playPVCGame(boardSize);
        }

        // Player versus player
        else {

            //Get board size
            std::cout << "Please insert the size of the board(From 5 to 10)" << std::endl;
            do
            {
                std::cin >> boardSizeInput;
                boardSize = convertCharToUnsigned(boardSizeInput);

                if (boardSize < 5 || boardSize>10) {
                    std::cout << "Incorrect input!" << std::endl;
                    std::cout << "Board size must be between 5 and 10! Try again!" << std::endl;

                }

            } while (boardSize < 5 || boardSize>10);
            
            playPVPGame(boardSize);

        }

        // Game restart
        if (RESTART_OPTION == 'R' || RESTART_OPTION == 'r') {
            continue;
        }

        delete[] gameStyle;
        delete[] boardSizeInput;
    }


   
    return 0;
}
