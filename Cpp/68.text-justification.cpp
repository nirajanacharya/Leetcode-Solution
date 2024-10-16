// class Solution {
// public:
//     vector<string> fullJustify(vector<string>& words, int maxWidth) {
//         int i = 0;
//         vector<string> ans;
//         int limit = words.size();

//         while (i < limit) {
//             string s = words[i];
//             int space = 0;
//             int wordsize = words[i].size();
//             int wordsCount = 1; 
//             int end = i;

//             if (s.size() == maxWidth) {
//                 i++;
//                 ans.push_back(s);
//                 continue;
//             } 
//             else {
//                 for (int j = i + 1; j < limit; j++) {
//                     int nextWordSize = words[j].size();
//                     if ((wordsize + nextWordSize + space + 1) > maxWidth) {
//                         end = j - 1;
//                         break;
//                     } else {
//                         wordsize += nextWordSize;
//                         space++;
//                         wordsCount++;
//                         end = j;
//                     }
//                 }

//                 if (end != limit - 1) {
//                     int left = maxWidth - (wordsize + space);
//                     space += left;
//                     if(wordsCount==1){
//                         for(int wa=0;wa<space;wa++){
//                             s=s+" ";
                            

//                         }
//                         ans.push_back(s);
//                         s="";
//                     }
//                     else if (space % (wordsCount - 1) == 0) {
//                         int reqSpaces = space / (wordsCount - 1);
//                         for (int u = i + 1; u <= end; u++) {
//                             for (int re = 0; re < reqSpaces; re++) {
//                                 s += " ";
//                             }
//                             s += words[u];
//                         }
//                         ans.push_back(s);
//                     } else {
//                         int remainder = space % (wordsCount - 1);
//                         int reqSpaces = space / (wordsCount - 1);
//                         for (int u = i + 1; u <= end; u++) {
//                             for (int re = 0; re < reqSpaces; re++) {
//                                 s += " ";
//                             }
//                             if (remainder > 0) {
//                                 s += " ";
//                                 remainder--;
//                             }
//                             s += words[u];
//                         }
//                         ans.push_back(s);
//                     }
//                     i = end + 1;
//                 } else {
//                     for (int u = i + 1; u <= end; u++) {

//                         s += " ";
//                         s += words[u];
                        
//                     }
//                     int left=maxWidth-s.size();
//                     while(left--){
//                         s+=" ";
//                     }
//                     ans.push_back(s);
//                     i = limit;  // Corrected to move to the end
//                 }
//             }
//         }
//         return ans;
//     }
// };












































class Solution
{
public:
    vector<string> fullJustify(vector<string> &w, int check)
    {
        vector<string> ans;
        int i = 0;
        while (i < w.size())
        {
            int end = i;
            int space = 0;
            int word = 0;
            string s = "";
            int word_length = 0;
            for (int j = i; j < w.size(); j++)
            {
                if (j == i)
                {
                    word++;
                    word_length += w[j].size();
                }
                else
                {
                    if (word_length + space + 1 + w[j].size() > check)
                        break;
                    else
                    {
                        space++;
                        word++;
                        word_length += w[j].size();
                        end = j;
                    }
                }
            }
            if (end != w.size() - 1)
            {
                int extra = 0;
                int spc = 0;
                if (space)
                {
                    spc = (check - word_length) / space;
                    extra = (check - word_length) % space;
                }
                for (int j = i; j <= end; j++)
                {
                    s += w[j];
                    for (int k = 0; k < spc && j != end; k++)
                    {
                        s += " ";
                    }
                    if (extra)
                    {
                        extra--;
                        s += " ";
                    }
                }
                if (space == 0)
                {
                    int k = s.size();
                    for (int j = 1; j <= (check - k); j++)
                    {
                        s += " ";
                    }
                }
            }
            else
            {
                for (int j = i; j <= end; j++)
                {
                    if (j == i)
                        s += w[j];
                    else
                    {
                        s += " ";
                        s += w[j];
                    }
                }
                int k = s.size();
                for (int j = 1; j <= (check - k); j++)
                {
                    s += " ";
                }
            }
            i = end + 1;
            ans.push_back(s);
        }
        return ans;
    }
};