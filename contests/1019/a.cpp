#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n; set<int> nums;
    for(int i=0; i<n; i++){
        int el; cin >> el;
        nums.insert(el);
    }

    cout << nums.size() << endl;
}

int main(){
    int t; cin >> t; while(t--) solve();
}