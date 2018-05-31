#include "book.h"
#include <fstream>
#include <string>
#include <iostream>

Book::Book(long i_bookID,
         std::string i_title,
         std::string i_author,
         long i_ISBN,
         int i_publicationDate,
         std::string i_publicationPlace,
         std::string i_publisher,
         int i_pagesNumber,
         bool i_availability,
         std::string i_borrowerLogin,
         QDateTime i_startdate,
         QDateTime i_enddate,
         bool i_reservation,
         std::string i_reserveLogin)
    : m_bookID(i_bookID),
      m_title (i_title),
      m_author (i_author),
      m_ISBN (i_ISBN),
      m_publicationDate (i_publicationDate),
      m_publicationPlace (i_publicationPlace),
      m_publisher (i_publisher),
      m_pagesNumber (i_pagesNumber),
      m_availability (i_availability),
      m_borrowerlogin (i_borrowerLogin),
      m_startdate (i_startdate),
      m_enddate (i_enddate),
      m_reservation (i_reservation),
      m_reserveLogin (i_reserveLogin)


{

}
