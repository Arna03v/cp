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
    int a, b, c, d; cin >> a >> b >> c >> d;

    if(b<=d&&c<=a+d-b) {
        cout<<(d-b)+(a+d-b-c)<<"\n";
    } else {
        cout<<"-1\n";
    }
}

int main(){
    int t; cin >> t; while(t--) solve();
}