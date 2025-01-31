// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// int main(){

// }

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

void solve(){
    int n, x, y; cin >> n >> x >> y;
    int sum = 0;
    vector<int> nums(n);
    for(int& i : nums) {
        cin >> i;
        sum += i;
    }

    // brute force is very simple but n^2 will give TLE
    // storing in a pair and sorting will do something 
    vector<pair<int,int> > a;
    for(int i=0; i<nums.size(); i++){
        a.push_back(make_pair(nums[i], i));
    }

    sort(a.begin(), a.end());

    // for(pair<int,int> p : a){
    //     cout << p.first << "->" << p.second << ", ";
    // }
    // cout << endl;
    int smallest=INT_MAX;
    int largest=INT_MIN;

    for(int i=0; i<a.size(); i++){
        if(a[i].first >= (sum - y)){
            smallest = min(smallest,i);
            break;
        }
    }

    if(smallest == INT_MAX) smallest = 0;

    for(int i=a.size()-1; i>= 0; i--){
        if(a[i].first <= (sum - x)){
            largest = max(largest,i);
            break;
        }
    }

    if(largest == INT_MIN) largest = a.size()-1;

    // cout << "smallest is : " << smallest << ", largest is : " << largest << endl;

    int res = 0;

    for(int i=smallest; i<= largest; i++){
        for(int j=i+1; j<=largest; j++){
            if(x <= sum - a[i].first - a[j].first <= y && a[i].second < a[j].second)res++;
        }
    }

    cout << "res is : " << res;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}
