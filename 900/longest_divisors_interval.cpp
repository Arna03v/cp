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

#define int long long

// find an array of contigous elements such that
// n is a multiple of all the elements
// return the size of the max possible array

void solve(){
    int n; cin >> n;

    // brute force till 40 works; did till 40 because 40! is > 10^18

    int res = 0;
    int curr = 0;

    for(int i=1; i<40; i++){
        if(n%i == 0){
            curr++;
            res = max(res, curr);
        }else{
            curr = 0;
        }
    }

    cout << res << "\n";

    // we cn also chcek forthe first integer that doesnt divide
    // similar to mine
    /*
    ull n;
		cin>>n;
 
		ull ans;
		for(ull i=1; ;i++){
			if(n%i != 0){
				ans = i-1;
				break;
			}
			
		}
		cout<<ans<<nl;
    */

}

signed main(){
    int t; cin >> t; while(t--) solve();
}