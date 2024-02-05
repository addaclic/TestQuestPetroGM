#ifndef TESTQUEST_H_
#define TESTQUEST_H_

#include <string>

class Figure {
 public:
  Figure(std::string name, int x, int y) : name_(name), x_(x), y_(y) {}

  std::string name() const { return name_; }
  int x() const { return x_; }
  int y() const { return y_; }

 private:
  std::string name_;
  int x_;
  int y_;
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
