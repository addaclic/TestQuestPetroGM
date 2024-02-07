#ifndef TESTQUEST_H_
#define TESTQUEST_H_

#include <iostream>
#include <string>

#include "Figure/classBishop.h"
#include "Figure/classKing.h"
#include "Figure/classKnight.h"
#include "Figure/classQueen.h"
#include "Figure/classRook.h"

// class Shadow : public Figure {
//  public:
//  Shadow(const std::string name, int x, int y) : Figure(name, x, y){};

// };

class ChessField {
 public:
  ChessField() {
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        if ((i + j) % 2)
          field_[i][j] = 'O';
        else
          field_[i][j] = '#';
      }
    }
  };

  void Print() {
    for (int j = 0; j < 8; ++j) {
      for (int i = 0; i < 8; ++i) {
        std::cout << field_[i][j] << " ";
      }
      std::cout << std::endl;
    }
  };

  void PlaceFigure() {
    int x, y;
    std::string name;
    for (int i = 0; !std::cin.eof(); ++i) {
      if (i == 10)
        throw std::invalid_argument("Too many figures");
      else {
        std::cin >> name;
        std::cin >> x;
        std::cin >> y;
        if ((x > 7 || y > 7) || (x < 0 || y < 0)) {
          throw std::out_of_range("Out of range");
        } else {
          if (field_[x][y] != 'O' && field_[x][y] != '#') {
            throw std::invalid_argument("Duplicate coordinates");
          } else {
            if (name == "knight")
              field_[x][y] = 'G';
            else
              field_[x][y] = name.at(0) - 32;
          }
        }
      }
    }
  };

  void CheckAttack() {
    for (int y = 0; y < 8; ++y) {
      for (int x = 0; x < 8; ++x) {
        if (field_[x][y] == 'R') {
          Rook rook("Rook", x, y);
          rook.Attack(field_);
        } else if (field_[x][y] == 'B') {
          Bishop bishop("Bishop", x, y);
          bishop.Attack(field_);
        } else if (field_[x][y] == 'K') {
          King king("King", x, y);
          king.Attack(field_);
        } else if (field_[x][y] == 'G') {
          Knight knight("Knight", x, y);
          knight.Attack(field_);
        } else if (field_[x][y] == 'Q') {
          Queen queen("Queen", x, y);
          queen.Attack(field_);
        }
      }
    }
  };

  const char (*GetField())[8] { return field_; };

 private:
  char field_[8][8];
};

#endif  // TESTQUEST_H_
