#ifndef FIGURE_CLASSKING_H
#define FIGURE_CLASSKING_H

#include "classFigure.h"

class King : public Figure {
 public:
  King(const std::string name, int x, int y) : Figure(name, x, y){};
  void Attack(const char other[8][8]) const {
    std::cout << name() << "(" << x() << ", " << y() << "): ";
    for (int i = x() - 1; i <= x() + 1; ++i) {
      for (int j = y() - 1; j <= y() + 1; ++j) {
        if (i < 0 || i > 7 || j < 0 || j > 7)
          continue;
        else if (i == x() && j == y())
          continue;
        else if (other[i][j] != 'O' && other[i][j] != '#')
          std::cout << other[i][j] << " ";
      }
    }
    std::cout << std::endl;
  };
};

#endif  // FIGURE_CLASSKING_H