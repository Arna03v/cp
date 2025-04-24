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
// #define int long long
// #define inti int
#define zz "res is : " << 


// choose exactly one substring and reverse it
// to get a lexicographically lesser string
// dont need to get the minimum string
// if we cant get a lesser string, print no
// else print yes and then the suitable string


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n; string s; cin >> s;

    int position = -1;
    bool can_get_a_better_string = false;
    for(int i=1; i<n; i++){
        if(s[i] < s[i-1]){
            // we can get a better string
            can_get_a_better_string = true;
            position = i;
            break;

        }
    }

    if(!can_get_a_better_string){
        cout << "NO" << nl;
        return 0;
    }

    // we know we can get a better string
    // swap i and i-1
    // as i < i-1
    // which means if i-1 came before i, the string would be lesser

    cout << "yes" << nl;
    cout << position << " " << position + 1 << nl;

    return 0;
}