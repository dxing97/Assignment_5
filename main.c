#include <stdio.h>
#include <math.h>
#define SIZE 17

int main() {
    int i, j;
    /*
     * multiplication table
     */
    for(i = 1; i < SIZE; i++) {
        for(j = 1; j < SIZE; j++) {
            printf("%2d ", i*j%SIZE);
        }
        printf("\n");
    }
    printf("\n");

    /*
     * addition table
     */
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%2d ", (i+j)%SIZE);
        }
        printf("\n");
    }
    printf("\n");

    /*
     * proving 3 is a generator of mod 17 (started at 3 because we have a magic oracle that told us 2 is not a generator)
     */
    int generator = 3;
    for(i = 1; i < SIZE; i++) {
        printf("%d^%2d %% %d = %d\n", generator, i, SIZE, ((int) pow(generator, i)) % SIZE);
    }
    printf("\n");

    /*
     * use one generator to generate all other generators with coprimes (coprimes of 17-1 are all odd numbers between 1 and 16 inclusive)
     */
    for(i = 1; i< SIZE - 1; i+= 2) {
        printf("%d^%d %% %d = %d\n", generator, i, SIZE, ((int)pow(generator, i)) % SIZE);
    }
}