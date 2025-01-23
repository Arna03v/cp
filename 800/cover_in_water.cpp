#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    // if we have three empty cells, we can place 2 water cells and get an infinite supply
    // if we dont have space for 3 empty cells, we need to place all water using the action 1
    bool have_space = false;
    int curr = 0;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '.'){
            curr++;
            if(curr == 3){
                have_space = true;
                break;
            }
        }else{
            curr = 0;
        }
    }

    if(have_space) cout << 2 << endl;
    else{
        int res = 0;
        for(char& c : s){
            if(c == '.') res++;
        }

        cout << res << endl;
    }


}

int main(){
    int t; cin >> t;
    while(t--) solve();
}