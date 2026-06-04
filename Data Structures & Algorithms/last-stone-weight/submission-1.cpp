class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n = stones.size();
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }

        while(pq.size()!=1){
            int h1 = pq.top();
            pq.pop();
            int h2 = pq.top();
            pq.pop();

            if(h1<h2)
            pq.push(h2-h1);
            else
            pq.push(h1-h2);

            if(h1==h2){
                if(pq.size()==0)
                return 0;
            }
        }

        return pq.top();
    }
};
