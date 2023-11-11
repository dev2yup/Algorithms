// 1149. RGB거리 (다이나믹 프로그래밍, 동적 계획법)

#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    int cost[MAX][3]; // 각 집에 칠하는 비용 받는 배열
    int dp[MAX][3]; // 비용의 합을 저장 (메모이제이션)

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> cost[i][j];
        }
    }

    dp[0][0] = dp[0][1] = dp[0][2] = 0; // 0번째 집은 존재하지 않으므로 0으로 초기화

    for (int i = 1; i <= N; i++)
    {
        // 점화식
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0]; // i번째 집이 R로 칠할 때 최소 값 (i-1번째 dp에서 R 제외한 최소 비용)
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1]; // i번째 집이 G로 칠할 때 최소 값 (i-1번째 dp에서 G 제외한 최소 비용)
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2]; // i번째 집이 B로 칠할 때 최소 값 (i-1번째 dp에서 B 제외한 최소 비용)
    }

    cout << min(min(dp[N][0], dp[N][1]), dp[N][2]);
    
    return 0;
}

// 예제 입력

// 6
// 30 19 5
// 64 77 64
// 15 19 97
// 4 71 57
// 90 86 84
// 93 32 91

// 예제 출력
// 208