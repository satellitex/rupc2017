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
    double th, x = 0, y = 0;
    for (int i = 0; i < 2; i++) {
        cin >> th;
        x += cos(rad(th));
        y += sin(rad(th));
    }
    printf("%.10f\n", ang(atan2(y, x) + (1e-12)));
    return 0;
}

/*
  atan と atan2 の違いを知らなかったのでダメ
 */
