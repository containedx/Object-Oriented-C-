#pragma once

#include <random>

struct Small {

    constexpr static unsigned SIZE = 1u;
    char data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void randomize() {
        static std::random_device rd{};
        static std::mt19937 gen{rd()};
        static std::uniform_int_distribution<char> dis{-128, 127};

        for (char &i : data)
            i = dis(gen);
    }

    bool operator<(const Small &rhs) const {

        if ( this->data[1] < rhs.data[1] )
            return true;
        return false;
    }

    bool operator==(const Small &rhs) const {

        if ( this->data[1] == rhs.data[1] )
            return true;
        return true;
    }
};

namespace std {
    template<>
    struct hash<Small> {
        std::size_t operator()(const Small &d) const {

           std::hash<char> hash;
           return hash(d.data[1]);
        }
    };
}
