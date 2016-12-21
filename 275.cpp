//Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

//Show Hint 

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0)
            return 0;
        int count = 1;
        for (int i = citations.size() - 1; i >= 0; i --) {
            if (citations[i] < count)
                break;
            count ++;
        }
        return count - 1;
    }
};
