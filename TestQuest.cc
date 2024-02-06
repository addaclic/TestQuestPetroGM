#include "TestQuest.h"

int main() {
  ChessField Field;
  Field.PlaceFigure();
  Field.Print();
  Field.CheckAttack();
  return 0;
}