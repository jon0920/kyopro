#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct Node{
    int children[26];
    int count;

    Node() : count(0){
        fill(children, children + 26, -1);
    }
};

struct Trie {
    vector<Node> nodes;
    Trie(){
        nodes.emplace_back();
    }

    void insert(const string &s){
        int cur = 0;
        nodes[cur].count++;
        for(char c : s){
            int idx = c - 'a';
            if(nodes[cur].children[idx] == -1){
                nodes[cur].children[idx] = nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].children[idx];
            nodes[cur].count++;
        }
    }

    int query(const string &s){
        int cur = 0;
        int depth = 0;
        int max_lcp = 0;
        for(char c : s){
            int idx = c - 'a';
            cur = nodes[cur].children[idx];
            depth++;
            if(nodes[cur].count >= 2) max_lcp = depth;
            else break;
        }
        return max_lcp;
    }
};

int main(){
    
    int n;
    cin >> n;
    Trie trie;
    vector<string> s(n);
    rep(i,n){
        cin >> s[i];
        trie.insert(s[i]);
    }

    rep(i,n) cout << trie.query(s[i]) << endl;

    return 0;
}