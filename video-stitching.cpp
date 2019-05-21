class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int infty = 1e8;
        vector<int> A(T + 1, infty);
        sort(clips.begin(), clips.end());
        
        int N = clips.size();
        A[0] = 0;
        for (int i = 0; i < N; i++) {
            int s = clips[i][0];
            int e = clips[i][1];
            
            if (s >= T) {
                continue;
            }
            e = min(e, T);
            if (A[s] == infty) {
                continue;
            }
            for (int x = s; x <= min(e, T); x++) {
                A[x] = min(A[x], A[s] + 1);
            }
        }
        
        return A[T] == infty ? -1 : A[T];
    }
};
