class Solution {
public:
    void binarySearch(int x, int l, int r, int& store){
        if(l>r) return;
        int mid = l + (r-l)/2;
        long long prod = 1LL*mid * mid;

        if(prod == x){
            store = mid;
            return;
        }

        if(prod<x){
            store = mid;
            binarySearch(x,mid+1,r,store);
        }
        else{
            binarySearch(x,l,mid-1,store);
        }

    }
    int mySqrt(int x) {
        if(x<=1) return x;

        int store = 0;
        binarySearch(x,1,x/2,store);

        return store;
    }
};