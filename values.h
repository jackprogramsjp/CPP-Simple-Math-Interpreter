#ifndef VALUES_H
#define VALUES_H

#include <string>

namespace Values {
    class Number {
        public:
            double value;

            Number(double);

            operator std::string const();
    };

    void print_number(Number&);
}

#endif // VALUES_H