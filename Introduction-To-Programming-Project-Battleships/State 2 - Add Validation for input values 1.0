// IntroductionToProgrammingProjectBattleShips.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <windows.h>

const int BUFFER_SIZE = 101;

unsigned convertCharToInt(char c) {

    return c - '0';
}

bool checkValidCoordinates(char** playerBoard, unsigned boardSize, unsigned indexStartingRow, unsigned indexStartingColumn, char aircraft,char direction) {
    

    //Check if indexes are in the boundaries
    if (indexStartingRow<1 && indexStartingRow>boardSize) {
        return false;
    }

    if (indexStartingColumn<1 && indexStartingColumn>boardSize) {
        return false;
    }

    //Check direction of positioning
    if (direction == 'h' || direction == 'H') {
    
        //Check all aircrafts
        if (aircraft == 'A') {

            //Check if aircraft would fit in the boundaries
            if (indexStartingColumn + 5 > boardSize) {
                return false;
            }

            //Check if there is free space for the ship
            for (unsigned i = indexStartingColumn; i < indexStartingColumn + 5; i++)
            {
                if (playerBoard[indexStartingRow][i] != '*') {
                    return false;
                }
            }
        }

        if (aircraft == 'B') {

            //Check if aircraft would fit in the boundaries
            if (indexStartingColumn + 4 > boardSize) {
                return false;
            }

            //Check if there is free space for the ship
            for (unsigned i = indexStartingColumn; i < indexStartingColumn + 4; i++)
            {
                if (playerBoard[indexStartingRow][i] != '*') {
                    return false;
                }
            }
        }

        if (aircraft == 'C') {

            //Check if aircraft would fit in the boundaries
            if (indexStartingColumn + 3 > boardSize) {
                return false;
            }

            //Check if there is free space for the ship
            for (unsigned i = indexStartingColumn; i < indexStartingColumn + 3; i++)
            {
                if (playerBoard[indexStartingRow][i] != '*') {
                    return false;
                }
            }
        }

        if (aircraft == 'D') {

            //Check if aircraft would fit in the boundaries
            if (indexStartingColumn + 5 > boardSize) {
                return false;
            }

            //Check if there is free space for the ship
            for (unsigned i = indexStartingColumn; i < indexStartingColumn + 2; i++)
            {
                if (playerBoard[indexStartingRow][i] != '*') {
                    return false;
                }
            }
        }
    }

    else {
    
        if (aircraft == 'A') {

            //Check if aircraft would fit in the boundaries
            if (indexStartingRow + 5 > boardSize) {
                return false;
            }

            //Check if there is free space for the ship
            for (unsigned i = indexStartingRow; i < indexStartingRow + 5; i++)
            {
                if (playerBoard[i][indexStartingColumn] != '*') {
                    return false;
                }
            }
        }
    
        if (aircraft == 'B') {

            //Check if aircraft would fit in the boundaries
            if (indexStartingRow + 4 > boardSize) {
                return false;
            }

            //Check if there is free space for the ship
            for (unsigned i = indexStartingRow; i < indexStartingRow + 4; i++)
            {
                if (playerBoard[i][indexStartingColumn] != '*') {
                    return false;
                }
            }
        }

        if (aircraft == 'C') {

            //Check if aircraft would fit in the boundaries
            if (indexStartingRow + 3 > boardSize) {
                return false;
            }

            //Check if there is free space for the ship
            for (unsigned i = indexStartingRow; i < indexStartingRow + 3; i++)
            {
                if (playerBoard[i][indexStartingColumn] != '*') {
                    return false;
                }
            }
        }

        if (aircraft == 'D') {

            //Check if aircraft would fit in the boundaries
            if (indexStartingRow + 2 > boardSize) {
                return false;
            }

            //Check if there is free space for the ship
            for (unsigned i = indexStartingRow; i < indexStartingRow + 2; i++)
            {
                if (playerBoard[i][indexStartingColumn] != '*') {
                    return false;
                }
            }
        }
    }

    return true;
}

void printStartMenu() {

    std::cout << "Welcome to Battleships!" << std::endl;
    std::cout << std::endl;
    std::cout << "Choose game style" << std::endl;
    std::cout << std::endl;
    std::cout << "Press 0 for PVP" << std::endl;
    std::cout << "Press 1 for PVE" << std::endl;

}

