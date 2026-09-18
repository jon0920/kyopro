#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

struct Node{
    int children[26];
    int turn;

    Node() : turn(INF){
        fill(children, children + 26, -1);
    }
};

struct Trie{
    vector<Node> nodes;
    Trie(){
        nodes.emplace_back();
    }

    void insert(const string &s, int q){
        int cur = 0;
        for(char c : s){
            int idx = c - 'a';
            if(nodes[cur].children[idx] == -1){
                nodes[cur].children[idx] = nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].children[idx];
        }
        nodes[cur].turn = min(nodes[cur].turn, q);
    }

    int solve(const string &s){
        int cur = 0;
        int res = INF;
        for(char c : s){
            int idx = c - 'a';
            if(nodes[cur].children[idx] == -1) break;
            cur = nodes[cur].children[idx];
            if(nodes[cur].turn != INF){
                res = min(res, nodes[cur].turn);
            }
        }
        return res;
    }
};

int main(){
    
    int q;
    cin >> q;
    Trie trie;
    vector<pair<string,int>> y;
    rep(i,q){
        int t;
        string s;
        cin >> t >> s;
        if(t == 1) trie.insert(s, i);
        else y.push_back({s, i});
    }

    vector<int> imos(q + 1);
    for(auto [s, l] : y){
        int r = trie.solve(s);
        if(l < r){
            imos[l]++;
            if(r <= q) imos[r]--;
        }
    }
    rep(i,q) imos[i + 1] += imos[i];
    
    rep(i,q) cout << imos[i] << endl;
    
    return 0;
}