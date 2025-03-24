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

// find all prime factors of n
// if one of them is odd, cout yes
// else cout no

// brute force
bool isPrime(int n){

    int count = 0; // to count the number of factors

    for(int i=1; i<=sqrt(n); i++){
        if(n%i == 0){
            count++;
        }

        if(n/i != i)count++;
    }

    if(count == 2)return true;
    else return false;
}
void solve(){
    int n; cin >> n;

    vector<int> prime_factors;
    for(int i=2; i<=n; i++){
        if(n%i == 0 && isPrime(i)){
            prime_factors.push_back(i);
        }
    }

    for(int& el : prime_factors){
        if(el&1){
            cout << "YES" << nl;
            return;
        }
    }

    cout << "NO" << nl;
    return;
}

// optimised
void solve2(){
    int n; cin >> n;
    // divide the number by its smallest prime factor untilt the number itself is a prime factor
    vector<int> primeFactors; 
    
    // Loop from 2 up to n
    for(int i = 2; i <= n; i++){
        // Check if n is divisible by i
        if(n % i == 0){
            // If divisible, add i to
            // the primeFactors vector
            primeFactors.push_back(i);
        }
        // Continue dividing n by i
        // until it's no longer divisible
        while(n % i == 0){
            n = n / i;
        }
    }

    for(int& el : primeFactors){
        if(el & 1){
            cout << "YES" << nl;
            return;
        }
    }

    cout << "NO" << nl;
    return;
}

// smarter way
// if a number has a odd divisor; say x; it is made up off odd prime divisors as odd*odd = odd
// which means if a number has no odd divisors; it must have 2 as its only factor

void solve3(){
    int n; cin >> n;

    while(n%2 != 1 && n/2 != 1){
        n = n/2;
    }

    if(n%2 == 1){
        // it has a odd divisot
        cout << "YES" << nl;
        return;
    }else{
        // n = 2 has been reached
        cout << "NO" << nl;
        return;
    }
}

// smrter in O(1)
void solve4(){
    int n; cin >> n;

    // we just need to check if n is a power of 2
    int res = n&(n-1); // n = 10000 and n-1 = 01111 -> n&(n-1) = 0
    if(res == 0){
        // it has no odd divisor
        cout << "NO" << nl;
        return;
    }

    cout << "YES" << nl;
    return;


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve3();
}