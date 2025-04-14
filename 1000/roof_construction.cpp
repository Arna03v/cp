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

// the max value we xan achieve is 1000 and 0111
// the upper bound is 2^k ^ 2^k - 1; where k is the largest set bit
// we want to do is better than this
// we want to get rid of the highest set bit
// ther will be one guy after which we cant rid of the highest set bit,
    // some guy will have 1 in MSB and that guy - will have 0 in the MSB
    // so we can never get rid of the highest set bit

// our roof construction cost is atleast 2^k where k is the highest set bit
// now that we know a lower bound, can we arrange in a way that we get the lower bound?

// say n = 11; then k = 3 (from 2^3)
// we need to place elements such that max of pairwise XOR does not go over 2^k
// if we place (8,9,10) together, we can see that the 2^k bit goes; removing the MSB to some extent
// before 8, what we should we put such that the XOR stays 2^k
// so if we 0 next to 8, the pairwise max is 8
// anything before doesnt matter because 8 > any possible pariwise xor of elements less than 8 as it has one bit lesser

// how many such combinations exist (elements > 2^K) * (elements less than 2^k)

// 2^k - 1, 2^k - 2, .. 1, 0, 2^k, 2^k + 1, 2^k + 2, ...

void solve(){
    int n; cin >> n; // number of pillars for construction

    // find the higest set bit
    int k=0;
    while((1<<(k+1)) <= n-1)k++; // we are not including the number 'n' in the output arrau

    for(int i=(1<<k)-1; i>=0; i--)cout << i << " ";
    for(int i=(1<<k); i<n; i++)cout << i << " ";
    cout << nl;


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}