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
#include <queue>
using namespace std;

#define nl "\n"
#define int long long
#define zz "res is : " << 

// custom comparator for pq
class Compare{
    public:
        // {health, id}
        bool operator() (pair<int,int>& a, pair<int,int>& b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first < b.first;
        }
};


// gives TLE
void solve(){
    int n, k; cin >> n >> k; 

    // store the {health and the index}
    std::priority_queue<pair<int,int>,vector<pair<int,int> >, Compare > pq;

    for(int i=0; i<n; i++){
        int el;
        cin >> el;
        pq.push({el, i+1});
    }

    // now take the elements one by one and deal k damage
    while(pq.size() != 0){
        int index = pq.top().second;
        int health = pq.top().first;
        pq.pop();

        health -= k;

        if(health <= 0){
            cout << index << " ";
        }else{
            pq.push({health, index});
        }
    }

    cout << nl;

}

// lets save the health as a[i]%k; death order will only be determined by the last attack, till then they will just keep getting deplpeted which is useless
void solve2(){
    int n, k; cin >> n >> k; 

    // store the {health and the index}
    std::priority_queue<pair<int,int>,vector<pair<int,int> >, Compare > pq;

    for(int i=0; i<n; i++){
        int el;
        cin >> el;
        el %= k;
        if( el == 0) el = k;
        pq.push({el, i+1});
    }

    // now take the elements one by one and deal k damage
    while(pq.size() != 0){
        int index = pq.top().second;
        int health = pq.top().first;
        pq.pop();

        health -= k;

        if(health <= 0){
            cout << index << " ";
        }else{
            pq.push({health, index});
        }
    }

    cout << nl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve2();
}