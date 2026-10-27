#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    string s;
    cin >> n >> k >> s;

    rep(i,n){
        if(s[i] == 'o'){
            if(i - 1 >= 0) s[i - 1] = '.';
            if(i + 1 < n) s[i + 1] = '.';
            k--;
        }
    }

    vector<pair<int,int>> len;
    int sum = 0;
    int l = 0;
    while(l < n){
        if(s[l] != '?'){
            l++;
            continue;
        }

        int r = l;
        while(r < n && s[r] == '?') r++;

        len.push_back({l, r});
        sum += (r - l + 1) / 2;
        l = r;
    }

    if(k == 0){
        for(char &c : s){
            if(c == '?') c = '.';
        }
    } else if(sum == k){
        for(auto [l, r] : len){
            if((r - l) % 2 == 0) continue;
            for(int i = l; i < r; i++){
                if((i - l) % 2 == 0) s[i] = 'o';
                else s[i] = '.';
            }
        }
    }

    cout << s << endl;
    
    return 0;
}