void loadMatrixPlayer(char** playerBoard, unsigned boardSize) {

    playerBoard[0] = new char[boardSize];
    playerBoard[0][0] = ' ';

    for (unsigned i = 1; i < boardSize; i++)
    {
        playerBoard[0][i] = i-1 + '0';

    }

    for (unsigned i = 1; i <= boardSize; i++)
    {
        playerBoard[i] = new char[boardSize];

        playerBoard[i][0] = i-1 + '0';

        
        for (unsigned j = 1; j < boardSize; j++)
        {
            playerBoard[i][j] = '*';
        }
    }

}

void printBoard(char** playerBoard, unsigned boardSize) {

    for (unsigned i = 0; i < boardSize; i++)
    {
        for (unsigned j = 0; j < boardSize; j++)
        {
            std::cout << playerBoard[i][j] << " ";;
        }
        std::cout << std::endl;
    }

}

void initialiseAircraftCarrier(char** playerBoard, unsigned boardSize) {

    std::cout << "Now its time to place your Aircraft carrier!(It's size is 5 and is displayed with the letter A!)" << std::endl;
    std::cout << "Please select whether you want to place your ship vertically or horizontally! Type V for vertical and H for horizontal!" << std::endl;

    char direction;


    do
    {
        std::cin >> direction;

        if (direction != 'v' && direction != 'h' && direction != 'V' && direction != 'H') {
            std::cout << "Incorrect input!" << std::endl;
            std::cout << "Type V or v for vertical and H or h for horizontal! Try again!" << std::endl;
        }

    } while (direction != 'v' && direction != 'h' && direction != 'V' && direction != 'H');

    if (direction == 'h' || direction == 'H') {

        unsigned row;
        unsigned column;
        char rowChar;
        char columnChar;
        do
        {
            std::cout << "Type the index of the row you want to put your ship at!" << std::endl;


            std::cin >> row;
            
            

            row++;


            std::cout << "Type the index of the column from which the space the ship will be placed!" << std::endl;

            std::cin >> column;
           
            column++;

            if (!checkValidCoordinates(playerBoard, boardSize, row, column, 'A',direction)) {
                std::cout << "Incorrect input!" << std::endl;
                std::cout << "You have typed invalid coordinates! Try again!" << std::endl;
                return;
            }

        } while (!checkValidCoordinates(playerBoard, boardSize, row, column, 'A', direction));

        for (unsigned i = column; i < column + 5; i++)
        {
            playerBoard[row][i] = 'A';
        }

        printBoard(playerBoard, boardSize);

    }

    else {

        char rowChar;
        char  columnChar;
        unsigned row;
        unsigned column;

        do
        {
            std::cout << "Type the index of the column you want to put your ship at!" << std::endl;

            std::cin >> columnChar;
            column = convertCharToInt(columnChar);
            column++;


            std::cout << "Type the index of the row from which the space the ship will be placed!" << std::endl;

            std::cin >> rowChar;
            row = convertCharToInt(rowChar);
            row++;

            if (!checkValidCoordinates(playerBoard, boardSize, row, column, 'A', direction)) {
                std::cout << "Incorrect input!" << std::endl;
                std::cout << "You have typed invalid coordinates! Try again!" << std::endl;

            }

        } while (!checkValidCoordinates(playerBoard, boardSize, row, column, 'A', direction));

        for (unsigned i = row; i < row + 5; i++)
        {
            playerBoard[i][column] = 'A';
        }

        printBoard(playerBoard, boardSize);
    }

}

