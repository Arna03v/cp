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

// either *2
// or /6 if rem == 0

// rturn minimum number of moves to get 1
// else return -1

// check PF
// if anything else except 2/3 then then -1
// else #3s < #2s; then not possible
// else if #3s >= #2s; thenwe can make it 6 and divide

// bool flag;
// vector<int> solve2(int n){
//     vector<int> res;
//     flag = true;

//     // Divide by 2 until n is odd
//     while (n % 2 == 0) {
//         res.push_back(2);
//         n /= 2;
//     }


//     for(int i=3; i*i<=n; i++){
//         while(n%i == 0){
//             res.push_back(i);
//             n/=i;
//         }
//     }

//     if(n > 1 && n > 3){  // remaining prime factors
//         cout << "res is : " << -1 << nl;
//         flag = false;   
//         return res;
//     }

//     return res;
// }

// void solve(){
//     int n; cin >> n; 

//     vector<int> factor_tree = solve2(n);

//     if(!flag){
//         return;
//     }
//     // if(factor_tree[factor_tree.size()-1] != 3){
//     //     cout << "res is : " << -1 << nl;
//     //     return;
//     // }

//     int two_count = 0;
//     int three_count = 0;

//     for(int& el : factor_tree){
//         if(el == 2){
//             two_count++;
//         }else three_count++;
//     }

//     if(two_count > three_count){
//         cout << "res is : " << -1 << nl;
//         return;
//     }else{
//         int res = three_count;
//         res += (three_count - two_count);
//         cout << "res is : " << res << nl;
//         return;
//     }
    
// }

// simpler to code
// divide by 2s
// then by 3s
// then the cases like discussed above
void solve(){
    int n; 
    cin >> n;

    int cnt2 = 0, cnt3 = 0;

    while (n % 2 == 0) {
        n /= 2;
        cnt2++;
    }

    while (n % 3 == 0) {
        n /= 3;
        cnt3++;
    }

    if (n > 1 || cnt2 > cnt3) {
        cout << -1 << "\n";
    } else {
        cout << 2 * cnt3 - cnt2 << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}