class Solution {
public:
    enum { NORMAL, LINE_COMMENT, BLOCK_COMMENT };
    
    
    vector<string> removeComments(vector<string>& source) {
        int state = NORMAL;
        vector<string> res;
        string output_line;
        for (auto line: source) {
            for (int i = 0; i < line.length(); i++) {
                if (state == NORMAL && line[i] == '/' && i + 1 < line.length()) {
                    if (line[i + 1] == '/') {
                        state = LINE_COMMENT;
                        i += 1;
                    } else if (line[i + 1] == '*' ) {
                        state = BLOCK_COMMENT;
                        i += 1;
                    }
                } else if (state == BLOCK_COMMENT && line[i] == '*' && i + 1 < line.length() && line[i + 1] == '/') {
                    state = NORMAL;
                    i += 1;
                    continue;
                } 
                if (state == NORMAL) {
                    output_line.push_back(line[i]);
                }
            }
            if (!output_line.empty() && state != BLOCK_COMMENT) {
                res.push_back(output_line);
                output_line.clear();
            }
            if (state == LINE_COMMENT) {
                state = NORMAL;
            }
        }
        return res;
    }
};

class Solution {
public:
    typedef enum { NORMAL, LINE_COMMENT, BLOCK_COMMENT } state_t;
    
    bool isEnterBlockComment(string line, int i, state_t state) {
        return state == NORMAL && line[i] == '/' && i + 1 < line.length() && line[i + 1] == '*';
    }
    
    bool isExitBlockComment(string line, int i, state_t state) {
        return state == BLOCK_COMMENT && line[i] == '*' && i + 1 < line.length() && line[i + 1] == '/';
    }
    
    bool isEnterLineComment(string line, int i, state_t state) {
        return state == NORMAL && line[i] == '/' && i + 1 < line.length() && line[i + 1] == '/';
    }
    
    vector<string> removeComments(vector<string>& source) {
        state_t state = NORMAL;
        vector<string> res;
        string output_line;
        for (auto line: source) {
            for (int i = 0; i < line.length(); i++) {
                if (isEnterBlockComment(line, i, state)) {
                    state = BLOCK_COMMENT;
                    i += 1;    
                } else if (isEnterLineComment(line, i, state)) {
                    state = LINE_COMMENT;
                    i += 1;
                } else if (isExitBlockComment(line, i, state)) {
                    state = NORMAL;
                    i += 1;
                    continue;
                } 
                if (state == NORMAL) {
                    output_line.push_back(line[i]);
                }
            }
            if (!output_line.empty() && state != BLOCK_COMMENT) {
                res.push_back(output_line);
                output_line.clear();
            }
            if (state == LINE_COMMENT) {
                state = NORMAL;
            }
        }
        return res;
    }
};