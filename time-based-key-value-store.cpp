class TimeMap {
public:
    /** Initialize your data structure here. */
    
    map<string, map<int, string>> H;
    
    
    TimeMap() {
        H = map<string, map<int, string>>();
    }
    
    void set(string key, string value, int timestamp) {
        H[key][- timestamp] = value;
        //cout << "M[" << timestamp << " <- " << value << endl;
    }
    
    string get(string key, int timestamp) {
        //cout << "   query " << key << " " << timestamp << endl;
        auto it = H[key].lower_bound(- timestamp);
        if (it == H[key].end()) {
            return "";
        }
        return (*it).second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
