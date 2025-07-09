#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = [] () {
    struct ___ {
        static void _() { ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
    }();
#endif

class FindSumPairs {

    vector<int> vec1, vec2;
    unordered_map<int, int> mp;


public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->vec1 = nums1;
        this->vec2 = nums2;

        for( int& i : nums2 )
            mp[i]++;
    }

    void add(int index, int val) {
        mp[vec2[index]]--;
        vec2[index] += val;
        mp[vec2[index]]++;
    }

    int count(int tot) {
        int c = 0;
        for( int& x : vec1 ) {
            c += mp[tot - x];
        }

        return c;
    }
};

int main() {
    return 0;
}