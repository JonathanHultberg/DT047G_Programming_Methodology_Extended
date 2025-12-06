#include <iostream>
#include "mail_box.h"
#include "email.h"

template<typename T>
void show(const std::vector<T> &vec){
    for (const auto& element: vec) {
        std::cout << element << "\n";
    }
}

int main() {
    mail_box mailbox;

    mailbox.add_email("Jimmy Åhlander", "2025-04-23",
        "C++, glöm inte att kontrollera för selfe-assignmet!");
    mailbox.add_email("Nayeb Maleki", "2025-09-23",
        "Exempel på ER-diagram och deras implementation");
    mailbox.add_email("Martin Kjällkvist", "2025-10-01",
        "R-values och L-values");
    mailbox.add_email("Ladok", "2025-08-12",
    "Ladokavisering, Resultat inrapporterat i Ladok");
    mailbox.add_email("Seth Dooley", "2025-10-07",
        "Missile launch codes");

    mailbox.sort_who();

    show(mailbox.get_mailbox());
    std::cout <<"\n\n";

    mailbox.sort_date();

    show(mailbox.get_mailbox());
    std::cout <<"\n\n";

    mailbox.sort_subject();

    show(mailbox.get_mailbox());


    return 0;
}