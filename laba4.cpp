#include <iostream>
#include <cmath>
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    double x, N, E, newE, sum_newE = 0,sum_moreE = 0, k = 1, t = 0, chisl=1, res = 0, power=1;
    short n_for = 0;
    cout << "Введите x,N,E"<<endl;
    cin >> x >> N >> E;
    newE = E / 10;
    res = 1;
    for (n_for = 1; n_for <= N; n_for++) {
        k *= (2 * n_for);
        chisl *= ((2 * n_for) - 1);
        power = power * x;
        t = (chisl / k) * (power);


        if (n_for % 2 == 0) {
            res += t;
        }
        if (n_for % 2 == 1) {
        res -= t;
        }
    chisl = 1;
    }
    int i=1;
    k = 1; 
    power =1 ;
    do{
        k *= (2 * i);
        chisl *= ((2 * i) - 1);
        power = power * x;
        t = (chisl / k) * (power);
                if (abs(t) > E){
                    if (i % 2 == 0) {
                         sum_moreE += t;
                    }
                    if (i % 2 != 0) {
                        sum_moreE -= t;
                    }
                    chisl = 1;
                }
        
        i++;
    }
    while (abs(t)>E);    
    
    int m=1;
    power = 1;
    k = 1;
    do{
        k *= (2 * m);
        chisl *= ((2 * m) - 1);
        power = power * x;
        t = (chisl / k) * (power);
            if (abs(t) > newE){
                if (m % 2 == 0) {
                    sum_newE += t;
                }
                if (m % 2 != 0) {
                    sum_newE -= t;
                }
                chisl = 1;
             }
        
        m++;
    }
    while (abs(t) > newE);    
   
    
    cout << res << " " << sum_moreE << " " << sum_newE << " " << (1/(sqrt(1+x))) << endl;
}
