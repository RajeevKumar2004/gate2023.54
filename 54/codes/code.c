#include <stdio.h>
#include <math.h>

// Function to compute factorial
double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Probability mass function for X
double pmf_X(int k) {
    if (k == 0) {
        return 0.5 * (1 + exp(-1));
    } else {
        return exp(-1) / (2 * factorial(k));
    }
}

// Expected Value E(X)
double expected_value_X() {
    double expected_value = 0;
    for (int k = 0; k <= 100; k++) { // You can adjust the range for higher values if needed
        expected_value += k * pmf_X(k);
    }
    return expected_value;
}

// Conditional Expected Value E(X|X>0)
double conditional_expected_value_X() {
    double conditional_expected_value = 0;
    double denominator = 1 - pmf_X(0);
    for (int k = 1; k <= 100; k++) { // You can adjust the range for higher values if needed
        conditional_expected_value += (k * pmf_X(k)) / denominator;
    }
    return conditional_expected_value;
}

int main() {
    double e_x = expected_value_X();
    double e_x_given_x_gt_0 = conditional_expected_value_X();

    printf("E(X) = %lf\n", e_x);
    printf("E(X|X>0) = %lf\n", e_x_given_x_gt_0);

    return 0;
}

