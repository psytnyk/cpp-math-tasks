#include <iostream>
#include <iomanip>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    int v, e;
    char t;

    cout << "Матриці графа\n";

    cout << "К-ть вершин: ";
    cin >> v;
    cout << "К-ть ребер: ";
    cin >> e;
    cout << "Тип графа (o-орієнтований/n-неорієнтований): ";
    cin >> t;
    int adj[10][10] = {0};
    int inc[10][20] = {0};
    cout << "\nВершини які з'єднані(через пробіл):\n";
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cout << "Ребро " << i + 1 << ": ";
        cin >> a >> b;
        a--;
        b--;
        adj[a][b] = 1;
        if (t == 'n')
            adj[b][a] = 1;

        if (t == 'o')
        {
            inc[a][i] = 1;
            inc[b][i] = -1;
        }
        else
        {
            inc[a][i] = inc[b][i] = 1;
        }
    }

    cout << "\nМатриця суміжності:\n";
    cout << "      │";
    for (int j = 0; j < v; j++)
    {
        cout << setw(4) << ("v" + to_string(j + 1));
    }
    cout << endl;
    cout << "──────┼";
    for (int j = 0; j < v; j++)
    {
        cout << "────";
    }
    cout << endl;
    for (int i = 0; i < v; i++)
    {
        cout << setw(5) << ("v" + to_string(i + 1)) << " │";
        for (int j = 0; j < v; j++)
        {
            cout << setw(4) << adj[i][j];
        }
        cout << endl;
    }

    cout << "\nМатриця інцидентності:\n";
    cout << "      │";
    for (int j = 0; j < e; j++)
    {
        cout << setw(4) << ("e" + to_string(j + 1));
    }
    cout << endl;
    cout << "──────┼";
    for (int j = 0; j < e; j++)
    {
        cout << "────";
    }
    cout << endl;
    for (int i = 0; i < v; i++)
    {
        cout << setw(5) << ("v" + to_string(i + 1)) << " │";
        for (int j = 0; j < e; j++)
        {
            cout << setw(4) << inc[i][j];
        }
        cout << endl;
    }

    if (t == 'o')
    {
        cout << "\n 1 - ребро виходить із вершини, -1 - ребро входить у вершину\n";
    }

    return 0;
}