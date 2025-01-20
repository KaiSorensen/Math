#include <stdio.h>
#include <string.h>
#include "error.h"

#define EPSILON 1e-6
// #define PI 3.14159265358979323846;
// #define E 2.71828182845904523536;

typedef char* Str;

// ////////////////////////
// // Sorting Algorithms //
// ////////////////////////

extern double* mergesort(double* x, int length) {
    //base case
    if (length <= 1) return x;

    //recursively split array into two halves
    int mid = length / 2;
    double* left = mergesort(x, mid);
    double* right = mergesort(x + mid, length - mid);
    double* sorted = (double*)malloc(length * sizeof(double));

    //merge
    int i = 0, j = 0;
    while (i < mid && j < length - mid) {
        if (left[i] < right[j]) {
            sorted[i + j] = left[i];
            i++;
        } else {
            sorted[i + j] = right[j];
            j++;
        }
    }
    while (i < mid) {
        sorted[i + j] = left[i];
        i++;
    }
    while (j < length - mid) {
        sorted[i + j] = right[j];
        j++;
    }
    //copy sorted array back into original array, because C langauge
    memcpy(x, sorted, length * sizeof(double));
    free(sorted);
    return x;
}

extern int* radixsort(int* x, int length) {
    return 0;
}

extern double* heapsort(double* x, int length) {
    return 0;
}


////////////////////////
// Rounding Functions //
////////////////////////

extern double ceil(double x) {
    return (int)x + 1;
}
extern double floor(double x) {
    return (int)x;
}
extern double round(double x) {
    return (int)(x + 0.5);
}
extern double absVal(double x) {
    return x < 0 ? -x : x;
}


/////////////////////
// Power Functions //
/////////////////////

extern double squareRoot(double x) {
    if (x < 0.0) ERROR("cannot SQRT negative number");
    if (x <= 1.0) return 1;

    double aprx = x / 2;
    while (absVal(aprx * aprx) - x > EPSILON) {
        aprx = (aprx + x / aprx) / 2;
    }
    return aprx;
};
extern double nthRoot(int n, double base) ;
extern double power(double x, int y) {
    double result = 1;
    int p = absVal(y);

    for (int i = 0; i < p; i++) result *= x;

    if (y < 0) result = 1 / result;
    return result;
}

// double exp(double x, double y) {};
// double log(double x) {};
// double log10(double x) {};


/////////////////////////////
// Trigonometric Functions //
/////////////////////////////

double sin(double x);
double cos(double x);
double tan(double x);


//////////////////////////
// Statistics Functions //
//////////////////////////

extern double minValue(double* x, int length) {
    double min = x[0];
    for (int i = 1; i < length; i++) {
        if (x[i] < min) min = x[i];
    }
    return min;
};
extern double maxValue(double* x, int length) {
    double max = x[0];
    for (int i = 1; i < length; i++) {
        if (x[i] > max) max = x[i];
    }
    return max;
};
extern double mean(double* x, int length) {
    double total = 0;
    int i;
    for (i = 0; i < length; i++) total += x[i];
    return total / (double)i;
}
// double median(double x[], int length) {
//     if (sizeof(x) % 2 == )
//     int i = 0;
//     for (int i = 0; i < sizeof(x); i++) total += x[i];
//     return total / i;
// };
// double mode(double x[]) {
    
// };
extern double range(double* x, int length) {
    if (length == 0) return 0;
    double min = x[0];
    double max = x[0];
    for (int i = 1; i < length; i++) {
        if (x[i] < min) min = x[i];
        if (x[i] > max) max = x[i];
    }
    return max - min;
};
double variance(double x[], int n);
double covariance(double x[], double y[], int n);
double correlation(double x[], double y[], int n);
double standard_deviation(double x[], int n);
double z_score(double x[], int n, double value);
double percentile(double x[], int n, double value);
double quartile(double x[], int n, int q);
double iqr(double x[], int n);
double skewness(double x[], int n);
double kurtosis(double x[], int n);

// Number theory functions
int is_prime(int x);
int gcd(int a, int b);
int lcm(int a, int b);
int factors(int x);
int prime_factors(int x);
int is_coprime(int a, int b);
int euler_phi(int x);
int carmichael_lambda(int x);
int chinese_remainder(int a[], int n[], int m);

