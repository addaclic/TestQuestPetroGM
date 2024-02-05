#include "TestQuest.h"

#include <fstream>
#include <iostream>
#include <string>

// void FieldInit(char Field[8][8]) {
//   for (int i = 0; i < 8; ++i) {
//     for (int j = 0; j < 8; ++j) {
//       if ((i + j) % 2)
//         Field[i][j] = 'O';
//       else
//         Field[i][j] = '#';
//     }
//   }
// }

// void FIeldPrint(char Field[8][8]) {
//   for (int i = 0; i < 8; ++i) {
//     for (int j = 0; j < 8; ++j) {
//       std::cout << Field[i][j] << " ";
//     }
//     std::cout << std::endl;
//   }
// }

int ReadFile() {
  int ErrorCode = 0;
  FILE* FileText;
  std::string ReadLine;
  if ((FileText = freopen("testquest.txt", "r", stdin)) == NULL)
    ErrorCode = 1;
  else {
    while (std::getline(std::cin, ReadLine)) {
      std::cout << ReadLine << std::endl;
    }
    fclose(FileText);
  }

  return ErrorCode;
}

int main() {
  ReadFile();

  return 0;
}