// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для
// виконання лаб. роботи №3.
// Він містинь функцію "main" з якої починається та закінчується виконання
// програми.
//

#include <fstream>
#include <iostream>
using namespace std;

void ShowTaskMenu() {
  cout << "Exersices" << endl;
  cout << "1. Task 1" << endl;
  cout << "2. Task 2" << endl;
  cout << "3. Task 3" << endl;
}

// Ваші файли загловки
//
#include "Lab3Example.h"
int main() {
  bool isSelected = false;
  while (!isSelected) {
    system("cls");
    ShowTaskMenu();
    int ch;
    cin >> ch;
    switch (ch) {
    case 1:
      exercise1();
      isSelected = true;
      break;
    case 2:
    exercise2();
      isSelected = true;
      break;
    case 3:
      isSelected = true;
      break;
    default:
      break;
    }
  }
}
