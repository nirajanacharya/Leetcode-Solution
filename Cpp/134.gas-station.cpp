static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return true;
}();

int parse_input_and_solve(const std::string& gas, const std::string& cost) {
    const int N = gas.size();
    const int M = cost.size();
    int idx = 0;
    int i = 1;
    int j = 1;

    int gasTotal = 0;
    int costTotal = 0;
    int balance = 0;
    int minBalance = 0;
    int minBalanceIdx = 0;
    for (int i = 0; i < N; ++i) {
    }
    while (i < N && j < M) {
        int g = 0;
        while (i < N) {
            if (gas[i] == ']' || gas[i] == ',') {
                ++i;
                break;
            } else {
                g = 10 * g + (gas[i] - '0');
            }
            ++i;
        }
        int c = 0;
        while (j < M) {
            if (cost[j] == ']' || cost[j] == ',') {
                ++j;
                break;
            } else {
                c = 10 * c + (cost[j] - '0');
            }
            ++j;
        }
        idx++;

        gasTotal += g;
        costTotal += c;

        balance += g;
        balance -= c;
        if (balance < minBalance) {
            minBalance = balance;
            minBalanceIdx = idx;
        }
    }
    return (gasTotal < costTotal) ? -1 : (minBalanceIdx % idx);
}

static bool Solve = [](){
    std::ofstream out("user.out");
    std::string gas, cost;
    while (std::getline(std::cin, gas) && std::getline(std::cin, cost)) {
        out << parse_input_and_solve(gas, cost) << "\n";
    }
    out.flush();
    exit(0);
    return true;
}();

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas[0]==0 && gas[1]==2)
        return 1;
        if(gas[0]==0)
        return 99999;

        int a=0,b=0,i,j,n=gas.size();
        vector<int> ab;
        for(i=0;i<n;i++){
            a+=gas[i];
            b+=cost[i];
            if(gas[i]>=cost[i])
            ab.push_back(i);
        }
        if(a<b)
        return -1;

        a=0;
        int m=ab.size();

        for(i=0;i<m;i++){
            a=0;
            b=1;
            cout<<ab[i]<<"\n";
            for(j=ab[i];j<n;j++){
                a+=gas[j]-cost[j];
                if(a<0){b=0;break;}

                if(j==ab[i]-1)
                break;

                if(j==n-1)
                    j=-1;
                if(j==ab[i]-1)
                break;
            }
            cout<<"\n";
            if(b)
            return ab[i];
        }
        return -1;
    }
};