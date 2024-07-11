 #include <cstdio>
#include <iostream>

using namespace std;

int main(void) {
    freopen("alienin.txt", "r", stdin);
    freopen("alienout.txt", "w", stdout);
    
    // Getting input
    int n, w;
    cin >> n >> w;

    int positions[n];
    for (int i = 0; i < n; i++) {cin >> positions[i];}

    // Convert to array with ones and zeroes

    int maxPos = positions[n-1];
    int allPositions[maxPos+1];

    for (int i = 0; i <= maxPos; i++) {allPositions[i] = 0;}
    for (int i = 0; i < n; i++) {allPositions[positions[i]] = 1;}

    int count = 0;
    int possible = 0;

    for (int i = 0; i < w && i <= maxPos; i++) {
        if (allPositions[i] == 1) {
            count++;
        }
    }

    possible = max(possible, count);

    // Sliding window of width w
    for (int i = 1, j = i + w - 1; j <= maxPos; i++, j++) {
        // cout << i << " " << j << endl;
        if (allPositions[i-1] == 1) {
            count--;
        }

        if (allPositions[j] == 1) {
            count++;
        }

        possible = max(possible, count);
    }

    cout << possible;
    return 0;
}