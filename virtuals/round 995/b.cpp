#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(){
    int n, a, b, c; cin >> n >> a >> b >> c;
    // simulation is TLE

    int cover = a + b + c;

    int whole_sets = n/cover;
    int remaining = n%cover;

    whole_sets *= 3;
    
    if(remaining != 0){
        if(remaining <= a){
            cout << whole_sets + 1 << endl;
            return;
        }else if(remaining<=(a+b)){
            cout << whole_sets + 2 << endl;
            return;
        }else {
            cout << whole_sets + 3 << endl;
            return;
        }
    }else{
        cout << whole_sets << endl;
    }


}

int main(){
    int t; cin >> t;
    while(t--) solve();
}