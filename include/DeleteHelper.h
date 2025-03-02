#pragma once
#include <string>

class DeleteHelper
{
public:
    explicit DeleteHelper(std::string name);
    void deleting() const;
    static void temporaryToOriginal();
    void deleteFromContactBook() const;

private:
    std::string contactName_;
};
