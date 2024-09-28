#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> optimizeBookings(vector<vector<int>>& bookings) {
    if (bookings.empty()) return {};

    // Sort the bookings by the start time
    sort(bookings.begin(), bookings.end());

    vector<vector<int>> optimizedBookings;
    vector<int> currentBooking = bookings[0];

    for (size_t i = 1; i < bookings.size(); i++) {
        vector<int> nextBooking = bookings[i];

        // If the current booking overlaps or is consecutive with the next one
        if (currentBooking[1] >= nextBooking[0]) {
            // Merge them by updating the end time to the maximum of both
            currentBooking[1] = max(currentBooking[1], nextBooking[1]);
        } else {
            // Push the current booking and move to the next
            optimizedBookings.push_back(currentBooking);
            currentBooking = nextBooking;
        }
    }

    // Push the last merged or individual booking
    optimizedBookings.push_back(currentBooking);

    return optimizedBookings;
}

// Example usage:
int main() {
    vector<vector<int>> bookings = {{9, 12}, {11, 13}, {14, 17}, {16, 18}};
    vector<vector<int>> result = optimizeBookings(bookings);
    
    for (const auto& booking : result) {
        cout << "[" << booking[0] << ", " << booking[1] << "] ";
    }
    // Output: [[9, 13], [14, 18]]
    
    return 0;
}
