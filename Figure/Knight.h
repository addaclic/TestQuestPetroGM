#ifndef FIGURE_CLASSKNIGHT_H
#define FIGURE_CLASSKNIGHT_H

#include "Figure.h"

class Knight : public Figure {
 public:
  Knight(const std::string name, int x, int y) : Figure(name, x, y){};
  void Attack(const char other[8][8]) const {
    std::cout << name() << "(" << x() << ", " << y() << "): ";
    for (int i = -2; i <= 2; i++) {
      for (int j = -2; j <= 2; j++) {
        if (abs(i) + abs(j) == 3) {
          int newX = x() + i;
          int newY = y() + j;
          if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            if (other[newX][newY] != 'O' && other[newX][newY] != '#')
              std::cout << other[newX][newY] << " ";
          }
        }
      }
    }
    std::cout << std::endl;
  };
};

#endif  // FIGURE_CLASSKNIGHT_H