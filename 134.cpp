//There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

//You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

//Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

//Note:
//The solution is guaranteed to be unique.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() == 1)
            return gas[0] - cost[0] >= 0 ? 0 : -1;
            
        vector<pair<int, int> >mins;
        int sum = 0;
        for (int i = 0; i < gas.size(); i ++) {
            int temp = gas[i] - cost[i];
            sum += temp;
            int temp_mins = temp;
            
            if (i == gas.size() - 1) {
                mins.push_back(make_pair(i, temp_mins));
                break;
            }
            
            int j = i + 1;
            int next_temp = gas[j] - cost[j];
            if (temp >= 0) {
                while(next_temp >= 0) {
                    sum += next_temp;
                    temp_mins += next_temp;
                    j ++;
                    if (j == gas.size() - 1)
                        break;
                    next_temp = gas[j] - cost[j];
                }
                mins.push_back(make_pair(i, temp_mins));
                i = j - 1;
            } else {
                while(next_temp < 0) {
                    sum += next_temp;
                    temp_mins += next_temp;
                    j ++;
                    if (j == gas.size() - 1)
                        break;
                    next_temp = gas[j] - cost[j];
                }
                mins.push_back(make_pair(i, temp_mins));
                i = j - 1;
            }
        }
        
        if (sum < 0)
            return -1;
        
        for (int i = 0; i < mins.size(); i ++) {
            if (Start(i, mins))
                return mins[i].first;
        }
        return -1;
    }
private:  
    
    bool Start(const int index, vector<pair<int, int> > mins) {
        int tank = 0;
        for (int i = index; i < index + mins.size(); i ++) {
            tank += mins[i % mins.size()].second;
            if (tank < 0)
                return false;
        }
        return true;
    }
};
