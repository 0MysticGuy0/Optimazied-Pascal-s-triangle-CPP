// PascalPiramida.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include <iomanip>
#include <string>
using namespace std;

unsigned long long StringN[100];// = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
int Ncashed = 0;

unsigned long long getNum(int N, int K) {
    if (N == Ncashed) {
      return StringN[K];
    }
    if(N>Ncashed) 
    {
        for (int f = N; f >= 0; f--) StringN[f] = ((N == 0 || f == 0 || f == N) ? 1 :(getNum(N-1,f) + getNum(N-1,f-1)));
        Ncashed = N;
        
        return StringN[K];
    }
    else {
        Ncashed = N;
        if (N == 0 || K == 0 || K == N) { StringN[K] = 1; return 1; }
        else return (getNum(N - 1, K - 1) + getNum(N - 1, K));
    }
}
long int fac(int n) {
    return n * ((n>1)?fac(n - 1):1);
}
int main()
{
    int n;
    cout<<"Enter the number of the strings: ";
    cin >> n;
    system("cls");
    int maxWith = to_string(getNum(n-1, n / 2 + 1)).size(); //max num size
   // int maxWith =((n-1)%2==0)? to_string(fac(2 * n/3) / (fac(n/3) * fac(n/3))).size(): to_string(fac(2 * n/3+1) / (fac(n/3+1) * fac(n/3+1)/2)).size();
    cout << maxWith<< endl;
    for (int i = 0; i < n; i++) {
      
        for (int c = 0; c < ((maxWith+1) * n - (i + 1) * (maxWith+1))/2 ; c++)cout << ' ';
       
        for (int j = 0; j <= i; j++) {
            cout << ' ';
            long long num = getNum(i, j);
            int s= to_string(num).size();//current num size
            for (int c = 0; c < (maxWith-s) / 2; c++)cout << ' ';
            cout <<num;
            for (int c = 0; c < (maxWith-s-((maxWith - s) / 2)); c++)cout << ' ';
        }
        cout<< endl;
    }

    system("PAUSE");
    return 0;
}

