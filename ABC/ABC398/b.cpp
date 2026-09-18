#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    map<int,int> mp;
    rep(i,7){
        int a;
        cin >> a;
        a--;
        mp[a]++;
    }

    rep(i,13){
        if(mp[i] >= 3){
            rep(j,13){
                if(i != j && mp[j] >= 2){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;

    return 0;
}