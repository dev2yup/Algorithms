// 스도쿠 (백트래킹)
#include <iostream>
#define square(x, y) ((x/3)*3+y/3)
//((x/3)+1+((y/3)*3))
#define MAX 9
using namespace std;

int sudoku[MAX][MAX];
bool col[MAX][MAX+1];
bool row[MAX][MAX+1];
bool square[MAX][MAX+1];

void input() // 입력받을 때마다 해당 위치에 값이 존재한다는 것을 기록
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
            if (sudoku[i][j] != 0)
            {
                row[i][sudoku[i][j]] = true; // i열에 값 sudoku[i][j]는 존재합니다.
                col[j][sudoku[i][j]] = true; // j행에 값 sudoku[i][j]는 존재합니다.
                square[square(i, j)][sudoku[i][j]] = true; // n번째 사각형에 값 sudoku[i][j]는 존재합니다.
            }
        }
    }
}

void print_sudoku()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }
}

void dfs(int n)
{
    if (n == 81)
    {
        print_sudoku();
        exit(0);
    }

    int x = n / 9; // 행
    int y = n % 9; // 열

    if (sudoku[x][y] == 0)
    {
        for (int i = 1; i < 10; i++)
        {
            if (!row[x][i] && !col[y][i] && !square[square(x, y)][i])
            {
                row[x][i] = col[y][i] = square[square(x,y)][i] = true;
                sudoku[x][y] = i;
                dfs(n+1);
                row[x][i] = col[y][i] = square[square(x,y)][i] = false;
                sudoku[x][y] = 0;
            }
        }
    }

    else
        dfs(n+1);
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    input();
    dfs(0);

    return 0;
}

// 예제 입력
// 0 3 5 4 6 9 2 7 8
// 7 8 2 1 0 5 6 0 9
// 0 6 0 2 7 8 1 3 5
// 3 2 1 0 4 6 8 9 7
// 8 0 4 9 1 3 5 0 6
// 5 9 6 8 2 0 4 1 3
// 9 1 7 6 5 2 0 8 0
// 6 0 3 7 0 1 9 5 2
// 2 5 8 3 9 4 7 6 0

// 예제 출력
// 1 3 5 4 6 9 2 7 8
// 7 8 2 1 3 5 6 4 9
// 4 6 9 2 7 8 1 3 5
// 3 2 1 5 4 6 8 9 7
// 8 7 4 9 1 3 5 2 6
// 5 9 6 8 2 7 4 1 3
// 9 1 7 6 5 2 3 8 4
// 6 4 3 7 8 1 9 5 2
// 2 5 8 3 9 4 7 6 1