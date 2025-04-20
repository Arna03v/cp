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

// larger the number of factors, larger the number
// lets find a number exactly 4 factors
// 1 factor = 1
// 1 factor = the number itself, say 'a'
// we need the other2 factors

// let's assume we have the answer and then simplify the constraints

// look at prime factorisation of `a`

// we want only 2 prime factors at max
    // a = p^(alpha)*q^(beta) -> alpha = 1 & beta = 1
    // a = p^(alpha) -> alpha = 3

// either a = pq/ a = p^3

// case 1 : a = pq
    // divisors are 1, p, q, pq

// case 2 :
    // divisors : 1, p, p^2. p^3

// find the smallest possible for each case such that difference of divisors is at least d
// return the min

// case 1: 
    // p-1 >= d
    // p >= d+1

    // can we find the smallest prime >= d + 1

    // p(p-1) >= d; automatically done
    // p^(p-1) >= d; automatically done

    // that will give us the answer for case 1

// case 2: 
    // p>=d+1
    // q >= p+d;
        // q >= 2d+1;

        // find the smallesr prtime greater than 2d+1?

    // q(p-1) >= d; automatically done


// TC -> O(root(n))
bool is_prime(int x){
    // return true if the number is a prime number

    for(int i=2; i*i <=x; i++){
        if(x%i == 0) return false;
    }

    return true;
}

// TC -> constant time
int next_prime(int x){
    // return the number >= x such that it is a prime
    for(int num = x; ;num++){
        if(is_prime(num)) return num;
    }

    return -1;
}

void solve(){
    int n; cin >> n; 
    
    int first = next_prime(n+1);
    int second = next_prime(first+n);

    cout <<  min(first*first*first, first*second) << nl;
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}