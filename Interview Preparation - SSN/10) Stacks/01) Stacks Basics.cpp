#include <iostream>
#include <stack>
using namespace std;

/*
===========================================================
                    STACK IN C++
===========================================================

Definition:
-----------
A Stack is a Linear Data Structure that follows
LIFO (Last In First Out).

Example:

        40   <-- Top
        30
        20
        10

Push(50)

        50
        40
        30
        20
        10

Pop()

        40
        30
        20
        10


Real Life Examples
------------------
1. Browser Back Button
2. Undo/Redo
3. Function Call Stack
4. Expression Evaluation
5. DFS Traversal

===========================================================
                STL Stack Operations
===========================================================

1. push(x)
Adds an element at the top.

Time Complexity : O(1)
Space Complexity: O(1)

-----------------------------------------------------------

2. pop()
Removes the top element.

Time Complexity : O(1)
Space Complexity: O(1)

-----------------------------------------------------------

3. top()
Returns the top element.

Time Complexity : O(1)

-----------------------------------------------------------

4. empty()
Returns true if stack is empty.

Time Complexity : O(1)

-----------------------------------------------------------

5. size()
Returns number of elements.

Time Complexity : O(1)

===========================================================
Overall Complexity
===========================================================

Push    -> O(1)
Pop     -> O(1)
Top     -> O(1)
Size    -> O(1)
Empty   -> O(1)

Space Used by Stack = O(n)

===========================================================
Applications
===========================================================

1. Balanced Parentheses
2. Next Greater Element
3. Next Smaller Element
4. Previous Greater Element
5. Previous Smaller Element
6. Largest Rectangle Histogram
7. Daily Temperatures
8. Asteroid Collision
9. Remove K Adjacent Duplicates
10. Infix/Postfix/Prefix Conversion
11. Expression Evaluation
12. DFS
13. Recursion Simulation

===========================================================
*/

int main() {

    stack<int> st;

    cout << "Push Elements\n";

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Top : " << st.top() << endl;

    cout << "Size : " << st.size() << endl;

    cout << "\nPop Element\n";

    st.pop();

    cout << "Top : " << st.top() << endl;

    cout << "Size : " << st.size() << endl;

    cout << "\nPrinting Stack\n";

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;

    return 0;
}
