#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <string>
using namespace std;

// Function to input vector elements
void inputVector(vector<int> &vec, const string &name) {
    size_t n;
    cout << "Enter the size of vector " << name << ": ";
    cin >> n;
    vec.resize(n);
    cout << "Enter elements of vector " << name << ": \n";
    for (size_t i = 0; i < n; ++i) {
        cin >> vec[i];
    }
}

// Function to print vector elements
void printVector(const vector<int> &vec, const string &name) {
    cout << "Vector " << name << ": ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// Function to calculate Euclidean distance between two vectors
double euclideanDistance(const vector<int> &a, const vector<int> &b) {
    double sum = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        sum += pow(a[i] - b[i], 2);
    }
    return sqrt(sum);
}

// Function to calculate dot product of two vectors
int dotProduct(const vector<int> &a, const vector<int> &b) {
    return inner_product(a.begin(), a.end(), b.begin(), 0);
}

// Function to calculate the magnitude of a vector
double magnitude(const vector<int> &vec) {
    double sum = 0;
    for (int val : vec) {
        sum += val * val;
    }
    return sqrt(sum);
}

// Function to calculate the angle between two vectors
double calculateAngle(const vector<int> &a, const vector<int> &b) {
    double dot = dotProduct(a, b);
    double magA = magnitude(a);
    double magB = magnitude(b);
    return acos(dot / (magA * magB));
}

// Function to merge and sort two vectors
vector<int> mergeAndSort(const vector<int> &a, const vector<int> &b) {
    vector<int> merged(a.begin(), a.end());
    merged.insert(merged.end(), b.begin(), b.end());
    sort(merged.begin(), merged.end());
    return merged;
}

// Insertion sort implementation
void insertionSort(vector<int> &vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

// Function to calculate mean, standard deviation, and median
void calculateStatistics(const vector<int> &vec) {
    double mean = accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
    double variance = 0;
    for (int val : vec) {
        variance += pow(val - mean, 2);
    }
    variance /= vec.size();
    double stddev = sqrt(variance);

    double median;
    if (vec.size() % 2 == 0) {
        median = (vec[vec.size() / 2 - 1] + vec[vec.size() / 2]) / 2.0;
    } else {
        median = vec[vec.size() / 2];
    }

    cout << "Mean: " << mean << endl;
    cout << "Standard Deviation: " << stddev << endl;
    cout << "Median: " << median << endl;
}

// Function to check if a vector is STARKX
bool isStarkx(const vector<int> &vec) {
    for (size_t i = 0; i < vec.size(); i += 2) {
        for (size_t j = 1; j < vec.size(); j += 2) {
            if (vec[i] <= vec[j]) return false;
        }
    }
    return true;
}

// Function to extract the largest digits from a vector and form a number
string extractLargestDigits(const vector<int> &vec) {
    string result = "";
    for (int num : vec) {
        int largestDigit = 0;
        while (num > 0) {
            largestDigit = max(largestDigit, num % 10);
            num /= 10;
        }
        result += to_string(largestDigit);
    }
    return result;
}

// Function to count digits in each vector element
vector<int> countDigits(const vector<int> &vec) {
    vector<int> digitCounts(vec.size(), 0);
    for (size_t i = 0; i < vec.size(); ++i) {
        int num = vec[i];
        while (num > 0) {
            digitCounts[i]++;
            num /= 10;
        }
    }
    return digitCounts;
}

int main() {
    // Part 1: Basic vector operations
    vector<int> A, B;
    inputVector(A, "A");
    inputVector(B, "B");

    printVector(A, "A");
    printVector(B, "B");

    cout << "Euclidean Distance: " << euclideanDistance(A, B) << endl;
    cout << "Dot Product: " << dotProduct(A, B) << endl;
    cout << "Angle (in radians): " << calculateAngle(A, B) << endl;

    vector<int> merged = mergeAndSort(A, B);
    printVector(merged, "Merged and Sorted Vector");
    calculateStatistics(merged);

    // Part 2: STARKX check
    vector<int> starkxVector;
    inputVector(starkxVector, "STARKX");
    cout << "Is STARKX: " << (isStarkx(starkxVector) ? "Yes" : "No") << endl;

    // Part 3: Largest digits and count digits
    vector<int> A_copy = A;
    cout << "Largest digits combined into a number: " << extractLargestDigits(A) << endl;

    vector<int> digitCounts = countDigits(A);
    printVector(digitCounts, "Digit Counts");

    return 0;
}
