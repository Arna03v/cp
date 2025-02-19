#include <iostream>
#include <algorithm>
#include <vector>

// #include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n; 
    string s; cin >> s;

    int l = 0;
    int r = s.size()-1;

    while(l<r && s[l] != s[r]){
        l++;
        r--;
    }

    if(l==r) cout << 1 << endl;
    else if (l>r) cout << 0 << endl;
    else cout << r-l + 1 << endl;
    return;
}

int main(){
    int t; cin >> t; while(t--) solve();
}