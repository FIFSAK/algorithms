#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 
#include <algorithm>
#include <map>

using namespace std;

struct date {
    int year, month, day;
};


date parseDate(const string& dateString) {
    stringstream ss(dateString);
    string token;
    date result;

    getline(ss, token, '-');
    result.day = stoi(token);

    getline(ss, token, '-');
    result.month = stoi(token);

    getline(ss, token);
    result.year = stoi(token);

    return result;
}

bool compare(date a, date b) {
    if (a.year != b.year) {
        return a.year > b.year;
    }
    if (a.month != b.month) {
        return a.month > b.month;
    }
    return a.day > b.day;
}


void heapifydown(vector<date>& dates, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && compare(dates[l], dates[largest])) {
        largest = l;
    }

    if (r < n && compare(dates[r], dates[largest])) {
        largest = r;
    }

    if (largest != i) {
        swap(dates[i], dates[largest]);
        heapifydown(dates, n, largest);
    }
}

void buildHeap(vector<date>& dates, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifydown(dates, n, i);
    }
}

void heapsort(vector<date>& dates) {
    int n = dates.size();
    buildHeap(dates, n);

    for (int i = n - 1; i >= 0; i--) {
        swap(dates[0], dates[i]);
        heapifydown(dates, i, 0);
    }
}


int main() {
    long long n; cin >> n;
    vector<date> dates;
    
    for (long long i = 0; i < n; i++) {
        string s;cin>>s;
        date temp = parseDate(s);
        dates.push_back(temp);
    }
    heapsort(dates);

    for(auto cur: dates){
        if (cur.month<10){
            if(cur.day<10){
                cout<<'0'<<cur.day<<"-"<<'0'<<cur.month<<"-"<<cur.year<<endl;
                continue;
            }
            cout<<cur.day<<"-"<<'0'<<cur.month<<"-"<<cur.year<<endl;
            continue;
        }
        if(cur.day<10){
                cout<<'0'<<cur.day<<"-"<<cur.month<<"-"<<cur.year<<endl;
                continue;
            }
        cout<<cur.day<<"-"<<cur.month<<"-"<<cur.year<<endl;
    }

    return 0;
}