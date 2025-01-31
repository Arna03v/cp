#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for(int& i : a) cin >> i;
    for(int& i : b) cin >> i;

    // if (a[i] > b[i+1]) he solves on i
    // and solve on last day of a[i]

    int sum = 0;
    for(int i=0; i<n-1; i++){
        if(a[i] > b[i+1]){
            sum += (a[i] - b[i+1]);
        }
    }

    sum += a[n-1];
    cout << sum << endl;
    return;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}