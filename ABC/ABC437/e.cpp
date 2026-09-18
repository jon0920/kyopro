#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct Node{
    map<int,int> children;
    vector<int> ids;
};

vector<Node> trie;
vector<int> p;

int main(){
    
    int n;
    cin >> n;
    trie.emplace_back();

    vector<int> node_id(n + 1);

    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        int parent = node_id[x];
        if(trie[parent].children.count(y)){
            node_id[i] = trie[parent].children[y];
        } else {
            int next_id = trie.size();
            trie[parent].children[y] = next_id;
            trie.emplace_back();
            node_id[i] = next_id;
        }
        trie[node_id[i]].ids.push_back(i);
    }

    auto dfs = [](auto dfs, int x) -> void {
        for(int id : trie[x].ids){
            p.push_back(id);
        }
        for(auto &[k, v] : trie[x].children){
            dfs(dfs, v);
        }
    };

    dfs(dfs, 0);

    for(int x : p) cout << x << " ";
    cout << endl;
    
    return 0;
}