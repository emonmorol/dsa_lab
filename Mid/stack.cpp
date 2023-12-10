#include <iostream>
using namespace std;
// STACK USING ARRAY

int stack[100];
int top = -1;

void PUSH(int data) {
    if (top >= 100) return;
    stack[++top] = data;
}
void POP() {
    if (top == -1) return;
    top--;
}
int PEEK() {
    if (top == -1) return -1;
    return stack[top];
}
bool isEmpty() {
    if (top == -1)
        return true;
    else
        return false;
}

int main() {
    return 0;
}