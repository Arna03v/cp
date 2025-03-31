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

int solve2(int m, int mid, int n){
    // how many bench + gap fit 
    int quo = m/(mid+1); 
    // how many spots remain after fitting bench + gaps
    int rem = m%(mid+1); 

    int per_row = quo*(mid);
    per_row += min(rem, mid);
    return per_row*n;

}

void solve(){
    int n, m, k; cin >> n >> m >> k;

    // n is rows
    // m is cols
    // k is # participants

    // the range of min bench length is from 1 to m
    // for each iteration; check max nuber of students that can sit

    int l=1;
    int r=m;
    int res = m;

    while(l<=r){
        int mid = (r+l)/2;

        int total_students = solve2(m, mid, n);
        if(total_students >= k){
            res = mid;
            r = mid -1;
        }else{
            // we need more students to sit
            l = mid + 1;
        }
    }

    cout << res << nl;
    return;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
