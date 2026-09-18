#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    map<string,string> opposite ={
        {"N","S"},
        {"S","N"},
        {"W","E"},
        {"E","W"},
        {"NW","SE"},
        {"NE","SW"},
        {"SW","NE"},
        {"SE","NW"},
    };

    string d;
    cin >> d;
    cout << opposite[d] << endl;

    
    return 0;
}