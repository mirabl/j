class StartAndIndex implements Comparable<StartAndIndex> {
    int start;
    int index;
    public StartAndIndex(int s, int i) {
        start = s;
        index = i;
    }
    
    public int compareTo(StartAndIndex other) {
        if (other.start < start || (other.start == start && other.index < index)) {
            return -1;
        } else if (other.start == start && other.index == index) {
            return 0;
        } else {
            return 1;
        }
    }
}

class Solution {
    private int findIndexOfGreaterThan(StartAndIndex[] A, int t) {
        int best = -1;
        int lo = 0;
        int hi = A.length - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid].start >= t) {
                best = A[mid].index;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return best;
    }
    
    public int[] findRightInterval(int[][] intervals) {
        int n = intervals.length;
        StartAndIndex[] starts = new StartAndIndex[n];
        for (int i = 0; i < n; i++) {
            starts[i] = new StartAndIndex(intervals[i][0], i);
        }
        Arrays.sort(starts);
        
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = findIndexOfGreaterThan(starts, intervals[i][1]);
        }
        
        return res;
    }
}
