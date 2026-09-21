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

// TODO: asagida tekrar eden yapiya ayri fonksiyon düsün
// FIX: name == " " dedigim icin birden fazla boslugu kabul ediyo, tüm girdiyi dolasip kontrol etmem lazim
// FIX: add girildiğinde iki kez "enter your name" basıyo
// FIX: kişi bilgilerini aldıktan sonra programdan çıkıyo

void PhoneBook::displayAdd(void)
{
    std::string name;
    std::string lastName;
    std::string nick;
    std::string phoneNum;
    std::string secret;
    
    std::cout << "You're about to add a new contact to the phonebook." << std::endl;
    std::cout << "Little Warning, you can't leave your infos empty." << std::endl;
    while(name.empty() || name == " " || name == "\t" || name == "\n") {
        std::cout << "Please enter your name: " << std::endl;
        getline(std::cin, name, '\n'); 
        if(std::cin.eof()) return ;
    }
    while(lastName.empty() || lastName == " " || lastName == "\t" || lastName == "\n" ) {
        std::cout << "Please enter your last name: " << std::endl;
        getline(std::cin, lastName, '\n'); 
        if(std::cin.eof()) return ;
    }
    while(nick.empty()  || nick == " " || nick == "\t" || nick == "\n") {
        std::cout << "Please enter your nickname: " << std::endl;
        getline(std::cin, nick, '\n'); 
        if(std::cin.eof()) return ;
    }
    while(phoneNum.empty() || phoneNum == " " || phoneNum == "\t" || phoneNum == "\n" ) {
        std::cout << "Please enter your phone number: " << std::endl;
        getline(std::cin, phoneNum, '\n');
        if(std::cin.eof()) return ;
    }
    while(secret.empty() || secret == " " || secret == "\t" || secret == "\n" ) {
        std::cout << "Give us your darkest secret: " << std::endl;
        getline(std::cin, secret, '\n');
        if(std::cin.eof()) return ;

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

// FIX: phonebook boşken index seçtiriyorum mecburen olmayan/bos bi index basıyo ama hata vermiyo
// FIX: bos kalan contact bilgisi hata vermiyo
// FIX: index için digit olmayan bi deger girince hata vermiyo
void PhoneBook::displayContacts(void)
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
{
    int i = 0;
    displayContacts();
    while(i < 0 || i > _nbContacts)
    {
        std::cout << "Invalid index!" << std::endl << "Enter an index: " << std::endl;
        std::cin >> i;
    }
    std::cout << "Enter an index: " << std::endl;
    std::cin >> i;
    std::cout << std::setw(10) << i << "|" << std::setw(10) << _contacts[i].getName() << "|" << std::setw(10) << _contacts[i].getLastName();
    std::cout  << "|" << std::setw(10) << _contacts[i].getNickName() << "|" << std::setw(10) << _contacts[i].getPhoneNum() << "|" << std::setw(10) << _contacts[i].getDarkestSecret() << std::endl;
}

/*
FIX: 
Welcome! Select one of these: ADD, SEARCH or EXIT?
SEARCH
--- Saved Contacts ---
Enter an index: 
8
terminate called after throwing an instance of 'std::bad_alloc'
  what():  std::bad_alloc
zsh: IOT instruction (core dumped)  ./a.out

*/
void PhoneBook::displayExit(void)
{

}

int main()
{
    std::string input;
    PhoneBook ptr;

    std::cout << "Welcome! Select one of these: ADD, SEARCH or EXIT?" << std::endl;
    std::cin >> input;
    while(input != "ADD" && input != "SEARCH" && input != "EXIT")
    {
        std::cout << "Invalid input! Select one of these: ADD, SEARCH or EXIT?" << std::endl;
        std::cin >> input;
    }
    if(input == "ADD")
        ptr.displayAdd();
    if(input == "SEARCH")
        ptr.displaySearch();
    if(input == "EXIT")
        ptr.displayExit();
}

PhoneBook::~PhoneBook()
{
    //destructor
}
