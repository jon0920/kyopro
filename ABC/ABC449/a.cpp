#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const double pi = 3.141592653589793;

int main(){

    double d;
    cin >> d;
    d /= (double)2;
    cout << fixed << setprecision(17);
    cout << pi * d * d << endl;

    return 0;
}