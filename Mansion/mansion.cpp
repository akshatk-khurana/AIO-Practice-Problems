#include <cstdio>
#include <iostream>

using namespace std;

int w, n;

int answer;

int main(void) {
    FILE *input_file = fopen("manin.txt", "r");
    FILE *output_file = fopen("manout.txt", "w");

    fscanf(input_file, "%d %d", &n, &w);
    int houses[n];

    for (int i = 0; i < n; i++) {
        fscanf(input_file, "%d", &houses[i]);
    }


    int sum = 0;
    int k = 0;
    while (k <= w-1) {
        sum += houses[k];
        k++;
    }

    answer = max(answer, sum);

    for (int i = 1, j = i+w-1; j < n; j++, i++) {
        sum -= houses[i-1];
        sum += houses[j];
        answer = max(answer, sum);
    }

    fprintf(output_file, "%d\n", answer);
    fclose(input_file);
    fclose(output_file);

    return 0;
}