#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"

#define GREEN_TEXT "\033[0;32m"
#define RED_TEXT "\033[0;31m"
#define RESET_COLOR "\033[0m"

#define PASSED GREEN_TEXT "passed" RESET_COLOR
#define FAILED RED_TEXT "**FAILED**" RESET_COLOR

float passed = 0;
float failed = 0;

//////////////////////
// HELPER FUNCTIONS //
//////////////////////

void print_array_ints(int* array, int length) {
    printf("[");
    for (int i = 0; i < length; i++) {
        printf("%d", array[i]);
        if (i < length - 1) printf(", ");
    }
    printf("]");
}

void print_array_doubles(double* array, int length) {
    printf("[");
    for (int i = 0; i < length; i++) {
        printf("%lf", array[i]);
        if (i < length - 1) printf(", ");
    }
    printf("]");
}



/////////////////////////
// ASSERTION FUNCTIONS //
/////////////////////////
void ASSERT_bool(int expected, String funcName) { 
    if (!(expected)) {printf("\t%s  %s\n", funcName, FAILED); failed++;} 
    else {printf("\t%s  %s\n", funcName, PASSED); passed++;}
}
void ASSERT_int(int actual, int expected, String funcName) { 
    if (expected != actual) {printf("%s  %s (expected: %d -- found: %d)\n", funcName, FAILED, expected, actual); failed++;} 
    else {printf("\t%s  %s\n", funcName, PASSED); passed++;}
}
void ASSERT_double(double actual, double expected, String funcName) { 
    if ((actual) - (expected) > EPSILON || (expected - actual) > EPSILON) {printf("\t%s  %s (expected: %f -- found: %f)\n", funcName, FAILED, expected, actual); failed++;} 
    else {printf("\t%s  %s\n", funcName, PASSED); passed++;}
}
void ASSERT_array_ints (int* actual, int* expected, int length, String funcName) {
    for (int i = 0; i < length; i++) {
        if (actual[i] != expected[i]) {
            printf("\t%s  %s (expected: ", funcName, FAILED); 
            print_array_ints(expected, length);
            printf(" -- found: ");
            print_array_ints(actual, length);
            printf(")\n");
            failed++; 
            return;
        }
    } 
    printf("\t%s  %s\n", funcName, PASSED); passed++;
}
void ASSERT_array_doubles(double* actual, double* expected, int length, String funcName) {
    for (int i = 0; i < length; i++) {
        if (actual[i] != expected[i]) {
            printf("\t%s  %s (expected: ", funcName, FAILED); 
            print_array_doubles(expected, length);
            printf(" -- found: ");
            print_array_doubles(actual, length);
            printf(")\n");
            failed++; 
            return;
        }
    } 
    printf("\t%s  %s\n", funcName, PASSED); passed++;
}
void ASSERT_strings(String actual, String expected, String funcName, int freeInput) {
    if (strcmp(actual, expected) != 0) {printf("\t%s  %s (expected: %s -- found: %s)\n", funcName, FAILED, expected, actual); failed++;} 
    else {printf("\t%s  %s\n", funcName, PASSED); passed++;}
    if (freeInput) free(actual);
}


////////////////////////
// SORTING ALGORITHMS //
////////////////////////

void test_countsort() {
    ASSERT_array_ints(my_countsort((int[]){1}, 1, 1), (int[]){1}, 1, "test_countsort([1])");
    ASSERT_array_ints(my_countsort((int[]){1, 2, 3, 4, 5}, 5, 1), (int[]){1, 2, 3, 4, 5}, 5, "test_countsort([1,2,3,4,5], 1)");
    ASSERT_array_ints(my_countsort((int[]){5, 4, 3, 2, 1}, 5, 1), (int[]){1, 2, 3, 4, 5}, 5, "test_countsort([5,4,3,2,1], 1)");
    ASSERT_array_ints(my_countsort((int[]){30, 20, 10, 0, 10}, 5, 10), (int[]){0, 10, 10, 20, 30}, 5, "test_countsort([30,20,10,0,10], 10)");
    ASSERT_array_ints(my_countsort((int[]){550, 640, 770, 830, 920}, 5, 10), (int[]){920,830,640,550,770}, 5, "test_countsort([550,640,770,830,920], 10)");
    ASSERT_array_ints(my_countsort((int[]){550, 640, 770, 830, 920}, 5, 100), (int[]){550,640,770,830,920}, 5, "test_countsort([550,640,770,830,920], 100)");
}

