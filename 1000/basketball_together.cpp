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

// each player might join atmost 1 team
// form 0 or more teams 
// if power(team) > d, victory

// power of each team = power(bes player in the team)
// return max number of wins

// gives a runtime error -> maybe a index issue?
void solve(){
    int n, d; cin >> n >> d; vector<int> nums(n);
    for(int& el : nums) cin >> el;

    sort(nums.rbegin(), nums.rend());

    int best_player = 0;
    int worst_player = n-1;

    int res = 0;

    while(best_player <= worst_player){
        int number_of_players = (d + nums[best_player] - 1)/nums[best_player]; // ceil 

        if (worst_player + 1 < best_player + number_of_players) break; // Not enough players to form a team

        best_player++;
        worst_player -= (number_of_players - 1);
        res++;
    }

    cout << "res is : " << res << '\n';
}

// a for loop implementation
void solve2(){
    int n, d; cin >> n >> d; vector<int> nums(n);
    for(int& el : nums) cin >> el;

    sort(nums.rbegin(), nums.rend());

    int res = 0; // number of teams
    int remaining_players = n;

    for(int i=0; i<n; i++){
        int best_player = nums[i];

        int number_of_players = 1 + d/best_player;

        if(number_of_players <= remaining_players){
            res += 1;
            remaining_players -= number_of_players;
        }else break;
    }

    cout << zz res << nl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve2();
}