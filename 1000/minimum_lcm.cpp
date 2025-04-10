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

// to find lcm
// find gcd
// lcm = a*b/gcd

int GCD(int a, int b){
    if(b == 0){
        return a;
    }

    return GCD(b, a%b);
}

// gives TLE -> n*logc
void solve(){
    int n; cin >> n; 
    
    int i = 1;
    int j = n-1;
    int mini_lcm = (i*j)/GCD(i,j);

    int res_a = i;
    int res_b = j;

    while(i <= j){
        int lcm = (i*j)/GCD(i,j);

        if (lcm <= mini_lcm){
            mini_lcm = lcm;
            res_a = i;
            res_b = j;
        }

        i++;
        j--;
    }

    cout << res_a << " " << res_b << nl;
    return;
}

// better than that is sqrt(n) -> 10^5 or logn which also works
// we can find factors in sqrt(n), which is common during gcd and lcm, which is why we consider it

// lets assume that a<=b, we are anyway checking the first half of the search space.
// what can be a possible relation between a and b
// what if a is the factor of b, or b is a multiple of a (assume that a<=b WLG)
    // we just want to see if looking at factors hels as this is a lcm question

// when a is a factor of b
    // then LCM = b
// if a if not a factor of b
    // then the LCM is at something among 2b, 3b, 4b ... (multiples of the larger number)
    // the LCM is at least 2b
    // and since b > a, and a+b = n, we can also say that b is always >= n/2
        // which means that the LCM >= n
    
// which means we need to search when a is a factor of b, no need to search for other elements
// as in this case LCM < n always and in the other case LCM >= n always

// can implement above, which is faster then solve() but still not fast enough

// a + b = n
// a + ax = n
// n = a(1+x)
    // this means that a is a factor of n

// so we only need to search among the factors of n -> can find in sqrt(n)
// once if find 'a' that minimises the LCM, we get b = n - a

// how to find this a, we want to this b to be as less as possible as LCM = b
// we want 'a' to be as large as possible
// we want the largest divisor of n, that will be 'a'
    // start from 2, the first number that divides n is say f
    // then the largest divisor will be n/f -> a (just ensure that we follow a<=b)
    // if we dont find a divisor then 1,n-1 can be a solution anyways

void solve3(){
    int n; cin >> n;

    int a = 1; // a possible answer if we dont find a suitable a

    for(int i=2; i*i<=n; i++){ // this search space ensures a<=b; we are only searching in the first half
        
        if(n%i == 0){ // then 'i' becomes the 'f' discussed above
            a = n/i;
            break;
        }
    }

    cout << a << " " <<n-a << nl;
    return;
}



void solve2(){
    int n; cin >> n; 
    
    int i = 1;
    int j = n-1;
    int mini_lcm = (i*j)/GCD(i,j);

    int res_a = i;
    int res_b = j;

    while(i <= j){
        if(j%i == 0)// check only if i is a factor of 
        {
            int lcm = (i*j)/GCD(i,j);

            if (lcm <= mini_lcm){
                mini_lcm = lcm;
                res_a = i;
                res_b = j;
            }
        }

        i++;
        j--;
    }

    cout << res_a << " " << res_b << nl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve3();
}