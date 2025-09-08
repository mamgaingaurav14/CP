//magic square
  #include <bits/stdc++.h>
using namespace std;
#define lil long long int


vector<vector<int>> generateMagicSquare(int n) {
    if (n % 2 == 0) {
        throw invalid_argument("Magic square generation is supported only for odd orders.");
    }

    vector<vector<int>> magicSquare(n, vector<int>(n, 0));
    int num = 1;
    int i = 0, j = n / 2; // Start at middle of first row

    while (num <= n * n) {
        magicSquare[i][j] = num++;
        int new_i = (i - 1 + n) % n; // Move up (wrap around if needed)
        int new_j = (j + 1) % n;     // Move right (wrap around if needed)

        if (magicSquare[new_i][new_j] != 0) {
            // Cell is already filled, move down one row instead
            i = (i + 1) % n;
        } else {
            i = new_i;
            j = new_j;
        }
    }

    return magicSquare;
}



// Function to print the magic square
void printMagicSquare(const vector<vector<int>>& magicSquare) {
    for (const auto& row : magicSquare) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}