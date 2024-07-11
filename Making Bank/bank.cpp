#include <cstdio>
#include <iostream>
int N;
using namespace std;
int main() {
    FILE *input_file = fopen("bankin.txt", "r");
    FILE *output_file = fopen("bankout.txt", "w");

    fscanf(input_file, "%d", &N);
    char days[N];

    fscanf(input_file, "%s", days);

    int skill = 1;
    int total = 0;
    for (int i = 0; i < N; i++) {
        if (days[i] == 'M') {
            total+=skill;
        } else {
            int daysLeft = N-i;
            if (total+skill < total+daysLeft) {
                skill+=1;
            } else {
                total += skill;
            }
        }
    }

    fprintf(output_file, "%d\n", total);
    fclose(input_file);
    fclose(output_file);

    return 0;
}