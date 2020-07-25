#include <iostream>
#include <vector>
using namespace std;

namespace itertools
{

    template <typename FuncB, typename T>
    class filterfalse
    {
    public:
        FuncB boolvec;
        T _container;

        filterfalse(FuncB booli, T vec) : boolvec(booli), _container(vec) {}

        class iterator
        {
        public:
            FuncB funcbool;
            typename T::iterator itervec;

            iterator(FuncB funcbooli, typename T::iterator itervector)
                : funcbool(funcbooli), itervec(itervector) {}

            //-------------------------------------------------operators-------------------------------------------------
            bool operator!=(const iterator &other)
            {
                while (other.itervec != itervec)
                {
                    if (!funcbool(*itervec))
                    {
                        return true;
                    }
                    ++itervec;
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
                return *this;
            }
        };

        iterator begin()
        {
            return iterator(boolvec, _container.begin());
        }

        iterator end()
        {
            return iterator(boolvec, _container.end());
        }
    };
} // namespace itertools