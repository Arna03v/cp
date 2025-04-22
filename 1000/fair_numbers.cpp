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
#include <cstdlib>
using namespace std;

#define nl "\n"
#define int long long
#define zz "res is : " << 

// a number = fair if it is divisble by each of its non-zero digits
// given a positive integer `n`, find the minimum x st
    // x >= n, x == fair

// brute force, keep going till the number is fair
// gives a run time error
void solve(){
    int n; cin >> n; 
    
    while(true){
        string num = to_string(n);
        bool flag = true;
        for(int i=0; i<num.size(); i++){
            if(num[i] != '0' && n % (num[i] - '0') != 0){
                flag = false;
                break;
            }
        }

        if(flag == true){
            // every number divided it
            cout << n << nl;
            return;
        }else{
            // gives an issue with stoi if the number is greater than an integer
            n = stoll(num) + 1;
        }
    }
}

void solve2(){
    int n; cin >> n;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
