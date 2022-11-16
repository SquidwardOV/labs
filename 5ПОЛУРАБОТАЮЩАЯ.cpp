#include <iostream>


using namespace std;

int main()
{
    int size, count = 0, k = 0;

    cout << "Введите количество элементов в изначальном массиве: ";
    cin >> size;

    int* arr = new int[size];
    int* new_arr = new int[size];

    cout << "Введите элементы массива: ";
    for (int i = 0; i < size; ++i) {
    cin >> arr[i];
    }

    for (int i = 0; i < size; ++i) {

        for (int j = 1; j < size; ++j) {

            if (arr[i] == arr[j] && i != j) {
                ++count;
            }
        }       
        if (count == 0) {
            new_arr[k] = arr[i];
            ++k;

        }   
        count = 0;
    }   
    for (int i = 0; i < k; ++i) {
        cout << new_arr[i] << " ";
    }
    delete [] arr;
    delete [] new_arr;
}
