#include <iostream>
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
    cout << "Графи" << endl;

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
    cout << "\nСуміжність:\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nІнцидентність:\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < e; j++)
        {
            cout << inc[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}