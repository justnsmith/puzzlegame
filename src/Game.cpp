#include "Game.h"

#include "Board.h"

void Game::startGame() {
  do {
    gameboard.printBoard();
    printInstructions();
    char input = getInput();
    if (input == 'w') {
      gameboard.moveUp();
    } else if (input == 'a') {
      gameboard.moveLeft();
    } else if (input == 's') {
      gameboard.moveDown();
    } else if (input == 'd') {
      gameboard.moveRight();
    } else if (input != 'q') {
      std::cout << "Invalid command. Try again.\n";
    } else {
      std::cout << "You have quit the game.\n";
      return;
    }
    std::cout << '\n';
  } while (!gameboard.checkIfSolved());
  std::cout << "You have won the game!\n";
}

char Game::getInput() {
  char input{};
  std::cin >> input;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return input;
}

void Game::printInstructions() {
  std::cout << "w - slide tile up\n";
  std::cout << "a - slide tile left\n";
  std::cout << "s - slide tile down\n";
  std::cout << "d - slide tile right\n";
  std::cout << "q - quit game\n";
}
