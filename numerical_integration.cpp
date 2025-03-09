#include <iostream>
#include <vector>
using namespace std;

double func(double x)
{
    return 1 / (1 + x * x); // Example function: 1 / (1 + x^2)
}

void trapezoidal(int n, double lower, double upper)
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

    cout << "Trapezoidal Rule Integral: " << integral << "\n";
}

void simpson13(int n, double lower, double upper)
{
    if (n % 2 != 0)
    {
        cout << "Simpson's 1/3 Rule requires even intervals.\n";
        return;
    }

    vector<double> x(n + 1), y(n + 1);
    double h = (upper - lower) / n;

    for (int i = 0; i <= n; i++)
    {
        x[i] = lower + i * h;
        y[i] = func(x[i]);
    }

    double integral = y[0] + y[n];
    for (int i = 1; i < n; i += 2)
    {
        integral += 4 * y[i];
    }
    for (int i = 2; i < n; i += 2)
    {
        integral += 2 * y[i];
    }
    integral *= (h / 3);

    cout << "Simpson's 1/3 Rule Integral: " << integral << "\n";
}

void simpson38(int n, double lower, double upper)
{
    if (n % 3 != 0)
    {
        cout << "Simpson's 3/8 Rule requires intervals to be a multiple of 3.\n";
        return;
    }

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
        if (i % 3 == 0)
            integral += 2 * y[i];
        else
            integral += 3 * y[i];
    }
    integral *= (3 * h / 8);

    cout << "Simpson's 3/8 Rule Integral: " << integral << "\n";
}

int main()
{
    int n, choice;
    double lower, upper;

    cout << "Enter the number of intervals: ";
    cin >> n;
    cout << "Enter lower limit: ";
    cin >> lower;
    cout << "Enter upper limit: ";
    cin >> upper;

    cout << "Choose the method number:\n";
    cout << "1. Trapezoidal Rule\n";
    cout << "2. Simpson's 1/3 Rule\n";
    cout << "3. Simpson's 3/8 Rule\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        trapezoidal(n, lower, upper);
        break;
    case 2:
        simpson13(n, lower, upper);
        break;
    case 3:
        simpson38(n, lower, upper);
        break;
    default:
        cout << "Invalid choice!\n";
    }

    return 0;
}
