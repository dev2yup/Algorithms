//도키도키 간식드리미

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    queue<int> current_queue; // 현재 줄 서있는 길
    stack<int> side_stack; // 옆 길
    int students, entry_count = 1; // 승환이 앞 학생 수, 들어가야 할 번호

    cin >> students;

    for (int i = 0; i < students; i++)
    {   
        int number;
        cin >> number;
        current_queue.push(number);
    }

    while (!current_queue.empty())
    {
        if (current_queue.front() > entry_count) // 들어가야할 번호보다 맨 앞 사람의 번호가 크면
        {
            if (!side_stack.empty())
            {
                if (side_stack.top() == entry_count) // 옆길의 top을 검사해서 들어가야할 번호인지 확인
                {
                    side_stack.pop();
                    ++entry_count;
                }
                else
                {
                    side_stack.push(current_queue.front()); // 아니면 옆길로 보냄
                    current_queue.pop();
                }
            }
            else
            {
                side_stack.push(current_queue.front()); // 옆길로 보냄
                current_queue.pop();
            }
        }
        else // 들어가야 할 번호이면 입장
        {
            entry_count++;
            current_queue.pop();
        }
    }

    while (!side_stack.empty())
    {
        if (side_stack.top() != entry_count) // 들어가야 할 번호와 스택(옆 길)의 top이랑 같지 않으면 Sad
        {
            cout << "Sad";
            return 0;
        }
        else 
        {
            side_stack.pop();
            entry_count++;
        }
    }

    cout << "Nice";
    return 0;
}

// 예제 입력 
// 5
// 5 4 1 3 2

// 3
// 2 1 3
// 예제 출력 
// Nice

// Nice