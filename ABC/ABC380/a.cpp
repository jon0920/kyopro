#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    map<int, int> cnt;

    while(n > 0){
        int a = n % 10;
        cnt[a]++;
        n /= 10;
    }

    for(int i = 1; i <= 3; i++){
        if(cnt[i] != i){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    
    return 0;
}