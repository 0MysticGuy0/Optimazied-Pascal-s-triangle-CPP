// PascalPiramida.cpp

#include<iostream>
#include <string>
using namespace std;

const short MAX_STRING_LENGTH = 100;
unsigned long long StringN[MAX_STRING_LENGTH];//Cashed string of the triangle
int Ncashed = 0;//Index of the saved/cashed string

///
unsigned long long getNum(int N, int K) {//get the number for position(N-string,K-Column)
    if (N == Ncashed) {//If string N was saved, use array(saved values)
      return StringN[K];
    }
    if(N>Ncashed) //if the string wasn't saved and comes after saved one, save current string
    {
        for (int f = N; f >= 0; f--) StringN[f] = ((N == 0 || f == 0 || f == N) ? 1 :(getNum(N-1,f) + getNum(N-1,f-1)));
        Ncashed = N;
        return StringN[K];
    }
    else {//if current string is before cashed one
        Ncashed = N;
        if (N == 0 || K == 0 || K == N) { StringN[K] = 1; return 1; }
        else return (getNum(N - 1, K - 1) + getNum(N - 1, K));
    }
}
///
int main()
{
    int n;//Number of strings in output
    cout<<"Enter the number of the strings: ";
    cin >> n;
    system("cls");
    int maxWith = to_string(getNum(n-1, n / 2 + 1)).size(); //max num size
    //cout << maxWith<< endl;

    for (int i = 0; i < n; i++) {
      
        for (int c = 0; c < ((maxWith+1) * n - (i + 1) * (maxWith+1))/2 ; c++)  cout << ' ';//Print spaces left to centralize the triangle
       
        for (int j = 0; j <= i; j++) {
            cout << ' ';//чтобы большие числа не сливались в одно
            long long num = getNum(i, j);
            int s= to_string(num).size();//current num size

            for (int c = 0; c < (maxWith-s) / 2; c++)cout << ' ';//spaces to the left of the number
            cout <<num;
            for (int c = 0; c < (maxWith-s-((maxWith - s) / 2)); c++)cout << ' ';//spaces to the кшпре of the number
        }
        cout<< endl;//end of string
    }
    cout << endl << endl;
    system("PAUSE");
    return 0;
}

