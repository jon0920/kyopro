#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<ll> ball;
    rep(i,n){
        ball.push_back(a[i]);
        while(ball.back() == ball[ball.size() - 2] && ball.size() > 1){
            ball.pop_back();
            ball[ball.size() - 1]++;
        }
    }
    cout << ball.size() << endl;
    
    return 0;
}