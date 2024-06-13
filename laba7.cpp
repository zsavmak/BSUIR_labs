#include <iostream>

using namespace std;

int main()
{
    double q = -2.25, e = 0.0004, d0;
    int d = 4, n = 5;
    double x[6], x0[6],  a[6][6], b[6];
    a[0][0] = a[4][4] = q;
    b[1] = b[2] = b[3] = d;
    a[1][0] = a[0][1] = a[2][1] = a[1][2] = a[3][2] = a[2][3] = a[3][4] = a[4][3] = 1;
    a[1][1] = a[2][2] = a[3][3] = -2;
    for (double w = 0.2; w <= 2; w += 0.2)
    {
        for (int i = 0; i < n; i++)
            x0[i] = x[i] = 1;

        int it = 0;
        double de = 1000;
        while (it < 100 && de > e){
            double g;
            for (int i = 0; i < n; i++)
            {
                g = b[i];

                for (int j = 0; j < n; j++)
                {
                    if (i == j) continue;
                    g = g - a[i][j] * x0[j];
                }
                g = g / a[i][i];

                g = w * g + (1 - w) * x[i];
                d0 = abs(x[i] - g);
                x[i] = g;
                if (d0 < de) de = d0;
                else continue;


            }

            it = it + 1;
            for (int i = 0; i < n; i++)
                x0[i] = x[i];

        }

        cout << "w = " << w << "; e = " << de << "; it = " << it << endl;
    }
    return 0;
}
