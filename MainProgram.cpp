// =============================================================================
// Lab Title  : Introduction to Pointers in C++
// Course     : CMP1001 -- Introduction to Programming (C++)
// File       : MainProgram_teacher.cpp   <<<< TEACHER VERSION -- DO NOT DISTRIBUTE
// =============================================================================

#include <iostream>
using namespace std;

// =============================================================================
// SECTION 1 -- WARM-UP
// =============================================================================

// TODO 1: return the pointer argument unchanged
int* getAddress(int* p)
{
    return p;  // p already IS the address of the caller's variable
}

// TODO 2: dereference and return the value
int readValue(const int* p)
{
    return *p;
}

void section1_warmup()
{
    cout << "\n===== SECTION 1: Warm-Up =====\n";

    int age = 20;
    int* result = getAddress(&age);
    cout << "Address of age    : " << &age   << "\n";
    cout << "Returned by func  : " << result << "\n";
    cout << "Match? (1=yes)    : " << (result == &age) << "\n";  // 1

    int score = 99;
    cout << "Value via pointer : " << readValue(&score) << "\n";  // 99
}

// =============================================================================
// SECTION 2 -- CORE CONCEPTS
// =============================================================================

// TODO 3: write newVal through the pointer
void writeValue(int* p, int newVal)
{
    *p = newVal;
}

// TODO 4: check for nullptr
bool isNullptr(int* p)
{
    return p == nullptr;
}

// TODO 5: add amount through double pointer
void addThroughPointer(double* p, double amount)
{
    *p += amount;
}

void section2_core_concepts()
{
    cout << "\n===== SECTION 2: Core Concepts =====\n";

    int temperature = 36;
    cout << "temperature before : " << temperature << "\n";
    writeValue(&temperature, 100);
    cout << "temperature after  : " << temperature << "\n";  // 100

    int* pNull = nullptr;
    int  val   = 5;
    cout << "isNullptr(nullptr) : " << isNullptr(pNull) << "\n";  // 1
    cout << "isNullptr(&val)    : " << isNullptr(&val)  << "\n";  // 0

    double price = 9.99;
    addThroughPointer(&price, 5.0);
    cout << "price after +5.0   : " << price << "\n";  // 14.99
}

// =============================================================================
// SECTION 3 -- GUIDED EXERCISES
// =============================================================================

void swapInts(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void exercise3a_swap()
{
    cout << "\n--- Exercise 3A: Swap via Pointer ---\n";
    int x = 3, y = 7;
    cout << "Before swap: x=" << x << "  y=" << y << "\n";
    swapInts(&x, &y);
    cout << "After swap : x=" << x << "  y=" << y << "\n";
}

int getElementByOffset(const int* ptr, int offset)
{
    return *(ptr + offset);
}

void exercise3b_pointer_arithmetic()
{
    cout << "\n--- Exercise 3B: Pointer Arithmetic ---\n";
    int numbers[] = {10, 20, 30, 40, 50};
    int* p = numbers;
    cout << "Array via pointer: ";
    for (int i = 0; i < 5; i++) { cout << *p << " "; p++; }
    cout << "\n";
    cout << "Element at offset 3 : " << getElementByOffset(numbers, 3) << "\n";
    cout << "Element at offset 0 : " << getElementByOffset(numbers, 0) << "\n";
}

void fillArray(int* arr, int size)
{
    for (int i = 0; i < size; i++) arr[i] = i * 10;
}

int sumArray(const int* arr, int size)
{
    int total = 0;
    for (int i = 0; i < size; i++) total += arr[i];
    return total;
}

void exercise3c_array_pointer()
{
    cout << "\n--- Exercise 3C: Array via Pointer ---\n";
    const int SIZE = 6;
    int data[SIZE];
    fillArray(data, SIZE);
    cout << "Filled array: ";
    for (int i = 0; i < SIZE; i++) cout << data[i] << " ";
    cout << "\n";
    cout << "Sum of array: " << sumArray(data, SIZE) << "\n";
}

// =============================================================================
// SECTION 4 -- CHALLENGE
// =============================================================================

void findMinMax(const int* arr, int size, int* minVal, int* maxVal)
{
    *minVal = arr[0];
    *maxVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < *minVal) *minVal = arr[i];
        if (arr[i] > *maxVal) *maxVal = arr[i];
    }
}

void challengeA_minMax()
{
    cout << "\n--- Challenge A: Min & Max via Pointer ---\n";
    int scores[] = {42, 17, 98, 55, 3, 76};
    int lo, hi;
    findMinMax(scores, 6, &lo, &hi);
    cout << "Min: " << lo << "\n";
    cout << "Max: " << hi << "\n";
}

void reverseArray(int* arr, int size)
{
    int* left  = arr;
    int* right = arr + size - 1;
    while (left < right)
    {
        int temp = *left;
        *left    = *right;
        *right   = temp;
        left++;
        right--;
    }
}

void challengeB_reverse()
{
    cout << "\n--- Challenge B: Reverse Array in Place ---\n";
    int vals[] = {1, 2, 3, 4, 5};
    int n = 5;
    cout << "Before: ";
    for (int i = 0; i < n; i++) cout << vals[i] << " ";
    cout << "\n";
    reverseArray(vals, n);
    cout << "After : ";
    for (int i = 0; i < n; i++) cout << vals[i] << " ";
    cout << "\n";
}

// =============================================================================
// MAIN
// =============================================================================
#ifndef NO_MAIN
int main()
{
    section1_warmup();
    section2_core_concepts();
    exercise3a_swap();
    exercise3b_pointer_arithmetic();
    exercise3c_array_pointer();
    challengeA_minMax();
    challengeB_reverse();
    cout << "\n===== Lab Complete =====\n";
    return 0;
}
#endif // NO_MAIN
