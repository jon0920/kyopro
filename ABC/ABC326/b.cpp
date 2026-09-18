#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;

    for(int x = n; x < 1000; x++){
        int i = x;
        int a = i % 10; i /= 10;
        int b = i % 10; i /= 10;
        int c = i % 10;
        if(a == b * c){
            cout << x << endl;
            return 0;
        }
    }
    
    return 0;
}