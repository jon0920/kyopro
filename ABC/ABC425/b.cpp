#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> used(n + 1, false);
    rep(i,n){
        cin >> a[i];
        if(a[i] != -1 && used[a[i]]){
            cout << "No" << endl;
            return 0;
        }
        if(a[i] != -1) used[a[i]] = true;
    }
    
    vector<int> p;
    int pos = 1;
    rep(i,n){
        if(a[i] != -1) p.push_back(a[i]);
        else{
            while(used[pos]) pos++;
            p.push_back(pos);
            used[pos] = true;
        }
    }
    cout << "Yes" << endl;
    for(auto x : p) cout << x << " ";
    cout << endl;
    
    return 0;
}