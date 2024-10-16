class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows == 1) {
            return s;
        }

        int i = 0;
        string solution = "";
        int stringLength = s.size();
        // Loop through numRows
        while (i < numRows) {
            // Add ith character to the string
            if (i < stringLength) {
                solution.push_back(s[i]);
            }
            
            // Compute zig length = 2 * (numRows - i - 1)
            int zigLength = 2 * (numRows - i - 1);

            // Compute zag length = 2 * i
            int zagLength = 2 * i;

            // Start another loop starting from i till string length
            int j = i;
            while (j < stringLength) {
                // add zig element to string if exists
                if (zigLength != 0) {
                    if ((j + zigLength) >= stringLength) {
                        break;
                    }
                    solution.push_back(s[j + zigLength]);
                    j += zigLength;
                }

                // add zag element to string if exists
                if (zagLength != 0) {
                    if ((j + zagLength) >= stringLength) {
                        break;
                    }
                    solution.push_back(s[j + zagLength]);
                    j += zagLength;
                }
            }

            ++i;
        }

        return solution;
    }
};