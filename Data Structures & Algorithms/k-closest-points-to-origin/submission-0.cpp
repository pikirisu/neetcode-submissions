class Solution {
public:
    class Info{
        public:
        int x;
        int y;
        int dist;

        Info(int x,int y, int dist){
            this->x = x;
            this->y = y;
            this->dist = dist;
        }
    };

    class comparator{
        public:
        bool operator()(Info a, Info b){
            return a.dist < b.dist;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

        priority_queue<Info,vector<Info>,comparator> pq;
        int n = points.size();
        for(int i=0;i<n;i++){
           Info element = Info(points[i][0],points[i][1], points[i][0]*points[i][0] + points[i][1]*points[i][1]);
           pq.push(element);
           if(pq.size()>k)
           pq.pop(); 
        }

        for(int i=0;i<k;i++){
            ans.push_back({pq.top().x,pq.top().y});
            pq.pop();
        }
        return ans;
    }
};
