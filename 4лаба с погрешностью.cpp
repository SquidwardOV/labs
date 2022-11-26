#include <iostream>
#include <iomanip>
#include <cmath>
#include <Windows.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int choice;
    cout << "1. Сумма заданного каличества слагаемых\n";
    cout << "2. Сумма с заданной точностью\n";
    cout << "3. Завершить работу\n";
    bool isError = false;
    do
    {
        cout << "-> ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 3)
        {
            isError = true;
            cout << "Ошибка ввода!\n";
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
        }
        else
            isError = false;
    } while (isError);

    //std::cout << choice << '\n';
    do
    {
        //-------------------------------------------
        double x;
        cout << "Введите значение x: ";
        while (!(cin >> x) || abs(x) >= 1)
        {
            cout << "Ошибка ввода (|x|<1)!\n";
            cin.clear();
            cin.ignore(255, '\n');
        }
        //std::cout << x << '\n';
        cout << setw(26) << left << "Точное значение" << " = " << fixed << setprecision(11) << 1 / sqrt(1 + x) << '\n';
        if (choice == 1)
        {
            cout << "Задача 1\n";
            cout << "Введите количество слагаемых::\n";
            int n;
            cin >> n;
            double s = 1, new_x = 1, chisl = 1, znam = 1;
            for (int i = 1; i < n; ++i) {
                znam *= (2 * i);
                new_x *= x;
                chisl *= ((2 * i) - 1);
                cout << ((2 * i) - 1) << " " << "числитель" << endl;
                cout << (2 * i) << " " << "знаменатель" << endl;
                if (i % 2 == 0) {
                    s += chisl / znam * new_x;
                }
                if (i % 2 != 0) {
                    s -= chisl / znam * new_x;
                }
                chisl = 1;
            }
            cout << s << endl;
        }

        else    //choice = 2
        {
            cout << "Задача  2\n";
            double E;
            cout << "Введите точность вычислений: "; cin >> E;
            int i = 1;
            double s = 1, new_x = 1, chisl = 1, znam = 1, t = 1;
            while (t > E) {
                znam *= (2 * i);
                new_x *= x;
                for (int b = 1; b <= i; ++b) {
                    chisl *= ((2 * b) - 1);
                    cout << ((2 * b) - 1) << " " << "числитель" << endl;
                    cout << (2 * i) << " " << "знаменатель" << endl;
                    cout << endl;
                }
                if (i % 2 == 0) {
                    s += chisl / znam * new_x;
                }
                if (i % 2 != 0) {
                    s -= chisl / znam * new_x;
                }
                t = chisl / znam * new_x;
                chisl = 1;
                ++i;
            }
            cout << "Точность = " << E << '\n';
            cout << "Количество слагаемых = " << i << '\n';
            cout << setw(26) << left << "Приближённое значение при E" << " = " << fixed << setprecision(11) << s << '\n';
            cout << endl;
            while (t > E / 10) {
                znam *= (2 * i);
                new_x *= x;
                for (int b = 1; b <= i; ++b) {
                    chisl *= ((2 * b) - 1);
                }
                if (i % 2 == 0) {
                    s += chisl / znam * new_x;
                }
                if (i % 2 != 0) {
                    s -= chisl / znam * new_x;
                }
                t = chisl / znam * new_x;
                chisl = 1;
                ++i;
            }
            cout << "Точность = " << E / 10 << '\n';
            cout << "Количество слагаемых = " << i << '\n';
            cout << setw(26) << left << "Приближённое значение при E на 10" << " = " << fixed << setprecision(11) << s << '\n';

        }
        char isExit;
        cout << "Завершить работу (Y/N - любой символ)\n";
        cin >> isExit;
        if (isExit == 'Y' || isExit == 'y') choice = 3;
    } while (choice != 3);
    return 0;
}
