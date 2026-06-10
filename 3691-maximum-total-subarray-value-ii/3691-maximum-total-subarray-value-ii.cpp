class SegmentTree{
private:
    int n;
    vector<int>arr;
    vector<pair<int,int>>segTree;

    // build sement tree
    void buildSegTree(int segIndex, int left, int right){

        // base case
        if(left == right){
            segTree[segIndex].first = arr[left];
            segTree[segIndex].second = arr[left];
            return;
        }

        // find mid
        int mid = left + (right - left)/2;

        // build left subtree
        buildSegTree(2*segIndex+1, left, mid); 

        // build right subtree
        buildSegTree(2*segIndex+2, mid+1, right); 

        // update the segtree min max value while coming back
        segTree[segIndex].first = min(segTree[2*segIndex+1].first, segTree[2*segIndex+2].first);
        segTree[segIndex].second = max(segTree[2*segIndex+1].second, segTree[2*segIndex+2].second);
    }

    // Range min & max Query
    pair<int,int> rangeMinMaxQueryUtil(int segIndex, int left, int right, int queryLeft, int queryRight){
        
        // No overlap
        if(queryRight < left || right < queryLeft){
            return {INT_MAX, INT_MIN};
        }
        
        // Complete Overlap
        if(queryLeft <= left && right <= queryRight){
            return segTree[segIndex];
        }

        // Partial overlap
        int mid = left + (right - left)/2;

        pair<int,int>leftAns = rangeMinMaxQueryUtil(2*segIndex+1, left, mid, queryLeft, queryRight);
        pair<int,int>rightAns = rangeMinMaxQueryUtil(2*segIndex+2, mid+1, right, queryLeft, queryRight);

        return {min(leftAns.first, rightAns.first), max(leftAns.second, rightAns.second)};

    }

public:

    // constructor
    SegmentTree(vector<int>&arr){
        n = arr.size();
        this->arr = arr;
        segTree.resize(4*n);

        // build the segment tree
        buildSegTree(0, 0, n-1);
    }

    pair<int,int> rangeMinMaxQuery(int queryLeft, int queryRight){
        return rangeMinMaxQueryUtil(0, 0, n-1, queryLeft, queryRight);
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        
        // Better brute force
        long long ans = 0;
        int n = nums.size();
        priority_queue<tuple<long long, int, int>>pq;

        // instantiate the segtree
        SegmentTree seg = SegmentTree(nums);

        // initialize the pq with best values first
        // (start, n-1). i.e. (0, n-1), (1, n-1) ..
        for(int start = 0; start<n; start++){
            pair<int,int>minMax = seg.rangeMinMaxQuery(start, n-1);
            int bestValue = minMax.second - minMax.first;
            pq.push({bestValue, start, n-1});
        }

        while(k--){
            
            auto [bestValue, start, end] = pq.top();
            pq.pop();

            ans += bestValue;

            if(end - 1 >= start){
                pair<int,int>minMax = seg.rangeMinMaxQuery(start, end-1);
                int nextBestValue = minMax.second - minMax.first;
                pq.push({nextBestValue, start, end-1});
            }
        }

        return ans;
    }
};