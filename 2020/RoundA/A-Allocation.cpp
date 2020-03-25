#include <bits/stdc++.h>

using namespace std;

int calculateMaxNumberOfHouses(int N, int B, vector<int> &A) {
    int result = 0;
    while (result < N and B >= A[result]) {
        B -= A[result];
        result++;
    }
    return result;
}

int main() {
    int T, N, B, Aj, maxNumberOfHouses;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N >> B;
        vector<int> A(N);
        for (int j = 0; j < N; ++j) {
            cin >> Aj;
            A[j] = Aj;
        }
        sort(A.begin(), A.end());
        maxNumberOfHouses = calculateMaxNumberOfHouses(N, B, A);
        cout << "Case #" << i << ": " << maxNumberOfHouses << "\n";
    }
    return 0;
}
