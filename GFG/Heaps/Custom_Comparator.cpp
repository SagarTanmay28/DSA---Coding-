#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string name;
    int rno;
    double cgpa;

    Student(string name, int rno, double cgpa) {
        this->name = name;
        this->rno = rno;
        this->cgpa = cgpa;
    }

    // custom comparator
    // O(1)
    bool compareStudent(const Student& a, const Student& b) {
        if (a.cgpa == b.cgpa)
            return a.rno < b.rno;     // smaller roll number first
        return a.cgpa < b.cgpa;       // increasing cgpa
    }
};

int main() {
    Student s1("Gopi", 200, 8.3);
    Student s2("Shahid", 49, 8.9);
    Student s3("Anuj", 90, 8.5);
    Student s4("Isha", 8, 8.3);
    Student s5("Aditya", 31, 9.7);

    vector<Student> arr = {s1, s2, s3, s4, s5};

    sort(arr.begin(), arr.end());

    for (auto &s : arr) {
        cout << s.name << " " << s.rno << " " << s.cgpa << endl;
    }

    return 0;
}

