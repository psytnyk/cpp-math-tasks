#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (b != 0)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

string fraction(int num, int den)
{
    if (num == 0)
        return "0";
    int g = gcd(num, den);
    num /= g;
    den /= g;
    if (den < 0)
    {
        num = -num;
        den = -den;
    }
    if (den == 1)
        return to_string(num);
    return to_string(num) + "/" + to_string(den);
}

void printBox(string cells[3][3], int n)
{
    size_t width = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (cells[i][j].length() > width)
                width = cells[i][j].length();

    for (int i = 0; i < n; i++)
    {
        string left = (i == 0) ? "┌" : (i == n - 1 ? "└" : "│");
        string right = (i == 0) ? "┐" : (i == n - 1 ? "┘" : "│");

        cout << "  " << left << " ";
        for (int j = 0; j < n; j++)
        {
            if (j > 0)
                cout << "  ";
            cout << setw(width) << cells[i][j];
        }
        cout << " " << right << endl;
    }
}

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    int size;

    cout << "   Калькулятор оберненої матриці\n";

    cout << "Введіть розмір матриці (2 або 3): ";
    cin >> size;
    int matrix[3][3];

    cout << "\nВведіть цілі числа для матриці (через пробіл) " << size << "x" << size << ":\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Рядок " << i + 1 << ": ";
        for (int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
        }
    }

    string cells[3][3];

    cout << "\nМатриця A:\n";
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cells[i][j] = to_string(matrix[i][j]);
    printBox(cells, size);

    int det;

    if (size == 2)
    {
        det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else
    {
        det = matrix[0][0] * matrix[1][1] * matrix[2][2] +
              matrix[0][1] * matrix[1][2] * matrix[2][0] +
              matrix[0][2] * matrix[1][0] * matrix[2][1] -
              matrix[0][2] * matrix[1][1] * matrix[2][0] -
              matrix[0][1] * matrix[1][0] * matrix[2][2] -
              matrix[0][0] * matrix[1][2] * matrix[2][1];
    }

    cout << "\nВизначник det(A) = " << det << endl;

    if (det == 0)
    {
        cout << "\nОберненої матриці не існує (визначник = 0)\n";
        return 0;
    }

    int result[3][3];

    if (size == 2)
    {
        int a = matrix[0][0], b = matrix[0][1];
        int c = matrix[1][0], d = matrix[1][1];

        int alg[2][2];
        alg[0][0] = d;
        alg[0][1] = -b;
        alg[1][0] = -c;
        alg[1][1] = a;

        int aij[2][2];
        aij[0][0] = alg[0][0];
        aij[0][1] = alg[1][0];
        aij[1][0] = alg[0][1];
        aij[1][1] = alg[1][1];

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result[i][j] = aij[j][i];
    }
    else
    {
        int alg[3][3];
        alg[0][0] = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
        alg[0][1] = matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2];
        alg[0][2] = matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];

        alg[1][0] = matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2];
        alg[1][1] = matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0];
        alg[1][2] = matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2];

        alg[2][0] = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];
        alg[2][1] = matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1];
        alg[2][2] = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

        int aij[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                aij[i][j] = alg[i][j];
            }
        }

        int adj[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                adj[i][j] = aij[j][i];
            }
        }

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                result[i][j] = adj[j][i];
    }

    cout << "\nФормула: A⁻¹ = (1/det(A)) × A*\n";
    cout << "A⁻¹ = (1/" << det << ") × A*\n";

    cout << "\nОбернена матриця A⁻¹ (дроби скорочено):\n";
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cells[i][j] = fraction(result[i][j], det);
    printBox(cells, size);

    return 0;
}