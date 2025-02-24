#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

// set intersection works better with sets instead of vectors

void solve() {
    int a, b, xk, yk, xq, yq;
    cin >> a >> b;
    cin >> xk >> yk;
    cin >> xq >> yq;

    vector<pair<int, int>> dir = {
        {a, b}, {a, -b}, {-a, b}, {-a, -b},
        {b, a}, {b, -a}, {-b, a}, {-b, -a}
    };

    set<pair<int, int>> king_jumps;
    set<pair<int, int>> queen_jumps;

    // Generate possible knight moves from the king's position
    for (auto [dx, dy] : dir) {
        king_jumps.insert({xk + dx, yk + dy});
    }

    // Generate possible knight moves from the queen's position
    for (auto [dx, dy] : dir) {
        queen_jumps.insert({xq + dx, yq + dy});
    }

    // Count common positions where a knight can attack both king and queen
    int count = 0;
    for (auto pos : king_jumps) {
        if (queen_jumps.count(pos) == 1) {
            count++;
        }
    }

    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
