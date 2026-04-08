#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

// ====================== Пример функции ======================
double f(double x) {
    return pow(x, 3) - 2 * x - 5;
}

double f_prime(double x) {
    return 3 * pow(x, 2) - 2;
}

// ====================== Метод Ньютона ======================
double newton_method(double x0, double tol = 1e-10, int max_iter = 50) {
    double x = x0;
    cout << fixed << setprecision(10);
    cout << "Метод Ньютона:\n";
    for (int i = 0; i < max_iter; ++i) {
        double fx = f(x);
        double fpx = f_prime(x);
        if (abs(fpx) < 1e-12) {
            cout << "Производная близка к нулю\n";
            break;
        }
        double x_new = x - fx / fpx;
        cout << "Итерация " << i << ": x = " << x << ", f(x) = " << fx << "\n";
        if (abs(x_new - x) < tol) {
            cout << "Корень найден: x ≈ " << x_new << "\n\n";
            return x_new;
        }
        x = x_new;
    }
    cout << "Метод не сошелся за " << max_iter << " итераций\n\n";
    return x;
}

// ====================== Метод парабол ======================
double parabolic_method(double x0, double x1, double x2, double tol = 1e-10, int max_iter = 50) {
    cout << "Метод парабол:\n";
    for (int i = 0; i < max_iter; ++i) {
        double f0 = f(x0), f1 = f(x1), f2 = f(x2);
        cout << "Итерация " << i << ": x0=" << x0 << ", x1=" << x1 << ", x2=" << x2
            << ", f2=" << f2 << "\n";

        double h1 = x1 - x2, h0 = x0 - x2;
        double f21 = (f1 - f2) / h1;
        double f20 = (f0 - f2) / h0;
        double a = (f20 - f21) / (h0 - h1);
        double b = f21 + a * h1;
        double c = f2;

        double disc = b * b - 4 * a * c;
        if (disc < 0) {
            cout << "Комплексный корень (дискриминант < 0)\n";
            break;
        }
        double sqrt_disc = sqrt(disc);

        double z1 = (-b + sqrt_disc) / (2 * a);
        double z2 = (-b - sqrt_disc) / (2 * a);
        double z = (abs(z1) < abs(z2)) ? z1 : z2;

        double x_new = x2 + z;

        if (abs(x_new - x2) < tol) {
            cout << "Корень найден: x = " << x_new << "\n\n";
            return x_new;
        }

        x0 = x1; x1 = x2; x2 = x_new;
    }
    cout << "Метод не сошелся за " << max_iter << " итераций\n\n";
    return x2;
}

// ====================== Метод обратной параболы ======================
double inverse_parabolic_method(double x0, double x1, double x2, double tol = 1e-10, int max_iter = 50) {
    cout << "Метод обратной параболы:\n";
    for (int i = 0; i < max_iter; ++i) {
        double f0 = f(x0), f1 = f(x1), f2 = f(x2);
        cout << "Итерация " << i << ": x0=" << x0 << ", x1=" << x1 << ", x2=" << x2
            << ", f2=" << f2 << "\n";

        if (abs(f0) < 1e-12 || abs(f1) < 1e-12 || abs(f2) < 1e-12) {
            cout << "Корень найден (f=0): x = " << (abs(f0) < 1e-12 ? x0 : abs(f1) < 1e-12 ? x1 : x2) << "\n\n";
            return abs(f0) < 1e-12 ? x0 : abs(f1) < 1e-12 ? x1 : x2;
        }

        double a = ((x2 - x1) * (f0 - f2) - (x2 - x0) * (f1 - f2)) /
            ((f0 - f2) * (f1 - f2) * (f0 - f1));
        double b = ((x2 - x0) * (f1 * f1 - f2 * f2) - (x2 - x1) * (f0 * f0 - f2 * f2)) /
            ((f0 - f2) * (f1 - f2) * (f0 - f1));
        double c = x2 - a * f2 * f2 - b * f2;

        double x_new = c;

        if (abs(x_new - x2) < tol) {
            cout << "Корень найден: x ≈ " << x_new << "\n\n";
            return x_new;
        }

        x0 = x1; x1 = x2; x2 = x_new;
    }
    cout << "Не сошлось за " << max_iter << " итераций.\n\n";
    return x2;
}

int main() {
    cout << "Решение уравнения f(x) = x^3 - 2x - 5 = 0\n\n";

    double x_newton = newton_method(2.0);

    double x_parab = parabolic_method(1.0, 2.0, 3.0);
    double x_inv = inverse_parabolic_method(1.0, 2.0, 3.0);

    cout << "Итоговые приближения:\n";
    cout << "Ньютон:             " << x_newton << "\n";
    cout << "Метод парабол:      " << x_parab << "\n";
    cout << "Обратная парабола:  " << x_inv << "\n";

    return 0;
}