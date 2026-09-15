#include "Contact.hpp"

Contact::Contact()
{
    
}

void Contact::inputInfos(void)
{
    std::cout << "Name? :  ";
    std::cin  >> _name;
    std::cout << std::endl << "Last Name? :  ";
    std::cin  >> _lastName;
    std::cout << std::endl << "Phone Number? :  ";
    std::cin  >> _phoneNum;
    std::cout << std::endl << "Area Code? :  ";
    std::cin  >> _areaCode;
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
std::string Contact::getAreaCode(void) const
{
    return _areaCode;
}
