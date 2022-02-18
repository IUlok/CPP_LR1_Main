#include <iostream>
#include <math.h>
#include <unistd.h> // Заголовочный файл, позволяющий реализовать ф-цию sleep()
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

void format() {
  int point;
  int format, otstup;
  char symb;
  cout << "Выбери тип отображения ответов:\n1\tБез форматирования\n2\tНаучный\n3\tС отступом\nНомер:\t";
  cin >> point;
  switch(point) {
    case 1:
      format=1;
      break;
    case 2:
      format=2;
      break;
    case 3:
      cout << "Введи через пробел сначала величину отступа, а затем символ, которым его заполнять:\nВвод:\t";
      cin >> otstup >> symb;
      break;
    default:
      cout << "Такого формата нет!\n";
  }
  if (format=2) {
    cout.setf(ios::scientific);
  }
  if (format=3) {
    cout.width(otstup);
    cout.fill(symb);
  }
  else {
    cout.setf(ios::showpos);
  }
}

int main() {
  setlocale(LC_ALL, "ru"); // Для использования русского алфавита
  float x, x1, x2;
  float y; // Значение ф-ции
  float d; // Шаг в case 3
  int point; // Пункт меню
  int a=1; // Для бесконечного цикла

while (a) {
    system("clear"); // Очищаю окно терминала на каждой новой итерации цикла для красоты
    cout << "Выберите пункт меню:\n1\tВычисление f(x)\n2\tВывод наибольшего значения двух ф-ций f(x1), f(x2)\n3\tВывод наибольшего значения ф-ций в промежутке\n4\tВыход\nНомер:\t";
    cin >> point; // Выбор пункта меню
    switch (point) {

      case 1: // Вычисление f(x):
        cout << "Введите значение x:\nx = ";
        cin >> x;
        y = func(x);
        format();
        cout << "Значение функции f(x): " << y << "\nЭкран очистится через 5 секунд..." << endl;;
        sleep(5); // Задержка 5 секунд перед началом новой итерации и очистки экрана
        break;

      case 2: // Вычисление наибольшего значения f(x1), f(x2):
        cout << "Введите значение x1:\nx1 = ";
        cin >> x1;
        cout << "Введите значение x2:\nx2 = ";
        cin >> x2;
        y = max(func(x1), func(x2));
        cout << "Наибольшее значение функции f(x): " << y << "\nЭкран очистится через 5 секунд..." << endl;
        sleep(5); // Задержка 5 секунд перед началом новой итерации и очистки экрана
        break;

      case 3: // Вычисление значений в промежутке
        cout << "Введите значение x1:\nx1 = ";
        cin >> x1;
        cout << "Введите значение x2:\nx2 = ";
        cin >> x2;
        cout << "Введите величину шага d:\nd = ";
        cin >> d;
        for (float i = x1; i <= (x2+0.000001); i+=d) { // 0.000001 - маленькое число для устранения погрешности в шаге
          y = func(i);
          cout << "Значение y для f(" << i << ") = " << y << endl;
        }
        cout << "\nЭкран очистится через 10 секунд..." << endl; // Задержка 10 секунд перед началом новой итерации и очистки экрана
        sleep(10);
        break;

      case 4: // Выход из программы
        return 0;

      default: // Значение, не явл. пунктом меню:
        cout << "Такого пункта меню нет! Экран очистится через 3 секунды..." << endl;
        sleep(3); // Задержка 3 секунды перед началом новой итерации и очистки экрана
        break;
    }
  }
}
