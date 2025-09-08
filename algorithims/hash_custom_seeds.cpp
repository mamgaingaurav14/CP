
  #include <bits/stdc++.h>
using namespace std;
#define lil long long int

//hash function for pair class
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2;  // Combine the two hashes
    }
};

//for vector hash 
struct vector_hash {
    std::size_t operator()(const std::vector<int>& v) const {
        std::size_t seed = 0;
        for (int i : v) {
            // Combine the hash of each element with the seed
            seed ^= std::hash<int>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

