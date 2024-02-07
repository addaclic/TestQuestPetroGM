#ifndef FIGURE_CLASSFIGURE_H
#define FIGURE_CLASSFIGURE_H

#include <iostream>
#include <string>

class Figure {
 public:
  Figure(const std::string name, int x, int y) : name_(name), x_(x), y_(y){};

  std::string name() const { return name_; };
  int x() const { return x_; };
  int y() const { return y_; };

 protected:
  void Attackstraight(const char other[8][8]) const {
    char figure = 0;
    for (int i = 0; i < 8; ++i) {
      if (other[x()][i] != 'O' && other[x()][i] != '#' && i != y())
        figure = other[x()][i];
      if (figure && i == y()) {
        std::cout << figure << " ";
        figure = 0;
      } else if (i > y() && figure) {
        std::cout << figure << " ";
        figure = 0;
        break;
      }
    }
    for (int i = 0; i < 8; ++i) {
      if (other[i][y()] != 'O' && other[i][y()] != '#' && i != x())
        figure = other[i][y()];
      if (figure && i == x()) {
        std::cout << figure << " ";
        figure = 0;
      } else if (i > x() && figure) {
        std::cout << figure;
        break;
      }
    }
  };

  void AttackDiagonal(const char other[8][8]) const {
    int i = x(), j = y();
    if (x() < y()) {
      i -= x();
      j -= x();
    } else {
      i -= y();
      j -= y();
    }
    char figure = 0;
    for (; i < 8 && j < 8; ++i, ++j) {
      if (other[i][j] != 'O' && other[i][j] != '#' && i != x() && j != y())
        figure = other[i][j];
      if (figure && i == x() && j == y()) {
        std::cout << figure << " ";
        figure = 0;
      } else if (i > x() && j > y() && figure) {
        std::cout << figure << " ";
        figure = 0;
        break;
      }
    }
    i = x(), j = y();
    while (i != 7 && j != 0) {
      ++i, --j;
    }
    while (i != -1 && j != 8) {
      if (other[i][j] != 'O' && other[i][j] != '#' && i != x() && j != y())
        figure = other[i][j];
      if (figure && i == x() && j == y()) {
        std::cout << figure << " ";
        figure = 0;
      } else if (i < x() && figure) {
        std::cout << figure << " ";
        break;
      }
      --i, ++j;
    }
  };

 private:
  const std::string name_;
  int x_;
  int y_;
};

#endif  // FIGURE_CLASSFIGURE_H