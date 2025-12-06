//
// Created by jonat on 2025-10-06.
//

#ifndef LAB_4_EMAIL_H
#define LAB_4_EMAIL_H
#include <string>


class email {
private:
    std::string who;
    std::string date;
    std::string subject;
public:
    email(std::string who, std::string date, std::string subject);
    email() = default;

    friend std::ostream& operator<<(std::ostream& os, const email& em);

    friend struct comp_who_date_subject;
    friend struct comp_date_who_subject;
    friend struct comp_subject_who_date;
};

struct comp_who_date_subject {
    bool operator()(const email &lhs, const email& rhs);
};

struct comp_date_who_subject {
    bool operator()(const email &lhs, const email& rhs);
};

struct comp_subject_who_date {
    bool operator()(const email &lhs, const email& rhs);
};

#endif //LAB_4_EMAIL_H
