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
    int n, k; cin >> n >> k; vector<int> nums(n);
    int prod = 1;
    for(int& el : nums) {cin >> el; prod *= el;}

    if(k == 2){
        if(prod&1){
            cout << "res is : " << 1 << nl;
            return;
        }else{
            cout << "res is : " << 0 << nl;
            return;
        }
    }else if(k==3){
        

    }else if(k==4){

    }else{

    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}