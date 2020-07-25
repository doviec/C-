#include <iostream>
#include <vector>
using namespace std;

namespace itertools
{
    typedef struct
    {
        template <typename T>
        T operator()(T f1, T f2) const
        {
            return f1 + f2;
        }
    } add;

    template <typename T, typename _operator = add>
    class accumulate
    {
    public:
        T _container;
        _operator operat;

        accumulate(T vec, _operator operat1 = add()) : _container(vec), operat(operat1) {}

        class iterator
        {
        public:
            typename T::iterator iter;
            decltype(*(_container.begin())) sum;
            int counter;
            _operator operat;

            iterator(typename T::iterator first, _operator operat1)
                : iter(first), sum(*iter), counter(0), operat(operat1) {}

            //-------------------------------------------------operators-------------------------------------------------
            bool operator!=(const iterator &other)
            {
                return other.iter != iter;
            }

            // bool operator==(const iterator &other)
            // {
            //     return this == other.iter;
            // }

            auto operator*()
            {
                if (counter == 0) // means its the first item
                {
                    counter++;
                    return *iter;
                }
                sum = operat(sum, *iter);
                return sum;
            }

            iterator &operator++()
            {
                ++iter;
                return *this;
            }
        };

        iterator begin()
        {
            return iterator(_container.begin(), operat);
        }
        iterator end()
        {
            return iterator(_container.end(), operat);
        }
    };
} // namespace itertools