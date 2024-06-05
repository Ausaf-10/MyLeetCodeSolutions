class Solution {
public:
    vector<int> findAnagrams(string txt, string pat) {
        unordered_map<char,int> mp;
	    for (auto it : pat) mp[it]++;
	    int i = 0, j = 0, k = pat.size(), n = txt.size(), cnt = mp.size();
        vector<int> ans;
	    while (j < n){
	        char ch = txt[j];
	        if (mp.find(ch) != mp.end()){
	            mp[ch]--;
	            if (mp[ch] == 0) cnt--;
	        }
	        if (j-i+1 < k){
	            j++;
	            continue;
	        }
	        if (cnt == 0){
                ans.push_back(i);
            }
	        if (mp.find(txt[i]) != mp.end()){
	            if (mp[txt[i]] == 0) cnt++;
	            mp[txt[i]]++;
	        }
	        i++,j++;
	        
	    }
	    
	    return ans;
    }
};