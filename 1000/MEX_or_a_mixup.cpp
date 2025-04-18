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

// MEX = minimum excluded
// write an array such that MEX = a, xors = b
// shortest possible length of such array?
// all numbers are non negative

// the array is a mex value of a
// [0, 1, 2, ..., a-1]

// let the xors of the array be `x`

// case 1 : x == b
    // we dont need any other number
    // res == a;
    // as it contains elements from 0 to a-1, which is 'a' elements

// we need to somehow make the xors from `x` to `b`
// if we do x xors x -> 0, 0 xors b -> b; so we need the element x xors b in the array to make the final xors = b

// case 2 : x!= b && x xors b != a
    // if x xors b != a; if we add this element to the array' MEX is still = a
    // the xors of array will become x xors x xors b = b
    // th final res = a+1

// case 3 : x!=b && x xors b == a
    // now we cannot add this element to the array
    // add x xors b xors 1 and 1; this way the 1 and 1 will cancel out
    // and the MEX remains = b
    // res = a + 2

// insted of doing O(n) computation for each case
// we can precompute the xors; as we know the upper limit of a

vector<int> xors(3e5 + 10); // stores the xors of elements from 0 to i in the i'th position

void solve(){
    int a, b; cin >> a >> b;

    // since mex = a
    // we need the xors of a-1 elements
    int curr = xors[a-1];

    if(curr == b){
        cout << a << nl;
        return;
    }else{
        if((curr^b) != a){
            // we can include this element
            cout << a+1 << nl;
        }else{
            cout << a+2 << nl;
        }
    }

    return;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // pre compute
    xors[0] = 0;
    for(int i=1; i<xors.size(); i++){
        xors[i] = xors[i-1]^i;
    }

    int t; cin >> t; while(t--) solve();
}