void initialiseBattleShip(char** playerBoard, unsigned boardSize) {

    std::cout << "Now its time to place your Battleship!(It's size is 4 and is displayed with the letter B!)" << std::endl;
    std::cout << "Please select whether you want to place your ship vertically or horizontally! Type V for vertical and H for horizontal!" << std::endl;

    char direction;


    do
    {
        std::cin >> direction;

        if (direction != 'v' && direction != 'h' && direction != 'V' && direction != 'H') {
            std::cout << "Incorrect input!" << std::endl;
            std::cout << "Type V or v for vertical and H or h for horizontal! Try again!" << std::endl;
        }

    } while (direction != 'v' && direction != 'h' && direction != 'V' && direction != 'H');

    if (direction == 'h' || direction == 'H') {

        unsigned row;
        unsigned column;
        char rowChar;
        char columnChar;
        do
        {
            std::cout << "Type the index of the row you want to put your ship at!" << std::endl;


            std::cin >> rowChar;

            row = convertCharToInt(rowChar);

            row++;


            std::cout << "Type the index of the column from which the space the ship will be placed!" << std::endl;

            std::cin >> columnChar;
            column = convertCharToInt(columnChar);
            column++;

            if (!checkValidCoordinates(playerBoard, boardSize, row, column, 'B', direction)) {
                std::cout << "Incorrect input!" << std::endl;
                std::cout << "You have typed invalid coordinates! Try again!" << std::endl;

            }

        } while (!checkValidCoordinates(playerBoard, boardSize, row, column, 'B', direction));

        for (unsigned i = column; i < column + 4; i++)
        {
            playerBoard[row][i] = 'B';
        }

        printBoard(playerBoard, boardSize);

    }

    else {

        char rowChar;
        char  columnChar;
        unsigned row;
        unsigned column;

        do
        {
            std::cout << "Type the index of the column you want to put your ship at!" << std::endl;

            std::cin >> columnChar;
            column = convertCharToInt(columnChar);
            column++;


            std::cout << "Type the index of the row from which the space the ship will be placed!" << std::endl;

            std::cin >> rowChar;
            row = convertCharToInt(rowChar);
            row++;

            if (!checkValidCoordinates(playerBoard, boardSize, row, column, 'B', direction)) {
                std::cout << "Incorrect input!" << std::endl;
                std::cout << "You have typed invalid coordinates! Try again!" << std::endl;

            }

        } while (!checkValidCoordinates(playerBoard, boardSize, row, column, 'B', direction));

        for (unsigned i = row; i < row + 4; i++)
        {
            playerBoard[i][column] = 'B';
        }

        printBoard(playerBoard, boardSize);
    }
}

void initialiseCruiser(char** playerBoard, unsigned boardSize) {

    std::cout << "Now its time to place your Cruiser!(It's size is 3 and is displayed with the letter C!)" << std::endl;
    std::cout << "Please select whether you want to place your ship vertically or horizontally! Type V for vertical and H for horizontal!" << std::endl;

    char direction;


    do
    {
        std::cin >> direction;

        if (direction != 'v' && direction != 'h' && direction != 'V' && direction != 'H') {
            std::cout << "Incorrect input!" << std::endl;
            std::cout << "Type V or v for vertical and H or h for horizontal! Try again!" << std::endl;
        }

    } while (direction != 'v' && direction != 'h' && direction != 'V' && direction != 'H');

    if (direction == 'h' || direction == 'H') {

        unsigned row;
        unsigned column;
        char rowChar;
        char columnChar;
        do
        {
            std::cout << "Type the index of the row you want to put your ship at!" << std::endl;


            std::cin >> rowChar;

            row = convertCharToInt(rowChar);

            row++;


            std::cout << "Type the index of the column from which the space the ship will be placed!" << std::endl;

            std::cin >> columnChar;
            column = convertCharToInt(columnChar);
            column++;

            if (!checkValidCoordinates(playerBoard, boardSize, row, column, 'C', direction)) {
                std::cout << "Incorrect input!" << std::endl;
                std::cout << "You have typed invalid coordinates! Try again!" << std::endl;

            }

        } while (!checkValidCoordinates(playerBoard, boardSize, row, column, 'C', direction));

        for (unsigned i = column; i < column + 3; i++)
        {
            playerBoard[row][i] = 'C';
        }

        printBoard(playerBoard, boardSize);

    }

    else {

        char rowChar;
        char  columnChar;
        unsigned row;
        unsigned column;

        do
        {
            std::cout << "Type the index of the column you want to put your ship at!" << std::endl;

            std::cin >> columnChar;
            column = convertCharToInt(columnChar);
            column++;


            std::cout << "Type the index of the row from which the space the ship will be placed!" << std::endl;

            std::cin >> rowChar;
            row = convertCharToInt(rowChar);
            row++;

            if (!checkValidCoordinates(playerBoard, boardSize, row, column, 'C', direction)) {
                std::cout << "Incorrect input!" << std::endl;
                std::cout << "You have typed invalid coordinates! Try again!" << std::endl;

            }

        } while (!checkValidCoordinates(playerBoard, boardSize, row, column, 'C', direction));

        for (unsigned i = row; i < row + 3; i++)
        {
            playerBoard[i][column] = 'C';
        }

        printBoard(playerBoard, boardSize);
    }
}

