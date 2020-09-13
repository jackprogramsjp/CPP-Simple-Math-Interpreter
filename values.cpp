#include <iostream>
#include <string>

#include "values.h"

namespace Values {
    Number::Number(double value) {
        this->value = value;
    }

    Number::operator std::string const() {
        return std::to_string(value);
    }

    void print_number(Number& number) {
        std::cout << static_cast<std::string>(number) << "\n";
    }
}