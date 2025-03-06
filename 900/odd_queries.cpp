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

void solve(){

    int n,q; cin >> n >> q; vector<int> nums(n);
    for(int& el : nums) {cin >> el;}


    // {{l,r,k}, {l,r,k} ...}
    vector<vector<int> > queries(q,vector<int>(3));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    // brute force would be to traverse the length for every query
    // but we can use prefix sums

    vector<int> prefix(n,0);
    prefix[0] = nums[0];
    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] + nums[i];
    }

    for(vector<int>& q : queries){
        int l = q[0]-1;
        int r = q[1]-1;
        int k = q[2];

        // cout << "l, r, k -> " << l << " " << r << " " << k << " " << endl;

        long long sum = prefix[n-1]; // full sum
        sum -= prefix[r];
        if(l == 0){
            sum -=0;
        }else sum -= prefix[l-1];

        sum += k*(r-l+1);

        // long long sum = prefix[n-1] - (prefix[r] - prefix[l-1]) + k*(r-l+1);
        if(sum&1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main(){
    int t; cin >> t; while(t--) solve();
}