void test_radixsort() {
    ASSERT_array_ints(my_radixsort((int[]){1}, 1), (int[]){1}, 1, "test_radixsort([1])");
    ASSERT_array_ints(my_radixsort((int[]){1, 2, 3, 4, 5}, 5), (int[]){1, 2, 3, 4, 5}, 5, "test_radixsort([1,2,3,4,5])");
    ASSERT_array_ints(my_radixsort((int[]){5, 4, 3, 2, 1}, 5), (int[]){1, 2, 3, 4, 5}, 5, "test_radixsort([5,4,3,2,1])");
    ASSERT_array_ints(my_radixsort((int[]){30, 20, 10, 0, 10}, 5), (int[]){0, 10, 10, 20, 30}, 5, "test_radixsort([30,20,10,0,10])");
    ASSERT_array_ints(my_radixsort((int[]){1, 29, 333, 4, 5, 68, 7, 83, 912, 10}, 10), (int[]){1, 4, 5, 7, 10, 29, 68, 83, 333, 912}, 10, "test_radixsort([1,29,333,4,5,68,7,83,912,10])");
    ASSERT_array_ints(my_radixsort((int[]){5500, 640, 920, 770, 830}, 5), (int[]){640, 770, 830, 920, 5500}, 5, "test_radixsort([5500,640,920,770,830])");
}


void test_mergesort() {
    ASSERT_array_doubles(my_mergesort((double[]){1.0, 2.0, 3.0, 4.0, 5.0}, 5), (double[]){1.0, 2.0, 3.0, 4.0, 5.0}, 5, "test_mergesort([1,2,3,4,5])");
    ASSERT_array_doubles(my_mergesort((double[]){5.0, 4.0, 3.0, 2.0, 1.0}, 5), (double[]){1.0, 2.0, 3.0, 4.0, 5.0}, 5, "test_mergesort([5,4,3,2,1])");
    ASSERT_array_doubles(my_mergesort((double[]){-1.5, 0.0, 2.7, -3.2, 4.1}, 5), (double[]){-3.2, -1.5, 0.0, 2.7, 4.1}, 5, "test_mergesort([-1.5,0,2.7,-3.2,4.1])");
    ASSERT_array_doubles(my_mergesort((double[]){-10.0, -20.0, -5.0, -15.0, -8.0}, 5), (double[]){-20.0, -15.0, -10.0, -8.0, -5.0}, 5, "test_mergesort([-10,-20,-5,-15,-8])");
    ASSERT_array_doubles(my_mergesort((double[]){3.14, 2.71, 1.41, 0.58, 1.73}, 5), (double[]){0.58, 1.41, 1.73, 2.71, 3.14}, 5, "test_mergesort([3.14,2.71,1.41,0.58,1.73])");
    ASSERT_array_doubles(my_mergesort((double[]){0.0, 0.0, 0.0, 0.0, -0.1}, 5), (double[]){-0.1, 0.0, 0.0, 0.0, 0.0}, 5, "test_mergesort([0,0,0,0,-0.1])");
}

void test_sorting_algorithms() {
    printf("Testing sorting algorithms...\n"); printf("\n");
    test_countsort(); printf("\n");
    test_radixsort(); printf("\n");
    test_mergesort(); printf("\n");
    printf("\n");
}


////////////////////////
// ROUNDING FUNCTIONS //
////////////////////////

