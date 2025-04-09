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

// take first element of either array
// remove it
// insert to back of c

// retur the max length of subarray consistin of eual values

// store the count of contiguous sections for each array
// do some traversal and math

// TLE SOLUTION

// try to keep the same values together, we wsnt the longest run of values to be together   
// find the longest possible chain for every unique element in A and in B
// return lA + lB

// finding the longest run of all elements in an array can be done in n*logn using map and count variable
// map<element, longest run of that element>; do for A and B
// can find unique elements in set


void solve(){

    unordered_set<int> s; // to store all the unique elements

    int n; cin >> n; vector<int> a(n);
    for(int& el : a) {cin >> el; s.insert(el);}

    vector<int> b(n);
    for(int& el : b) {cin >> el; s.insert(el);}

    unordered_map<int,int> a_count;
    unordered_map<int,int> b_count;

    int count = 1;
    a_count[a[0]] = 1;

    for(int i=1; i<n; i++){
        if(a[i] == a[i-1]){
            count++;
        }else{
            count = 1;
        }

        a_count[a[i]] = max(a_count[a[i]], count); // if we do in the if conditionwe have to update at the end again
    }

    count = 1;
    b_count[b[0]] = 1;

    for(int i=1; i<n; i++){
        if(b[i] == b[i-1]){
            count++;
        }else{
            count = 1;
        }

        b_count[b[i]] = max(b_count[b[i]], count);
    }

    int res = INT_MIN;

    for(auto el : s){
        // for each element in s
        res = max(res, a_count[el] + b_count[el]);
    }

    cout << res << nl;
    return;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}