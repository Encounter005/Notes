#pragma once
#include <iostream>

class NonCopy {
private:
    NonCopy(const NonCopy&) = delete;
    NonCopy& operator=(const NonCopy&) = delete;
public:
    ~NonCopy() = default;
protected:
    NonCopy() = default;
};
