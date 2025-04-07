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

bool custom_sort(pair<int,int> &a, pair<int,int>& b){
    if(a.first == b.first){
        return a.second < b.second; // ascending order
    }

    return a.first > b.first; // descending order
}

// this only gives the shars from Pak, we also need shares from residents to other residents
void solve(){
    int n, p; cin >> n >> p; vector<int> a(n), b(n);
    for(int& el : a) cin >> el; // max number of residents each resident can share announcement to
    for(int& el : b) cin >> el; // cost for each resident to share annonuncement to another resident

    // store in <number of people, cost per person>
    // sort in descending order by number of people, lower cost = better

    // choose the first 'x' such that their number of people = n
    // pak needs to share it only those people

    


    vector<pair<int,int> > nums;
    for(int i=0; i<n; i++){
        nums.push_back({a[i], b[i]});
    }

    sort(nums.begin(), nums.end(), custom_sort);

    int final_cost = 0;
    int to_send = n;
    int i = 0;
    while(to_send > 0){
        final_cost += p;
        to_send -= nums[i].first;
        i++;
    }

    cout << zz final_cost << nl;
    return;


}

// notice that n residents = n shares; some from Pak and rest from the residents themselves
// pak has unlimited shares at some cost p, othershave limited shares a[i] at cost b[i]
// pak must share to atleast 1 resident in the beginning
// after this there can be n-1 shares 
// now share using the cheapest share/using pak
// can be done using proiority queue/sorting
// O(nlogn)

void solve2(){
    int n, p; cin >> n >> p; vector<int> a(n), b(n);
    for(int& el : a) cin >> el; // max number of residents each resident can share announcement to
    for(int& el : b) cin >> el; // cost for each resident to share annonuncement to another resident

    // push in {cost, number of people} and then sort 
    vector<pair<int,int> > nums;

    nums.push_back({p, n + 1}); // when pak sends it
    for(int i=0; i<n; i++){
        nums.push_back({b[i], a[i]});
    }

    sort(nums.begin(), nums.end());

    int res = p; // sending to atleast one person
    int informed = 1;
    int i=0;

    while(informed < n){
        int remaining = n - informed;

        int curr_cost = nums[i].first;
        int curr_capacity = nums[i].second;

        if(curr_capacity <= remaining){
            // we can use these guys
            res += curr_capacity*curr_cost;
            informed += curr_capacity;
        }else{
            res += curr_cost*remaining;
            informed = n;
        }

        i++;
    }

    cout << res << nl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve2();
}