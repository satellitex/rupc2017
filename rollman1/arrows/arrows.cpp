#include <bits/stdc++.h>

using namespace std;

constexpr double PI = acos(-1);

double rad(double ang)
{
    return ang * PI / 180;
}

double ang(double rad)
{
    return rad * 180 / PI;
}

int main()
{
    double th[2];
    for (int i = 0; i < 2; i++) {
        cin >> th[i];
    }

    double x = 0, y = 0;
    for (int i = 0; i < 2; i++) {
        x += sin(rad(th[i]));
        y += cos(rad(th[i]));
    }
    
    printf("%.10f\n", ang(atan(x / y) + (1e-12)));
    return 0;
}
