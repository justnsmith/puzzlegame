#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game {
 private:
  Board gameboard{};
  char getInput();
  void printInstructions();

 public:
  void startGame();
};

#endif
