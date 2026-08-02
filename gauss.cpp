#include <stdio.h>

int main() {
    float x = 0, y = 0, z = 0;
    float x1, y1, z1;
    int i;

    // Iteration loop
    for(i = 1; i <= 7; i++) {

        // Using Jacobi formulas
        x1 = (7.74 - y + 2*z) / 10;
        y1 = (39.66 - x - 3*z) / 12;
        z1 = (54.8 - 3*x - 4*y) / 15;

        printf("Iteration %d: x = %.3f, y = %.3f, z = %.3f\n", i, x1, y1, z1);

        // Update values
        x = x1;
        y = y1;
        z = z1;
    }

    printf("\nFinal Approximation:\n");
    printf("x = %.3f, y = %.3f, z = %.3f\n", x, y, z);

    return 0;
}
