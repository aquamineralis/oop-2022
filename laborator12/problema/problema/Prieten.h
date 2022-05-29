#pragma once
#include "Contact.h"
#include <string>

class Prieten : public Contact {
  private:
    std::string birthday;
    std::string phoneNumber;
    std::string address;

  public:
    Prieten(std::string name, std::string birthday, std::string phoneNumber, std::string address)
        : Contact(name), birthday(birthday), phoneNumber(phoneNumber), address(address) {
    }
    std::string getBirthday() const;
    std::string getPhoneNumber() const;
    std::string getAddress() const;
};
