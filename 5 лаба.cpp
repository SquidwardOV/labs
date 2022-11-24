#include <iostream>


using namespace std;

void inclusionSort (int *num, int size){
    for (int i = 1; i < size; ++i){
        int value = num[i];
        int index = i;
        while ((index > 0) && (num[index - 1] > value)){
            num[index] = num[index - 1];
            index--;
        }
        num[index] = value;
    }
}


int main(){

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

        for (int j = 0; j < size; ++j) {

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


int* res_arr = new int[k];

for (int i = 0; i < k; ++i) {
res_arr[i] = new_arr[i];
}
delete[] arr;
delete[] new_arr;

for (int i = 0; i < k; ++i) {
cout << res_arr[i] << " ";
}

delete[] res_arr;


}
