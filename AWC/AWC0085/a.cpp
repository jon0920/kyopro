#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    int m = 0;
    while(!(n & (1 << m))) m++;
    vector<pair<int,int>> s(n);
    rep(i,n){
        int a;
        cin >> a;
        s[i] = {a, i};
    }

    vector<int> ans(n);
    rep(i,m){
        vector<pair<int,int>> tmp;
        int sz = s.size();
        for(int j = 0; j < sz; j += 2){
            if(s[j].first > s[j + 1].first){
                tmp.push_back(s[j]);
                ans[s[j + 1].second] = i + 1;
            } else {
                tmp.push_back(s[j + 1]);
                ans[s[j].second] = i + 1;
            }
        }
        s = tmp;
    }

    for(auto x : ans) cout << x << " ";
    cout << endl;

    
    return 0;
}