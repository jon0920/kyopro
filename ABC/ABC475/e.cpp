#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct Node {
    int cnt = 0;
    int nxt[2] = {0, 0};
};

vector<Node> trie;

inline int to_index(char c){
    return c == 'x' ? 1 : 0;
};

void update_trie(const string &s, int val){
    int cur = 1;
    trie[cur].cnt += val;
    for(char c : s){
        int id = to_index(c);
        if(trie[cur].nxt[id] == 0){
            trie.emplace_back();
            trie[cur].nxt[id] = trie.size() - 1;
        }
        cur = trie[cur].nxt[id];
        trie[cur].cnt += val;
    }
};

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    
    trie.reserve(n * k + 2);
    trie.emplace_back();
    trie.emplace_back();
    
    string t;
    cin >> t;
    vector<string> s(n);
    rep(i,n){
        cin >> s[i];
        update_trie(s[i], 1);
    }

    int q;
    cin >> q;
    while(q--){
        int i, j;
        cin >> i >> j;
        i--, j--;

        update_trie(s[i], -1);
        s[i][j] = (s[i][j] == 'o' ? 'x' : 'o');
        update_trie(s[i], 1);

        int cur = 1;
        int pass = 0;
        bool is_passed = false;
        rep(kk,k){
            int ac_id = to_index(t[kk]);
            int wa_id = 1 - ac_id;

            int ac_node = trie[cur].nxt[ac_id];
            int c = ac_node ? trie[ac_node].cnt : 0;

            int r;
            bool p1;
            if(pass + c <= m){
                p1 = true;
                pass += c;
                r = wa_id;
            } else {
                p1 = false;
                r = ac_id;
            }

            int ans = to_index(s[i][kk]);
            if(ans != r){
                if(p1) is_passed = true;
                else is_passed = false;
                break;
            }

            cur = trie[cur].nxt[r];
        }

        if(is_passed) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}