#include <cstdio>
#include <iostream>

using namespace std;
int c, n, k;
string chairs;

int main(void) {
    freopen("chairsin.txt", "r", stdin);
    freopen("chairsout.txt", "w", stdout);

    cin >> c >> n >> k;
    cin >> chairs; 
    
    // don't change!
    int cannotAdjust = n-k;
    int leastDistance = c;

    int numChairs = 0;
    int numDry = 0;
    int right;

    for (int i = 0; i < c; i++) {
        numChairs++;
        if (chairs[i] == 'd') {numDry++;}

        if (numChairs >= n && numDry >= cannotAdjust) {
            leastDistance = min(leastDistance, numChairs);
            right = i;
            break;
        }
    }

    for (int left = 1; left < c; left++) {
        numChairs--;
        if (chairs[left-1] == 'd') {numDry--;}

        while (right < c) {
            if (numChairs >= n && numDry >= cannotAdjust) {
                leastDistance = min(leastDistance, numChairs);
                break;
            }

            numChairs++;
            right++;
            if (chairs[right] == 'd') {numDry++;}
        }
    }

    cout << leastDistance;

    return 0;
}