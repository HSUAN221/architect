// Copyright (c)
#ifndef SRC_ARCHITECT_BEGINNER_HPP_
#define SRC_ARCHITECT_BEGINNER_HPP_

namespace architect {

class beginner {
 public:
    beginner() = default;
    explicit beginner(value_type);
    virtual ~beginner();

    bool setValue(value_type);
    value_type getValue(void);
 private:
    value_type value_;
};

inline beginner::beginner(value_type val)
: value_(val) {}

inline beginner::~beginner() {/*empty*/}

bool beginner::setValue(value_type val) {
    value_ = val;
    return true;
}

value_type beginner::getValue(void) {
    return value_;
}

}
#endif  // SRC_ARCHITECT_BEGINNER_HPP_
