#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int m;
    cin >> m;

    vector<int> a;
    for(int i = 0; i <= 10; i++){
        for(int j = 0; j < (m % 3); j++){
            a.push_back(i);
        }
        m /= 3;
    }

    cout << a.size() << endl;
    for(int x : a){
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}