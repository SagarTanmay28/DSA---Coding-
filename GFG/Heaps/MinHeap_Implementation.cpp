// TC:
// add → O(log n)
// remove → O(log n)
// peek → O(1)
// SC: O(n)

class Heap {
    vector<int> arr;
    int idx;   // 1-based indexing

public:
    Heap(int capacity) {
        arr.assign(capacity + 1, INT_MAX);
        idx = 1;
    }

    // O(1)
    int peek() {
        if (size() == 0) {
            return -1;
        }
        return arr[1];
    }

    // O(log n)
    void add(int ele) {
        if (idx == arr.size()) {
            return;
        }

        arr[idx++] = ele;
        int root = idx - 1;

        // O(log n)
        while (root != 1) {
            int parent = root / 2;
            if (arr[root] < arr[parent]) {
                swap(arr[root], arr[parent]);   // O(1)
                root = parent;
            } else {
                break;
            }
        }
    }

    // O(log n)
    int remove() {
        if (idx == 1) {
            return -1;
        }

        int mn = arr[1];
        arr[1] = arr[idx - 1];
        idx--;

        int root = 1;

        // O(log n)
        while (root <= size()) {
            int left = 2 * root;
            int right = 2 * root + 1;

            int leftVal = (left <= size()) ? arr[left] : INT_MAX;
            int rightVal = (right <= size()) ? arr[right] : INT_MAX;

            if (arr[root] < leftVal && arr[root] < rightVal)
                break;

            if (leftVal < rightVal) {
                swap(arr[root], arr[left]);   // O(1)
                root = left;
            } else {
                swap(arr[root], arr[right]);  // O(1)
                root = right;
            }
        }
        return mn;
    }

    // O(n)
    void display() {
        for (int i = 1; i < idx; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // O(1)
    int size() {
        return idx - 1;
    }
};
