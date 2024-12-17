#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

// Function to calculate linear regression coefficients
void calculateLinearRegression(const vector<double> &x, const vector<double> &y, double &beta1, double &beta0) {
    size_t n = x.size();
    double xSum = 0, ySum = 0, xySum = 0, xSquaredSum = 0;

    for (size_t i = 0; i < n; ++i) {
        xSum += x[i];
        ySum += y[i];
        xySum += x[i] * y[i];
        xSquaredSum += x[i] * x[i];
    }

    double xMean = xSum / n;
    double yMean = ySum / n;

    beta1 = (xySum - n * xMean * yMean) / (xSquaredSum - n * xMean * xMean);
    beta0 = yMean - beta1 * xMean;
}

// Function to interleave characters of two strings
string mergeStrings(const string &a, const string &b) {
    size_t maxLength = max(a.size(), b.size());
    string merged;
    merged.reserve(a.size() + b.size());

    for (size_t i = 0; i < maxLength; ++i) {
        if (i < a.size()) merged += a[i];
        if (i < b.size()) merged += b[i];
    }
    return merged;
}

int main() {
    // Part 1: Linear Regression
    size_t n;
    cout << "Enter the number of points n: ";
    cin >> n;

    vector<double> x(n), y(n);

    cout << "Enter the coordinates x and y: \n";
    for (size_t i = 0; i < n; ++i) {
        cout << "Point " << i + 1 << ": ";
        cin >> x[i] >> y[i];
    }

    double beta1, beta0;
    calculateLinearRegression(x, y, beta1, beta0);

    cout << "Linear regression equation: y = " << beta0 << " + " << beta1 << " * x" << endl;

    double newX, newY;
    cout << "Enter a new point (x, y): ";
    cin >> newX >> newY;

    double predictedY = beta0 + beta1 * newX;
    double error = abs(newY - predictedY);

    cout << "Predicted value of Y: " << predictedY << endl;
    cout << "Error: " << error << endl;

    // Part 2: String Manipulation
    string a, b;
    cout << "Enter the first word: ";
    cin >> a;
    cout << "Enter the second word: ";
    cin >> b;

    string merged = mergeStrings(a, b);
    cout << "Merged word: " << merged << endl;

    return 0;
}
