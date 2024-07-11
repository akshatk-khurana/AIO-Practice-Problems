#include <iostream>
using namespace std;

int main() {
    freopen("snapin.txt", "r", stdin);
    freopen("snapout.txt", "w", stdout);
    int R, S;
    cin >> R >> S;
    
    int rose[R];
    int scarlet[S];
    
    for (int i = 0; i < R; i++) {
        cin >> rose[i];
    }

    for (int i = 0; i < S; i++) {
        cin >> scarlet[i];
    }

    int pairsCount = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < S; j++) {
            if (rose[i] == scarlet[j]) {pairsCount++;}
        }
    }

    cout << pairsCount;
} 