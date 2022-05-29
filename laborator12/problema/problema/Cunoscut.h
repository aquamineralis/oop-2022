#pragma once
#include "Contact.h"
#include <string>

class Cunoscut : public Contact {
  private:
    std::string phoneNumber;

  public:
    Cunoscut(std::string name, std::string phoneNumber) : Contact(name), phoneNumber(phoneNumber) {
    }
    std::string getPhoneNumber() const;
};
