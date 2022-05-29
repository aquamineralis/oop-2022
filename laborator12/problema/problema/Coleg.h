#pragma once
#include "Contact.h"
#include <string>

class Coleg : public Contact {
  private:
    std::string phoneNumber;
    std::string firm;
    std::string address;

  public:
    Coleg(std::string name, std::string phoneNumber, std::string firm, std::string address)
        : Contact(name), phoneNumber(phoneNumber), firm(firm), address(address) {
    }
    std::string getPhoneNumber() const;
    std::string getFirm() const;
    std::string getAddress() const;
};
