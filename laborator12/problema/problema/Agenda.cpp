#include "Agenda.h"
#include "Prieten.h"

Contact* Agenda::searchContactByName(std::string name) const {
    auto contact = std::find_if(contacts.begin(), contacts.end(), [name](Contact* c) { return c->getName() == name; });
    if (contact == contacts.end())
        return nullptr;
    return *contact;
}

const std::list<Contact*> Agenda::getFriendsList() const {
    std::list<Contact*> friendsList;
    for (auto contact: contacts) {
        if (dynamic_cast<Prieten*>(contact) != nullptr)
            friendsList.push_back(contact);
    }
    return friendsList;
}

void Agenda::deleteContactByName(std::string name) {
    contacts.remove_if([name](Contact* c) { return c->getName() == name; });
}

void Agenda::addContact(Contact* contact) {
    contacts.push_back(contact);
}
