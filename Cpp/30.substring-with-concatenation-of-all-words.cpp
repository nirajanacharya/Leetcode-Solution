#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")

bool init() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    return true;
}

bool _ = init();

constexpr unsigned int C = 1 << 16;
constexpr unsigned int M = ((1 << 16) - 1) << 16;

unsigned int** window = new unsigned int* [10000];

class Solution {
public:
    std::vector<int> findSubstring(std::string s,
                                   const std::vector<std::string>& words) {
        const unsigned short len = words[0].size();
        if (s.size() < len) {
            return {};
        }
        std::unordered_map<std::string_view, unsigned int> word_count;
        word_count.reserve(words.size());
#pragma unroll
        for (const auto& s : words) {
            word_count[s] += C;
        }
        unsigned short l = 0, r = 0;
        vector<int> ans;
#pragma unroll
        for (unsigned short start = 0; start < len; ++start) {
            for (unsigned short i = start; i + len <= s.size(); i += len) {
                auto it = word_count.find(std::string_view(&s[i], &s[i + len]));
                if (it == word_count.end()) {
#pragma unroll
                    for (unsigned short idx = l; idx < r; ++idx) {
                        *window[idx] &= M;
                    }
                    l = r = 0;
                } else {
                    if (it->second >> 16 == (it->second & ~M)) {
#pragma unroll
                        for (unsigned short idx = l; idx < r; ++idx) {
                            ++l;
                            if (window[idx] == &it->second) {
                                break;
                            }
                            --(*window[idx]);
                        }
                    } else {
                        ++(it->second);
                    }
                    window[r++] = &it->second;
                    if (r - l == words.size()) {
                        ans.push_back(i - len * (words.size() - 1));
                    }
                }
            }
#pragma unroll
            for (unsigned short idx = l; idx < r; ++idx) {
                *window[idx] &= M;
            }
            l = r = 0;
        }
        return ans;
    }
};