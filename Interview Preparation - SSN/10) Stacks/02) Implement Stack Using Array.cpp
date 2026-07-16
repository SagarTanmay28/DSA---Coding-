#include <iostream>
using namespace std;

class Stack {

    int *arr;
    int topIndex;
    int capacity;

public:

    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == capacity - 1;
    }

    void push(int x) {

        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++topIndex] = x;
    }

    void pop() {

        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        topIndex--;
    }

    int top() {

        if (isEmpty())
            return -1;

        return arr[topIndex];
    }

    int size() {
        return topIndex + 1;
    }

    void display() {

        if (isEmpty()) {
            cout << "Stack Empty\n";
            return;
        }

        for (int i = topIndex; i >= 0; i--)
            cout << arr[i] << " ";

        cout << endl;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {

    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    st.display();

    cout << "Top : " << st.top() << endl;

    st.pop();

    st.display();

    cout << "Size : " << st.size() << endl;

    return 0;
}

/*

Time Complexity

Push    O(1)
Pop     O(1)
Top     O(1)
Size    O(1)
Display O(n)

Space Complexity

O(n)

*/
