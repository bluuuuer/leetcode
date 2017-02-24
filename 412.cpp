/*
Write a program that outputs the string representation of numbers from 1 to n.
But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
Example: 
n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i ++) {
            string temp = "";
            if (i % 15 == 0)
                temp = "FizzBuzz";
            else if (i % 3 == 0)
                temp = "Fizz";
            else if (i % 5 == 0)
                temp = "Buzz";
            else {
                stringstream ss;
                ss << i;
                ss >> temp;
            }
            res.push_back(temp);
        }
        return res;
    }
};
