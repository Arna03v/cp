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

// each element [-100, 100]
// operation is to multiply adjacent cells by -1

// what is the maximum sum we can achieve?

// note that if we have config as [-1, 2, -1]; we can do the operation twice, to get [1,2,1]

// if we have even number of negatives; then they can be removed
// if we have odd number of negatives; then one number will always remain negative
    // let the smallest value be negative
    // not the smallest negative, but the smallest abs value be negative

void solve(){
    int n, m; cin >> n >> m; vector<vector<int> > nums(n, vector<int>(m, 0));

    // n rows
    // m cols

    int sum = 0;
    int mini = INT_MAX;
    int count = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> nums[i][j];
            sum += abs(nums[i][j]);

            if(nums[i][j] <= 0){
                count++;
            }

            mini = min(mini, abs(nums[i][j])); // need to track even when the number is positive

        }
    }

    // cout << "count is : " << count << ", and mini is :" << mini << nl;

    if(count&1){
        cout << sum - 2*mini << nl;
    }else cout << sum << nl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}