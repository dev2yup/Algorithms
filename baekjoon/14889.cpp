// 스타트와 링크
#include <iostream>
#include <cmath>
#define MAX 22
using namespace std;

int N;
int synergy[MAX][MAX];
int check[MAX];
int min_diff = 20000;

void dfs(int cnt, int pos) // pos는 다음 값
{
    if (cnt == N / 2)
    {
        int start = 0, link = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (check[i] == true && check[j] == true) start += synergy[i][j];
                if (check[i] == false && check[j] == false) link += synergy[i][j];
            }
        }

        int temp = abs(start - link);
        if (temp < min_diff) min_diff = temp;

        return ;
    }

    for (int i = pos; i <= N - 1; i++) // N 까지 반복문 돌리면 팀에 중복이 발생함
    {
        check[i] = true;
        dfs(cnt+1, i+1);
        check[i] = false;
    }
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> synergy[i][j];
        }
    }

    dfs(0, 1); 

    cout << min_diff;

    return 0;
}