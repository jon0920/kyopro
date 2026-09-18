#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    vector<int> a(5);
    rep(i,5) cin >> a[i];

    int cnt = 0;
    bool sort = false;
    while(!sort)
        rep(i,4){
            if(a[i] > a[i+1]){
                int tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                cnt++;
            }
        rep(i,5){
            sort = true;
            if(a[i] != i+1) sort = false;
        }
    }

    cout << (cnt == 1 ? "Yes" : "No") << endl;
    
    return 0;
}