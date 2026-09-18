#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> chords(n * 2);
    rep(i,n){
        int a, b;
        cin >> a >> b;
        a--, b--;
        chords[a] = i;
        chords[b] = i;
    }

    stack<int> st;
    vector<bool> seen(n);
    rep(i,n * 2){
        int id = chords[i];
        if(!seen[id]){
            seen[id] = true;
            st.push(id);
        } else {
            if(!st.empty() && st.top() == id){
                st.pop();
            } else {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    
    return 0;
}