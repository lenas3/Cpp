#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>


class Contact {
    public:
        void inputInfos(void);
        std::string getName(void) const;
        std::string getLastName(void) const;
        std::string getPhoneNum(void) const;
        std::string getAreaCode(void) const;
        int nbContacts;

    private:
        std::string _name;
        std::string _lastName;
        std::string _phoneNum;
        std::string _areaCode;
};

#endif
