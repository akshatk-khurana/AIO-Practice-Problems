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

        if (!bought1 && total >= P1 && C1 != 0) {
            if (total < total - P1 + (C1*daysLeft)) {
                production += C1;
                total -= P1;
                bought1 = true;
            }
        }

        if (!bought1 && total >= P2 && C2 != 0) {
            if (total < total - P2 + (C2*daysLeft)) {
                production += C2;
                total -= P2;
                bought2 = true;
            }
        }
    }
    cout << total;
    return 0;
}