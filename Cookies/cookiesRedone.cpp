#include <iostream>
using namespace std;
int main() {
    freopen("cookiesin.txt", "r", stdin);
    freopen("cookiesout.txt", "w", stdout);

    int D, C0, P1, C1, P2, C2;
    cin >> D >> C0 >> P1 >> C1 >> P2 >> C2;

    int total = 0;
    int production = C0;
    int bought1 = false;
    int bought2 = false;

    int daysLeft;
    for (int i = 1; i < D+1; i++) {
        daysLeft = D - i;
        total += production;

        int case1 = total - P1 + (C1*daysLeft);
        int case2 = total - P2 + (C2*daysLeft);

        if (C1 == C2) { // if equal
            if (C1 != 0) {
                if (case1 > case2 && case1 > total) {
                    if (case)
                }
                // if both are not 0
            }
        } else if (C1 > C2) {

        } else if (C2 > C1) {

        }
    }
    cout << total;
    return 0;
}