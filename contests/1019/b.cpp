// #include <bits/stdc++.h>
// using namespace std;

// // initially the finger is on 0
// // there are only 2 buttons, 0 and 1

// // ops
//     // press the button the finger is on
//     // move  the finger to the other button

// // cost(string) = minimum number of operations to type the string
// // before every typing; we can reverse atmost one substring of the whole string

// // find min cost to make s; by doing atmost one substring reversal

// void solve(){
//     int n; cin >> n; string s; cin >> s;

//     vector<int> left(n), right(n);
//     // left is the cost to build the string from left to index i
//     // right is the cost to build the string from right to index i

//     int cost = 0;
//     int curr = 0;
//     for(int i=0; i<n; i++){

//         if(s[i] == curr){
//             cost++;
//             left[i] = cost;
//         }else{
//             cost +=2;
//             if(curr == 0)curr =1;
//             else curr = 1;
//             left[i] = cost;
//         }
//     }

//     curr = 0;
//     cost = 0;

//     for(int i=n-1; i>=0;  i--){
//         if(s[i] == curr){
//             cost++;
//             right[i] = cost;
//         }else{
//             cost += 2;
//             if(curr == 0)curr =1;
//             else curr = 1;
//             right[i] = cost;
//         }
//     }

//     int mini = INT_MAX;

//     for(int i=0; i<n; i++){
//         mini = min(mini, left[i] + right[i]);
//     }

//     cout << mini << endl;
//     return;


// }

// int main(){
//     int t; cin >> t; while(t--) solve();
// }

// reversing can help us reduce the 0->1 and 1->0  transitions
// this is the only way it can help

#include <bits/stdc++.h>
using namespace std;

int total_transitions;
int count_01;
int count_10;

void pre_process(string s){
    char curr = '0';

    for(int i=0; i<s.size(); i++){
        // cout << "for i : " << i << "s[i] = " << s[i] << ", curr = " << curr << "->";
        if(s[i] != curr){
            // increase the number of transitions

            // cout << "for the index: " << i << ", TT++ ->";

            total_transitions++;
            if(curr == '0')count_01++;
            else count_10++;
            
        }

        // change the curr
        curr = s[i];
    }
}

void solve(){
    int n; cin >> n; 
    string s; cin >> s;

    total_transitions = 0;
    count_01 = 0; // how many 01 transitions
    count_10 = 0;

    pre_process(s);
    // how much can we gain
    // even if we reverse  a string
    // the cost of making the substring being reversed does not change
    // the cost an only change at the ends
    // max gain can be of 2 operations

    // for gaining 2 operations
    // we need atleast 2 of 01 or 10
    // 0101 -> 0110 (4 -> 2)

    // cout << "total transitions are : " << total_transitions << "->"
    // cout << "count_01 : " << count_01 << ", count_10 : " << count_10 << "->";

    if(!total_transitions) {cout << n << endl; return;}

    int saving = 0;

    if(count_01 >=2 || count_10 >= 2) saving = 2;

    // what happens when we max one of each
    // 111111001 -> can save one transition
    // but we need one of each
    // if we have a 01, the next one has to be a 10
    else if(total_transitions >= 2) saving = 1;
    else saving = 0;

    // total cost = typing all charcters + cost of all transitions - how many can we gain at best
    int res = n + total_transitions - saving;
    cout << res << endl;
    return;


}

int main(){
    int t; cin >> t; while(t--) solve();
}
