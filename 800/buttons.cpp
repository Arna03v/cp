#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void solve(){
    int a,b,c; cin >> a >> b >> c;

    // cout << "for a b c : " << a << b << c << endl;
    
    if(a==b){
        if(c%2 == 1){
            cout << "First" << endl;
            return;
        }else{
            cout << "Second" << endl;
            return;
        }
    }
    else if(a > b+c){
        cout << "First" << endl;
        return;
    }else if(b > a+c){
        cout << "Second" << endl;
        return;
    }else if (a + ceil(c/2) > b + floor(c/2))
    {
        cout << "First" << endl;
        return;
    } else if(a + ceil(c/2) < b + floor(c/2)){
        cout << "Second" << endl;
        return;
    }

}

int main(){
    int t; cin >> t; 
    while(t--) solve();
}