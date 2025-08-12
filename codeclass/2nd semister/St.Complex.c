#include <stdio.h>

struct Complex {
    float real;
    float imag;
};

void addComplex(struct Complex c1, struct Complex c2);
void subtractComplex(struct Complex c1, struct Complex c2);

int main() {
    struct Complex c1, c2;
    printf("Enter real and imaginary parts of first complex number: ");
    scanf("%f %f", &c1.real, &c1.imag);
    printf("Enter real and imaginary parts of second complex number: ");
    scanf("%f %f", &c2.real, &c2.imag);
    addComplex(c1, c2);
    subtractComplex(c1, c2);
    return 0;
}

void addComplex(struct Complex c1, struct Complex c2) {
    struct Complex sum;
    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;
    printf("Sum: %.2f + %.2fi\n", sum.real, sum.imag);
}

void subtractComplex(struct Complex c1, struct Complex c2) {
    struct Complex diff;
    diff.real = c1.real - c2.real;
    diff.imag = c1.imag - c2.imag;
    printf("Difference: %.2f + %.2fi\n", diff.real, diff.imag);
}