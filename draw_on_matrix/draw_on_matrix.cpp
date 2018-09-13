#include <cstdlib>
#include <iostream>

using namespace std;

void delete_color(char** c, int n, int m, int x, int y, int color){
    int i = x, j = y;
    if (color == 1){
        while (i < n && j >= 0 && (c[i][j] == 'B' || c[i][j] == 'G')){
            c[i][j] = (c[i][j] == 'B' ? 'X' : 'Y');
            i++;
            j--;
        }
        i = x - 1;
        j = y + 1;
        while (i >= 0 && j < m && (c[i][j] == 'B' || c[i][j] == 'G')){
            c[i][j] = (c[i][j] == 'B' ? 'X' : 'Y');
            i--;
            j++;
        }
    }
    else{
        while (i < n && j < m && (c[i][j] == 'Y' || c[i][j] == 'G')){
            c[i][j] = (c[i][j] == 'Y' ? 'X' : 'B');
            i++;
            j++;
        }
        i = x - 1;
        j = y - 1;
        while (i >= 0 && j >= 0 && (c[i][j] == 'Y' || c[i][j] == 'G')){
            c[i][j] = (c[i][j] == 'Y' ? 'X' : 'B');
            i--;
            j--;
        }
    }
    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    char **c;
    c = new char*[n];
    for (int i = 0; i < n; i++) c[i] = new char[m];
    int x = -1, y = -1;
    int times = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> c[i][j];
    while (1){
        x = -1;
        y = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (c[i][j] != 'X'){
                    x = i;
                    y = j;
                }
        if (x == -1 && y == -1) break;
        else{
            if (c[x][y] == 'Y')    delete_color(c, n, m, x, y, -1);
            else delete_color(c, n, m, x, y, 1);
            times++;
            cout << "===" << endl;
            for (int ii = 0; ii < n; ii++){
                for (int jj = 0; jj < m; jj++){
                    cout << c[ii][jj] << " ";
                }
                cout << endl;
            }

            cout << "===" << endl;
        }
    }
    cout << times << endl;
    return 0;
}

