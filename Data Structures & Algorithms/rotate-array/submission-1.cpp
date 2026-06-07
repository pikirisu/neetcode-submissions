class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==k%n) return;
        int iterator =  0;
        int number_of_times = n-k%n;
        while(number_of_times--)
        iterator++;

        vector<int> part1(nums.begin()+iterator,nums.end());
        vector<int> part2(nums.begin(),nums.begin()+iterator);

        part1.insert(part1.end(),part2.begin(),part2.end());

        nums = part1;
    }
};