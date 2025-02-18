#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

void solve(){
    int n; cin >> n; 
    string s; cin >> s;

    int l = 0;
    int r = s[s.size()-1];

    while(s[l] != s[r] && l<r){
        l++;
        r--;
    }

    if(l==r) cout << 1 << endl;
    else cout << r-l << endl;
    return;
}

int main(){
    int t; cin >> t; while(t--) solve();
}