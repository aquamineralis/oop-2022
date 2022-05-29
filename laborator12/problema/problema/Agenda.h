#pragma once
#include "Contact.h"
#include <list>

class Agenda {
  private:
    std::list<Contact*> contacts;

  public:
    Contact* searchContactByName(std::string name) const;
    const std::list<Contact*> getFriendsList() const;
    void deleteContactByName(std::string name);
    void addContact(Contact* contact);
};
