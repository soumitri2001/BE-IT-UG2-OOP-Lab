/*
Complete the class with all function definitions for a stack
Now, create a stack with size 10, push 2, 3, 4 and 5 in that order and finally pop one element. Display elements
present in the stack.
*/

#include <iostream>
using namespace std;

class Stack
{
private:
    int *buffer;
    int top;
    int size;

public:
    Stack(int);     //create a stack with specified size
    void push(int); //push the specified item
    int pop();      //return the top element
    void disp();    //displays elements in the stack in top to bottom order
};

Stack::Stack(int sz)
{
    size = sz;
    buffer = (int *)malloc(size * sizeof(int));
    top = -1;
}

void Stack::push(int x)
{
    if (top == size - 1)
    {
        cout << "Overflow\n";
        return;
    }
    buffer[++top] = x;
}

int Stack::pop()
{
    if (top == -1)
        return -99999;
    else
        return buffer[top--];
}

void Stack::disp()
{
    cout << "Contents of stack:\n";
    int ptr = top;
    while (ptr >= 0)
    {
        cout << buffer[ptr--] << " ";
    }
    cout << "\n";
}

int main()
{
    Stack st(10);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.disp();
    int d = st.pop();
    st.disp();
    st.push(6);
    st.disp();
}