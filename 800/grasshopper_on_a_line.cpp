#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
InputCopy
3
10 2
10 3
3 4
OutputCopy
2
7 3
1
10
1
3
*/

void solve(){
    int x, k; cin >> x >> k;
    vector<int> res;

    while(x!=0){
        for(int i=x; i>0; i--){
            if(i%k != 0 && x-i >= 0){
                // can do this jump
                res.push_back(i);
                x -= i;
            }
        }
    }

    cout << res.size() << endl;
    for(int& el : res) cout << el << " ";
    cout << endl;
    
}

int main(){
    int t; cin >> t; while(t--) solve();
}