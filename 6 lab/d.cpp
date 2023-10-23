#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function to parse a date in the format "dd-mm-yyyy"
void parseDate(const string& date, int& day, int& month, int& year) {
    stringstream ss(date);
    char ignore;

    ss >> day >> ignore >> month >> ignore >> year;
}

int main() {
    int n; cin>>n;
    // Sample list of dates
    vector<string> dates;
    for (int i = 0;i<n;i++){
        string s;cin>>s;
        dates.push_back(s);
    }
    // Map to store dates for sorting
    map<int, map<int, int>> dateMap;

    // Populate the map
    for (const auto& date : dates) {
        int day, month, year;
        parseDate(date, day, month, year);

        dateMap[year][month] = day;  // Note: This will overwrite dates with the same year and month. If you expect multiple dates with the same year and month, you'd need a different approach.
    }

    // Print the sorted dates
    for (const auto& yearEntry : dateMap) {
    for (const auto& monthEntry : yearEntry.second) {
        string dayStr, monthStr;

        // Pad day if needed
        if (monthEntry.second < 10) {
            dayStr = "0" + to_string(monthEntry.second);
        } else {
            dayStr = to_string(monthEntry.second);
        }

        // Pad month if needed
        if (monthEntry.first < 10) {
            monthStr = "0" + to_string(monthEntry.first);
        } else {
            monthStr = to_string(monthEntry.first);
        }

        // Print the formatted date
        cout << dayStr << "-" << monthStr << "-" << yearEntry.first << endl;
    }
}

    return 0;
}