void test_ceil() {
    ASSERT_double(ceil(3.7), 4.0, "test_ceil(3.7)");
    ASSERT_double(ceil(-3.7), -3.0, "test_ceil(-3.7)");
    ASSERT_double(ceil(0.0), 0.0, "test_ceil(0.0)");
    ASSERT_double(ceil(-0.0), 0.0, "test_ceil(-0.0)");
    ASSERT_double(ceil(3.0), 3.0, "test_ceil(3.0)");
}
void test_floor() {
    ASSERT_double(floor(3.7), 3.0, "test_floor(3.7)");
    ASSERT_double(floor(-3.7), -4.0, "test_floor(-3.7)");
    ASSERT_double(floor(0.0), 0.0, "test_floor(0.0)");
    ASSERT_double(floor(-0.0), 0.0, "test_floor(-0.0)");
    ASSERT_double(floor(3.0), 3.0, "test_floor(3.0)");
}
void test_round() {
    ASSERT_double(round(3.7), 4.0, "test_round(3.7)");
    ASSERT_double(round(3.2), 3.0, "test_round(3.2)");
    ASSERT_double(round(-3.7), -4.0, "test_round(-3.7)");
    ASSERT_double(round(-3.2), -3.0, "test_round(-3.2)");
    ASSERT_double(round(0.0), 0.0, "test_round(0.0)");
    ASSERT_double(round(-0.0), 0.0, "test_round(-0.0)");
    ASSERT_double(round(0.5), 1.0, "test_round(0.5)");
    ASSERT_double(round(-0.5), -1.0, "test_round(-0.5)");
}
void test_absVal() {
    ASSERT_double(absVal(3.7), 3.7, "test_absVal(3.7)");
    ASSERT_double(absVal(-3.7), 3.7, "test_absVal(-3.7)");
    ASSERT_double(absVal(0.0), 0.0, "test_absVal(0.0)");
    ASSERT_double(absVal(-0.0), 0.0, "test_absVal(-0.0)");
}

void test_rounding_functions() {
    printf("Testing rounding functions...\n"); printf("\n");
    test_ceil(); printf("\n");
    test_floor(); printf("\n");
    test_round(); printf("\n");
    test_absVal(); printf("\n");
    printf("\n");
}


/////////////////////
// POWER FUNCTIONS //
/////////////////////

void test_sqrt() {
    ASSERT_double(squareRoot(4, EPSILON), 2.0, "test_sqrt(4)");
    ASSERT_double(squareRoot(625, EPSILON), 25.0, "test_sqrt(625)");
    ASSERT_double(squareRoot(0, EPSILON), 0.0, "test_sqrt(0)");
    ASSERT_double(squareRoot(1, EPSILON), 1.0, "test_sqrt(1)");
    ASSERT_double(squareRoot(2, EPSILON), 1.414214, "test_sqrt(2)");
    ASSERT_double(squareRoot(30, EPSILON), 5.477226, "test_sqrt(30)");
    ASSERT_double(squareRoot(1234, EPSILON), 35.128336, "test_sqrt(1234)");
    ASSERT_double(squareRoot(55555, EPSILON), 235.701082, "test_sqrt(55555)");
    ASSERT_double(squareRoot(PI, EPSILON), 1.772454, "test_sqrt(PI)");
    ASSERT_double(squareRoot(0.25, EPSILON), 0.5, "test_sqrt(0.25)");
}

void test_cubeRoot() {
    ASSERT_double(cubeRoot(8, EPSILON), 2.0, "test_cubeRoot(8)");
    ASSERT_double(cubeRoot(27, EPSILON), 3.0, "test_cubeRoot(27)");
    ASSERT_double(cubeRoot(0, EPSILON), 0.0, "test_cubeRoot(0)");
    ASSERT_double(cubeRoot(1, EPSILON), 1.0, "test_cubeRoot(1)");
    ASSERT_double(cubeRoot(2, EPSILON), 1.259921, "test_cubeRoot(2)");
    ASSERT_double(cubeRoot(30, EPSILON), 3.107233, "test_cubeRoot(30)");
    ASSERT_double(cubeRoot(1234, EPSILON), 10.079368, "test_cubeRoot(1234)");
    ASSERT_double(cubeRoot(55555, EPSILON), 39.588379, "test_cubeRoot(55555)");
    ASSERT_double(cubeRoot(PI, EPSILON), 1.464591, "test_cubeRoot(PI)");
    ASSERT_double(cubeRoot(0.125, EPSILON), 0.5, "test_cubeRoot(0.125)");
}

