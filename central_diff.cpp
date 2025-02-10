#include <iostream>
#include <vector>
using namespace std;

void central_difference(vector<double> &x, vector<double> &y, int n)
{
    vector<double> differences = y;
    for (int step = 1; step < n; step++)
    {
        cout << "Step " << step << ": ";
        for (int i = 0; i < n - step; i++)
        {
            differences[i] = (differences[i] + differences[i + 1]) / 2;
            cout << differences[i] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    cin >> n;

    vector<double> x(n), y(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    central_difference(x, y, n);

    return 0;
}
