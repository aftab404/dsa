class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(string t: strs){
					if (t.size() < 10) {
						s += "00" + to_string(t.size()) + t;
 				} else if (t.size() < 100) {
						s += "0" + to_string(t.size()) + t;
					} else {
						s += to_string(t.size()) + t;
					}
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int idx = 0;
				int n = s.size();
        while(idx < n){
            string int_s = "";
            int curr_size = stoi(s.substr(idx,3));
						cout << "curr_size: " << curr_size << endl;
            for(int i = 1; i<=curr_size ; i++){
                int_s += s[idx + 2 + i];
            }
            idx += curr_size + 3;
            res.push_back(int_s);
        }

        return res;

    }
};