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

// sum of elements = s
// beauty = b
// where b = sum (a[i]/k)
// size of a = n

// each element is non negative
    // we have inifinite number of 0s, 0s dont affect the value of beauty

// lets look at forming the array with the correct beauty first
// if we have a single element as b.k and eveyr other elemtn less than k -> beuty = k

// when will this approach not work
// sum of above array would be >= b.k where every non first element can range from 0 to k-1
// if sum < bk then we can never form an array
// if sum > bk + (n-1)(k-1) then we have too much sum, we cannot form the array with beauty = k

// lets to try make the first element even larger, makes filling rest of the elements easier
// first element can be b.k + k-1; the beuaty is still k

// in this case the upper bounf for s becomes s > bk + n(k-1) will not work

// else we can
void solve(){
    int n, k, b, s; cin >> n >> k >> b >> s;

    if(s < k*b || s > (k*b) + (n)*(k-1)){
        cout << -1 << nl;
        return;
    }

    // our sum is in the bounds
    int first = k*b;
    s -= k*b; // what if the sum get over before the k-1

    if(s >= k-1){
        first += (k-1);
        s -= (k-1);
    }else{
        // anyway its less than k-1
        // adding wont change the beauty
        first += s;
        s = 0;
    }

    cout << first << " "; // we have printedt the first element

    for(int i=1; i<n; i++){
        int ai;

        // if we can add k-1, then do it
        if( s>= (k-1)){
            ai = (k-1);
            s -= (k-1);
        }else{
            // anyways we can add
            ai = s;
            s = 0;
        }

        cout << ai << " ";
    }

    cout << nl;











}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}