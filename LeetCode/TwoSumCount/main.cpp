//Given a list of integers, count the number of unique pairs (i, j) where:
// nums[i] + nums[j] == target
/*vector<int> nums = {1, 2, 3, 2, 1};
int target = 4;
Valid pairs:

(1, 3)

(2, 2)

(3, 1)

So, total: 3 pairs*/
#include <vector>
#include <iostream>
#include <unordered_map>

int main()
{

}

int TwoSum(std::vector<int> nums,int target) // return the number of times the indices add up to the target
// use hashmap to track frequencies
{
    int Count{}; // add it when u find new indices;
    std::unordered_map<int,int> Map; // stores indices as keys and values 
    for(int i = 0;i<nums.size();i++)
    {
        int b = target - nums[i]; // nums[i] = a; Map[n] = b;
        if(Map.find(b) != Map.end())
        { // meaning that the complement is inside the 2nd buffer
            Count++;
        }
        Map[b] = i; 
    }
}