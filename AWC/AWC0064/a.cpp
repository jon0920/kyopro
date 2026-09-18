#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> ans;
    int cnt = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(a >= k){
            if(ans.empty() || ans.back() != i - 1) cnt++;
            ans.push_back(i);
        }
    }

    cout << cnt << endl;

    return 0;
}