#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll a, n;
    cin >> a >> n;
    ll mx = 1;
    while(mx <= n) mx *= 10;

    vector<int> dist(mx + 1, -1);
    dist[1] = 0;
    queue<int> que;
    que.push(1);

    auto rotate = [&](int m){
        string t = to_string(m);
        int sz = t.size();
        string res = "";
        res += t.back();
        res += t.substr(0, sz - 1);
        return stoi(res);
    };

    while(!que.empty()){
        int s = que.front(); que.pop();

        ll x = s * a;
        if(x <= mx){
            if(dist[x] == -1){
                dist[x] = dist[s] + 1;
                que.push(x);
            }
        }
        if(s >= 10 && s % 10 != 0){
            int y = rotate(s);
            if(y <= mx){
                if(dist[y] == -1){
                    dist[y] = dist[s] + 1;
                    que.push(y);
                }
            }
        }
    }

    cout << dist[n] << endl;

    return 0;
}