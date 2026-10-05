#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    string x;
    cin >> x;
    int n = x.size();
    int dig_sum = 0, car = 0;
    for(char c : x) dig_sum += c - '0';

    string res = "";
    for(int i = n - 1; i >= 0; i--){
        car += dig_sum;
        res += (car % 10) + '0';
        car /= 10;
        dig_sum -= x[i] - '0';
    }

    while(car > 0){
        res += (car % 10) + '0';
        car /= 10;
    }

    reverse(res.begin(), res.end());
    cout << res << endl;
    
    return 0;
}