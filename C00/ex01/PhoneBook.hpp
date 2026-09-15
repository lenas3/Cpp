#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include "Contact.hpp"

class PhoneBook
{
    public:
        int getNbContacts;

    private:
        Contact contacts[8];
        int _nbContacts;
};

#endif
