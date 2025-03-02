#pragma once
#include <string>

class Users
{
public:
    explicit Users(std::string name);
    void checkIn() const;

private:
    std::string name_;
};