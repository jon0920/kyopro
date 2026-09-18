#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int M = 1'000'000;
vector<int> spf(M + 1);

void build_spf(){
    for(int i = 0; i <= M; i++) spf[i] = i;
    for(int i = 2; i * i <= M; i++){
        if(spf[i] == i){
            for(int j = i * i; j <= M; j += i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

int main(){

    build_spf();

    int n;
    cin >> n;

    unordered_map<int, pair<ll,ll>> memo;

    ll max_ans = 0, min_ans = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(a == 1) continue;

        if(memo.count(a)){
            min_ans += memo[a].first;
            max_ans += memo[a].second;
            continue;
        }

        vector<int> facs;
        int temp = a;
        while(temp > 1){
            facs.push_back(spf[temp]);
            temp /= spf[temp];
        }

        ll mn = 0, prod_mn = 1;
        for(int p : facs){
            mn += prod_mn;
            prod_mn *= p;
        }

        sort(facs.rbegin(), facs.rend());
        ll mx = 0, prod_mx = 1;
        for(int p : facs){
            mx += prod_mx;
            prod_mx *= p;
        }

        memo[a] = {mn, mx};
        max_ans += mx;
        min_ans += mn;
    }

    cout << min_ans << " " << max_ans << endl;

    return 0;
}