void initialiseDestroyer(char** playerBoard, unsigned boardSize) {

    std::cout << "Now its time to place your Destroyer!(It's size is 2 and is displayed with the letter D!)" << std::endl;
    std::cout << "Please select whether you want to place your ship vertically or horizontally! Type V for vertical and H for horizontal!" << std::endl;

    char direction;


    do
    {
        std::cin >> direction;

        if (direction != 'v' && direction != 'h' && direction != 'V' && direction != 'H') {
            std::cout << "Incorrect input!" << std::endl;
            std::cout << "Type V or v for vertical and H or h for horizontal! Try again!" << std::endl;
        }

    } while (direction != 'v' && direction != 'h' && direction != 'V' && direction != 'H');

    if (direction == 'h' || direction == 'H') {

        unsigned row;
        unsigned column;
        char rowChar;
        char columnChar;
        do
        {
            std::cout << "Type the index of the row you want to put your ship at!" << std::endl;


            std::cin >> rowChar;

            row = convertCharToInt(rowChar);

            row++;


            std::cout << "Type the index of the column from which the space the ship will be placed!" << std::endl;

            std::cin >> column;
            column = convertCharToInt(columnChar);
            column++;

            if (!checkValidCoordinates(playerBoard, boardSize, row, column, 'D', direction)) {
                std::cout << "Incorrect input!" << std::endl;
                std::cout << "You have typed invalid coordinates! Try again!" << std::endl;
                return;
            }

        } while (!checkValidCoordinates(playerBoard, boardSize, row, column, 'D', direction));

        for (unsigned i = column; i < column + 2; i++)
        {
            playerBoard[row][i] = 'D';
        }

        printBoard(playerBoard, boardSize);

    }

    else {

        char rowChar;
        char  columnChar;
        unsigned row;
        unsigned column;

        do
        {
            std::cout << "Type the index of the column you want to put your ship at!" << std::endl;

            std::cin >> columnChar;
            column = convertCharToInt(columnChar);
            column++;


            std::cout << "Type the index of the row from which the space the ship will be placed!" << std::endl;

            std::cin >> rowChar;
            row = convertCharToInt(rowChar);
            row++;


            if (!checkValidCoordinates(playerBoard, boardSize, row, column, 'D', direction)) {
                std::cout << "Incorrect input!" << std::endl;
                std::cout << "You have typed invalid coordinates! Try again!" << std::endl;

            }

        } while (!checkValidCoordinates(playerBoard, boardSize, row, column, 'D', direction));

        for (unsigned i = row; i < row + 2; i++)
        {
            playerBoard[i][column] = 'D';
        }

        printBoard(playerBoard, boardSize);
    }
}

int main()
{
    char  gameStyle;
    unsigned boardSize;
   

    printStartMenu();

    //Get game style
    do
    {
        std::cin >> gameStyle;

        if (gameStyle != '0' && gameStyle != '1') {
            std::cout << "Incorrect input!" << std::endl;
            std::cout << "Only valid commands are 0 and 1! Try again!" << std::endl;
            continue;
        }

    } while (gameStyle != '0' && gameStyle != '1');


    if (gameStyle=='1') {
    
        std::cout<< "You have chosen PVE game!" << std::endl;
    }

    else {
        std::cout << "You have chosen PVP game!" << std::endl;
    }

    //Get board size
    std::cout << "Please insert the size of the board(From 5 to 10)" << std::endl;
    do
    {
        std::cin >> boardSize;

        if (boardSize < 5 || boardSize>10) {
            std::cout << "Incorrect input!"<<std::endl;
            std::cout << "Board size must be between 5 and 10! Try again!" << std::endl;
            return;
        }
        
    } while (boardSize < 5 || boardSize>10);
  
    //Increase the board size by 1 so that in the matrix it is clearly visualized which column or row you are selecting
    boardSize++;
    char** pointerToPlayer1Board = new char* [boardSize];
    char** pointerToPlayer2Board = new char* [boardSize];

    //Load up the boards with custom elements
    loadMatrixPlayer(pointerToPlayer1Board,boardSize);
    loadMatrixPlayer(pointerToPlayer2Board, boardSize);

    printBoard(pointerToPlayer1Board, boardSize);

    //initialise boats
    std::cout << "Now its time to fill in your battle ships!" << std::endl;
    
    initialiseAircraftCarrier(pointerToPlayer1Board, boardSize);

    initialiseBattleShip(pointerToPlayer1Board, boardSize);

    initialiseCruiser(pointerToPlayer1Board, boardSize);

    initialiseDestroyer(pointerToPlayer1Board, boardSize);

    initialiseDestroyer(pointerToPlayer1Board, boardSize);
   
    return 0; 
}

