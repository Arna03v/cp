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
    int w, h; cin >> w >> h; 
    int k; cin >> k;
    vector<int> lower(k); // y coordinate is 0
    for(int& el : lower) cin >> el;

    int l; cin >> l;
    vector<int> upper(l); // y coordinate is h
    for(int& el : upper) cin >> el;

    int m; cin >> m;
    vector<int> left(m); // x coordinate is 0
    for(int& el : left) cin >> el;

    int n; cin >> n;
    vector<int> right(n); // x coordinate is w
    for(int& el : right) cin >> el;

    // there are only 4 possible answers
    // base is the points on the end; and choose the correct height
    // return the max of them

    int h1 = (lower[k-1] - lower[0]) * h;
    int h2 = (upper[l-1] - upper[0]) * h;
    int h3 = (left[m-1] - left[0]) * w;
    int h4 = (right[n-1] - right[0]) * w;

    cout << max(h1,max(h2,max(h3,h4))) << nl;
    return;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}