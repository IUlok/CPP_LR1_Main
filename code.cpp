#include <iostream>
#include <math.h>
#include <unistd.h>
using namespace std;

float func(float x) { // Функция счёта выражения
  if (x < -10) {
    x = -10;
    return ((1+x)/(2+pow(x, 2)))*pow(sin(x), 2);
  }
  if (x > 10) {
    x = 10;
    return ((1+x)/(2+pow(x, 2)))*pow(sin(x), 2);
  }
  else {
    return ((1+x)/(2+pow(x, 2)))*pow(sin(x), 2);
  }
}

int main() {
  setlocale(LC_ALL, "ru"); // Для использования русского алфавита
  float x; // Значение x
  float y; // Значение ф-ции
  int point; // Пункт меню
  int a=1;

while (a) {
    system("clear");
    cout << "Выберите пункт меню:\n1\tВычисление f(x)\n2\tВывод наибольшего значения двух ф-ций f(x1), f(x2)\n3\tВывод наибольшего значения ф-ций в промежутке\n4\tВыход\nНомер:\t";
    cin >> point;
    switch (point) {
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        return 0;
      default:
        cout << "Такого пункта меню нет!" << endl;
        sleep(5);
        break;

    }
  }
}
