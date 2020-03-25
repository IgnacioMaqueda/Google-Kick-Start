#include <bits/stdc++.h>

using namespace std;

int calculateMaxBeauty(int N, const string& beautyScores) {
    int res = 0;
    int d = 0;
    int h = (N + 1) / 2;
    for (int i = d; i < h; ++i) {
        res += beautyScores[i] - '0';
    }
    int actual = res;
    while (h < N) {
        actual += beautyScores[h] - '0';
        actual -= beautyScores[d] - '0';
        if (actual > res) {
            res = actual;
        }
        d++;
        h++;
    }
    return res;
}

int main() {
    int T, N, maxBeauty;
    string beautyScores;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N >> beautyScores;
        maxBeauty = calculateMaxBeauty(N, beautyScores);
        cout << "Case #" << i << ": " << maxBeauty << "\n";
    }
    return 0;
}
