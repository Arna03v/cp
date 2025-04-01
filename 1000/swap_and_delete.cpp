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

// delete char -> 1
// swap -> 0

// empty string is always good
// final string t is good if t[i] != s[i] for all i <= length(t)
// minimum total cost

// max total cost = s.length(); just delete everything

void solve(){
    string s; cin >> s;

    int zero_count = 0;
    int one_count = 0;
    for(char& c : s){
        if(c == '0')zero_count++;
        else one_count++;
    }

    int cost = 0;

    int i = 0;
    while(i<s.size()){
        if(s[i] == '0'){
            if(one_count <= 0){break;}
            else one_count--;
        }else{
            if(zero_count <= 0){break;}
            else zero_count--;
        }
        i++;
    }

    if(i == s.size())cout << cost << nl;
    else cout << (s.size() - i) << nl;
    return;
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}