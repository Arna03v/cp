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
using namespace std;

#define nl "\n"

inline void solve(){
    int n; cin >> n; 

    // IF N IS ODD THEN ITS NOT POSSIBLE
    if(n&1 || n==2){
        cout << -1 << nl;
        return;
    }

    // 4x + 6y = n
    // 2x + 3y = n/2

    // maximise the number of buses; increase value of x
    // if n/2 is even (say n = 12)
    // x = 3
    // if n/2 is odd (say n=14)
    // x = 2, y = 1
    // so we have floor(n/2) buses

    // minimise the buses; increase value of y
    // 3k, 3k+1, 3k+2
    // we get ceil(n/3)

    cout << ceil(n/3) << " " << floor(n/2) << nl;
    return;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}

/*
EDITORIAL SOLUTION

Let the number of buses with two axles is 𝑥
 and the number of buses with three axles is 𝑦
. Then the equality 4𝑥+6𝑦=𝑛
 must be true. If 𝑛
 is odd, there is no answer, because the left part of the equality is always even. Now we can divide each part of the equality by two: 2𝑥+3𝑦=𝑛2
.

Let's maximize the number of buses. Then we should make 𝑥
 as large as possible. So, we will get 2+…+2+2=𝑛2
 if 𝑛2
 is even, and 2+…+2+3=𝑛2
 otherwise. In both cases the number of buses is ⌊𝑛2⌋
.

Now let's minimize the number of buses. So, we should make 𝑦
 as large is possible. We will get 3+…+3+3+3=𝑛2
 if 𝑛2
 is divisible by 3
, 3+…+3+3+2=𝑛2
 if 𝑛≡2(mod3)
, and 3+…+3+2+2=𝑛2
 if 𝑛≡1(mod3)
. In all cases the number of buses is ⌈𝑛3⌉
.

Also don't forget the case 𝑛=2
 — each bus has at least four wheels, so in this case there is no answer.

Time complexity: (1)
.
*/