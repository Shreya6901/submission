#include <iostream>
#include <vector>
using namespace std;

double func(double x, double y)
{
    return 1 / (1 + x + y); // Example function: 1 / (1 + x + y)
}

double trapezoidal_double_integral(double xl, double xu, double yl, double yu, double h, double k)
{
    int n = (xu - xl) / h + 1;
    int m = (yu - yl) / k + 1;
    vector<vector<double>> z(m, vector<double>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            z[i][j] = func(xl + j * h, yl + i * k);
        }
    }

    double integral = 0.0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == 0 || i == m - 1) && (j == 0 || j == n - 1))
                integral += z[i][j];
            else if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                integral += 2 * z[i][j];
            else
                integral += 4 * z[i][j];
        }
    }
    integral *= (h * k) / 4.0;
    return integral;
}

double simpson_double_integral(double xl, double xu, double yl, double yu, double h, double k)
{
    int n = (xu - xl) / h + 1;
    int m = (yu - yl) / k + 1;
    vector<vector<double>> z(m, vector<double>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            z[i][j] = func(xl + j * h, yl + i * k);
        }
    }

    double integral = 0.0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == 0 || i == m - 1) && (j == 0 || j == n - 1))
                integral += z[i][j];
            else if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                integral += 4 * z[i][j];
            else
                integral += 16 * z[i][j];
        }
    }
    integral *= (h * k) / 9.0;
    return integral;
}

int main()
{
    double xl, xu, yl, yu, h, k;
    cout << "Enter lower limit of x: ";
    cin >> xl;
    cout << "Enter upper limit of x: ";
    cin >> xu;
    cout << "Enter lower limit of y: ";
    cin >> yl;
    cout << "Enter upper limit of y: ";
    cin >> yu;
    cout << "Enter step size h: ";
    cin >> h;
    cout << "Enter step size k: ";
    cin >> k;

    double trap_result = trapezoidal_double_integral(xl, xu, yl, yu, h, k);
    double simpson_result = simpson_double_integral(xl, xu, yl, yu, h, k);

    cout << "Double Integral using Trapezoidal Rule: " << trap_result << "\n";
    cout << "Double Integral using Simpson's 1/3 Rule: " << simpson_result << "\n";

    return 0;
}
