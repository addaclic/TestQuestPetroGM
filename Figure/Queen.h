#ifndef FIGURE_CLASSQUEEN_H
#define FIGURE_CLASSQUEEN_H

#include "Figure.h"

class Queen : public Figure {
 public:
  Queen(const std::string name, int x, int y) : Figure(name, x, y){};
  void Attack(const char other[8][8]) const {
    std::cout << name() << "(" << x() << ", " << y() << "): ";
    Attackstraight(other);
    AttackDiagonal(other);
    std::cout << std::endl;
  };
};

#endif  // FIGURE_CLASSQUEEN_H