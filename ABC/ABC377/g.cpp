#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

struct Node{
    int children[26];
    int min_len;

    Node() : min_len(INF){
        fill(children, children + 26, -1);
    }
};

struct Trie{
    vector<Node> nodes;
    Trie(){
        nodes.emplace_back();
    }

    void insert(const string &s){
        int cur = 0;
        int len = s.size();
        for(char c : s){
            int idx = c - 'a';
            if(nodes[cur].children[idx] == -1){
                nodes[cur].children[idx] = nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].children[idx];
            nodes[cur].min_len = min(nodes[cur].min_len, len);
        }
    }

    int query(const string &s){
        int cur = 0;
        int len = s.size();
        int res = len;
        rep(i,len){
            int idx = s[i] - 'a';
            if(nodes[cur].children[idx] == -1) break;
            cur = nodes[cur].children[idx];

            int depth = i + 1;
            int cost = len + nodes[cur].min_len - 2 * depth;
            res = min(res, cost);
        }
        return res;
    }
};

int main(){
    
    int n;
    cin >> n;
    Trie trie;
    rep(i,n){
        string s;
        cin >> s;
        cout << trie.query(s) << endl;
        trie.insert(s);
    }
    
    return 0;
}