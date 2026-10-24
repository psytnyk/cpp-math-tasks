#include <iostream>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    int size;

    cout << "Введіть розмір матриці (2 або 3): ";
    cin >> size;
    int matrix[3][3];

    cout << "\nВведіть цілі числа для матриці(через пробіл) " << size << "x" << size << ":\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Рядок " << i + 1 << ": ";
        for (int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "\nВаша матриця A:\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(6) << matrix[i][j] << " ";
        }
        cout << endl;
    }

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
        cout << "\nОберненої матриці не існує (визначник = 0)";
        return 0;
    }

    cout << "Формула: A⁻¹ = (1/det(A)) × aij(A)\n";
    cout << "A⁻¹ = (1/" << det << ") × aij(A)\n";

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

        cout << "\nОбернена матриця:\n";
        cout << "A⁻¹ = 1/" << det << " × [  ";
        for (int i = 0; i < 2; i++)
        {
            cout << setw(4) << aij[0][i] << "  " << setw(4) << aij[1][i];
            if (i < 1)
                cout << endl
                     << "            ";
        }
        cout << "]\n";

        cout << "\nАбо:\nA⁻¹ = [  ";
        for (int i = 0; i < 2; i++)
        {
            cout << setw(4) << aij[0][i] << "/" << det << "  "
                 << setw(4) << aij[1][i] << "/" << det;
            if (i < 1)
                cout << endl
                     << "      ";
        }
        cout << "]\n";
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

        cout << "\nОбернена матриця:\n";
        cout << "A⁻¹ = 1/" << det << " × [  ";
        for (int i = 0; i < 3; i++)
        {
            cout << setw(4) << adj[0][i] << "  "
                 << setw(4) << adj[1][i] << "  "
                 << setw(4) << adj[2][i];
            if (i < 2)
                cout << endl
                     << "            ";
        }
        cout << "]\n";

        cout << "\nАбо:\nA⁻¹ = [  ";
        for (int i = 0; i < 3; i++)
        {
            cout << setw(4) << adj[0][i] << "/" << det << "  "
                 << setw(4) << adj[1][i] << "/" << det << "  "
                 << setw(4) << adj[2][i] << "/" << det;
            if (i < 2)
                cout << endl
                     << "      ";
        }
        cout << "]\n";
    }

    return 0;
}