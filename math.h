#ifndef MATH_H
#define MATH_H

#define EPSILON 1e-6 // used as "maximum margin of error" when needed
#define PI 3.14159265358979323846
// #define E 2.71828182845904523536

typedef char* String;

// Sorting algorithms
int* my_countsort(int *x, int length, int exp);
int* my_radixsort(int *x, int length);
double* my_mergesort(double *x, int length);
// double* my_heapsort(double x[], int length);

// Rounding functions
double ceil(double x);
double floor(double x);
double round(double x);
double absVal(double x);

// // power functions
double squareRoot(double x, double precision);
double cubeRoot(double x, double precision);
double power(double x, int y);
// double exp(double x);
// double log(double x);
// double log10(double x);

// // Trigonometric functions
// double sin(double x);
// double cos(double x);
// double tan(double x);

// // Statistics functions
double minValue(double* x, int length);
double maxValue(double* x, int length);
double mean(double* x, int length);
// double median(double x[], int length);
// double mode(double x[], int n);
double range(double* x, int n);
// double variance(double x[], int n);
// double covariance(double x[], double y[], int n);
// double correlation(double x[], double y[], int n);
// double standard_deviation(double x[], int n);
// double z_score(double x[], int n, double value);
// double percentile(double x[], int n, double value);
// double quartile(double x[], int n, int q);
// double iqr(double x[], int n);
// double skewness(double x[], int n);
// double kurtosis(double x[], int n);

// // Number theory functions
int is_prime(int x);
// int gcd(int a, int b);
// int lcm(int a, int b);
// int factors(int x);
// int prime_factors(int x);
// int is_coprime(int a, int b);
// int euler_phi(int x);
// int carmichael_lambda(int x);
// int chinese_remainder(int a[], int n[], int m);

// // Set theory functions
// int set_union(int a[], int b[], int c[], int n, int m);
// int intersection(int a[], int b[], int c[], int n, int m);
// int difference(int a[], int b[], int c[], int n, int m);
// int complement(int a[], int b[], int n, int m);
// int symmetric_difference(int a[], int b[], int c[], int n, int m);
// int cartesian_product(int a[], int b[], int c[], int n, int m);

// // Graph theory functions
// int rotate_clockwise(int a[], int b[], int c[], int n, int m);
// int rotate_counterclockwise(int a[], int b[], int c[], int n, int m);
// int shortest_path(int a[], int b[], int c[], int n, int m);
// int minimum_spanning_tree(int a[], int b[], int c[], int n, int m);
// int traveling_salesman(int a[], int b[], int c[], int n, int m);
// int maximum_flow(int a[], int b[], int c[], int n, int m);
// int minimum_cut(int a[], int b[], int c[], int n, int m);
// int vertex_cover(int a[], int b[], int c[], int n, int m);
// int independent_set(int a[], int b[], int c[], int n, int m);
// int clique(int a[], int b[], int c[], int n, int m);
// int graph_coloring(int a[], int b[], int c[], int n, int m);
// int graph_matching(int a[], int b[], int c[], int n, int m);
// int graph_isomorphism(int a[], int b[], int c[], int n, int m);

// // Combinatorial functions
int factorial(int x);
// int permutation(int n, int r);
// int combination(int n, int r);
// int choose(int n, int r);
// int derangement(int n);
// int partition(int n);

// // Cryptography functions
// String encrypt(String text, int key);
// String decrypt(String text, int key);
String padTo256(String text);
String sha256(String text);
// String hmac(String text, String key);
// String sign(String text, String key);
// int verify(String text, String signature, String key);
// int diffie_hellman(int a, int b, int p);

// // Linear algebra functions
// void add(double a[], double b[], double c[], int n, int m);
// void subtract(double a[], double b[], double c[], int n, int m);
// void multiply(double a[], double b[], double c[], int n, int m);
// void dot_product(double a[], double b[], double c[], int n, int m);
// void cross_product(double a[], double b[], double c[], int n, int m);
// void transpose(double a[], double b[], int n, int m);
// void determinant(double a[], int n);
// void inverse(double a[], double b[], int n);
// void rank(double a[], int n);
// void eigenvalues(double a[], double b[], int n);
// void eigenvectors(double a[], double b[], double c[], int n);
// void lu_decomposition(double a[], double b[], double c[], int n);
// void qr_decomposition(double a[], double b[], double c[], int n);
// void svd_decomposition(double a[], double b[], double c[], int n, int m);
// void cholesky_decomposition(double a[], double b[], int n);
// void gram_schmidt(double a[], double b[], int n, int m);
// void jacobi_rotation(double a[], double b[], int n);
// void gauss_seidel(double a[], double b[], int n);
// void gauss_elimination(double a[], double b[], int n);
// void cramer_rule(double a[], double b[], double c[], int n);
// void least_squares(double a[], double b[], double c[], int n, int m);
// void regression(double a[], double b[], double c[], int n, int m);

// // Optimization functions
// void fibonacci_search(double a[], double b[], int n);
// void hill_climbing(double a[], double b[], int n);
// void simulated_annealing(double a[], double b[], int n);
// void genetic_algorithm(double a[], double b[], int n);
// void particle_swarm_optimization(double a[], double b[], int n);
// void ant_colony_optimization(double a[], double b[], int n);
// void artificial_bee_colony(double a[], double b[], int n);
// void cuckoo_search(double a[], double b[], int n);
// void firefly_algorithm(double a[], double b[], int n);
// void bat_algorithm(double a[], double b[], int n);
// void wolf_search(double a[], double b[], int n);
// void krill_herd(double a[], double b[], int n);
// void whale_optimization(double a[], double b[], int n);

// // Machine learning functions
// void k_nearest_neighbors(double a[], double b[], double c[], int n, int m);
// void k_means(double a[], double b[], double c[], int n, int m);
// void k_medoids(double a[], double b[], double c[], int n, int m);
// void k_medians(double a[], double b[], double c[], int n, int m);
// void k_modes(double a[], double b[], double c[], int n, int m);

// // Algebra functions
// void solve_X(String expression);

#endif // MATH_H