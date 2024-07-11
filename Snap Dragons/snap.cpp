#include <iostream>

using namespace std;

int main() {
    freopen("snapin.txt", "r", stdin);
    freopen("snapout.txt", "w", stdout);
    int R, S;
    cin >> R >> S;
    
    int maximum = 0;
    int temp;
    
    int rose[R];
    int scarlet[S];

    for (int i = 0; i < R; i++) {
        cin >> rose[i]; maximum = max(maximum, rose[i]);
    }

    for (int i = 0; i < S; i++) {
        cin >> scarlet[i]; maximum = max(maximum, scarlet[i]);
    }

    int roseFrequency[maximum+1];
    int scarletFrequency[maximum+1];

    for (int i = 1; i < maximum+1; i++) {
        roseFrequency[i] = 0;
        scarletFrequency[i] = 0;
    }

    for (int i:rose) {
        roseFrequency[i]++;
    }

    for (int i:scarlet) {
        scarletFrequency[i]++;
    }

    int pairsCount = 0;
    for (int i = 1; i < maximum+1; i++) {
        pairsCount += (roseFrequency[i] * scarletFrequency[i]);
    }
    cout << pairsCount;
} 