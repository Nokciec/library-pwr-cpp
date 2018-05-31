#ifndef REPOSITORY_FOR_CLIENT_H
#define REPOSITORY_FOR_CLIENT_H
#include "book.h"

class Repository_for_client
{
public:

    Repository_for_client();
private:
    Book makeReservation (long bookID, long long clientID);
    Book cancelReservation (long bookID);
    Book renewBorrowedBook (long bookID, long long clientID);
};

#endif // REPOSITORY_FOR_CLIENT_H
