#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int m=2;
    int n,str1,str2;
    double length,mini;
    cout<<"Ââåäèòå êîëëè÷åñòâî òî÷åê"<<endl;
    cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;++i){
            arr[i]=new int[m];
    }
    for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                    arr[i][j]=rand()%20-5;
                    cout<<arr[i][j]<<'\t';
            }
            cout<<endl;
    }
    mini=sqrt((pow((arr[0][0]-arr[1][0]),2)+pow((arr[0][0]-arr[1][0]),2)));
    for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                   length=sqrt((pow((arr[i][0]-arr[j][0]),2)+pow((arr[i][0]-arr[j][0]),2)));
                   if (length<mini){
                          mini=length;
                          str1=i;
                          str2=j;
                   }
            }
    }
    cout<<"Ìèíèìàëüíîå ðàññòîÿíèå: "<<mini<<endl;;
    cout<<arr[str1][0]<<' '<<arr[str2][1]<<endl;
    cout<<arr[str2][0]<<' '<<arr[str2][1]<<endl;
    for(int i=0;i<n;++i){
            delete [] arr[i];
    }
    delete[] arr;
    system("pause");
    return 0;
} 
