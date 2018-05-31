#ifndef USER_H
#define USER_H
#include <string>

class User
{
public:
    std::string name;
    std::string surname;
    std::string login;
    std::string password;
    enum class Type
    {
        Guest,
        Client,
        Librarian
    };

    Type type;

    User();
};

#endif // USER_H
