// LC 1851: Minimum Interval | LC 732: My Calendar III (Line Sweep)
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Line Sweep Pattern
class MyCalendarThree {
    map<int, int> events;
public:
    int book(int start, int end) {
        events[start]++;
        events[end]--;
        int maxOverlap = 0, current = 0;
        for (auto& [_, delta] : events) {
            current += delta;
            maxOverlap = max(maxOverlap, current);
        }
        return maxOverlap;
    }
};

// Count overlapping intervals at each point
int countMaxOverlap(vector<vector<int>>& intervals) {
    map<int, int> points;
    for (auto& iv : intervals) { points[iv[0]]++; points[iv[1]]--; }
    int maxOverlap = 0, current = 0;
    for (auto& [_, delta] : points) { current += delta; maxOverlap = max(maxOverlap, current); }
    return maxOverlap;
}

// LC 729: My Calendar I (no double booking)
class MyCalendar {
    map<int, int> bookings;
public:
    bool book(int start, int end) {
        auto it = bookings.upper_bound(start);
        if (it != bookings.end() && it->first < end) return false;
        if (it != bookings.begin() && prev(it)->second > start) return false;
        bookings[start] = end;
        return true;
    }
};

int main() {
    MyCalendarThree cal;
    cout << cal.book(10, 20) << " " << cal.book(50, 60) << " " << cal.book(10, 40) << endl;
    return 0;
}