void test_power_functions() {
    printf("Testing power functions...\n"); printf("\n"); 
    test_sqrt(); printf("\n");
    test_cubeRoot(); printf("\n");
    printf("\n");
}


//////////////////////////
// STATISTICS FUNCTIONS //
//////////////////////////

void test_minValue() {
    ASSERT_double(minValue((double[]){1.0, 2.0, 3.0, 4.0, 5.0}, 5), 1.0, "test_minValue([1,2,3,4,5])");
    ASSERT_double(minValue((double[]){-1.5, 0.0, 2.7, -3.2, 4.1}, 5), -3.2, "test_minValue([-1.5,0,2.7,-3.2,4.1])");
    ASSERT_double(minValue((double[]){-10.0, -20.0, -5.0, -15.0, -8.0}, 5), -20.0, "test_minValue([-10,-20,-5,-15,-8])");
    ASSERT_double(minValue((double[]){3.14, 2.71, 1.41, 0.58, 1.73}, 5), 0.58, "test_minValue([3.14,2.71,1.41,0.58,1.73])");
    ASSERT_double(minValue((double[]){0.0, 0.0, 0.0, 0.0, -0.1}, 5), -0.1, "test_minValue([0,0,0,0,-0.1])");
    ASSERT_double(minValue((double[]){1e-10, -1e-11, 1e-12, 1e-13, 1e-14}, 5), -1e-11, "test_minValue([1e-10,-1e-11,1e-12,1e-13,1e-14])");
}
void test_maxValue() {
    ASSERT_double(maxValue((double[]){1.0, 2.0, 3.0, 4.0, 5.0}, 5), 5.0, "test_maxValue([1,2,3,4,5])");
    ASSERT_double(maxValue((double[]){-1.5, 0.0, 2.7, -3.2, 4.1}, 5), 4.1, "test_maxValue([-1.5,0,2.7,-3.2,4.1])");
    ASSERT_double(maxValue((double[]){-10.0, -20.0, -5.0, -15.0, -8.0}, 5), -5.0, "test_maxValue([-10,-20,-5,-15,-8])");
    ASSERT_double(maxValue((double[]){3.14, 2.71, 1.41, 0.58, 1.73}, 5), 3.14, "test_maxValue([3.14,2.71,1.41,0.58,1.73])");
    ASSERT_double(maxValue((double[]){0.0, 0.0, 0.0, 0.0, 0.1}, 5), 0.1, "test_maxValue([0,0,0,0,0.1])");
    ASSERT_double(maxValue((double[]){-1e-10, 1e-11, 1e-12, 1e-13, 1e-14}, 5), 1e-10, "test_maxValue([-1e-10,1e-11,1e-12,1e-13,1e-14])");
}
void test_mean() {
    ASSERT_double(mean((double[]){1.0, 2.0, 3.0, 4.0, 5.0}, 5), 3.0, "test_mean([1,2,3,4,5])");
    ASSERT_double(mean((double[]){-1.5, 0.0, 2.7, -3.2, 4.1}, 5), 0.42, "test_mean([-1.5,0,2.7,-3.2,4.1])");
    ASSERT_double(mean((double[]){-10.0, -20.0, -5.0, -15.0, -8.0}, 5), -11.6, "test_mean([-10,-20,-5,-15,-8])");
    ASSERT_double(mean((double[]){3.14, 2.71, 1.41, 0.58, 1.73}, 5), 1.914, "test_mean([3.14,2.71,1.41,0.58,1.73])");
    ASSERT_double(mean((double[]){0.0, 0.0, 0.0, 0.0, 0.1}, 5), 0.02, "test_mean([0,0,0,0,0.1])");
    ASSERT_double(mean((double[]){1e-10, -1e-11, 1e-12, 1e-13, 1e-14}, 5), 1.8e-11, "test_mean([1e-10,-1e-11,1e-12,1e-13,1e-14])");
}
void test_range() {
    ASSERT_double(range((double[]){1.0, 2.0, 3.0, 4.0, 5.0}, 5), 4.0, "test_range([1,2,3,4,5])");
    ASSERT_double(range((double[]){-1.5, 0.0, 2.7, -3.2, 4.1}, 5), 7.3, "test_range([-1.5,0,2.7,-3.2,4.1])");
    ASSERT_double(range((double[]){-10.0, -20.0, -5.0, -15.0, -8.0}, 5), 15.0, "test_range([-10,-20,-5,-15,-8])");
    ASSERT_double(range((double[]){3.14, 2.71, 1.41, 0.58, 1.73}, 5), 2.56, "test_range([3.14,2.71,1.41,0.58,1.73])");
    ASSERT_double(range((double[]){0.0, 0.0, 0.0, 0.0, 0.1}, 5), 0.1, "test_range([0,0,0,0,0.1])");
    ASSERT_double(range((double[]){1e-10, -1e-11, 1e-12, 1e-13, 1e-14}, 5), 1.1e-10, "test_range([1e-10,-1e-11,1e-12,1e-13,1e-14])");
    ASSERT_double(range((double[]){5.0}, 1), 0.0, "test_range([5])");
}

