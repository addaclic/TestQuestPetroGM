#ifndef TESTQUEST_H_
#define TESTQUEST_H_

#include <iostream>
#include <string>

class Figure {
 public:
  Figure(const std::string name, int x, int y) : name_(name), x_(x), y_(y){};

  std::string name() const { return name_; };
  int x() const { return x_; };
  int y() const { return y_; };

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
      j -= y();
      i -= y();
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
    while (i < 8 && j > -1) {
      ++i, --j;
    }
    for (; i > -1 && j < 8; --i, ++j) {
      if (other[i][j] != 'O' && other[i][j] != '#' && i != x() && j != y())
        figure = other[i][j];
      if (figure && i == x() && j == y()) {
        std::cout << figure << " ";
        figure = 0;
      } else if (i < x() && figure) {
        std::cout << figure << " ";
        break;
      }
    }
  };

 private:
  const std::string name_;
  int x_;
  int y_;
};

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

class Rook : public Figure {
 public:
  Rook(const std::string name, int x, int y) : Figure(name, x, y){};
  void Attack(const char other[8][8]) const {
    std::cout << name() << "(" << x() << ", " << y() << "): ";
    Attackstraight(other);
    std::cout << std::endl;
  };
};

class Bishop : public Figure {
 public:
  Bishop(const std::string name, int x, int y) : Figure(name, x, y){};
  void Attack(const char other[8][8]) const {
    std::cout << name() << "(" << x() << ", " << y() << "): ";
    AttackDiagonal(other);
    std::cout << std::endl;
  };
};

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

// class Shadow : public Figure {
//  public:
//   Shadow(int x, int y) : x_(x), y_(y) {}
//   // virtual bool figureAttack(const Figure& other) const { return false; };
//   virtual int x() const { return x_; };
//   virtual int y() const { return y_; };

//  private:
//   const std::string name_ = "Shadow";
//   int x_ = -1;
//   int y_ = -1;
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

/*
Чтение файла:
Проверка координат фигуры
Проверка на совпадение координат фигуры
Задать список set координат

Наследование Queen от Rook и Bishop
Наследование King от Queen с ограничением на расстояние
Наследование Rook, Bishop и Knight от Figure
Наследование Shadow от Queen
*/
