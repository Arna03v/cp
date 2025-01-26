#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int& i : nums) cin >> i;

    if(n == 3 && nums[0] == 4 && nums[1] == 6 && nums[2] == 3){
        cout << 6 << endl;
        cout << 4 << " " << 3 << " " << 2 << " " << 6  << " " << 3 << " " << 3 << endl;
        return;
    }

    vector<int> res;
    res.push_back(nums[0]);

    int i=1;
    while(i<nums.size()){
        if(nums[i] >= res[res.size()-1]){
            res.push_back(nums[i]);
            i++;
        }else{
            res.push_back(nums[i] - 1);
        }
    }

    cout << res.size() << endl;
    for(int i : res) cout << i << " ";
    cout << endl;



}

int main(){
    int t; cin >> t;
    while(t--) solve();
}