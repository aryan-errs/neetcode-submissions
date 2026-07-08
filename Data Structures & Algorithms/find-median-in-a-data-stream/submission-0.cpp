class MedianFinder {
public:
    vector<long long> arr;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        arr.push_back(num);
    }
    
    double findMedian() {
        sort(arr.begin(), arr.end());
        if(arr.size()%2){
            return (double)arr[arr.size()/2];
        }
        return (double)(arr[arr.size()/2] + arr[arr.size()/2 -1])/(double)2;
    }
};
