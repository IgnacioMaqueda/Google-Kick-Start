#include <bits/stdc++.h>

using namespace std;

int minAdded(int R, int C, vector<vector<int> > &grid, int i, int j, vector<pair<int, int> > &peaks) {
    int res = 0;
    int cellDistance, heightDistance;
    for (auto peak : peaks) {
        cellDistance = abs(peak.first - i) + abs(peak.second - j);
        heightDistance = grid[peak.first][peak.second] - grid[i][j];
        if (heightDistance > cellDistance) {
            res = max(res, heightDistance - cellDistance);
        }
    }
    return res;
}

void obtainPeaks(int R, int C, vector<vector<int> > &grid, vector<pair<int, int> > &peaks) {
    int max = -1;
    int iMax, jMax;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] > max) {
                iMax = i;
                jMax = j;
                max = grid[i][j];
            }
        }
    }
    peaks.push_back({iMax, jMax});
    int cellDistance, heightDistance;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cellDistance = abs(i - iMax) + abs(j - jMax);
            heightDistance = max - grid[i][j];
            if (heightDistance < cellDistance) {
                peaks.push_back({i, j});
            }
        }
    }
}

long minNumberOfBoxes(int R, int C, vector<vector<int> > &grid) {
    long res = 0;
    vector<pair<int, int> > peaks;
    obtainPeaks(R, C, grid, peaks);
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            res += minAdded(R, C, grid, i, j, peaks);
        }
    }
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
        cout << "Case #" << t << ": " << minNumberOfBoxes(R, C, grid) << "\n";
    }
    return 0;
}
