#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = (ll)1e18;

// f(i, l, r, c)
ll dfs(int i, ll l, ll r, int c,
       const vector<ll>& len,
       const vector<vector<ll>>& cnt,
       const vector<vector<int>>& prefX,
       const vector<vector<int>>& prefY){

    if(l > r) return 0;

    if(i == 1){
        return prefX[c][r] - prefX[c][l-1];
    }
    if(i == 2){
        return prefY[c][r] - prefY[c][l-1];
    }

    if(r <= len[i-1]){
        return dfs(i-1, l, r, c, len, cnt, prefX, prefY);
    }
    else if(l > len[i-1]){
        return dfs(i-2, l-len[i-1], r-len[i-1], c, len, cnt, prefX, prefY);
    }
    else{
        return dfs(i-1, l, len[i-1], c, len, cnt, prefX, prefY)
             + dfs(i-2, 1, r-len[i-1], c, len, cnt, prefX, prefY);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string X, Y;
    cin >> X >> Y;

    int Q;
    cin >> Q;

    int n1 = X.size(), n2 = Y.size();

    // prefix sum
    vector<vector<int>> prefX(26, vector<int>(n1+1,0));
    vector<vector<int>> prefY(26, vector<int>(n2+1,0));

    for(int i=0;i<n1;i++){
        for(int c=0;c<26;c++) prefX[c][i+1] = prefX[c][i];
        prefX[X[i]-'a'][i+1]++;
    }
    for(int i=0;i<n2;i++){
        for(int c=0;c<26;c++) prefY[c][i+1] = prefY[c][i];
        prefY[Y[i]-'a'][i+1]++;
    }

    // len
    vector<ll> len(100);
    len[1] = n1;
    len[2] = n2;
    int LIM = 2;
    for(int i=3;i<100;i++){
        len[i] = min(INF, len[i-1] + len[i-2]);
        if(len[i] >= INF) LIM = i;
    }

    // cnt
    vector<vector<ll>> cnt(100, vector<ll>(26,0));
    for(int c=0;c<26;c++){
        cnt[1][c] = prefX[c][n1];
        cnt[2][c] = prefY[c][n2];
    }
    for(int i=3;i<100;i++){
        for(int c=0;c<26;c++){
            cnt[i][c] = min(INF, cnt[i-1][c] + cnt[i-2][c]);
        }
    }

    // S[10^18] は S[LIM] でOK
    int root = LIM;

    while(Q--){
        ll L,R;
        char ch;
        cin >> L >> R >> ch;
        int c = ch - 'a';

        cout << dfs(root, L, R, c, len, cnt, prefX, prefY) << '\n';
    }
}