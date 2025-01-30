#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// is it possible to include every element in 2 subsets such that each of them is either even-even or odd-odd

void solve(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int& i : nums) cin >> i;

    int sum = 0;
    for(int i : nums) sum += i;

    if(sum % 2 == 1){
        cout << "No" << endl;
        return;
    }else cout << "Yes" << endl;

}

int main(){
    int t; cin >> t;
    while(t--) solve();
}