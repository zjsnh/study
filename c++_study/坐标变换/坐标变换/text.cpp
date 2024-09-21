#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void fun_K(double& x, double& y, double k) {
    x = x * k;
    y = y * k;
}

void fun_O(double& x, double& y, double o) {
    double x_new = x * cos(o) - y * sin(o);
    double y_new = x * sin(o) + y * cos(o);
    x = x_new;
    y = y_new;
}

int main() {
    int n = 0, m = 0;
    cin >> n >> m;

    vector<pair<int, double>> v(n);
    vector<double> prefix_K(n + 1, 1.0);  
    vector<double> prefix_O(n + 1, 0.0);  

    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;

        if (v[i].first == 1) {
            prefix_K[i + 1] = prefix_K[i] * v[i].second;  
            prefix_O[i + 1] = prefix_O[i];  
        }
        else {
            prefix_K[i + 1] = prefix_K[i];  
            prefix_O[i + 1] = prefix_O[i] + v[i].second;  
        }
    }

    while (m--) {
        int i = 0, j = 0;
        double x = 0, y = 0;
        cin >> i >> j >> x >> y;


        double total_K = prefix_K[j] / prefix_K[i - 1];

        double total_O = prefix_O[j] - prefix_O[i - 1];

        fun_K(x, y, total_K);
        fun_O(x, y, total_O);

        printf("%0.3f ", x);
        printf("%0.3f\n", y);
    }

    return 0;
}

