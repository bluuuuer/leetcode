/*
Implement a data structure supporting the following operations:

Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
Challenge: Perform all these in O(1) time complexity.
*/

class AllOne {
public:
    AllOne() {}
    
    void inc(string key) {
        if (this->key_val.find(key) == this->key_val.end())
            this->key_val[key] = 1;
        else
            this->key_val[key] ++;
    }
    
    void dec(string key) {
        if (this->key_val.find(key) != this->key_val.end()) {
            if (this->key_val[key] == 1)
                this->key_val.erase(key);
            else
                this->key_val[key] --;
        }
    }
    
    string getMaxKey() {
        int max_num = 0;
        string res = "";
        for (auto& x : this->key_val) {
            if (x.second > max_num) {
                max_num = x.second;
                res = x.first;
            }
        }
        return res;
    }
    
    string getMinKey() {
        int min_num = 10000000;
        string res = "";
        for (auto& x : this->key_val) {
            if (x.second < min_num) {
                min_num = x.second;
                res = x.first;
            }
        }
        return res;
    }

private:
    unordered_map<string, int> key_val;
};
