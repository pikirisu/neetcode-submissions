class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int>rev;
        for(int i=0; i<32; i++){
            int digit = n&1;
            n/=2;
            rev.push_back(digit);
        }
        
        uint32_t x = 0;
        int m = rev.size();
        for(int i=m-1; i>=0;i--){
            int s = rev[i]*pow(2,m-i-1);
            x+=s;
        }

        return x;
    }
};
