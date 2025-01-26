#include <iostream>
#include <vector>
#include <string>
using namespace std;

int score(const vector<string>& grid) {
    int totalScore = 0;
    vector<int> ringScores = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        int points = ringScores[i];

        // Top and bottom rows for the current ring
        for (int j = i; j < 10 - i; j++) {
            if (grid[i][j] == 'X') totalScore += points;
            if (grid[9 - i][j] == 'X') totalScore += points;
        }

        // Left and right columns for the current ring
        for (int j = i + 1; j < 9 - i; j++) {
            if (grid[j][i] == 'X') totalScore += points;
            if (grid[j][9 - i] == 'X') totalScore += points;
        }
    }

    return totalScore;
}

void solve() {
    vector<string> grid(10);
    for (int i = 0; i < 10; i++) {
        cin >> grid[i];
    }

    int result = score(grid);
    cout << result << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}