// N-queen 문제
#include <iostream>
#define MAX 15
using namespace std;

int n;
int queen_col[MAX];
int cnt;

bool promising(int row)
{
    // 같은 행 또는 열에 있거나 대각선에 있을 경우.
    for (int i = 0; i < row; i++)
    {
        if (queen_col[i] == queen_col[row] || ( abs(row-i) == abs(queen_col[row] - queen_col[i]) ))
        {
            return false;
        }
    }
    return true;
}

void dfs(int row)
{
    if (row == n)
    {
        cnt++;
        return ;
    }

    for (int col = 0; col < n; col++)
    {
        queen_col[row] = col;
        if (promising(row))
        {
            dfs(row + 1);
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    dfs(0);

    cout << cnt;

    return 0;
}