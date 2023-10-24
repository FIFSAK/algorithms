#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 
#include <algorithm>
#include <map>

using namespace std;

struct Student {
    string surname, name;
    double gpa;
};


bool compare(const Student& a, const Student& b) {
    if (a.gpa == b.gpa) {
        if (a.surname == b.surname) {
            return a.name > b.name;
        }
        return a.surname > b.surname;
    }
    return a.gpa > b.gpa;
}

void heapifydown(vector<Student>& students, int n, int i, bool (*compare)(const Student&, const Student&)) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && compare(students[l], students[largest])) {
        largest = l;
    }

    if (r < n && compare(students[r], students[largest])) {
        largest = r;
    }

    if (largest != i) {
        swap(students[i], students[largest]);
        heapifydown(students, n, largest, compare);
    }
}

void buildHeap(vector<Student>& students, int n, bool (*compare)(const Student&, const Student&)) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifydown(students, n, i, compare);
    }
}

void heapsort(vector<Student>& students, bool (*compare)(const Student&, const Student&)) {
    int n = students.size();
    buildHeap(students, n, compare);

    for (int i = n - 1; i >= 0; i--) {
        swap(students[0], students[i]);
        heapifydown(students, i, 0, compare);
    }
}
// Map to store grade to value association
map<string, double> gradeValues = {
    {"A+", 4.00},
    {"A", 3.75},
    {"B+", 3.50},
    {"B", 3.00},
    {"C+", 2.50},
    {"C", 2.00},
    {"D+", 1.50},
    {"D", 1.00},
    {"F", 0}
};

int main() {
    long long n; cin >> n;
    vector<Student> students;

    for (long long i = 0; i < n; i++) {
        Student student;
        cin >> student.surname >> student.name;
        long long size; cin >> size;
        double sumcredit = 0;
        double gpa = 0;
        for (long long j = 0; j < size; j++) {
            string grade; cin >> grade;
            long long credit; cin >> credit;
            sumcredit += credit;
            gpa += gradeValues[grade] * credit;
        }
        student.gpa = gpa / sumcredit;
        students.push_back(student);
    }

        // Custom sorting criteria for ascending GPA
    heapsort(students, compare);


    for (const auto& student : students) {
        cout << student.surname << " " << student.name << " " << fixed << setprecision(3) << student.gpa << endl;
    }

    return 0;
}