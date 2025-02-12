#include <string.h> // for memcpy, strlen, strcpy
#include "error.h"

#define EPSILON 1e-6 // used as "maximum margin of error" when needed
// #define PI 3.14159265358979323846;
// #define E 2.71828182845904523536;

typedef char* String; //String datatype for ease of use :)

////////////////////////
// Sorting Algorithms //
////////////////////////


// O(n)
extern int* my_countsort(int* x, int length, int exp) {
    if(exp < 1 || (exp != 1 && exp % 10 != 0)) ERROR("grammar for exp: (10*)");

    int sorted[length];
    int counts[10] = {0}; // start with array of 0's
    int indices[10] = {0}; // we will want both counts and the trailing-indices for later

    // count the appearances of each digit
    for (int i = 0; i < length; i++) {
        int digit = x[i] / exp % 10; // get's the digit at the 'exp' place
        counts[digit]++;
        indices[digit]++;
    }

    // for each digit, get the trailing index of it's allocation range in outputs
    for (int i = 1; i < 10; i++) { //note that it starts at 1!
        indices[i] += indices[i - 1];
    }

    // sort items based on digit into 
    for (int i = 0; i < length; i++) {
        int digit = x[i] / exp % 10;
        int index = indices[digit] - counts[digit]; // get the beginning index of the allocation range so that they're inserted in same order with which they came.
        sorted[index] = x[i];
        counts[digit]--;
    }

    memcpy(x, sorted, length * sizeof(int));
    return x;
}

// O(n)
extern int* my_radixsort(int* x, int length) {
    int maxValue = 0;
    for (int i = 0; i < length; i++) {
        if (x[i] > maxValue) maxValue = x[i];
    }

    int exp = 1;
    while (maxValue / exp > 0) {
        my_countsort(x, length, exp);
        exp *= 10;
    }
    return x;
}

// O(n log n)
// why am I using malloc
extern double* my_mergesort(double* x, int length) {
    //base casec
    if (length <= 1) return x;

    //recursively split array into two halves
    int mid = length / 2;
    double* left = my_mergesort(x, mid);
    double* right = my_mergesort(x + mid, length - mid);
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

// O(n log n)
// extern double* my_heapsort(double* x, int length) {
//     return 0;
// }


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

extern double squareRoot(double x, double precision) {
    if (x < 0.0) ERROR("cannot square root negative number");
    if (x == 0.0) return 0.0;

    double aprx = x / 2;
    while (absVal((aprx * aprx) - x) > precision) {
        aprx = (aprx + x / aprx) / 2;
    }

    return aprx;
};
extern double cubeRoot(double x, double precision) {
    if (x < 0.0) ERROR("cannot cube root negative number");
    if (x == 0.0) return 0.0;

    double aprx = x / 3;
    while (absVal((aprx * aprx * aprx) - x) > precision) {
        aprx = (2 * aprx + x / (aprx * aprx)) / 3;
    }

    return aprx;
}

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
    if (length == 0) ERROR("received length 0");
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
// brute force is_prime, O(x)
extern int is_prime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i < x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
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
    long int result = x;
    for (int i = x - 1; i > 0; i--) result *= i;
    return result;
}
int permutation(String s, int r);
int combination(int n, int r);
long int choose(int n, int r);
int derangement(int n);
int partition(int n);

// Cryptography functions
String encrypt(String text, int key);
String decrypt(String text, int key);

// helper for sha512
String padTo256(String text) {
    int _256bits = 256/ 8; // 64 bytes
    int _64bits  = 64 / 8; // 8 bytes

    // calculate the padding parameters
    int textLen = strlen(text); // get the length of the string, using 64 bits
    int padLen = _256bits - (textLen % _256bits); // calculate the number of bits needed to pad the string to a multiple of 512
    if (padLen == _256bits) padLen = 0; // if len is a already multiple of 512, no padding is needed
    if (padLen < _64bits) padLen += _256bits; // ensure space for appending 64 bit string length for sha512

    // allocate and instantiate the padded string
    String padded = (String)malloc(textLen + padLen + 1); // allocate memory for the padded string, +1 for null terminator
    if (!padded) ERROR("failed to allocate memory for padded string");
    strcpy(padded, text); // copy the original string into the padded string
    padded[textLen] = 0b10000000;  // place the 1 bit (as 1000-0000 to be correct bit-wise)
    for (int i = 1; i < padLen; i++) padded[textLen + i] = 0; // pad the string with 0's, note that printf will terminate as soon as it hits a 0

    // int positionOf64BitLen = textLen + padLen - ; // position of the 64 bit string length
    // printf("positionOf64BitLen: %d\n", positionOf64BitLen);

    uint64_t bigEndianTextLen = __builtin_bswap64(textLen * 8); // ensures big-endian, as expected by sha512... I hope :O
    memcpy(padded + textLen + padLen - _64bits, &bigEndianTextLen, sizeof(bigEndianTextLen)); // append the 64 bit string length to the end of the string
    padded[textLen + padLen] = '\0'; // null-terminate the string

    return padded;
}

extern String sha256(String text) {
    String paddedText = padTo256(text);
    // Get the last 8 bytes (64 bits) from the padded message
    uint64_t paddedTextLength = 0;
    for (int i = 0; i < 8; i++) {
        paddedTextLength <<= 8;  // Shift left by 8 bits
        paddedTextLength |= (uint8_t)paddedText[paddedText.length() - 8 + i]; // Append byte
    }
    printf("paddedTextLength: %llx\n", paddedTextLength);


    // initial 8 hash value constants that are the first 64 bits of the fractional parts of the square roots of the first 8 prime numbers
    uint32_t square_hash_constants[8];
    double i = 0;
    for(int j = 0; j < 8; i++) {
        if (is_prime(i)) {
            double sqrt = squareRoot(i, 0.000000001);
            double fractional = sqrt - (int)sqrt;
            uint32_t first32bits = fractional * 0xFFFFFFFF; // mask the fractional part to 32 bits
            square_hash_constants[j] = first32bits;
            printf("square_hash_constants[%d] as hex: %llx\n", (int)i, square_hash_constants[j]);
            j++;
        }
    }

    //initial 64 hash value constants that are the first 32 bits of the fractional parts of the cube roots of the first 64 prime numbers
    uint32_t cube_hash_constants[64];
    i = 0;
    for(int j = 0; j < 64; i++) {
        if (is_prime(i)) {
            double cbrt = cubeRoot(i, 0.000000001);
            double fractional = cbrt - (int)cbrt;
            uint32_t first32bits = fractional * 0xFFFFFFFF; // mask the fractional part to 32 bits
            cube_hash_constants[j] = first32bits;
            printf("cube_hash_constants[%d] as hex: %llx\n", (int)i, cube_hash_constants[j]);
            j++;
        }
    }

    // message schedule array of 64 32-bit words
    uint32_t message_schedule[64];


    return "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d";
}

String hmac(String text, String key);
String sign(String text, String key);
int verify(String text, String signature, String key);

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
void solve_X(String expression);