#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    multiset<int> a;
    vector<int> b(n);
    rep(i,n){
        int x;
        cin >> x;
        a.insert(x);
        b[i] = x;
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for(auto x : b){
        a.erase(a.find(x));
    }

    deque<int> dq;
    for(auto x : b) dq.push_back(x);
    for(auto x : a) dq.push_back(x);

    int ans = 0;
    while(!dq.empty()){
        if(dq.front() == ans + 1){
            dq.pop_front();
            ans++;
        } else {
            dq.pop_back();
            if(dq.empty()) break;
            dq.pop_back();
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}