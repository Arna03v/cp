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
using namespace std;

// min size of array is 2
// convert all arrays to 0

// select 2 indexes [l,r]
// s = Al ^ Al+1 ^ ... ^ Ar
// replace all element in the range with s

// can perform the operations atmost 8 times. 
// return the number of operations and then the indexes involved
// do not have to minimise the number of operations

// xor the same numbers = 0
// xor of even length twice = 0
// if length is even; xor the whole thing twice
// if lenth is odd; xor 1-n-1 twice and the n-1 to n



void solve(){
    int n; cin >> n; vector<int> nums(n);
    for(int& el : nums) cin >> el;

    if(n%2 == 0){
        cout << 2 << endl;
        cout << "1 " << n << endl;
        cout << "1 " << n << endl;

    }else{
        cout << 4 << endl;
        cout << "1 " << n-1 << endl;
        cout << "1 " << n-1 << endl;
        cout << n-1 << ' ' << n << endl;
        cout << n-1 << ' ' << n << endl;
    }
}

int main(){
    int t; cin >> t; while(t--) solve();
}