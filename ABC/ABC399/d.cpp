#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(2 * n);
        rep(i,2 * n) cin >> a[i];
        
        vector<vector<int>> pos(n + 1);
        rep(i,2 * n){
            pos[a[i]].push_back(i);
        }
        for(auto &v : pos) sort(v.begin(), v.end());

        set<pair<int,int>> ans;
        for(int i = 0; i < 2 * n - 1; i++){
            int j = i + 1;
            if(pos[a[i]][0] + 1 == pos[a[i]][1]) continue;
            if(pos[a[j]][0] + 1 == pos[a[j]][1]) continue;

            vector<int> vec = {pos[a[i]][0], pos[a[j]][0], pos[a[i]][1], pos[a[j]][1]};
            sort(vec.begin(), vec.end());
            if(vec[0] + 1 == vec[1] && vec[2] + 1 == vec[3]){
                int x = a[i], y = a[j];
                if(x > y) swap(x, y);
                ans.insert({x, y});
            }
        }
        cout << ans.size() << endl;
    }

    return 0;
}