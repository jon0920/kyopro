#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n);
    vector<vector<int>> second(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        cnt[a]++;
        second[a].push_back(b);
    }
    
    pair<int,int> cand1 = {-1, -1}, cand2 = {-1, -1};
    rep(i,n){
        if(cand1.first < cnt[i]){
            cand2.first = cand1.first;
            cand2.second = cand1.second;
            cand1.first = cnt[i];
            cand1.second = i;
        } else if(cand2.first < cnt[i]){
            cand2.first = cnt[i];
            cand2.second = i;
        }
    }

    rep(i,n){
        pair<int,int> cand = (i != cand1.second ? cand1 : cand2);
        map<int,int> tmp_cnt;
        for(int c : second[i]){
            tmp_cnt[c]++;
        }
        for(auto [k, v] : tmp_cnt){
            if(cnt[k] + v > cand.first){
                cand = {cnt[k] + v, k};
            } else if(cnt[k] + v == cand.first && k < cand.second){
                cand = {cnt[k] + v, k};
            }
        }
        cout << cand.second + 1 << endl;
    }
    
    return 0;
}