#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct Node{
    int children[10];
    ll val;
    ll max_val;

    Node() : val(0), max_val(0){
        fill(children, children + 10, -1);
    }
};

struct Trie{
    vector<Node> nodes;
    Trie(){
        nodes.emplace_back();
    }

    void update(int cur, const string &s, int idx, ll v){
        if(idx == (int)s.size()){
            nodes[cur].val += v;
        } else {
            int c = s[idx] - '0';
            if(nodes[cur].children[c] == -1){
                nodes[cur].children[c] = nodes.size();
                nodes.emplace_back();
            }
            update(nodes[cur].children[c], s, idx + 1, v);
        }

        ll max_child = 0;
        rep(c,10){
            int id = nodes[cur].children[c];
            if(id != -1){
                max_child = max(max_child, nodes[id].max_val);
            }
        }
        nodes[cur].max_val = nodes[cur].val + max_child;
    }

    ll solve(const string &s, ll v){
        update(0, s, 0, v);
        return nodes[0].max_val;
    }
};

int main(){
    
    int n;
    cin >> n;
    Trie trie;
    rep(i,n){
        string a;
        ll b;
        cin >> a >> b;
        string r = a;
        reverse(r.begin(), r.end());
        cout << trie.solve(r, b) << endl;
    }
    
    return 0;
}