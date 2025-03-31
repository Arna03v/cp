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
    int n; cin >> n; 

    if(n%2 == 0){
        cout << -1 << nl;
        return;
    }

    for(int i=1; i<=n; i++){
        if(i&1){
            cout << i << " ";
        }
    }

    for(int i=1; i<=n; i++){
        if(!(i&1)){
            cout << i << " ";
        }
    }

    cout << nl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}