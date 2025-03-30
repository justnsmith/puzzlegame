#include "Board.h"

Board::Board() {
  generateBoard();
  currentPosition = {0, 0};
}

void Board::generateBoard() {
  std::mt19937 mt{static_cast<std::mt19937::result_type>(
      std::chrono::steady_clock::now().time_since_epoch().count())};
  std::array<int, 15> generatePosition = {1, 2,  3,  4,  5,  6,  7, 8,
                                          9, 10, 11, 12, 13, 14, 15};
  std::uniform_int_distribution puzzleRange{0, 14};
  for (int i = generatePosition.size() - 1; i > 0; i--) {
    std::swap(generatePosition[static_cast<int>(puzzleRange(mt))],
              generatePosition[i]);
  }

  int k = 0;
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COLUMN; j++) {
      if (i == 0 && j == 0) {
        puzzleBoard[i][j] = -1;
      } else {
        puzzleBoard[i][j] = generatePosition[k];
        k++;
      }
    }
  }
}

void Board::printBoard() {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COLUMN; j++) {
      if (puzzleBoard[i][j] == -1) {
        std::cout << "    ";
      } else if (puzzleBoard[i][j] < 10) {
        std::cout << "   " << puzzleBoard[i][j];
      } else {
        std::cout << "  " << puzzleBoard[i][j];
      }
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

bool Board::checkIfSolved() {
  if (currentPosition.first != 3 || currentPosition.second != 3) return false;

  int current = 1;
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COLUMN; j++) {
      if (i == 3 && j == 3) {
        break;
      } else if (puzzleBoard[i][j] != current) {
        return false;
      } else {
        current++;
      }
    }
  }
  return true;
}

bool Board::moveUp() {
  if (currentPosition.first == 0) return false;

  std::swap(puzzleBoard[currentPosition.first][currentPosition.second],
            puzzleBoard[currentPosition.first - 1][currentPosition.second]);
  currentPosition.first--;
  return true;
}

bool Board::moveDown() {
  if (currentPosition.first == 3) return false;

  std::swap(puzzleBoard[currentPosition.first][currentPosition.second],
            puzzleBoard[currentPosition.first + 1][currentPosition.second]);
  currentPosition.first++;
  return true;
}

bool Board::moveLeft() {
  if (currentPosition.second == 0) return false;

  std::swap(puzzleBoard[currentPosition.first][currentPosition.second],
            puzzleBoard[currentPosition.first][currentPosition.second - 1]);
  currentPosition.second--;
  return true;
}

bool Board::moveRight() {
  if (currentPosition.second == 3) return false;

  std::swap(puzzleBoard[currentPosition.first][currentPosition.second],
            puzzleBoard[currentPosition.first][currentPosition.second + 1]);
  currentPosition.second++;
  return true;
}
