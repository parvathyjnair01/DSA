#include <stdio.h>

struct poly {
    int coef;
    int exp;
} p1[30], p2[30], p3[30];

// Function to display a polynomial
void display(struct poly p[], int n) {
    for (int i = 0; i < n; i++) {
        if (p[i].coef == 0) continue; // skip 0 terms

        if (i > 0 && p[i].coef > 0) printf(" + "); // add + sign for positive terms (after first)

        if (p[i].exp == 0) {
            printf("%d", p[i].coef);   // constant term
        } else if (p[i].exp == 1) {
            printf("%dx", p[i].coef);  // power 1
        } else {
            printf("%dx^%d", p[i].coef, p[i].exp);  // general case
        }
    }
    printf("\n");
}

int main() {
    int n1, n2, n3, i, j, k;
    printf("Enter first polynomial:");
    printf("\nEnter number of terms: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        printf("Enter term %d (coefficient and exponent): ", i + 1);
        scanf("%d %d", &p1[i].coef, &p1[i].exp);
    }
    printf("\nEnter second polynomial:");
    printf("\nEnter number of terms: ");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        printf("Enter term %d (coefficient and exponent): ", i + 1);
        scanf("%d %d", &p2[i].coef, &p2[i].exp);
    }

    i = j = k = 0;
    while (i < n1 && j < n2) {
        if (p1[i].exp == p2[j].exp) {
            p3[k].coef = p1[i].coef + p2[j].coef;
            p3[k].exp = p1[i].exp;
            i++; j++; k++;
        } else if (p1[i].exp > p2[j].exp) {
            p3[k] = p1[i];
            i++; k++;
        } else {
            p3[k] = p2[j];
            j++; k++;
        }
    }

    // Copy remaining terms
    while (i < n1) {
        p3[k] = p1[i];
        i++; k++;
    }
    while (j < n2) {
        p3[k] = p2[j];
        j++; k++;
    }

    n3 = k;

    // Display results
    printf("\nFirst Polynomial: ");
    display(p1, n1);

    printf("Second Polynomial: ");
    display(p2, n2);

    printf("Sum Polynomial: ");
    display(p3, n3);

    return 0;
}
