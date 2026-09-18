#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    map<string, int> cnt;

    for(int i = 0; i + k <= n; i++){
        string sub = s.substr(i, k);
        cnt[sub]++;
    }
    
    int max_count = 0;
    for(auto &p : cnt){
        max_count = max(max_count, p.second);
    }

    vector<string> result;
    for(auto &p : cnt){
        if(p.second == max_count)
            result.push_back(p.first);
    }

    sort(result.begin(), result.end());
    cout << max_count << endl;
    for(auto &t : result){
        cout << t << " ";
    }
    cout << endl;
}