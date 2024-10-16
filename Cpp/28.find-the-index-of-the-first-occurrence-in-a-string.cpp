class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        
        //return haystack.find(needle) == string::npos?-1:haystack.find(needle);
        int lenHayStack = haystack.length();
        int lenNeedle = needle.length();
        if(lenNeedle > lenHayStack)
            return -1;
        for(int i =0;i<lenHayStack;i++)
        {
            int k =0;
            for(;k<lenNeedle;k++)
                if(needle[k] != haystack[k+i])
                    break;
            if(k == lenNeedle)
                return i;
        }
        return -1;
    }
};