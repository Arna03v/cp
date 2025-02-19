#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

void solve(){
    int n; cin >> n; vector<int> nums(n);
    int count = 0;

    for(int& el : nums){
        cin >> el;
        if(el == 2) count++;
    }

    if(count%2 == 1) {
        cout << -1 << endl;
        return;
    }else if(count == 0){
        cout << 1 << endl;
        return;
    }else if(count%2 == 0){
        int mid = count/2;
        int tracker = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 2){
                tracker++;
                if(tracker == mid){
                    cout << i+1 << endl;
                    return;
                }
            }
        }
    }

}

int main(){
    int t; cin >> t; while(t--) solve();
}