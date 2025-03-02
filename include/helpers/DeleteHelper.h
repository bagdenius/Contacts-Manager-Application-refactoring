#pragma once
#include <string>
using namespace std;

class DeleteHelper
{
private:
    string contactName;

public:
    DeleteHelper(string name);
    void deleting();
    void temporary_to_original();
    void deleteFromContactbook();
};
