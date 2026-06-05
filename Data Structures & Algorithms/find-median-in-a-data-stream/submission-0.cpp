class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    double median;
    MedianFinder() {
        median = 0;
    }
    
    void addNum(int num) {
        if(min_heap.size()==max_heap.size()){
            if(num<median){
                max_heap.push(num);
                median = max_heap.top();
            }
            else{
                min_heap.push(num);
                median = min_heap.top();
            }
        }
        else if(min_heap.size()+1==max_heap.size()){
            if(num<median){
                int transfer = max_heap.top();
                max_heap.pop();
                min_heap.push(transfer);
                max_heap.push(num);
                median = (min_heap.top() + max_heap.top())/2.0;
            }
            else{
                min_heap.push(num);
                median = (min_heap.top() + max_heap.top())/2.0;
            }
        }
        else{
            if(num>median){
                int transfer = min_heap.top();
                min_heap.pop();
                max_heap.push(transfer);
                min_heap.push(num);
                median = (min_heap.top() + max_heap.top())/2.0;
            }
            else{
                max_heap.push(num);
                median = (min_heap.top() + max_heap.top())/2.0;
            }
        }
    }
    
    double findMedian() {
        return median;
    }
};
