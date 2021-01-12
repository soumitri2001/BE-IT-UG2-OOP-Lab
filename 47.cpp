/*
47. Design a class Stack with necessary exception handling.
*/

#include <iostream>
using namespace std;

// Exception classes

class OverflowException
{
public:
    OverflowException() {}
};

class UnderflowException
{
public:
    UnderflowException() {}
};

// Stack class

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
        throw OverflowException();
    else
        buffer[++top] = x;
}

int Stack::pop()
{
    if (top == -1)
        throw UnderflowException();
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
    Stack st(5);

    try
    {
        // int d1 = st.pop(); // UnderflowException should be thrown
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);
        st.disp();
        int d = st.pop();
        st.disp();
        st.push(6);
        st.push(7);
        st.disp();
        st.push(8); // OverflowException should be thrown
        st.disp();
        d = st.pop();
        st.disp();
    }
    catch (UnderflowException e)
    {
        cout << "Stack is already empty !\n";
    }
    catch (OverflowException e)
    {
        cout << "Stack overflown !\n";
    }
}