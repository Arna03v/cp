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

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.rbegin(), a.rend()); // Sort in descending order
    
    int res = 0;
    int count = 0;
    int min_skill = LLONG_MAX;
    
    for (int i = 0; i < n; i++) {
        count++;
        min_skill = min(min_skill, a[i]);
        
        if (count * min_skill >= x) {
            res++;
            count = 0;
            min_skill = LLONG_MAX;
        }
    }
    
    cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}