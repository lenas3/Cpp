#include "Contact.hpp"

Contact::Contact()
{
}

std::string Contact::getName(void) const
{
    return _name;
}
std::string Contact::getLastName(void) const
{
    return _lastName;
}
std::string Contact::getPhoneNum(void)  const
{
    return _phoneNum;
}
std::string Contact::getNickName(void)  const
{
    return _nickName;
}
std::string Contact::getDarkestSecret(void) const
{
    return _darkestSecret;
}

void Contact::setName(std::string input)
{
    _name = input;
}
void Contact::setLastName(std::string input)
{
    _lastName = input;
}
void Contact::setPhoneNum(std::string input) 
{
    _phoneNum = input;
}
void Contact::setNickname(std::string input)
{
    _nickName = input;
}
void Contact::setDarkestSecret(std::string input)
{
    _darkestSecret = input;
}
