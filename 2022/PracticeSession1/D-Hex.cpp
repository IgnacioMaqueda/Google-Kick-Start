#include <bits/stdc++.h>

using namespace std;

// Orientations: NE, E, SE, SW, W, NW
vector<pair<int, int> > nexts = {{-1, 1},
                                 {0,  1},
                                 {1,  0},
                                 {1,  -1},
                                 {0,  -1},
                                 {-1, 0}};

void countStones(int N, vector<string> &board, int &reds, int &blues) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == 'R') {
                ++reds;
            } else if (board[i][j] == 'B') {
                ++blues;
            }
        }
    }
}

bool in_limits(int row, int column, int N) {
    return 0 <= row and row < N and 0 <= column and column < N;
}

bool blueCompletedOnce(int N, vector<string> &board) {
    int row, column, orientation, next_row, next_column;
    for (int i = 0; i < N; ++i) {
        if (board[i][0] == 'B') {
            row = i;
            column = 0;
            orientation = 0;
            board[row][column] = 'b';
            while (column != N - 1 and (row != i or column != 0 or orientation != 5)) {
                next_row = row + nexts[orientation].first;
                next_column = column + nexts[orientation].second;
                if (in_limits(next_row, next_column, N) and
                    (board[next_row][next_column] == 'B' or board[next_row][next_column] == 'b')) {
                    row = next_row;
                    column = next_column;
                    orientation = (orientation + 6 - 1) % 6;
                    board[row][column] = 'b';
                } else {
                    orientation = (orientation + 1) % 6;
                }
            }
            if (column == N - 1) {
                return true;
            }
        }
    }
    return false;
}

bool blueCompletedTwice(int N, vector<string> &board) {
    int row, column, orientation, next_row, next_column;
    for (int i = 0; i < N; ++i) {
        if (board[i][0] == 'B') {
            row = i;
            column = 0;
            orientation = 0;
            while (column != N - 1 and (row != i or column != 0 or orientation != 5)) {
                next_row = row + nexts[orientation].first;
                next_column = column + nexts[orientation].second;
                if (in_limits(next_row, next_column, N) and board[next_row][next_column] == 'B') {
                    row = next_row;
                    column = next_column;
                    orientation = (orientation + 6 - 1) % 6;
                } else {
                    orientation = (orientation + 1) % 6;
                }
            }
            if (column == N - 1) {
                return true;
            }
        }
    }
    return false;
}

bool redCompletedOnce(int N, vector<string> &board) {
    int row, column, orientation, next_row, next_column;
    for (int j = 0; j < N; ++j) {
        if (board[N - 1][j] == 'R') {
            row = N - 1;
            column = j;
            orientation = 5;
            board[row][column] = 'r';
            while (row != 0 and (row != N - 1 or column != j or orientation != 4)) {
                next_row = row + nexts[orientation].first;
                next_column = column + nexts[orientation].second;
                if (in_limits(next_row, next_column, N) and
                    (board[next_row][next_column] == 'R' or board[next_row][next_column] == 'r')) {
                    row = next_row;
                    column = next_column;
                    orientation = (orientation + 6 - 1) % 6;
                    board[row][column] = 'r';
                } else {
                    orientation = (orientation + 1) % 6;
                }
            }
            if (row == 0) {
                return true;
            }
        }
    }
    return false;
}

bool redCompletedTwice(int N, vector<string> &board) {
    int row, column, orientation, next_row, next_column;
    for (int j = 0; j < N; ++j) {
        if (board[N - 1][j] == 'R') {
            row = N - 1;
            column = j;
            orientation = 5;
            while (row != 0 and (row != N - 1 or column != j or orientation != 4)) {
                next_row = row + nexts[orientation].first;
                next_column = column + nexts[orientation].second;
                if (in_limits(next_row, next_column, N) and board[next_row][next_column] == 'R') {
                    row = next_row;
                    column = next_column;
                    orientation = (orientation + 6 - 1) % 6;
                } else {
                    orientation = (orientation + 1) % 6;
                }
            }
            if (row == 0) {
                return true;
            }
        }
    }
    return false;
}

string findBoardStatus(int N, vector<string> &board) {
    int reds = 0;
    int blues = 0;
    countStones(N, board, reds, blues);
    if (max(reds, blues) - min(reds, blues) > 1) {
        return "Impossible";
    }
    if (max(reds, blues) < N) {
        return "Nobody wins";
    }
    if (blueCompletedOnce(N, board)) {
        if (blues < reds or blueCompletedTwice(N, board)) {
            return "Impossible";
        } else {
            return "Blue wins";
        }
    } else if (redCompletedOnce(N, board)) {
        if (blues > reds or redCompletedTwice(N, board)) {
            return "Impossible";
        } else {
            return "Red wins";
        }
    } else {
        return "Nobody wins";
    }
}

int main() {
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        vector<string> board(N);
        for (int i = 0; i < N; ++i) {
            cin >> board[i];
        }
        cout << "Case #" << t << ": " << findBoardStatus(N, board) << "\n";
    }
    return 0;
}
