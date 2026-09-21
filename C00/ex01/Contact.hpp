#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>


class Contact {
    public:
        void setName(std::string input);
        void setLastName(std::string input);
        void setPhoneNum(std::string input);
        void setNickname(std::string input);
        void setDarkestSecret(std::string input);
        std::string getName(void) const;
        std::string getLastName(void) const;
        std::string getPhoneNum(void) const;
        std::string getNickName(void) const;
        std::string getDarkestSecret(void) const;
        int nbContacts;
        Contact(void);

    private:
        std::string _name;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNum;
        std::string _darkestSecret;
};

#endif
