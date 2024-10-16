class Solution {
    using BT = std::vector<unsigned char>;

    bool solve(const int N,
        const std::vector<std::array<int,26>>& origPSA,
        const std::vector<std::array<int,26>>& scraPSA, 
        BT& dp,
        const int oStart, const int oEnd, const int sStart, const int sEnd,const  int depth) {
            int key = oStart*(N+1)*N + oEnd*N + sStart;
            if (dp[key] != 0) {
                return dp[key] == 2;
            }

            // Let's look at the distribution within the entire thing then
            auto origF = origPSA[oEnd];
            for (int i = 0; i < 26; i++) {
                origF[i] -= origPSA[oStart][i];
            }

            auto scraF = scraPSA[sEnd];
            for (int i = 0; i < 26; i++) {
                scraF[i] -= scraPSA[sStart][i];
            }

            if (origF != scraF) {
                dp[key] = 1;
                return false;
            }


            // If we made it here, then we are all good.
            int len = oEnd - oStart;
            if (len <= 1) {
                dp[key] = 2;
                return true;
            }


            for (int i = 1; i < len; i++) {
                const int oSplit = oStart + i;
                const int sSplit = sStart + i;
                // That is the split point.
                // So we have now 4 options.

                // This is plain, split into x y and run on x and y
                bool partA = solve(N, origPSA, scraPSA, dp, oStart, oSplit, sStart, sSplit, depth+1)
                && solve(N, origPSA, scraPSA, dp, oSplit, oEnd, sSplit, sEnd, depth+1);
                if (partA) {
                    dp[key] = 2;
                    return true;
                }

                const int revSplit = sEnd-i;

                // Now in this case we split it into x y and we want to run y x
                bool partB = solve(N, origPSA, scraPSA, dp, oStart, oSplit, revSplit, sEnd, depth+1)
                && solve(N, origPSA, scraPSA, dp, oSplit, oEnd, sStart, revSplit, depth+1);
                if (partB) {
                    dp[key] = 2;
                    return true;
                }
            }


            dp[key] = 1;
            return false;
        }

public:
    bool isScramble(const std::string& orig, const std::string& scrambled) {
        const int N = orig.size();
        // ok, I understood, so at each point we have to check.
        // So question here, is there any index we can't get this at?

        using IT = std::pair<std::pair<int,int>,std::pair<int,int>>;
        
 
        std::vector<std::array<int,26>> origPSA(N+1);
        origPSA[0] = std::array<int,26>{};
        for (int i = 0; i < N; i++) {
            origPSA[i+1] = origPSA[i];
            origPSA[i+1][orig[i]-'a']++;
        }

        std::vector<std::array<int,26>> scraPSA(N+1);
        scraPSA[0] = std::array<int,26>{};
        for (int i = 0; i < N; i++) {
            scraPSA[i+1] = scraPSA[i];
            scraPSA[i+1][scrambled[i]-'a']++;
        }

        // eventually it will become a guessing game.
        BT seen(N*(N+1)*N, 0);
        return solve(N, origPSA, scraPSA, seen, 0, N, 0, N, 0);

    }
};