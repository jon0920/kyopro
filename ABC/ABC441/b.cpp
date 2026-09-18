#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    set<char> sts, stt;
    for(char c : s) sts.insert(c);
    for(char c : t) stt.insert(c);


    int q;
    cin >> q;
    while(q--){
        string w;
        cin >> w;
        int stats = 0;
        for(char c : w){
            if(sts.count(c) && !stt.count(c)){
                cout << "Takahashi" << endl;
                stats = 0;
                break;
            }
            else if(!sts.count(c) && stt.count(c)){
                cout << "Aoki" << endl;
                stats = 0;
                break;
            }
            else if(sts.count(c) && stt.count(c)) stats = 1;
        }
        if(stats != 0) cout << "Unknown" << endl;
    }
    
    return 0;
}