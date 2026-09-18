#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int h, w;
    cin >> h >> w;
    int si, sj;
    cin >> si >> sj;
    pair<int,int> now = {si, sj};
    vector<vector<char>> s(h + 2, vector<char>(w + 2, '#'));
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++) cin >> s[i][j];
    }
    
    string x;
    cin >> x;
    for(char c : x){
        if(c == 'L'){
            if(s[now.first][now.second - 1] != '#') now.second--;
        }
        else if(c == 'R'){
            if(s[now.first][now.second + 1] != '#') now.second++;
        }
        else if(c == 'U'){
            if(s[now.first - 1][now.second] != '#') now.first--;
        }
        if(c == 'D'){
            if(s[now.first + 1][now.second] != '#') now.first++;
        }   
    }

    cout << now.first << " " << now.second << endl;
    
    return 0;
}