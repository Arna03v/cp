// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// int main(){

// }

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

// brture force n*m
void solve(){
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(m);
    vector<int> q(k);

    for(int& i : a) cin >> i;
    for(int& i : q) cin >> i;

    vector<bool> questions(n+1, false);
    for(int num : q){
        // num represents the question numbers he can solve
        questions[num] = true;
    }

    vector<int> res;

    // for each of the list that is asked
    for(int i=0; i<(int)a.size(); i++){
        bool can_solve_all = true;
        for(int j=1; j<n+1; j++){
            if(j==a[i]) continue; // as it doesnt contain this question
            if(questions[j] == false){
                can_solve_all = false;
            }
        }
        can_solve_all ? res.push_back(1) : res.push_back(0);
    }

    for(int i=0; i<res.size(); i++)cout << res[i];
    cout << endl;
    return;

}

// still n*m but with much more memory
void solve2(){
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(m); // contains the questions not in the i'th list
    vector<int> q(k); // contains the questions he can solve

    for(int& i : a) cin >> i;
    for(int& i : q) cin >> i;

    // keep track of the quetions of cant solve in a set
    // if a list contains any of those numbers, push false and break out
    unordered_set<int> can;
    unordered_set<int> all;
    for(int i=1; i<=n; i++){ 
        all.insert(i);
    }
    for(int i=0; i<q.size(); i++) can.insert(q[i]);

    vector<int> res;
    for(int i=0; i<a.size(); i++){
        all.erase(a[i]);
        if(std::includes(can.begin(), can.end(), all.begin(), all.end())){
            res.push_back(1);
        }else{
            res.push_back(0);
        }
        all.insert(a[i]);
    }

    for(int num : res) cout << num;
    cout << endl;
    return;

}

// O(n) solution bgy breaking it into cases
void solve3(){
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(m); // contains the questions not in the i'th list
    vector<int> q(k); // contains the questions he can solve

    for(int& i : a) cin >> i;
    for(int& i : q) cin >> i;

    vector<int> res;

    if(k == n){
        // he can solve all the quesitons
        for(int i=0; i<a.size(); i++) cout << 1;
        cout << endl;
        return;
    }
    if(k <= n-2){
        // since he doesnt know 2 or more answers, he cant solve any list
        for(int i=0; i<a.size(); i++) cout << 0;
        cout << endl;
        return;
    }
    if(k==n-1){
        // find the question you cant solve
        int cant = 0;
        for(int i=1; i<=n; i++) cant +=i;

        for(int i=0; i<q.size(); i++) cant -= q[i];

        // now cant contains the question he cannot solve
        for(int i=0; i<a.size(); i++){
            if(a[i] != cant){
                // he cant solve this list
                res.push_back(0);
            }else{
                res.push_back(1);
            }
        }

        for(int i=0; i<res.size(); i++) cout << res[i];
        cout << endl;
        return;

    }

}

int main(){
    int t; cin >> t;
    while(t--) solve3();
}