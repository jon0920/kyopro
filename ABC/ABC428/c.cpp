#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int q;
    cin >> q;
    vector<char> s;
    vector<pair<int,bool>> ok;
    rep(_,q){
        int type;
        cin >> type;
        if(type == 1){
            char c;
            cin >> c;
            s.push_back(c);
            int d = (c == '(' ? 1 : -1);

            if(ok.empty()){
                ok.push_back({d, d == 1});
            } else {
                auto [last, valid] = ok.back();
                int nxt = last + (c == '(' ? 1 : -1);
                bool nxt_valid = valid && (nxt >= 0);
                ok.push_back({nxt, nxt_valid});
            }
        } else {
            s.pop_back();
            ok.pop_back();
        }

        if(ok.empty() || ok.back().first == 0 && ok.back().second) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}