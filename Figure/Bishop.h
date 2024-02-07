#ifndef FIGURE_CLASSBISHOP_H
#define FIGURE_CLASSBISHOP_H

#include "Figure.h"

class Bishop : public Figure {
 public:
  Bishop(const std::string name, int x, int y) : Figure(name, x, y){};
  void Attack(const char other[8][8]) const {
    std::cout << name() << "(" << x() << ", " << y() << "): ";
    AttackDiagonal(other);
    std::cout << std::endl;
  };
};

#endif  // FIGURE_CLASSBISHOP_H