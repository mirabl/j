class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        const int N = int(S.size());
        int num_dashes = 0;
        for (int i = 0; i < N; i++) {
            if (S[i] == '-') {
                num_dashes++;
            }
        }
        int num_chars = N - num_dashes;
        int size_of_first_group = num_chars % K;
        if (size_of_first_group == 0) {
            size_of_first_group = K;
        }
        int i = 0;
        int j = 0;
        string t;
        while (i < N) {
            if (S[i] != '-') {
                t += toupper(S[i]);
                j++;
                if ((j == size_of_first_group || (j > size_of_first_group && (j - size_of_first_group) % K == 0)) && j < num_chars) {
                    t += '-';
                }
            }
            i++;
        }
        return t;
    }
};