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

// a pair of shoes is a single object
// s[i] is the size of the shoe of the i'th student
// s is non-decreasing

// for a valid shuffle
    // no student gets their own shoe
    // new_size >= old_size

// either return a valid permutation
// or return -1

void solve(){
    int n; cin >> n;
    map<int,int> m; // shoe_size, count, smallest one first
    vector<int> nums(n);
    for(int& el : nums) {
        cin >> el;
        m[el]++;
    }

    if(n == 1) {cout << -1 << nl; return;} // he cant wear his own show

    // the last guy can only wear a shoe if there is another one of his size pr greater
    if(nums[n-1] != nums[n-2]){
        cout << -1 << nl;
        return;
    }

    // if there are more than 2 guys with the same size; they can swap/interchange
    // if someone wears a size greater than for them
        // it fucks up others wearing the size greater than them

    int i = 1;
    vector<int> res;
    for(auto& el : m){
        int shoe_size = el.first;
        int count = el.second;

        if(count < 2){
            cout << -1 << nl;
            return;
        }

        // add shuffled values in the res
        for(int j=i+count-1; j>=i; j++){
            res.push_back(j);
        }

        i += count;
    }

    for(int& el : res){
        cout << el << " ";
    }
    cout << nl;

}


//optimise it
// one run to see if count is < 2 for anything
// second run to return the order

void solve2(){
    int n; cin >> n; vector<int> nums(n);
    for(int& el : nums) cin >> el;


    if(n == 1){
        cout << -1 << nl;
        return;
    }

    int count = 1;

    for(int i=1; i<n; i++){
        if(nums[i] == nums[i-1]){
            count++;
        }else{
            if(count < 2){
                cout << -1 << nl;
                return;
            }

            count = 1;
        }
    }

    // check the last group
    if(count < 2){
        cout << -1 << nl;
        return;
    }

    // now this run to return the results

    int l = 0;
    int r = 0;

    while(l < n){
        while(r < n && nums[l] == nums[r]){
            r++;
        }

        // now r points to a new number
        // shuffle and return, wear the shoe to the right
        for(int j = l + 1; j < r; ++j){
            cout << j + 1 << " "; // +1 for 1-based indexing
        }
        cout << l + 1 << " "; // last guy in group gets the first one's shoes


        // now reset the values
        l = r;
    }

    cout << nl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve2();
}