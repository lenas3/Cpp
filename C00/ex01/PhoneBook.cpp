#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    _nbContacts = 0;
    _index = 0;
}
int PhoneBook::getNbContacts(void) const
{
    return _nbContacts;
}

void PhoneBook::displayAdd(void)
{
    std::string name;
    std::string lastName;
    std::string nick;
    std::string phoneNum;
    std::string secret;
    
    std::cout << "You're about to add a new contact to the phonebook." << std::endl;
    std::cout << "Little Warning, you can't leave your infos empty." << std::endl;
    while(name.empty()) {
        std::cout << "Please enter your name: " << std::endl;
        getline(std::cin, name, '\n'); }
    while(lastName.empty() ) {
        std::cout << "Please enter your last name: " << std::endl;
        getline(std::cin, lastName, '\n');
    }
    while(nick.empty() ) {
        std::cout << "Please enter your nickname: " << std::endl;
        getline(std::cin, nick, '\n');
    }
    while(phoneNum.empty() ) {
        std::cout << "Please enter your phone number: " << std::endl;
        getline(std::cin, phoneNum, '\n');
    }
    while(secret.empty() ) {
        std::cout << "Give us your darkest secret: " << std::endl;
        getline(std::cin, secret, '\n');
    }   
    _contacts[_index].setName(name);
    _contacts[_index].setLastName(lastName);
    _contacts[_index].setNickname(nick);
    _contacts[_index].setPhoneNum(phoneNum);
    _contacts[_index].setDarkestSecret(secret);
    if(_index == 7) _index = 0; 
    else    _index++;
    if(_nbContacts < 8) _nbContacts++;
}

std::string PhoneBook::fixLength(std::string word)
{
    int i = 0;
    std::string dup;
    while(word[i] && i < 9)
    {
        dup += word[i]; //bu word[i]'yi dup[i]'nin sonuna eklemek için kullnaılan bi kullanım
        i++;
    }
    dup += '.';
    return (dup);
}

void PhoneBook::displayColumns(void)
{
    int i = 0;
    std::string name;
    std::string lastName;
    std::string nick;
    std::cout << "--- Saved Contacts ---" << std::endl;
    while (i < _nbContacts)
    {
        name = _contacts[i].getName();
        lastName = _contacts[i].getLastName();
        nick = _contacts[i].getNickName();
        if(name.length() >= 10)
            name = fixLength(name);
        if(lastName.length() >= 10)
            lastName = fixLength(lastName);
        if(nick.length() >= 10)
            nick = fixLength(nick);
        std::cout << std::setw(10) << i << "|" << std::setw(10) << name << "|" << std::setw(10) << lastName << "|" << std::setw(10) << nick << std::endl;
        i++;
    }
}

void PhoneBook::displaySearch(void)
{}
void PhoneBook::displayExit(void)
{}


int main()
{
    std::string input;  

    std::cout << "Welcome! Select one of these: ADD, SEARCH or EXIT?" << std::endl;
    std::cin >> input;
    while(input == "ADD" || input == "SEARCH" || input == "EXIT")
    {
        if(input == "ADD")
            displayAdd();
        if(input == "SEARCH")
            displaySearch();
        if(input == "EXIT")
            displayExit();
        std::cout << "Select one of these: ADD, SEARCH or EXIT?" << std::endl;
        std::cin >> input;
    }
}