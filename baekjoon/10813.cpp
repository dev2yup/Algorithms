#include <iostream>
using namespace std;

void swap_ball(int *first, int *second)
{
    int tmp;
    tmp = (*first);
    (*first) = (*second);
    (*second) = tmp;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M;
    int i, j;
    cin >> N >> M;
    int basket[N] = {0, };
    for (int itr = 1; itr <= N; itr++) // 처음에는 바구니에 적혀있는 번호와 같은 번호가 적힌 공이 들어있다.
    {
        basket[itr-1] = itr;
    }
    
    for (int itr = 0; itr < M; itr++)
    {
        cin >> i >> j;
        swap_ball(&basket[i-1], &basket[j-1]);
    }

    for (int itr = 0; itr < N; itr++)
    {
        cout << basket[itr] << ' ';
    }

    return 0;
}