// 스택 2

#include <iostream>
using namespace std;

typedef struct array_stack
{
    int array_stack[1000000] = {0, };
    int top;
} AS;

void create_stack(AS** stack)
{
    (*stack) = (AS*)malloc(sizeof(AS));
    (*stack)->top = -1;
}

void push(AS* stack, int data)
{
    stack->top++;
    stack->array_stack[stack->top] = data;
}

void pop(AS* stack)
{
    if (stack->top == -1)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << stack->array_stack[stack->top] << '\n';
        stack->top--;
    }
}

void stack_count(AS* stack)
{
    cout << stack->top + 1 << '\n';
}

void is_stack_empty(AS* stack)
{
    if (stack->top == -1) cout << 1 << '\n';
    else cout << 0 << '\n';
}

void top(AS* stack)
{
    if (stack->top == -1) cout << -1 << '\n';
    else cout << stack->array_stack[stack->top] << '\n';
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int count, command, data;
    AS* stack;

    create_stack(&stack);

    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> command;
        switch (command)
        {
        case 1:
            cin >> data;
            push(stack, data);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            stack_count(stack);
            break;
        case 4:
            is_stack_empty(stack);
            break;;
        case 5:
            top(stack);
            break;
        default:
            break;
        }
    }
}