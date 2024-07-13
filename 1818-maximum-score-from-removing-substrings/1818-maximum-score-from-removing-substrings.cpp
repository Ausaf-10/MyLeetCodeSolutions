class Solution {
public:
    int calculateMaxGain(string &s, int abPoints, int baPoints) {
        auto processStack = [](string &str, char first, char second, int points) {
            stack<char> stk;
            int totalPoints = 0;
            for (char ch : str) {
                if (stk.empty() || ch != second || stk.top() != first) {
                    stk.push(ch);
                } else {
                    stk.pop();
                    totalPoints += points;
                }
            }
            string remainingChars;
            while (!stk.empty()) {
                remainingChars.push_back(stk.top());
                stk.pop();
            }
            reverse(remainingChars.begin(), remainingChars.end());
            return make_pair(totalPoints, remainingChars);
        };

        int totalPoints = 0;
        if (abPoints >= baPoints) {
            auto [points, remaining] = processStack(s, 'a', 'b', abPoints);
            totalPoints += points;
            auto [finalPoints, _] = processStack(remaining, 'b', 'a', baPoints);
            totalPoints += finalPoints;
        } else {
            auto [points, remaining] = processStack(s, 'b', 'a', baPoints);
            totalPoints += points;
            auto [finalPoints, _] = processStack(remaining, 'a', 'b', abPoints);
            totalPoints += finalPoints;
        }

        return totalPoints;
    }

    int maximumGain(string s, int x, int y) {
        return calculateMaxGain(s, x, y);
    }
};
