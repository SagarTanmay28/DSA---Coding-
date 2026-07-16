#include <iostream>
using namespace std;

class Node {

public:

    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Stack {

    Node *topNode;
    int cnt;

public:

    Stack() {
        topNode = NULL;
        cnt = 0;
    }

    bool isEmpty() {
        return topNode == NULL;
    }

    void push(int x) {

        Node *temp = new Node(x);

        temp->next = topNode;
        topNode = temp;

        cnt++;
    }

    void pop() {

        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        Node *temp = topNode;

        topNode = topNode->next;

        delete temp;

        cnt--;
    }

    int top() {

        if (isEmpty())
            return -1;

        return topNode->data;
    }

    int size() {
        return cnt;
    }

    void display() {

        Node *temp = topNode;

        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    ~Stack() {

        while (topNode) {

            Node *temp = topNode;

            topNode = topNode->next;

            delete temp;
        }
    }
};

int main() {

    Stack st;

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

Advantages over Array

1. Dynamic Size
2. No Overflow until memory is exhausted
3. No contiguous memory required

Disadvantages

1. Extra memory for pointer
2. Slightly slower due to pointer traversal

*/
