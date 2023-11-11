#include <iostream>
#define operand 1000000000
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    unsigned long long sum = 0;
    unsigned long long temp[12] = {0, };
    unsigned long long dp[12] = {0, };

    for (int i = 2; i <= 10; i++)
    {
        dp[i] = 1;
        temp[i] = 1;
    }

    cin >> N;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            temp[j] = (dp[j-1] % operand) + (dp[j+1] % operand);
        }
        for (int j = 1; j <= 10; j++)
        {
            dp[j] = temp[j];
        }
    }

    for (int i = 1; i <= 10; i++)
    {
        sum += dp[i];
    }

    cout << sum % operand;

    return 0;
}