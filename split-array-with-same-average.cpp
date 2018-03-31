class Solution {
public:
    bool subsetOfSizeSumsToRec(vector<int>& A, int targetSubsetSize, int targetSum, int from, int currentSum, int currentSubsetSize) {
        if (currentSubsetSize == targetSubsetSize) {
            if (currentSum == targetSum) {
                return true;
            } 
            return false;
        }
        
        for (int i = from; i < A.size(); i++) {
            if (subsetOfSizeSumsToRec(A, targetSubsetSize, targetSum, i + 1, currentSum + A[i], currentSubsetSize + 1)) {
                return true;
            }
        }
        return false;
    }
    
    bool subsetOfSizeSumsTo2(vector<int>& A, int targetSubsetSize, int targetSum) {
        return subsetOfSizeSumsToRec(A, targetSubsetSize, targetSum, 0, 0, 0);
    }

    void allSumsRec(vector<int>& A, int lo, int hi, int subsetSize, set<int>& res, int from, int currentSum, int currentSubsetSize) {
        if (currentSubsetSize == subsetSize) {
            res.insert(currentSum);
            return;
        }
        for (int i = from; i <= hi; i++) {
            allSumsRec(A, lo, hi, subsetSize, res, i + 1, currentSum + A[i], currentSubsetSize + 1);
        }
    }
    
    set<int> allSums(vector<int>& A, int lo, int hi, int subsetSize) {
        set<int> res;
        allSumsRec(A, lo, hi, subsetSize, res, lo, 0, 0);
        return res;
    }
    
    bool subsetOfSizeSumsTo(vector<int>& A, int targetSubsetSize, int targetSum) {
        int middle = A.size() / 2;
        for (int numLeft = 0; numLeft <= targetSubsetSize; numLeft++) {
            auto sumsLeft = allSums(A, 0, middle, numLeft);
            auto sumsRight = allSums(A, middle + 1, A.size() - 1, targetSubsetSize - numLeft);
            for (int sumLeft: sumsLeft) {
                if (sumsRight.count(targetSum - sumLeft) == 1) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool splitArraySameAverage(vector<int>& A) {
        int totalSum = 0;
        for (int x: A) {
            totalSum += x;
        }
        int N = A.size();
        for (int H = 1; H < 1 + N / 2; H++) {
            if ((H * totalSum) % N != 0) {
                continue;
            }
            if (subsetOfSizeSumsTo(A, H, (H * totalSum) / N)) {
                return true;
            }
        }
        return false;
    }
};