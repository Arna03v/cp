#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// After what minimum number of operations s will appear in x as a substring?

// check if s is a substring of x
bool belongs_to(string& s, string& x){
    return x.find(s) != string::npos;
}

void solve(){
    int n, m; cin >> n >> m;
    string x; cin >> x; // length n
    string s; cin >> s; // length m

    // look at the constraints, n.m <= 25, worst case is n=1 and m=25 which will need 5 operations
    // so if after 5 operations, s doesnt not belong to x, print -1
    // basically brute force

    int number_of_operations = 0;
    while(number_of_operations < 6){
        // check if s belongs to x
        if(belongs_to(s,x)){
            cout << number_of_operations << endl;
            return;
        }else{
            x = x + x;
            number_of_operations++;
        }
    }

    cout << -1 << endl;


}

int main(){
    int t; cin >> t;
    while(t--) solve();
}