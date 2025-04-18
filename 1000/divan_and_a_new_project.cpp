#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_set>
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
#define zz "res is : " << 

void solve(){
    int n; cin >> n; vector<pair<int, int> > nums; // {times visited, index (0 to n-1)}

    // also need to store the index
    for(int i=1; i<=n; i++){
        int a; cin >> a;
        nums.push_back({a, i});
    }

    // now sort; most frequently visited should be closer
    sort(nums.rbegin(), nums.rend());

    vector<int> res(n+1); // 0 to n
    long long total_time = 0;
    int dist = 1;

    for (int i = 0; i < nums.size(); i++) {
        int visits = nums[i].first;
        int idx = nums[i].second;

        total_time += 2LL * visits * dist;

        // Alternate placing at +dist and -dist
        if (i % 2 == 0) {
            res[idx] = dist;
        } else {
            res[idx] = -dist;
            dist++; // Only increment after both sides filled
        }
    }

    cout << total_time << '\n';
    cout << 0 << ' '; // coordinate of headquarters
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}