#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
#include <fstream>

class Icosahedron {
  double a; // side of the icosahedron
  unsigned int color;

public:
  Icosahedron() : a(1.0), color(0) {}
  Icosahedron(double ai) : a(ai), color(0) {}
  Icosahedron(int ic) : a(1.0) {
    if (ic >= 0)
      color = ic;
    else
      color = 0;
  }
  Icosahedron(double a, int c) {
    this->a = a;
    if (c >= 0)
      color = c;
    else
      color = 0;
  }
  double getA() const { return a; }
  void setA(double a) {
    if (a < 0 || a > 1.e+100) {
      cout << " Error set  a \n";
      return;
    }
    this->a = a;
  }
  double getColor() const { return color; }
  void setColor(int c) {
    if (c < 0 || c > 10000) {
      cout << " Error set  color \n";
      return;
    }
    this->color = c;
  }
  double S() { return 5 * a * a * sqrt(3.0); }
  double V() { return 5 * a * a * a * (3 + sqrt(5.0)) / 12.0; }
  double r() { return a * (3 + sqrt(5.0)) / (4.0 * sqrt(3.0)); }
  double R() { return sqrt(2 * (5 + sqrt(5.0) * a)) / 4.0; }
  void printInfo() {
    cout << "\n a= " << a << " color = " << color;
    cout << "  S= " << S() << " V = " << V() << "  r= " << r() << " V = " << R()
         << endl;
  }
};

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

class Vector {
  int *point;
  int length;
  int state;

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
    point[index] = value;
  }

  int returnValue(int index) {
    return point[index];
  }

  void print() {
    for (int i = 0; i < length; i++) {
      cout << point[i] << " ";
    }
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
  vector2.print();
}

// Ключове слово static
/*example  4
Створити тип даних - клас вектор, який має вказівник на ComplexDouble, число
елементів і змінну стану. У класі визначити o	 конструктор без параметрів(
виділяє місце для одного елемента та інінціалізує його в нуль); o
конструктор з одним параметром - розмір вектора( виділяє місце та інінціалізує
масив значенням нуль);
o	конструктор із двома параметрами - розмір вектора та значення
ініціалізації(виділяє місце (значення перший аргумент) та інінціалізує значенням
другого аргументу). o	конструктор копій та операцію присвоєння; // !!! o
деструктор звільняє пам'ять; o	визначити функції друку, додавання; У змінну
стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі
масиву. Передбачити можливість підрахунку числа об'єктів даного типу. Написати
програму тестування всіх можливостей цього класу.
*/

#include <complex>
using namespace std;
typedef complex<double> ComplexDouble;
#define _RE 0
#define _IM 1

class ComplexVector {
  ComplexDouble *v;
  int num; // default num=2
  int state = 0;

public:
  ComplexVector() : ComplexVector(2) {}
  ComplexVector(int n);
  ComplexVector(int n, ComplexDouble &);
  ComplexVector(int n, ComplexDouble *);
  ComplexVector(const ComplexVector &s);
  ComplexVector &operator=(const ComplexVector &s);
  ~ComplexVector() {
    std::cout << " del vec";
    if (v)
      delete[] v;
  }
  void Output();
  void Input();
  ComplexVector Add(ComplexVector &b);
};

ComplexVector::ComplexVector(int n) {
  if (n <= 0)
    n = 2; // default num =2;
  num = n;
  v = new ComplexDouble[n];
  for (int i = 0; i < n; i++) {
    v[i] = 0.0;
    // v[i]._Val[_RE]=0.0; v[i]._Val[_IM]=0.0;
  }
}
ComplexVector::ComplexVector(int n, ComplexDouble &b) : ComplexVector(n) {
  for (int i = 0; i < num; i++) {
    v[i] = b;
    // v[i]._Val[_RE]=0.0; v[i]._Val[_IM]=0.0;
  }
}

ComplexVector::ComplexVector(int n, ComplexDouble *p) : ComplexVector(n) {
  if (p != nullptr)
    for (int i = 0; i < num; i++)
      v[i] = p[i];
}

ComplexVector::ComplexVector(const ComplexVector &s) {
  // if (this == &s) return;  // the expression is used in the old standard
  num = s.num;
  v = new ComplexDouble[num];
  state = 0;
  for (int i = 0; i < num; i++)
    v[i] = s.v[i];
}

ComplexVector &ComplexVector::operator=(const ComplexVector &s) {

  if (num != s.num) {
    if (v)
      delete[] v;
    num = s.num;
    v = new ComplexDouble[num];
    state = 0;
  }
  for (int i = 0; i < num; i++)
    v[i] = s.v[i];
  return *this;
}
void ComplexVector::Input() {
  int in_num = 0;
  do {
    cout << "Input size Vec\n";
    cin >> in_num;
  } while (in_num <= 0);
  if (num != in_num) {
    num = in_num;
    if (v)
      delete[] v;
    v = new ComplexDouble[num];
  }
  for (int i = 0; i < num; i++) {

#if defined(_MSC_VER)
    cout << " v [ " << i << " ] real img  ";
    cin >> v[i] >> v[i]._Val[_IM];
#else
    double re, im;
    cout << " v [ " << i << " ] real img  ";
    cin >> re >> im;
    v[i].real(re);
    v[i].imag(im);
#endif
  }
}

void ComplexVector::Output() {
  if (num != 0) {
    for (int i = 0; i < num; i++) {
      cout << " v [ " << i << " ]   " << v[i] << '\t';
      cout << endl;
    }
  }
}

ComplexVector ComplexVector::Add(ComplexVector &b) {
  int tnum;
  tnum = num < b.num ? num : b.num;
  if (tnum >= 0) {
    ComplexVector tmp(tnum);
    for (int i = 0; i < tnum; i++)
      tmp.v[i] = v[i] + b.v[i];
    return tmp;
  }
  return ComplexVector(1);
}

int mainExample4() {
  ComplexDouble a(1.0, 2), b, c;
  cout << a << endl;
#if defined(_MSC_VER)
  b._Val[_RE] = 21.3;
  b._Val[_IM] = 22.3;
#else
  b.real(21.3);
  b.imag(22.3);
#endif

  cout << b << endl;
  c = a + b;
  cout << c << endl;
  cout << " Test  " << endl;
  ComplexVector VecObj, VecObj1(10);
  cout << "VecObj \n";
  VecObj.Output();
  cout << "VecObj1 \n";
  VecObj1.Output();
  cout << " Input a " << endl;

#if defined(_MSC_VER)
  cin >> a >> a._Val[_IM];
#else
  double re, im;
  cin >> re >> im;
  a.real(re);
  a.imag(im);
#endif
  cout << a << endl;
  ComplexVector VecObj2(10, a);
  VecObj2.Output();

  VecObj.Input();
  cout << endl;
  VecObj.Output();
  VecObj1 = VecObj.Add(VecObj2);
  VecObj1.Output();

  return 1;
}

///
