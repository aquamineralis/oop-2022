#pragma once
#include <string>

class Contact {
  private:
    std::string name;

  public:
    Contact(std::string name) : name(name){};
    virtual std::string getName() const;
};
