#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cctype>
#include <utility>
#include <numeric>
using namespace std;

#define nl "\n"

inline void solve(){
    int n; cin >> n; vector<int> nums(n);
    for(int& el : nums) cin >> el;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}

/*
EDITORIAL SOLUTION
*/

/*

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n; vector<int> nums(n);
    for(int& el : nums) cin >> el;
}

int main(){
    int t; cin >> t; while(t--) solve();
}
*/

