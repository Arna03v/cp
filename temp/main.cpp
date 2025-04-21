#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define int long long
// #define "res is : " << 

// b.size = n*k
// bi = ai for i = 0 to n-1
// for i >=n, bi = bi-n

void solve(){
    int n, k, x; cin >> n >> k >> x; vector<int> a(n);
    for(int& el : a) cin >> el;

    int total_sum = 0;
    for(int i = 0; i < n; i++) {
        total_sum += a[i];
    }
    int sum_of_one_iteration = total_sum;
    total_sum *= k;

    if(total_sum < x){
        cout << 0 << nl;
        return;
    }

    // vector<int> b(n*k);
    // for(int i=0; i<n*k; i++){
    //     b[i] = a[i%n];
    // }

    int number_of_times_it_can_divide = sum_of_one_iteration / x;
    int remaining_sum = sum_of_one_iteration % x;
    int l = n*k-1 - number_of_times_it_can_divide*n;
    int sum = 0;

    while(l >= 0 && sum + a[l%n] < remaining_sum){
        sum += a[l%n];
        l--;
    }

    if(l<0){
        cout << 0 << nl;
        return;
    }

    cout << l + 1 << nl;
    return;
}

void solve2() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (auto &el : a) cin >> el;

    vector<int> suffix(n + 1, 0);
    for (int i = n - 1; i >= 0; --i)
        suffix[i] = suffix[i + 1] + a[i];
    int S = suffix[0];

    int total = 0;
    for (int i = 0; i < n; ++i) {
        int sum_part = suffix[i];
        if (sum_part >= x) {
            total += k;
        } else {
            if (S <= 0) continue;
            int numerator = x - sum_part;
            if (numerator <= 0) continue;
            int required_m = (numerator + S - 1) / S; // Ceiling division
            if (required_m <= k - 1)
                total += (k - required_m);
        }
    }
    cout << total << nl;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve2();
}