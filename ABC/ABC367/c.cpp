#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, k;
    cin >> n >> k;
    vector<int> r(n);
    rep(i,n) cin >> r[i];
    
    vector<int> a(n, 1);

    while(1){
        int sum = 0;
        for(int i : a) sum += i;
        if(sum % k == 0){
            rep(i,n){
                if(i) cout << " ";
                cout << a[i];
            }
            cout << endl;
        } 
        int j = n - 1;
        while(j >= 0){
            a[j]++;
            if(a[j] <= r[j]) break;
            a[j] = 1;
            j--;
        }
        if(j < 0) break;
    }


    
    return 0;
}