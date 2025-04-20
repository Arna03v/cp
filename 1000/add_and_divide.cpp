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

// a -> a/b
// b -> b + 1

// return minimum number of operations to make a = 0;

int solve2(int a, int b){
    // base case
    if(a == 0){
        return 0; // we stop the operations
    }

    // base case
    // if b==1 we will get infinite division
    if (b==1) return solve2(a, b+1);

    return min(solve2(a/b, b) + 1, solve2(a, b+1) + 1);
}

void solve(){
    int a, b; cin >> a >> b;

    // int res = solve2(a, b);

    // note that when doing the two operations; it is better to do increase than divide
    // than divide then increase

    // so lets try increasing b first; then dividing to make a = 0
    // when b >= 2; the max number of times we are going to divide is 
        // a is 10^9; which is 20 times
    // if b == 1; we increase and then divide;
    // so max number of operations should be 30

    // if we have anumber `a` which we want to destroy by dividing by `x`
    // it will take log a base (x) operations
    // larger the base, slower the growth (in graph of logx)
    // we are better of picking a graph with slower growth, as it will take lower number of operations

    // so increase b till a limit, and then do the division
    // no point in increasig during divisions; we are wasting operations
    // 4/3 == 1 and 4/4 == 1; so that increase we did did not get us anything

    // so get a value of 'b` and then divide it 


    // wprst case analysis
    // worst case: a=1e9, b=1 -> b=2, a=1e9 (1ops) -> log(1e9) ~ 30

    int res = INT_MAX; // the max number 

    // we try all cobination of ordering; 
    // i stands for the number of addition operations
    // worst case is O(900) -> 30*30
    for(int i=0; i<30; i++){
        int x = a;

        if(b+i >= 2){
            int turns = i;
            while(x > 0){
                // divide
                x = x/(b+i);
                turns++;
            }

            res = min(res, turns);
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