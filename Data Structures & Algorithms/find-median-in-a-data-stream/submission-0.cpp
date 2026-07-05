class MedianFinder {
public:
    priority_queue<int>maxheap ;
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int n = minheap.size() ;
        int m = maxheap.size() ;
        if(n==0) minheap.push(num);
        else if(num>minheap.top()) minheap.push(num);
        else maxheap.push(num); 

        // rebalance 
        if(maxheap.size()> minheap.size()+1){
            int x = maxheap.top() ; maxheap.pop() ;
            minheap.push(x);
        }
        else if(minheap.size()>maxheap.size()+1){
            int x = minheap.top() ; minheap.pop() ;
            maxheap.push(x) ;
        }
    }
    
    double findMedian() {
        double med ;
        int l = minheap.size() + maxheap.size() ;
        if(l%2==0){
            med = (minheap.top()+maxheap.top())/2.0 ;
        }
        else{
            if(minheap.size()>maxheap.size()){
                med = minheap.top() ;
            }
            else med = maxheap.top() ;
        }
        return med ;
    }
};
