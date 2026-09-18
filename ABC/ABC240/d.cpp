#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    stack<pair<int,int>> st;
    int cnt = 0;
    rep(i,n){
        int a;
        cin >> a;
        cnt++;
        if(st.empty() || st.top().first != a){
            st.push({a, 1});
        }
        else if(st.top().first == a){
            st.top().second++;
            if(st.top().first == st.top().second){
                cnt -= st.top().second;
                st.pop();
            }
        }
        cout << cnt << endl;
    }
    
    return 0;
}