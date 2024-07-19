class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), m = words.size(), wordLen = words[0].size(), windowSize = wordLen * m;
        unordered_map<string, int> wordMap;
        vector<int> ans;

        // Build the frequency map for words
        for (auto &word : words) wordMap[word]++;

        // Loop through each character up to wordLen to handle different offsets
        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> windowMap;

            // Slide the window across the string
            for (int j = i; j <= n - wordLen; j += wordLen) {
                string word = s.substr(j, wordLen);

                if (wordMap.find(word) != wordMap.end()) {
                    windowMap[word]++;
                    count++;

                    while (windowMap[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowMap[leftWord]--;
                        if (windowMap[leftWord] == 0) windowMap.erase(leftWord);
                        count--;
                        left += wordLen;
                    }

                    if (count == m) ans.push_back(left);
                } else {
                    windowMap.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return ans;
    }
};
