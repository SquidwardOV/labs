#include <iostream>
using namespace std;
 
int main()
{
    int k = 0, n;
    int arr[n], res[n];
    int count;
    cout << "Введите количество символов в массиве: ";
    cin>>n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n-1; i++)
    {
        count = 0;
        for(int j = 1; j < n; j++)
        {
            if(arr[i] == arr[j] && i != j)
                count++;
        }
        if(count == 0)
        {
            res[k] = arr[i];
            k++;
        }
    }
    for(int i = 0; i < k; i++)
        cout << res[i] << " ";
        
  }

