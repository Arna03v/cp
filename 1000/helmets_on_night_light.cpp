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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}