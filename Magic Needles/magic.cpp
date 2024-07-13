#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    freopen("bernardin.txt", "r", stdin);
    freopen("bernardout.txt", "w", stdout);

    int N;
    cin >> N;

    int needles[N];
    for (int i = 0; i < N && i < 100000; i++) {
        cin >> needles[i];
    }

    int needleToFind;
    int i = 0;
    while (i < 10000) {
        cin >> needleToFind;
        if (needleToFind == -1) {break;}

        int l = 0;
        int h = N-1;

        while (h != l) {
            int m = floor((l+h) / 2);
            
            if (needles[m] >= needleToFind) {
                h = m;
            } else {
                l = m + 1;
            }
        }
        
        if (needles[l] == needleToFind) {
            cout << l + 1 << endl;
        } else {
            cout << "needle is gone forever" << endl;
        }
    }
    
    return 0;
}