#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
};


bool compareDates(const Date& a, const Date& b) {
    if (a.year != b.year) {
        return a.year < b.year;
    }
    if (a.month != b.month) {
        return a.month < b.month;
    }
    return a.day < b.day;
}

int main() {
    int n;
    cin >> n;
    
    vector<Date> dates;

    for (int i = 0; i < n; i++) {
        string dateStr;
        cin >> dateStr;

        int day, month, year;
        sscanf(dateStr.c_str(), "%d-%d-%d", &day, &month, &year);

        dates.push_back(Date(day, month, year));
    }

    sort(dates.begin(), dates.end(), compareDates);

    for (const Date& date : dates) {
        printf("%02d-%02d-%04d\n", date.day, date.month, date.year);
    }

    return 0;
}
// run id = 4355
