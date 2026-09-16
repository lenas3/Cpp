#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
    public:
        int getNbContacts(void) const;  //bunu public yaptım çünkü dönen değerine mainden erişmem lazim
        void displayAdd(void);
        void displaySearch(void);
        void displayExit(void);

        PhoneBook(void);
        ~PhoneBook(void);

    private:
        Contact _contacts[8];
        void displayColumns(void);
        std::string fixLength(std::string word);
        int _nbContacts;
        int _index;
};

#endif