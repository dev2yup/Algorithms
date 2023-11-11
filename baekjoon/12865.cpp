#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int WV[101][2];
int dp[101][100001];


int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> WV[i][j];
        }
    }

    for (int i = 1; i <= N; i++) // i번 째 물품
    {
        for (int j = 1; j <= K; j++) // j무게일 때 최대 가치
        {
            if ( (j - WV[i][0]) >= 0 ) dp[i][j] = max(dp[i-1][j], dp[i-1][j-WV[i][0]] + WV[i][1]); // i번 째 물품을 안넣었을 때, 넣었을 때 둘 중 최대값
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[N][K];

    return 0;
}