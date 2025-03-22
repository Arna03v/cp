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

int gcd(int i, int j){
    return j == 0? i : gcd(j, i%j);
}

// brute force O(n) solution
void solve(){
    int a,b; cin >> a >> b;

    if(a == b) {cout << "0 0" << nl; return;}
    int max_fun = max(a-b, b-a);

    int curr_gcd = gcd(a,b);
    if(max_fun == curr_gcd){
        cout << max_fun << " " << "0" << nl;
        return; 
    }

    // let a be the greater value for understanding sake
    if(a<b){
        int temp = b;
        b = a;
        a = temp;
    } 

    int steps = -1;

    for(int i=1; i<= a-b; i++){
        if(gcd(a+i, b+i) == max_fun){
            steps = i;
            break;
        }
    }

    if(steps != -1){
        cout << max_fun << " " << steps << nl;
        return;
    }
    else{
        cout << max_fun << " " << a-b << nl;
        return;
    }
}

void solve2(){
    int a,b; cin >> a >> b;

    if(a == b) {cout << "0 0" << nl; return;}
    int max_fun = max(a-b, b-a);

    // let a be the greater value for understanding sake
    if(a<b){
        int temp = b;
        b = a;
        a = temp;
    } 

    // gcd (a,b) = gcd (a-b,b) when a > b
    // the value 1-b stays same no matter how many operations we apply
    // we can change value of b to a multiple of a-b to get a gcd = a-b
    // we need to make b a multiple of a-b in minimum number of steps
    // can either decrease b or increase b
    // if we are decreasing b, we need b%max_fun number of steps
    // if we are increasing b, we need max_fun - b%max_fun (think about it, it is really straight forward)

    cout << max_fun << " " << min(b%max_fun, max_fun - (b%max_fun)) << nl;
    return;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve2();
}