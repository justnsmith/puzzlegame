#ifndef BOARD_H
#define BOARD_H

#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <random>

const int ROW = 4;
const int COLUMN = 4;

class Board {
 private:
  std::array<std::array<int, ROW>, COLUMN> puzzleBoard{};
  std::pair<int, int> currentPosition{};

  void generateBoard();

 public:
  Board();
  bool checkIfSolved();
  void printBoard();

  bool moveUp();
  bool moveDown();
  bool moveLeft();
  bool moveRight();
};

#endif
