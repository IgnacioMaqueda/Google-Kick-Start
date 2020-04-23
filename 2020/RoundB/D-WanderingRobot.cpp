#include <bits/stdc++.h>

using namespace std;

void fillMem(vector<vector<float> > &mem, const int W0, const int H0, const int W, const int H) {
    for (int i = H; i >= H0; --i) {
        for (int j = W; j >= W0; --j) {
            mem[i][j] = mem[i + 1][j] * 0.5 + mem[i][j + 1] * 0.5;
        }
    }
}

float probabilityOfPassing(const int W, const int H, const int L, const int U, const int R, const int D) {
    int newW = (U == 1 or R == W) ? L : min(W, R + 1);
    int newH = (L == 1 or D == H) ? U : min(H, D + 1);
    vector<vector<float> > mem(newH, vector<float>(newW));
    if (R == newW or U == 1 or R == W) {
        for (int i = 0; i < newW - 1; ++i) {
            mem[newH - 1][i] = 1;
        }
        fillMem(mem, 0, 0, newW - 2, newH - 2);
    } else if (D == newH or L == 1 or D == H) {
        for (int i = 0; i < newH - 1; ++i) {
            mem[i][newW - 1] = 1;
        }
        fillMem(mem, 0, 0, newW - 2, newH - 2);
    } else {
        for (int i = 0; i < newW - 1; ++i) {
            mem[newH - 1][i] = 1;
        }
        for (int i = 0; i < newH - 1; ++i) {
            mem[i][newW - 1] = 1;
        }
        fillMem(mem, 0, U - 1, L - 2, newH - 2);
        fillMem(mem, 0, 0, newW - 2, U - 2);
    }
    return mem[0][0];
}

int main() {
    int T, W, H, L, U, R, D;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> W >> H >> L >> U >> R >> D;
        if ((L == 1 and U == 1) or (R == W and D == H) or (L == 1 and R == W) or (U == 1 and D == H)) {
            cout << "Case #" << t << ": 0.0\n";
        } else {
            cout << "Case #" << t << ": " << probabilityOfPassing(W, H, L, U, R, D) << "\n";
        }
    }
}
