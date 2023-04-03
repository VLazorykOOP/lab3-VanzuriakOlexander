#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
#include <fstream>

/*	Створити клас типу - дата з полями: день (1-31), місяць (1-12), рік
(ціле число). У класі визначити
        - 	конструктори ( не менше двох);
        - 	функції-члени встановлення дня, місяця та року, функції
встановлення полів класу повинні перевіряти коректність параметрів, що
задаються;
        - 	функції-члени одержання дня, місяця та року;
        - 	дві функції-члени друку за шаблоном: “5 січня 2019 року” і
“05.01.2019”. Написати програму тестування всіх можливостей цього класу.
*/

class Date {
private:
  int day;
  int month;
  int year;

public:
  // Конструктори
  Date() {
    day = 5;
    month = 1;
    year = 2019;
  }

  // Функції-члени встановлення дня, місяця та року
  void setDate(int d, int m, int y) {
    if (isValidDate(d, month, year)) {
      day = d;
      month = m;
      year = y;
    } else {
      cout << "Invalid date" << endl;
    }
  }

  void setDay(int d) {
    if (isValidDate(d, month, year)) {
      day = d;
    } else {
      cout << "Invalid day." << endl;
    }
  }

  void setMonth(int m) {
    if (isValidDate(day, m, year)) {
      month = m;
    } else {
      cout << "Invalid month." << endl;
    }
  }

  void setYear(int y) {
    if (isValidDate(day, month, y)) {
      year = y;
    } else {
      cout << "Invalid year." << endl;
    }
  }

  int getDay() { return day; }

  int getMonth() { return month; }

  int getYear() { return year; }

  // Функції-члени друку
  void print1() {
    string monthNames[] = {"January",   "February", "March",    "April",
                           "May",       "June",     "July",     "August",
                           "September", "October",  "November", "December"};
    cout << day << " " << monthNames[month - 1] << " " << year << " year"
         << endl;
  }

  void print2() {
    cout << setfill('0') << setw(2) << day << "." << setfill('0') << setw(2)
         << month << "." << year << endl;
  }

private:
  // Функція для перевірки коректності дати
  bool isValidDate(int d, int m, int y) {
    if (y < 0) {
      return false;
    }
    if (m < 1 || m > 12) {
      return false;
    }
    if (d > 31 || d < 0) {
      return false;
    }
    return true;
  }
};

void ShowExersice1Menu() {
  cout << "1. Enter from console" << endl;
  cout << "2. Read from txt" << endl;
  cout << "3. Default date with name of month" << endl;
  cout << "4. Default date with numbers" << endl;
}

void exercise1() {
  bool isSelected = false;
  Date d;
  ifstream fin("Date.txt");
  int day, month, year;
  while (!isSelected) {
    system("cls");
    ShowExersice1Menu();
    int ch;
    cin >> ch;
    switch (ch) {
    case 1:
      cout << "Enter date, month, year:";
      cin >> day >> month >> year;
      d.setDate(day, month, year);
      d.print1();
      isSelected = true;
      break;
    case 2:
      fin >> day;
      fin >> month;
      fin >> year;
      d.setDate(day, month, year);
      d.print1();
      isSelected = true;
      break;
    case 3:
      d.print1();
      isSelected = true;
      break;
    case 4:
      d.print2();
      isSelected = true;
      break;
    default:
      break;
    }
  }
  fin.close();
};

enum STATE { OK, BAD_INIT, BAD_DIV };

/*Задача 2 Створити тип даних - клас вектор, який має вказівник на int, число елементів
і змінну стану. У класі визначити

- конструктор без параметрів( виділяє місце для одного елемента та інінціалізує
його в нуль);
- конструктор з одним параметром - розмір вектора( виділяє місце та інінціалізує
масив значенням нуль);
- конструктор із двома параметрами - розмір вектора та значення
ініціалізації(виділяє місце (значення перший аргумент) та інінціалізує
значенням другого аргументу).
- конструктор копій та операцію присвоєння; // !!!
- деструктор звільняє пам'ять.
- визначити функцію, яка присвоює елементу масиву деяке значення (параметр за
замовчуванням);
- функцію яка одержує деякий елемент масиву;
- визначити функції друку, додавання, віднімання, які здійснюють ці
арифметичні операції з даними цього класу, множення на ціле типу short;
- визначити функції порівняння: більше, менше або рівно, які повертають true
або false.

У змінну стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі масиву.
Передбачити можливість підрахунку числа об'єктів даного типу. Написати програму тестування
всіх можливостей цього класу.
*/

class Vector {
  int *point;
  int length;
  int state = OK;

public:
  Vector() {
    length = 1;
    point = new int(length);
    point[0] = 0;
  }
  Vector(int len) {
    length = len;
    point = new int(length);
    for (int i = 0; i < length; i++) {
      point[i] = 0;
    }
  }

  Vector(int len, int value) {
    length = len;
    point = new int(length);
    for (int i = 0; i < length; i++) {
      point[i] = value;
    }
  }

  Vector(Vector &v) {
    length = v.length;
    if (v.point == nullptr) {
      state = BAD_INIT;
    }
    point = new int(v.length);
    for (int i = 0; i < v.length; i++) {
      point[i] = v.point[i];
    };
    state = v.state;
  }

  ~Vector() {
        delete[] point;
    }

  void setValue(int index, int value = 0) {
    if (index >= length ) {
      state = BAD_INIT;
      cout << "Out of range" << endl;
    } else {
      point[index] = value;
    }
  }

  int returnValue(int index) {
    if (index >= length ) {
      state = BAD_INIT;
      cout << "Out of range" << endl;
    } else {
      return point[index];
    }
  }

  void print() {
    for (int i = 0; i < length; i++) {
      cout << point[i] << " ";
    }
    cout << endl;
  };

  void sum(Vector &v) {
    for (int i = 0; i < length; i++) {
      point[i] += v.point[i];
    }
  }

  void sub(Vector &v) {
    for (int i = 0; i < length; i++) {
      point[i] -= v.point[i];
    }
  }

  void mult(short value) {
    for (int i = 0; i < length; i++) {
      point[i] *= value;
    }
  }

  bool equivalent(Vector &v1, Vector &v2) {
    bool result = true;
    for (int i = 0; i < v1.length; i++) {
      if(v1.point[i] != v2.point[i]) {
        result = false;
        break;
      }
    }

    return result;
  }

  bool less(Vector &v1, Vector &v2) {
    bool result = true;
    for (int i = 0; i < v1.length; i++) {
      if(v1.point[i] > v2.point[i]) {
        result = false;
        break;
      }
    }

    return result;
  }

  bool more(Vector &v1, Vector &v2) {
    bool result = true;
    for (int i = 0; i < v1.length; i++) {
      if(v1.point[i] < v2.point[i]) {
        result = false;
        break;
      }
    }

    return result;
  }
};


void exercise2() {
  Vector vector1(4, 2);
  Vector vector2(vector1);
  vector2.mult(3);
  cout << vector2.more(vector2, vector1) << endl;
  vector2.print();
  vector2.setValue(10);
}
