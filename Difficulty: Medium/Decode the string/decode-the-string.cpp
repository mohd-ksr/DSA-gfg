class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<int> countStack;
        stack<string> stringStack;
        string current = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0'); // build number
            } 
            else if (c == '[') {
                countStack.push(k);
                stringStack.push(current);
                k = 0;
                current = "";
            } 
            else if (c == ']') {
                int repeat = countStack.top(); countStack.pop();
                string prev = stringStack.top(); stringStack.pop();

                string expanded = "";
                for (int i = 0; i < repeat; i++) expanded += current;
                current = prev + expanded;
            } 
            else {
                current += c; // normal character
            }
        }

        return current;
    }
};