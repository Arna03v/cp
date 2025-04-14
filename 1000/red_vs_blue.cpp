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

// n matches
// red worn r times, blue won b times
// b < r

// print string s such that red one, and that maximum times red won in a row is the minimum 

// we have b B's; thus b+1 sections in which we need to place r balls
// thus one region must have at least ceil(r/b+1) red balls; this is the lower bound
// now we constuct this string

// some sections will have min number of Rs
// rest will have min_r + 1

void solve(){
    int n, r, b; cin >> n >> r >> b; 

    int min_r = r/(b+1); // minimum number of R's in each segemnt
    int sections_with_extra_r = r%(b+1); // number of segments that get an extra R

    for(int i=0; i<sections_with_extra_r; i++){
        cout << string(min_r + 1, 'R') << 'B';

    }

    // now the sections that get equal Rs
    for(int i=0; i<b - sections_with_extra_r; i++){
        cout << string(min_r, 'R') << 'B';
    }

    // now print the last r segmebnt
    cout << string(min_r, 'R') << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}