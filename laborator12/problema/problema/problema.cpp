#include <iostream>
#include "Agenda.h"
#include "Prieten.h"
#include "Coleg.h"
#include "Cunoscut.h"

int main() {
    Prieten* prieten1 = new Prieten(
          (std::string) "Ana", (std::string) "12.12.2001", (std::string) "0744633267", (std::string) "Iasi");
    Prieten* prieten2 = new Prieten(
          (std::string) "Iulia", (std::string) "22.08.2002", (std::string) "0724754268", (std::string) "Iasi");
    Cunoscut* cunoscut = new Cunoscut((std::string) "Maria", (std::string) "0745733367");
    Coleg* coleg =
          new Coleg((std::string) "Bianca", (std::string) "0754637227", (std::string) "Google", (std::string) "Iasi");

    Agenda agenda;
    agenda.addContact(prieten1);
    agenda.addContact(cunoscut);
    agenda.addContact(coleg);
    agenda.addContact(prieten2);

    auto friendsList = agenda.getFriendsList();
    std::cout << "Friends:\n";
    for (auto f : friendsList) {
        std::cout << f->getName() << '\n';
    }
    std::cout << '\n';

    std::string name("Bianca");
    auto contact = agenda.searchContactByName(name);
    if (contact == nullptr) {
        std::cout << name << " is not a contact\n";
    } else {
        std::cout << name << " is a contact\n";
    }

    agenda.deleteContactByName(name);

    contact = agenda.searchContactByName(name);
    if (contact == nullptr) {
        std::cout << name << " is not a contact\n";
    } else {
        std::cout << name << " is a contact\n";
    }
}