// Set theory functions
int set_union(int a[], int b[], int c[], int n, int m);
int intersection(int a[], int b[], int c[], int n, int m);
int difference(int a[], int b[], int c[], int n, int m);
int complement(int a[], int b[], int n, int m);
int symmetric_difference(int a[], int b[], int c[], int n, int m);
int cartesian_product(int a[], int b[], int c[], int n, int m);

// Graph theory functions
int rotate_clockwise(int a[], int b[], int c[], int n, int m);
int rotate_counterclockwise(int a[], int b[], int c[], int n, int m);
int shortest_path(int a[], int b[], int c[], int n, int m);
int minimum_spanning_tree(int a[], int b[], int c[], int n, int m);
int traveling_salesman(int a[], int b[], int c[], int n, int m);
int maximum_flow(int a[], int b[], int c[], int n, int m);
int minimum_cut(int a[], int b[], int c[], int n, int m);
int vertex_cover(int a[], int b[], int c[], int n, int m);
int independent_set(int a[], int b[], int c[], int n, int m);
int clique(int a[], int b[], int c[], int n, int m);
int graph_coloring(int a[], int b[], int c[], int n, int m);
int graph_matching(int a[], int b[], int c[], int n, int m);
int graph_isomorphism(int a[], int b[], int c[], int n, int m);


// Combinatorial functions
extern long int factorial(long int x) {
    if (x == 0) return 1;
    long int result;
    for (int i = x - 1; i > 0; i--) result *= i;
    return result;
}
int permutation(Str s, int r);
int combination(int n, int r);
long int choose(int n, int r);
int derangement(int n);
int partition(int n);

// Cryptography functions
char* encrypt(char* text, int key);
char* decrypt(char* text, int key);
char* hash(char* text);

char* unhash(char* text);
char* hmac(char* text, char* key);
char* sign(char* text, char* key);
int verify(char* text, char* signature, char* key);

// Linear functions
void add(double a[], double b[], double c[], int n, int m);
void subtract(double a[], double b[], double c[], int n, int m);
void multiply(double a[], double b[], double c[], int n, int m);
void dot_product(double a[], double b[], double c[], int n, int m);
void cross_product(double a[], double b[], double c[], int n, int m);
void transpose(double a[], double b[], int n, int m);
void determinant(double a[], int n);
void inverse(double a[], double b[], int n);
void rank(double a[], int n);
void eigenvalues(double a[], double b[], int n);
void eigenvectors(double a[], double b[], double c[], int n);
void lu_decomposition(double a[], double b[], double c[], int n);
void qr_decomposition(double a[], double b[], double c[], int n);
void svd_decomposition(double a[], double b[], double c[], int n, int m);
void cholesky_decomposition(double a[], double b[], int n);
void gram_schmidt(double a[], double b[], int n, int m);
void jacobi_rotation(double a[], double b[], int n);
void gauss_seidel(double a[], double b[], int n);
void gauss_elimination(double a[], double b[], int n);
void cramer_rule(double a[], double b[], double c[], int n);
void least_squares(double a[], double b[], double c[], int n, int m);
void regression(double a[], double b[], double c[], int n, int m);

// optimization functions ?
void fibonacci_search(double a[], double b[], int n);
void hill_climbing(double a[], double b[], int n);
void simulated_annealing(double a[], double b[], int n);
void genetic_algorithm(double a[], double b[], int n);
void particle_swarm_optimization(double a[], double b[], int n);
void ant_colony_optimization(double a[], double b[], int n);
void artificial_bee_colony(double a[], double b[], int n);
void cuckoo_search(double a[], double b[], int n);
void firefly_algorithm(double a[], double b[], int n);
void bat_algorithm(double a[], double b[], int n);
void wolf_search(double a[], double b[], int n);
void krill_herd(double a[], double b[], int n);
void whale_optimization(double a[], double b[], int n);

// Machine learning functions
void k_nearest_neighbors(double a[], double b[], double c[], int n, int m);
void k_means(double a[], double b[], double c[], int n, int m);
void k_medoids(double a[], double b[], double c[], int n, int m);
void k_medians(double a[], double b[], double c[], int n, int m);
void k_modes(double a[], double b[], double c[], int n, int m);

// Neural network functions

// Deep learning functions

// Reinforcement learning functions

// Natural language processing functions

//

// Algebra functions
void solve_X(char* expression);