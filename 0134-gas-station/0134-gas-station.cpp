class Solution {
public:
    int canCompleteCircuit(vector<int>& petrol, vector<int>& distance) {
        int n = petrol.size();

        if (petrol.size() == 1 && petrol[0] >= distance[0]) return 0;
        else if (petrol.size() == 1 && petrol[0] < distance[0]) return -1;

        int start = 0 , end = 1;


        int currPetrol = petrol[start] - distance[start]; 

        while (start!=end || currPetrol < 0){
            while (start!=end && currPetrol < 0){
                currPetrol -= petrol[start] - distance[start];
                start = (start + 1)%n;

                if (start == 0) return -1;
            }
            currPetrol += petrol[end] - distance[end];
            end = (end+1)%n;
        }

        return start;
    }
};