#include <bits/stdc++.h>

using namespace std;

void calculateHorizontal(int R, int C, vector<vector<int> > &grid, vector<vector<int> > &left, vector<vector<int> > &right) {
    for (int i = 0; i < R; ++i) {
        left[i][0] = grid[i][0];
        for (int j = 1; j < C; ++j) {
            if (grid[i][j]) {
                left[i][j] = grid[i][j] + left[i][j - 1];
            }
        }
        right[i][C - 1] = grid[i][C - 1];
        for (int j = C - 2; j >= 0; --j) {
            if (grid[i][j]) {
                right[i][j] = grid[i][j] + right[i][j + 1];
            }
        }
    }
}

void calculateVertical(int R, int C, vector<vector<int> > &grid, vector<vector<int> > &up, vector<vector<int> > &down) {
    for (int j = 0; j < C; ++j) {
        up[0][j] = grid[0][j];
        for (int i = 1; i < R; ++i) {
            if (grid[i][j]) {
                up[i][j] = grid[i][j] + up[i - 1][j];
            }
        }
        down[R - 1][j] = grid[R - 1][j];
        for (int i = R - 2; i >= 0; --i) {
            if (grid[i][j]) {
                down[i][j] = grid[i][j] + down[i + 1][j];
            }
        }
    }
}

int countShapesInDirections(int R, int C, vector<vector<int> > &dir1, vector<vector<int> > &dir2) {
    int res = 0;
    int n1, n2;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            n1 = dir1[i][j] / 2;
            n2 = dir2[i][j];
            if (n1 > 1 and n2 > 1) {
                res += min(n1, n2) - 1;
            }
        }
    }
    return res;
}

int numberOfLShapes(int R, int C, vector<vector<int> > &grid) {
    vector<vector<int> > left(R, vector<int>(C));
    vector<vector<int> > right(R, vector<int>(C));
    vector<vector<int> > up(R, vector<int>(C));
    vector<vector<int> > down(R, vector<int>(C));
    calculateHorizontal(R, C, grid, left, right);
    calculateVertical(R, C, grid, up, down);
    int res = 0;
    res += countShapesInDirections(R, C, left, up);
    res += countShapesInDirections(R, C, left, down);
    res += countShapesInDirections(R, C, right, up);
    res += countShapesInDirections(R, C, right, down);
    res += countShapesInDirections(R, C, up, left);
    res += countShapesInDirections(R, C, up, right);
    res += countShapesInDirections(R, C, down, left);
    res += countShapesInDirections(R, C, down, right);
    return res;
}

int main() {
    int T, R, C;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> R >> C;
        vector<vector<int> > grid(R, vector<int>(C));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> grid[i][j];
            }
        }
        cout << "Case #" << t << ": " << numberOfLShapes(R, C, grid) << "\n";
    }
    return 0;
}
