#ifndef BOOK_H
#define BOOK_H
//#include "bookdata.h"
#include <string>
#include <QDateTime>

class Book
{
public:
        long m_bookID;
        std::string m_title;
        std::string m_author;
        long m_ISBN;
        int m_publicationDate;
        std::string m_publicationPlace;
        std::string m_publisher;
        int m_pagesNumber;
        bool m_availability;
        std::string m_borrowerlogin;
        QDateTime m_startdate;
        QDateTime m_enddate;
        bool m_reservation;
        std::string m_reserveLogin;



        long getBookID() const { return m_bookID; }
        std::string getTitle() const {return m_title;}
        std::string getAuthor() const {return m_author;}
        long getISBN() const {return m_ISBN;}
        int getPublicationDate() const {return m_publicationDate;}
        std::string getPublicationPlace() const {return m_publicationPlace;}
        std::string getPublisher() const {return m_publisher;}
        int getPagesnumber() const {return m_pagesNumber;}
        bool getAvailability() const {return m_availability;}
        std::string getBorrowerLogin() const {return m_borrowerlogin;}
        QDateTime getStartDate() const {return m_startdate;}
        QDateTime getEndDate() const {return m_enddate;}
        bool getReservation() const {return m_reservation;}
        std::string getReserveLogin() const{return m_reserveLogin;}
        Book()=default;

        Book(long i_bookID,
             std::string i_title,
             std::string i_author,
             long i_ISBN,
             int i_publicationDate,
             std::string i_publicationPlace,
             std::string i_publisher,
             int i_pagesNumber,
             bool i_availability,
             std::string i_borrowerlogin,
             QDateTime i_startdate,
             QDateTime i_enddate,
             bool i_reservation,
             std::string i_reserveLogin);
};

#endif // BOOK_H
