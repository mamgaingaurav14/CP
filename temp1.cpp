#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
#define lil long long int

// Right, down, left, up directions
vector<vector<lil>> directions = {{0,1}, {-1,0}, {0,-1}, {1,0}};
unordered_map<char,lil> mapp = {{'R', 0}, {'D', 1}, {'L', 2}, {'U', 3}};
vector<vector<int>> visited(7, vector<int>(7, 0));

bool isDeadEnd(lil i, lil j) {
    // Checking if the current position is boxed in (no way to move)
    return (i > 0 && visited[i-1][j]) && (i < 6 && visited[i+1][j]) &&
           (j > 0 && visited[i][j-1]) && (j < 6 && visited[i][j+1]);
}

void dfs(string &given, lil index, lil &cnt, lil i, lil j) {
    if (index == 48) {
        if (i == 0 && j == 0) cnt++;
        return;
    }
    if (i < 0 || j < 0 || i > 6 || j > 6 || visited[i][j] == 1) return;

    // Pruning: If it's impossible to reach (0,0) in the remaining steps, return early
    if (abs(i - 0) + abs(j - 0) > 48 - index) return;

    // Mark the cell as visited
    visited[i][j] = 1;

    // Check for deadlock: If this cell is boxed in, return early
    if (isDeadEnd(i, j)) {
        visited[i][j] = 0;
        return;
    }

    // If the character is a '?', try all 4 directions
    if (given[index] == '?') {
        for (auto &dir : directions) {
            lil ni = i + dir[0];
            lil nj = j + dir[1];
            dfs(given, index + 1, cnt, ni, nj);
        }
    } else {
        // Move in the given direction
        lil move = mapp[given[index]];
        lil ni = i + directions[move][0];
        lil nj = j + directions[move][1];
        dfs(given, index + 1, cnt, ni, nj);
    }

    // Backtrack and unmark the current cell
    visited[i][j] = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string given;
    cin >> given;
    
    lil cnt = 0;
    lil i = 6, j = 0;
    
    dfs(given, 0, cnt, i, j);
    
    cout << cnt;
}
