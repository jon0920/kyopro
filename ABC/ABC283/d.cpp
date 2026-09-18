#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    string s;
    cin >> s;
    vector<char> st;
    vector<bool> box(26, false);
    for(char c : s){
        if(c == ')'){
            while(!st.empty() && st.back() != '('){
                box[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.pop_back();
        }
        else{
            st.push_back(c);
            if(c != '('){
                if(box[c - 'a'] == true){
                    cout << "No" << endl;
                    return 0;
                }
                box[c - 'a'] = true;
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}