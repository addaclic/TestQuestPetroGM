#ifndef FIGURE_CLASSROOK_H
#define FIGURE_CLASSROOK_H

#include "classFigure.h"

class Rook : public Figure {
 public:
  Rook(const std::string name, int x, int y) : Figure(name, x, y){};
  void Attack(const char other[8][8]) const {
    std::cout << name() << "(" << x() << ", " << y() << "): ";
    Attackstraight(other);
    std::cout << std::endl;
  };
};

#endif  // FIGURE_CLASSROOK_H