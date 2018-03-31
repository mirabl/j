class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int numLines = 1;
        int currentLineLength = 0;
        const int maxLineLength = 100;
        for (char c: S) {
            int w = widths[c - 'a'];
            if (currentLineLength + w > maxLineLength) {
                numLines++;
                currentLineLength = 0;
            }
            currentLineLength += w;
        }
        return {numLines, currentLineLength};
    }
};