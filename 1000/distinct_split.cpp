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

void solve(){
    int n; cin >> n; string s; cin >> s;

    // find the most repeating character and break it into 2 different strings
    unordered_map<char,int> m; // stores the frequency of each letter

    for(char c : s){
        m[c]++;
    }

    int max_char;
    int max_count = INT_MIN;
    for(auto el : m){
        char curr_char = el.first;
        int curr_count = el.second;
        if(curr_count >= max_count){
            max_char = curr_char;
            max_count = curr_count;
        }
    }

    if(max_count == 1){
        cout << zz n << nl;
        return;
    }

    // cout << "max_char is : " << max_char << ", and max_count is : " << max_count << nl;

    // otherwise we can split
    int first_occurence=-1;
    int second_occurence=-1;

    for(int i=0; i<n; i++){
        if(s[i] == max_char){
            if(first_occurence == -1){
                first_occurence = i;
            }else if (second_occurence == -1){
                second_occurence = i;
            }else break;
        }
    }

    // cout << "first_occurence is : " << first_occurence << ", and second_occurence is : " << second_occurence << nl;

    unordered_set<char> s1;
    unordered_set<char> s2;

    for(int i=0; i<n; i++){
        if(i< second_occurence){
            s1.insert(s[i]);
        }else{
            s2.insert(s[i]);
        }
    }

    cout << zz s1.size() + s2.size() << nl;
    return;


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}