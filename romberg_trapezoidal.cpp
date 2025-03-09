#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double func(double x)
{
    return 1 / (1 + x * x); // Example function: 1 / (1 + x^2)
}

double trapezoidal(int n, double lower, double upper)
{
    vector<double> x(n + 1), y(n + 1);
    double h = (upper - lower) / n;

    for (int i = 0; i <= n; i++)
    {
        x[i] = lower + i * h;
        y[i] = func(x[i]);
    }

    double integral = y[0] + y[n];
    for (int i = 1; i < n; i++)
    {
        integral += 2 * y[i];
    }
    integral *= (h / 2);
    return integral;
}

void romberg(double lower, double upper)
{
    double I1 = trapezoidal(2, lower, upper);
    double I2 = trapezoidal(4, lower, upper);
    double I = I2 + ((I2 - I1) / 3.0);
    double I3 = trapezoidal(8, lower, upper);
    double IP = I3 + ((I3 - I2) / 3.0);
    int n = 8;

    while (abs(IP - I) > 0.0001)
    {
        I = IP;
        I2 = I3;
        n *= 2;
        I3 = trapezoidal(n, lower, upper);
        IP = I3 + ((I3 - I2) / 3.0);
    }

    cout << "Romberg's Method Integral: " << IP << "\n";
}

int main()
{
    double lower, upper;
    cout << "Enter lower limit: ";
    cin >> lower;
    cout << "Enter upper limit: ";
    cin >> upper;

    romberg(lower, upper);
    return 0;
}
