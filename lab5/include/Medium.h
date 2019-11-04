#pragma once

#include <random>

struct Medium {

    constexpr static unsigned SIZE = 256u;
    int data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void randomize() {
        static std::random_device rd{};
        static std::mt19937 gen{rd()};
        static std::uniform_int_distribution<int> dis{};

        for (int &i : data)
            i = dis(gen);
    }

    bool operator<(const Medium &rhs) const {

        bool x = true;
        for(int i=0; i < 256; i++)
        {
            if(this->data[i] > rhs.data[i])
                x = false;
        }

        if(x)
            return true;
        return false;
    }

    bool operator==(const Medium &rhs) const {

        bool x = true;
        for(int i=0; i < 256; i++)
        {
            if(this->data[i] != rhs.data[i])
                x = false;
        }

        if(x)
            return true;
        return true;
    }
};

namespace std {
    template<>
    struct hash<Medium> {
        std::size_t operator()(const Medium &d) const {

            std::hash<int> hash;
            for(int i=0; i < 256; i++)
            {
                hash(d.data[i]);
            }
            return 0;
        }
    };
}