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

inline void solve(){
    string s, t; 
    cin >> s >> t; // extracting s and t from iss

    // order of calling the letters doesnt matter but it has to be removed
    unordered_map<char,int> given;
    unordered_map<char,int> fin;

    for(char& c : s){
        given[c]++;
    }

    for(char& c : t){
        fin[c]++;
    }

    int i = 0; // traverses s
    int j = 0; // traverses t

    while(j < t.size() && i < s.size()){
        int char_from_s = s[i];
        int char_from_t = t[j];

        if(char_from_s != char_from_t){
            // this character is not in t
            // remove this character
            given[char_from_s]--;
            i++;
        }else{
            // this character is in t
            
            if(given[char_from_s] == fin[char_from_t]){
                // then these match as same number from each remain
                given[char_from_s]--;
                fin[char_from_t]--;
                i++;
                j++;
            }else{
                // these dont match
                given[char_from_s]--;
                i++;
            }
        }

    }

    if(j != t.size()) cout << "NO" << nl;
    else cout << "YES" << nl;
    return;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}