vector<int> a = {2, 5, 6, 9, 20};
vector<int> b = {1, 3, 4, 5, 7, 8, 90};
vector<int> c(a.size() + b.size(), 0);

void mergeArrays(vector<int>& c, vector<int>& a, vector<int>& b) {
    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while (i < a.size())
        c[k++] = a[i++];

    while (j < b.size())
        c[k++] = b[j++];
}
