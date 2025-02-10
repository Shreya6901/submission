#include <iostream>
#include <vector>
using namespace std;

void forward_difference(vector<int> &x, vector<int> &y, int n)
{
    vector<int> differences = y;
    for (int step = 1; step < n; step++)
    {
        cout << "Step " << step << ": ";
        for (int i = 0; i < n - step; i++)
        {
            differences[i] = differences[i + 1] - differences[i];
            cout << differences[i] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> x(n), y(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    forward_difference(x, y, n);

    return 0;
}
