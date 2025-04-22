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

// one register to store only one variable at a time
// one operation = shifting the bits left or right by atmost 3 positions
// right shift is forbidden if it cuts off some 1s

// which means in one operation we can either multiply by 2,4,8
// or divide by 2,4,8 iff the number is divisble by 2/4/8

// minimum number of ops to get b from a
// if we cant get b then return -1

void solve(){
    int a,b; cin >> a >> b;

    if(a == b){
        cout << zz 0 << nl;
        return;
    }

    if(a>b){
        if((a/b)%2 != 0){
            cout << zz -1 << nl;
            return;
        }
    }else{
        if((b/a)%2 != 0){
            cout << zz -1 << nl;
            return;
        }
    }

    // now we know that we can get the other by some doing some operation
    // lets try to move from the smaller number to the bigger number
    if(b<a){
        a ^= b;
        b ^= a;
        a ^= b;
    }

    int operations = 0;

    while(a<b){
        a *= 2;
        operations++;
    }

    // now a == b
    int number_of_ops_if_we_used_8 = (operations + 4 - 1)/4;
    int rem = operations % 3;

    int res = number_of_ops_if_we_used_8;
    if(rem == 1)res++;
    else if(rem == 2)res++;
    else if(rem == 3) res += 2;

    cout << zz res << nl;
    return;


}

// the idea is correct ish; verify that they have teh same odd parts
// if thye dont then they can never reach each other
// if they do; them try to get one from another

void solve2(){
    int a, b; cin >> a >> b;

    int a_count = 0;
    int b_count = 0;
    while(a%2 == 0){a/=2; a_count++;}
    while(b%2 == 0){b/=2; b_count++;}

    if(a!=b){
        cout << -1 << nl;
        return;
    }

    // now that we know that tjeir odd parts are the same
    if(a_count == b_count){
        cout << 0 << nl;
        return;
    }

    int diff = abs(a_count - b_count);

    cout << diff/3 + (diff%3 != 0) << nl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve2();
}

/*
EDITORIAL SOLUTION
*/

