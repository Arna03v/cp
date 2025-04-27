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


// remove the first character
// remove the second character

void remove_second_last(string s);
set<string> t;

void remove_last(string s){

    if(s.empty()){
        return;
    }

    // remove the last character of a string
    s.pop_back();

    if(t.find(s) == t.end()){
        // this new string does not belong to the set
        t.insert(s);
    }

    remove_last(s);
    remove_second_last(s);
}

void remove_second_last(string s){

    if(s.size() == 1) remove_last(s);
    else if(s.size() == 0) return;

    // can only do something if there are atleast two elements
    s.erase(s.begin() + (s.size() - 2));

     if(t.find(s) == t.end()){
        // this new string does not belong to the set
        t.insert(s);
    }

    remove_last(s);
    remove_second_last(s);

}

void solve(){
    int n; cin >> n; string s; cin >> s;

    // if we reverse the string, same as removing last or second last
    // removing last is O(1)
    // removing second last is O(n)
    // removing first is O(n)
    // removing second is O(n)

    reverse(s.begin(), s.end());

    t.insert(s);

    remove_last(s);
    remove_second_last(s);

    cout << zz t.size() << nl;
    return;
}

// maybe the logic is getting too complicated
// lets just do without the optimidation

set<string> seen;
unordered_map<string, int> m; // m[string] = number of strings that can be generated from the current string as the base

void recurse(string s){
    // base case
    if(s.empty() || seen.count(s)){
        // it has nothing to delete from || already exists in the set
        return;
    }

    seen.insert(s);

    if(s.size() >= 1){
        recurse(s.substr(1)); // substring from index 1
    }

    if(s.size() >= 2){
        string t = s;
        t.erase(1,1); // from index 1 to index 1
        recurse(t);
    }
}

void solve2(){
    int n; cin >> n; string s; cin >> s;
    seen.clear(); // just a good practice

    recurse(s);

    cout << seen.size() << nl;
    return;

}

// f ->f is same as s -> f; might as well stick with f->f
// which means once we start removing the second letter
// removing the first letter is redundant, so from then on we should just remove second letters
    // as that string can be achieved by more first letter delettions


// once we start applying `s`, stick with `s` dont do more `f`
// this way we reduce the reduandant paths

// if we ahve `k` rounds of removal, n-k-1 characters from the end remoin
    // at rhe same level, the last n-k-1 characters are same after `k` removals

// which means s == t, iff
    // they have the same number of removals
    // their first character is the same

// now we will apply x `f` and the n-x `s` operations for string `t`

// if we have 2 same strings, then their second letter deletions are redundant, just take one path from this group
// redumdant because their first character remains the same

// we finf the first occurence of each letter in string s

map<char, int> ma;

void solve3(){
    int n; cin >> n; string s; cin >> s;

    for(int i=0; i<n; i++){
        char c = s[i];

        if(ma.find(c) == ma.end()){
            // this character is not in the map yet
            ma[c] = i;
        }


    }

    int res = 0;
    for(auto [ch, index] : ma){
        res += n - index;
    }

    cout << res << nl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve3();
}

// #include <iostream>
// #include <unordered_set>
// #include <string>
// using namespace std;

// unordered_set<string> seen;

// void generate(string s) {
//     if (s.empty() || seen.count(s)) return;
//     seen.insert(s);

//     // Try removing the first character
//     if (s.size() >= 1) generate(s.substr(1));

//     // Try removing the second character
//     if (s.size() >= 2) {
//         string temp = s;
//         temp.erase(1, 1);
//         generate(temp);
//     }
// }

// void solve() {
//     int n; cin >> n;
//     string s; cin >> s;
//     seen.clear();

//     generate(s);
//     cout << "res is : " << seen.size() << "\n";
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t; cin >> t;
//     while (t--) solve();
// }



#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
 
using namespace std;
 
// find_by_order, order_of_key: 0 indexed
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
// Add the necessary include paths to the compiler flags
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
 
#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)
const int INF = 1e9+10;
 
 
// Control Flow
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)
// #define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
// Types
#define ui unsigned int
#define us unsigned short
#define ull unsigned long long
#define ll long long
#define ld long double
#define vstr vector<string>
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
 
// Utils
#define len(x) int((x).size())
#define pb push_back
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()
 
// Constants
const ll MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// Helper Functions
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }
ll getRandomNumber(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
ll nCk(ll n, ll k){
	ll res = 1;
	for (ll i = 0; i < k; i++)
	{
		res = res * (n - i);
		res = res / (i + 1);
	}
	return res;}
 
 
/*
    ___        __              __   ______          __        _____ __             __          __  __
   /   | _____/ /___  ______ _/ /  / ____/___  ____/ /__     / ___// /_____ ______/ /______   / / / /__  ________
  / /| |/ ___/ __/ / / / __ `/ /  / /   / __ \/ __  / _ \    \__ \/ __/ __ `/ ___/ __/ ___/  / /_/ / _ \/ ___/ _ \
 / ___ / /__/ /_/ /_/ / /_/ / /  / /___/ /_/ / /_/ /  __/   ___/ / /_/ /_/ / /  / /_(__  )  / __  /  __/ /  /  __/
/_/  |_\___/\__/\__,_/\__,_/_/   \____/\____/\__,_/\___/   /____/\__/\__,_/_/   \__/____/  /_/ /_/\___/_/   \___/
*/
 
void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
 
	//find first occurrence of each letter in 's'
	map<char,int> mp;
	for(int i=0; i<n; i++){
		char ch = s[i];
		if(mp.find(ch) == mp.end())
			mp[ch] = i; 
	}
	ll total = 0;
	for(auto [ch,idx]: mp){
		total += (n-idx);
	}
	cout<<total<<nl;
 
}	
 
/*aaba; idx = 0; len = 4
  aba
  aa
  a
 
  aba; idx=0;len=3
  aa
  a
 
 
*/
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int t=1;
	cin>>t;
	while(t--)
		solve();
}