#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> dig;
    while(n){
        int x = n % 10;
        dig.push_back(x);
        n /= 10;
    }
    
    rep(i,dig.size() - 1){
        if(dig[i] >= dig[i + 1]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}