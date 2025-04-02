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
#define r return
#define re "s is : " << 

// note of k =2,3,5; they a primes
// which means we need to make one number divisble by them, thus owrking on only one number
// if k = 4
    // either make one number a multiple of 4
    // or make 2 even numbers


void solve(){
    int even_count = 0;
    int the_count = 0;
    int five_count = 0;
    int four_count = 0;
    int n, k; cin >> n >> k; vector<int> nums(n);
    for(int& el : nums){
        cin >> el;
        if(!(el&1)){
            even_count++;
        }
        if(el%3 ==0)the_count++;
        if(el%5 == 0)five_count++;
        if(el%4 == 0)four_count++;
    }
    if(k==2){
        // make one number even if the is no even numbers
        if(even_count > 0){
            cout << 0 << nl;
            return;
        }else{
            cout << 1 << nl;
            return;
        }

    }else if (k==3){
        if(the_count > 0){
            cout << 0 << nl;
            r;
        }else {
            int mini = LLONG_MAX;
            for(int& el : nums){
                mini = min(mini, 3 - el%3);
                if(mini == 1){
                    cout << 1 << nl;
                    return;
                }
            }
            cout << mini << nl;
            r;
        }
    }else if(k==4){
        if(four_count > 0 || even_count >= 2){
            cout <<  0 << nl;
            r;
        }

        
        int mini = LLONG_MAX;
        for(int& el : nums){
            mini = min(mini, 4 - el%4);
            if(mini == 1){
                cout <<  1 << nl;
                return;
            }
        }
        cout <<  max((long long)0, 2-even_count) << nl; // make 2 even numbers
        r;


    }else{
        // k == 5
        if(five_count > 0){
            cout << 0 << nl;
            r;
        }
        int mini = LLONG_MAX;
        for(int& el : nums){
            mini = min(mini, 5 - el%5);
            if(mini == 1){
                cout << 1 << nl;
                return;
            }
        }
        cout << mini << nl;
        r;
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}