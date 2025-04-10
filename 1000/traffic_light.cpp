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

int solve2(string s, int i){
    // traverse the string multiple times until color is green
    int time = 0;

    while(true){
        if(s[i] == 'g') break;

        // not green so move forward by one index
        i = (i+1)%s.size();
        time++;
    }
    return time;
}

// can only cross when color is green
// we know the color but not the moment of time


// TLE -> worst case(rrrrrr...grrrrrr) -> O(n^2), we cannot do more than nlogn
void solve(){
    int n; cin >> n; // length of the string-> traffic lights repeat every n seconds
    
    char c; cin >> c; // color of the current light

    string s; cin >> s; // the sequence of lights

    int res = INT_MIN;

    for(int i=0; i<n; i++){
        if(s[i] == c){
            res = max(solve2(s,i), res);
        }
    }

    cout << res << nl;
}


// gives O(n)
void solve2(){
    int n; cin >> n; // length of the string-> traffic lights repeat every n seconds
    char c; cin >> c; // color of the current light
    string s; cin >> s; // the sequence of lights

    // we can also append the string to itself, since we are guarenteed to find the result in the first 2 occurences of s
    s+=s;

    // we can search in the first half of this new string for the occurences of color 'c'
    // goingforward might not give the solution all the time
    // what if go backwards

    // keep track of the index of the latest 'g'
    // when we find 'c' in the first half, find index of g - curr index
    // store the max values of last occurence of g - curr_index

    int res = INT_MIN;
    int last_green = -1;
    
    for(int i=s.size()-1; i>=0; i--){
        if(s[i] == 'g') last_green = i;

        if(s[i] == c){
            if(i<n) res = max(res, last_green - i);
        }
    }

    cout << res << nl;
    return;
}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve2();
}