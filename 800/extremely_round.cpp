#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
#include <cctype>
using namespace std;

int number_of_digits(string& s) {
    int res = 0;
    for (char c : s) {
        if (isdigit(c) && c != '0') {
            res++;
        }
    }
    return res;
}

void solve(){
    int n; cin >> n; 

    int res = 0;
    for(int i=1; i<=n; i++){
        string number = to_string(i);
        if(number_of_digits(number) <= 1){
            res++;
        }
    }
    cout << res << endl;
    return;


}

int main(){
    int t; cin >> t; while(t--) solve();
}