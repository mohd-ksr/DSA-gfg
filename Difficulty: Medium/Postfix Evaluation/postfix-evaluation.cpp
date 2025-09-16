class Solution {
private:
    bool isNumber(string s){
        if(s=="+" || s=="-" || s=="*" || s=="/" || s=="^")return false;
        return true;
    }
    int floorDiv(int b, int a) {
        int q = b / a;
        int r = b % a;
        if (r != 0 && ((b < 0) ^ (a < 0))) {
            q -= 1;
        }
        return q;
    }
public:
    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;
        for (auto &e : arr) {
            if (isNumber(e)) {
                st.push(stoi(e));
            } else {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                if (e == "+") st.push(b + a);
                else if (e == "-") st.push(b - a);
                else if (e == "*") st.push(b * a);
                else if (e == "/") st.push(floorDiv(b, a)); // integer division
                else if (e == "^") st.push((int)pow(b, a)); // b^a, not XOR
            }
        }
        return st.top();
    }
};