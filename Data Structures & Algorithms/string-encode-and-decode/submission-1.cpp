class Solution {
public:

    string encode(vector<string>& strs) {
        // edge case
        if(strs.size() == 0){
            return string(1, char(258));
        }

        char separator = char(257);

        string  encoded = "";
        for(string s: strs){
            encoded += s;
            encoded += separator;
        }

        encoded.pop_back(); // last separator udao

        return encoded;
    }

    vector<string> decode(string s) {
        if(s == string(1, char(258))){
            return {}; // empty vector
        }

        char separator = char(257);

        vector<string> result;
        string temp = "";

        for(char ch: s){
            if(ch == separator){
                result.push_back(temp);
                temp ="";
            }
            else temp += ch;
        }

        // last string ke time separator nhi milega, string end hone ke baad ye aayega
        result.push_back(temp);
        return result;
    }
};
