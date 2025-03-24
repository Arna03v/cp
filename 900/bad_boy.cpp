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
#include <sstream>
using namespace std;

#define nl "\n"
#define int long long

void solve(){
    int n, m,i,j; cin >> n >> m >> i >> j; 
    
    // n,m -> dimensions of the room
    // i,j -> antons location

    // initial to first to second to inital
    // doesnt matter if we replace first and second
    // we just need to maximise the distance between the yoyos
    // top left, bottom right?

    cout << 1 << " " << 1 << " " << n << " " << m << nl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}