void test_statistics_functions() {
    printf("Testing statistics functions...\n"); printf("\n");
    test_minValue(); printf("\n");
    test_maxValue(); printf("\n");
    test_mean(); printf("\n");
    test_range(); printf("\n");
    printf("\n");
}


/////////////////////////////
// NUMBER THEORY FUNCTIONS //
/////////////////////////////

void test_is_prime() {
    ASSERT_int(is_prime(1), 0, "test_is_prime(1)");
    ASSERT_int(is_prime(2), 1, "test_is_prime(2)");
    ASSERT_int(is_prime(3), 1, "test_is_prime(3)");
    ASSERT_int(is_prime(4), 0, "test_is_prime(4)");
    ASSERT_int(is_prime(5), 1, "test_is_prime(5)");
    ASSERT_int(is_prime(6), 0, "test_is_prime(6)");
    ASSERT_int(is_prime(7), 1, "test_is_prime(7)");
    ASSERT_int(is_prime(8), 0, "test_is_prime(8)");
    ASSERT_int(is_prime(51), 0, "test_is_prime(51)");
}

void test_number_theory_functions() {
    printf("Testing number theory functions...\n"); printf("\n");
    test_is_prime(); printf("\n");
    printf("\n");
}


////////////////////////////
// CRYPTOGRAPHY FUNCTIONS //
////////////////////////////

void test_sha256() {
    ASSERT_strings(sha256("RedBlueBlock"), "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d", "test_sha512('hello')", 1);
    ASSERT_strings(sha256("world"), "486ea46224d1e0b4c1b6f0d61c4a1e0f0a9b6d3a", "test_sha512('world')", 1);
}
void test_cryptography_functions() {
    printf("Testing cryptography functions...\n"); printf("\n");
    test_sha256(); printf("\n");
    printf("\n");
}


void run_tests() {
    printf("\n----UNIT TESTS----\n\n");
    test_sorting_algorithms();
    test_rounding_functions();
    test_power_functions();
    test_statistics_functions();
    test_number_theory_functions();
    test_cryptography_functions();
    int totalTests = passed + failed;
    printf("*************************\n PASSED: %d%% (%d tests)\n*************************\n\n", (int)((passed/totalTests)*100),  totalTests);
}