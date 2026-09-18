#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<pair<string,string>> sr(n);
    rep(i,n) cin >> sr[i].first >> sr[i].second;

    vector<pair<int,int>> cand(n);
    rep(i,n){
        if(sr[i].second == "teacher" || sr[i].second == "doctor") cand[i] = {0, i};
        else cand[i] = {1, i};
    }
    sort(cand.begin(), cand.end());

    rep(i,n){
        cout << sr[cand[i].second].first << " " << (cand[i].first == 0 ? "sensei" : "san");
        cout << endl;
    }
    
    return 0;
}