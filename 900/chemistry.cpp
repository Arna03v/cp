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
using namespace std;

/*
Let's remember under what conditions we can rearrange the letters of a word to form a palindrome. This can be done if the number of letters with odd occurrences is not greater than 1
.

In our problem, it is sufficient to check that the number of letters with odd occurrences (denoted as 𝑥
) is not greater than 𝑘+1
. Let's prove this fact.

If 𝑥>𝑘+1
, then it is definitely impossible to obtain the answer, because with 𝑘
 operations we cannot make the number of letters with odd occurrences not greater than 1
. On the other hand, we can simply remove the character with an odd number of occurrences on each removal iteration and decrease the number of odd occurrences. If there are no such characters, we can choose any character and remove it, thus having 1
 character with an odd occurrence.
*/

// read the constraints and bounds correctly

void solve(){
    int n,k; cin >> n >> k; 
    string s; cin >> s;

    unordered_map<char,int> m;
    for(char& c : s){
        m[c]++;
    }

    // after removing k letters
    // either all should be even
    // or atmost one should be odd

    int even_count = 0;
    int odd_count = 0;

    for(auto& [chr, count] : m){
        if(count % 2 == 0)even_count++;
        else odd_count++;
    }

    // cout << "odd count is :" << odd_count << "->";
    for(auto& [chr, count] : m){
        if(count % 2 == 1){
            // cout << "char :" << chr << ", count : " << count;

        }
    }

    // cout << endl;

    if(odd_count > k + 1) cout << "NO" << endl;
    else cout << "YES" << endl;

}

int main(){
    int t; cin >> t; while(t--) solve();
}