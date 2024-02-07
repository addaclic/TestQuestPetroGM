#ifndef FIGURE_CLASSSHADOW_H
#define FIGURE_CLASSSHADOW_H

#include "classFigure.h"

class Shadow : public Figure {
 public:
  Shadow(const std::string name, int x, int y) : Figure(name, x, y){};
};

#endif  // FIGURE_CLASSSHADOW_H