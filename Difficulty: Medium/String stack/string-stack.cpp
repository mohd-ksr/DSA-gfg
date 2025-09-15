class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        int i = int(pat.size()) - 1;
        int j = int(tar.size()) - 1;
        int skip = 0;

        while (i >= 0) {
            if (skip > 0) {
                // this pat[i] was an appended char that got deleted later
                skip--;
                i--;
            } else {
                if (j >= 0 && pat[i] == tar[j]) {
                    // match this tar char
                    i--; j--;
                } else {
                    // use pat[i] as a delete operation (in forward time),
                    // which in reverse forces us to skip one appended char
                    skip++;
                    i--;
                }
            }
        }
        return j < 0; // all target cha
    }
};
// Time Complexity O(n)