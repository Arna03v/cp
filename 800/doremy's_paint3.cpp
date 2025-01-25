#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

// determine if we can can arrange the array in a way that nums[0] + nums[1] == nums[1]+nums[2] ... = some k

int noe(vector<int>& nums){
    set<int> s;
    for(int& i : nums) s.insert(i);

    return s.size();
}

int count(int i, vector<int>& nums){
    int res = 0;
    for(int& j : nums){
        if(i == j) res++;
    }

    return res;
}

void solve(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int& num : nums) cin >> num;

    // the array can have only 2 numbers with fixed frequency for this to happen

    if(n <= 2){
        cout << "YES" << endl;
        return;
    }

    sort(nums.begin(), nums.end());
    int smaller = nums[0];
    int larger = nums[n-1];

    if (noe(nums) > 2) {
        cout << "NO" << endl;
        return;
    }

    if(smaller == larger){
        cout <<"YES" << endl;
        return;
    }

    if(n%2 == 0){
        if(count(smaller, nums) != count(larger, nums)){
            cout << "NO" << endl;
            return;
        }
    }else{
        if(abs(count(smaller, nums) - count(larger,nums)) != 1){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;


}

int main(){
    int t; cin >> t;
    while(t--)solve();
}