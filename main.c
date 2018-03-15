#include <stdio.h>
#include <math.h>
#define SIZE 17

/*
 * ENEE 446 - Homework Assignment 5
 * compile with gcc, run the executable
 */

int main() {
    int i, j;
    /*
     * 1 - Show the addition and multiplication tables modulo 17
     *
     * multiplication table
     */
    printf("(Q1)\nMultiplication table: \n\n");
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
    printf("Division table: \n\n");
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%2d ", (i+j)%SIZE);
        }
        printf("\n");
    }
    printf("\n\n");


    /*
     * 2 - Determine all the generators of the multiplicative group Z_17
     *
     * proving 3 is a generator of mod 17
     * (started at 3 because we have a magic oracle that told us 2 is not a generator)
     *
     */
    printf("(Q2)\nFirst we prove that 3 is a generator of Z_17 manually:\n\n");
    int generator = 3;
    for(i = 0; i < SIZE - 1; i++) {
        printf("%d^%2d %% %d = %d\n", generator, i, SIZE, ((int) pow(generator, i)) % SIZE);
    }
    printf("\n");

    /*
     * use one generator to generate all other generators with coprimes (coprimes of 17-1 are all odd numbers between 1 and 16 inclusive)
     */
    printf("Using 3, we can find all other generators by raising 3 to \n"
                   "the power of each number coprime to 16, which for 16 is \n"
                   "every odd number between 1 and 16 inclusive:\n\n");
    for(i = 1; i< SIZE - 1; i+= 2) {
        printf("%d^%d %% %d = %d\n", generator, i, SIZE, ((int)pow(generator, i)) % SIZE);
    }
    printf("\n\n");
    /*
     * 3 - Show how you can do the following computations using shift networks
     */
    printf("(Q3)\n"
                   "a) 3+5%%17\n\n");
    for(i = 0; i < SIZE; i++) {
        if(i == 0) {
            printf("%2d .... %2d .... %2d(%2d) <-- = %d\n", i, (i + 3 + SIZE) % SIZE, (i+3+5+SIZE)%SIZE, i, (i+3+5+SIZE)%SIZE);
        } else {
            printf("%2d .... %2d .... %2d(%2d)\n", i, (i+3+SIZE) % SIZE, (i+3+5+SIZE)%SIZE, i);
        }
    }

    printf("\n\nb) 4+6+7%%17\n\n");
    for(i = 0; i < SIZE; i++) {
        if(i == 0) {
            printf("%2d .... %2d .... %2d .... %d (%2d) <-- = %d\n",
                   i, (i+4+SIZE) % SIZE, (i+4+6+SIZE)%SIZE, (i+4+6+7+SIZE)%SIZE, i, (i+4+6+7+SIZE)%SIZE);
        } else {
            printf("%2d .... %2d .... %2d .... %d (%2d)\n",
                   i, (i+4+SIZE) % SIZE, (i+4+6+SIZE)%SIZE, (i+4+6+7+SIZE)%SIZE, i);
        }
    }

    printf("\n\n");
    printf("c) 3*7%%17\n");
    printf("3^1 = 3, 3^11 = 7\n");

    for(i = 0; i < SIZE; i++) {
        if(i == 0) {
            printf("%2d .... %2d .... %2d(%2d) <-- = 3^%d %% 17 = %d\n",
                   i, (i + 1 + SIZE) % SIZE, (i+1+11+SIZE)%SIZE, i, (i+1+11+SIZE)%SIZE,
                   4);
        } else {
            printf("%2d .... %2d .... %2d(%2d)\n",
                   i, (i+1+SIZE) % SIZE, (i+1+11+SIZE)%SIZE, i);
        }
    }

    printf("\n\n");
    printf("d) 4*2*6 %% 17\n"
                   "3^12%%17=4, 3^15%%17=2, 3^16%%17=6\n");
    for(i = 0; i < SIZE; i++) {
        if(i == 0)
            printf("%2d .... %2d .... %2d .... %2d(%2d) <-- 3^9=14\n",
            i, (i+12)%SIZE, (i+12+15)%SIZE, (i+12+15+16)%SIZE, i);
        else
            printf("%2d .... %2d .... %2d .... %2d(%2d)\n",
                   i, (i+12)%SIZE, (i+12+15)%SIZE, (i+12+15+16)%SIZE, i);
    }
}