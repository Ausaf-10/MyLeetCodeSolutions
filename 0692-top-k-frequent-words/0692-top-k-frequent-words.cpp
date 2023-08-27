// WE WRITE THE COMPARATOR FUNCTION OF THE MINHEAP ACCORDING TO THE MIN HEAP REPRESENTATION OF ARRAY
// eg- > IN MIN HEAP, THE SMALLEST ELEMENT WILL BE AT THE LAST IN THE ARRAY [7,5,4,3,2,1]
// IN THIS ARRAY, 1 WILL BE PRESENT AT THE TOP AND THE ORDER IS 2 > 1 : A > B

class cmp{
    public: 
        bool operator()(pair<int,string>& a, pair<int,string>& b){
// IF THE FREQ IS EQUAL PEHLE WO JAAYE JISKA SIZE BADHA THAN CHOTA SO THAT THE CHOTA WALA WILL BE AT THE LAST IN ARRAY OR TOP IN MIN HEAP
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;           // BADHA PEHLE AAYE TAAKI CHOTA LAST MEIN ARRAY MEIN RAHE IN MIN HEAP
        }
};
class Solution {
public:
    // METHOD1
    // STORE THE FREQUENCIES AND PUT THEM IN A PAIR OF STRING AND INT AND SORT THEM AND GET THE K FREQUENT ELEMENTS ACCORDINLGY
   
    static bool compare(pair<int,string>& a, pair<int,string>& b){
        if (a.first == b.first) return a.second < b.second;     // means jo chota hai woh pehle and lexicographcal order! 
        return a.first > b.first;
    }
    
    vector<string> method1(vector<string>& words, int k){
        
        // SC: O(2N)
        map<string,int> mp;  
        for (auto it : words) mp[it]++;
        
        vector<pair<int,string>> ans;
        for (auto it : mp){
            ans.push_back({it.second,it.first});
        }
        
        vector<string> res;
        sort(ans.begin(), ans.end(),compare);               // TC: O(NlogN)
        for (int i=0; i<k; i++){
            string temp = ans[i].second;
            res.push_back(temp);
        }

        return res;
    }

    vector<string> method2(vector<string>& words, int k){
        priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> minHeap;
        
        unordered_map<string,int> mp;  
        for (auto it : words) mp[it]++;
        for (auto it : mp){
            minHeap.push({it.second,it.first});
            if (minHeap.size() > k) minHeap.pop();
        }

        // BCOZ THE ELEMENTS ARE PRESENT ACCORING TO THE ASCENDING ORDER FROM TOP TO BOTTOM IN MIN HEAP AND THE ANS WANTS THE OPPOSITE SO PUSH
        // FROM THE BACK IN ANS

        vector<string> ans(k);
        int indx = k-1;
        while (!minHeap.empty()){
            ans[indx] = minHeap.top().second;
            minHeap.pop();
            indx--;
        }
        

        return ans;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        return method2(words,k);
    }
};