#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<long long>& robots, vector<pair<long long, int>>& factories) {
        long long totalDistance = 0;
        int r = 0;  // Index for robots
        int f = 0;  // Index for factories

        // Sorting robots and factories by position to minimize distances
        sort(robots.begin(), robots.end());
        sort(factories.begin(), factories.end());

        // Matching robots to factories within capacity limits
        while (r < robots.size() && f < factories.size()) {
            long long factoryPosition = factories[f].first;
            int factoryCapacity = factories[f].second;

            while (r < robots.size() && factoryCapacity > 0) {
                totalDistance += abs(robots[r] - factoryPosition);
                r++;
                factoryCapacity--;
            }
            f++;
        }
        return totalDistance;
    }
};

int main() {
    // Original input vectors
    vector<int> param_1 = {-333539942, 359275673, 89966494, 949684497, -733065249, 241002388, 325009248, 403868412, -390719486, -670541382, 563735045, 119743141, 323190444, 534058139, -684109467, 425503766, 761908175};
    vector<vector<int>> param_2 = {{-590277115, 0}, {-80676932, 3}, {396659814, 0}, {480747884, 9}, {118956496, 10}};

    // Converting param_1 from vector<int> to vector<long long>
    vector<long long> robots(param_1.begin(), param_1.end());

    // Converting param_2 from vector<vector<int>> to vector<pair<long long, int>>
    vector<pair<long long, int>> factories;
    for (const auto& factory : param_2) {
        factories.push_back({static_cast<long long>(factory[0]), factory[1]});
    }

    // Call the function with the correctly typed vectors
    Solution solution;
    long long result = solution.minimumTotalDistance(robots, factories);
    cout << result << endl;

    return 0;
}
