A perfectly straight street is represented by a number line. The street has street lamp(s) on it and is represented by a 2D integer array lights.
Each lights[i] = [positioni, rangei] indicates that there is a street lamp at position positioni that lights up the area from
[positioni - rangei, positioni + rangei] (inclusive). The brightness of a position p is defined as the
number of street lamp that light up the position p. Given lights, return the brightest position on the street. 
If there are multiple brightest positions, return the smallest one.


This problem is a pure Line Sweep (Difference Array using Events) problem.

Idea

Each lamp covers:

[position−range,position+range]

Instead of marking every position, create events:

+1 at L = position - range
-1 at R + 1 = position + range + 1

Then sort all events and sweep.

While sweeping:

brightness += event
If the current brightness is greater than the maximum seen so far, record the current position.

Since events are processed in increasing order, the first position with maximum brightness is automatically the smallest one.

C++ (Line Sweep)
class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        map<int, int> events;

        for (auto &light : lights) {
            int pos = light[0];
            int range = light[1];

            events[pos - range]++;
            events[pos + range + 1]--;
        }

        int brightness = 0;
        int maxBrightness = 0;
        int ans = 0;

        for (auto &[position, change] : events) {
            brightness += change;

            if (brightness > maxBrightness) {
                maxBrightness = brightness;
                ans = position;
            }
        }

        return ans;
    }
};
Complexity
Time: O(n log n)
Space: O(n)



