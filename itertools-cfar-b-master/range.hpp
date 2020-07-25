
#include <iostream>
using namespace std;
namespace itertools
{
    class range
    {
    public:
        int first;
        int last;

        range(int first, int end) : first(first), last(end) {}

        class iterator
        {
        public:
            int runner;

            iterator(int first) : runner(first) {}

            //-------------------------------------------------operators-------------------------------------------------
            bool operator!=(iterator &other) const
            {
                return this->runner != other.runner;
            }

            bool operator==(iterator &other) const
            {
                return this->runner == other.runner;
            }

            int operator*()
            {
                return this->runner;
            }
            iterator &operator++()
            {
                ++runner;
                return *this;
            }
        };

        iterator begin()
        {
            return iterator(first);
        }
        iterator end()
        {
            return iterator(last);
        }
    };
} // namespace itertools
