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

void solve(){
    string s; cin >> s;

    int one_count = 0;
    int zero_count = 0;

    for(char& c : s){
        if(c == '1')one_count++;
        else zero_count++;
    }

    // we can play until we have only 1s or only 0s
    // each move we reduce 1 and 0
    int number_of_moves = min(one_count, zero_count);

    if(number_of_moves&1){
        cout << "DA" << nl; return;
    }else{
        cout << "NET" << nl; return;
    }


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}