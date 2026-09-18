#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> l(n), id(n);
    rep(i,n){
        int a;
        cin >> a;
        a--;
        l[i] = a;
        id[a] = i;
    }

    atcoder::fenwick_tree<int> fw(n);
    rep(i,n){
        int res = id[i] + 1;
        res -= fw.sum(0, id[i]);
        fw.add(id[i], 1);
        cout << res << endl;
    }
    
    return 0;
}