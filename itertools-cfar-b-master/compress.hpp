#include <iostream>
#include <vector>
using namespace std;

namespace itertools
{

    template <typename T, typename B>
    class compress
    {
        T _container;
        B boolvec;

    public:
        compress(T vec, B booli) : _container(vec), boolvec(booli) {}

        class iterator
        {
        public:
            typename T::iterator itervec;
            typename B::iterator booliter;

            iterator(typename T::iterator vec, typename B::iterator booliterator)
                : itervec(vec), booliter(booliterator) {}

            //-------------------------------------------------operators-------------------------------------------------
            bool operator!=(const iterator &other)
            {
                while (other.itervec != itervec)
                {
                    if (*booliter == true)
                    {
                        return true;
                    }
                    ++itervec;
                    ++booliter;
                }
                return false;
            }

            auto operator*()
            {
                return *itervec;
            }

            iterator &operator++()
            {
                ++itervec;
                ++booliter;
                return *this;
            }
        };

        iterator begin()
        {
            return iterator(_container.begin(), boolvec.begin());
        }

        iterator end()
        {
            return iterator(_container.end(), boolvec.begin());
        }
    };
} // namespace itertools