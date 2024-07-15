#include <iostream>
using namespace std;
int main() {
    freopen("cookiesin.txt", "r", stdin);
    freopen("cookiesout.txt", "w", stdout);

    int D, C0, P1, C1, P2, C2;
    cin >> D >> C0 >> P1 >> C1 >> P2 >> C2;

    int one, two, three, four, five;

    int total = 0;
    int production = C0;
    int bought1 = false;
    int bought2 = false;

    // none bought
    for (int i = 1; i < D+1; i++) {
        total += production;
    }

    one = total;

    total = 0;
    production = C0;
    bought1 = false;
    bought2 = false;

    // both bought
    for (int i = 1; i < D+1; i++) {
        total += production;
        
        if (bought1 == false && total >= P1) {
            bought1 = true;
            production += C1;
            total -= P1;
        }

        if (bought2 == false && total >= P2) {
            bought2 = true;
            production += C2;
            total -= P2;
        }
    }

    two = total;

    total = 0;
    production = C0;
    bought1 = false;
    bought2 = false;

    for (int i = 1; i < D+1; i++) {
        total += production;

        if (bought2 == false && total >= P2) {
            bought2 = true;
            production += C2;
            total -= P2;
        }

        if (bought1 == false && total >= P1) {
            bought1 = true;
            production += C1;
            total -= P1;
        }
    }

    three = total;

    total = 0;
    production = C0;
    bought1 = false;
    bought2 = false;

    // only factory one bought
    for (int i = 1; i < D+1; i++) {
        total += production;

        if (bought1 == false && total >= P1) {
            bought1 = true;
            production += C1;
            total -= P1;
        }
    }

    four = total;

    total = 0;
    production = C0;
    bought1 = false;
    bought2 = false;

    // only factory two bought
    for (int i = 1; i < D+1; i++) {
        total += production;

        if (bought2 == false && total >= P2) {
            bought2 = true;
            production += C2;
            total -= P2;
        }
    }

    five = total;

    // cout << one << endl;
    // cout << two << endl;
    // cout << three << endl;
    // cout << four << endl;
    // cout << five << endl;

    int answer = max(
        max(one, two),
        max(max(three, four), five)
    );

    cout << answer;
    return 0;
}