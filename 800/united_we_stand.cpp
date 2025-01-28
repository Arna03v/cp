#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int& i : nums) cin >> i;

    vector<int> c;
    vector<int> b;

    sort(nums.begin(), nums.end());
    if(nums[0] == nums.back()){ cout << -1 << endl; return;}
    else{
        // put all the greatest elements in c, the rest in b
        // that way c[i] cant divide b[i] as it is greater than b[i]
        sort(nums.rbegin(), nums.rend());

        if(nums[1] != nums[0]){
            c.push_back(nums[0]);
            for(int i=1; i<n; i++) b.push_back(nums[i]);
        }else{
            int i=1;
            while(nums[i] == nums[0]) i++;

            for(int j=i; j<n; j++)b.push_back(nums[j]);
            for(int j=0; j<i; j++)c.push_back(nums[i]);
        }
    }

    cout << "sizes are : " << b.size() << " " << c.size() << endl;
    for(int& el : b) cout << "--" << el << " ";
    cout << endl;
    for(int& el : c) cout << "--" << el << " ";
    cout << endl;

}

int main(){
    int t; cin >> t;
    while(t--) solve();
}