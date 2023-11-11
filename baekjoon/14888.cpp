// 14888 연산자 끼워넣기
#include <iostream>
#define MAX 12
using namespace std;

int n;
int sequence[MAX]; // 수열 
int operators[4]; // 연산자 개수
int my_max = -1000000001;
int my_min = 1000000001;

void dfs(int result, int idx)
{
    if (idx == n)
    {
        if (result > my_max)
        {
            my_max = result;
        }

        if (result < my_min)
        {
            my_min = result;
        }
        return ;
    }

    for (int i = 0; i < 4; i++)
    {   
        if (operators[i] > 0)
        {
            operators[i]--; // 연산자를 사용했으므로

            switch (i)
            {
            case 0: // 덧셈
                dfs(result + sequence[idx], idx+1);
                break;
            case 1: // 뺄셈
                dfs(result - sequence[idx], idx+1);
                break;
            case 2: // 곱셈
                dfs(result * sequence[idx], idx+1);
                break;
            case 3: // 나눗셈
                dfs(result / sequence[idx], idx+1);
                break;
            default:
                break;
            }

            operators[i]++; // 다른 연산자로 순서 바꿔서 사용하기 위해 다시 개수 늘려줌
        }
    }
    return ;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> sequence[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> operators[i];
    }

    dfs(sequence[0], 1);

    cout << my_max << '\n' << my_min;

    return 0;
}