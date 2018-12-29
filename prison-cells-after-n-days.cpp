class Solution {
public:
    vector<int> i, o;
    vector<int> M1;

    void byteToVec(int x, vector<int>& v) {
        for (int i = 0; i < 8; i++) {
            v[7 - i] = (x >> i) & 1;
        }
    }
    
    int vecToByte(vector<int>& v) {
        int x = 0;
        for (int i = 0; i < 8; i++) {
            x = x | (v[i] << (7 - i));
        }
        return x;
    }
    
    void oneStep(vector<int>& i, vector<int>& o) {
        o[0] = 0;
        o[7] = 0;
        
        for (int j = 1; j < 7; j++) {
            if (i[j - 1] == i[j + 1]) {
                o[j] = 1;
            } else {
                o[j] = 0;
            }
        }
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        i = vector<int>(8);
        o = vector<int>(8);
        M1 = vector<int>(256);
        for (int x = 0; x < 256; x++) {
            byteToVec(x, i);
            oneStep(i, o);
            int y = vecToByte(o);
            M1[x] = y;
        }
        
        vector<int> M1000(256);
        for (int x = 0; x < 256; x++) {
            int y = x;
            for (int i = 0; i < 1000; i++) {
                y = M1[y];
            }
            M1000[x] = y;
        }
        
        int x = vecToByte(cells);
        
        while (N >= 1000) {
            x = M1000[x];
            N -= 1000;
        }
        
        while (N > 0) {
            x = M1[x];
            N--;
        }
        
        byteToVec(x, o);
        return o;
    }
};
