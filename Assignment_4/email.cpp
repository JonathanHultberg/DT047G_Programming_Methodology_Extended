//
// Created by jonat on 2025-10-06.
//

#include "email.h"

email::email(std::string who, std::string date, std::string subject)
    : who(std::move(who)), date (std::move(date)), subject (std::move(subject)) {
}

bool comp_who_date_subject::operator()(const email &lhs, const email &rhs) {
    return std::tie(lhs.who, lhs.date, lhs.subject) < std::tie(rhs.who, rhs.date, rhs.subject);
}

bool comp_date_who_subject::operator()(const email &lhs, const email &rhs) {
    return std::tie(lhs.date,lhs.who, lhs.subject) < std::tie(rhs.date, rhs.who, rhs.subject);
}

bool comp_subject_who_date::operator()(const email &lhs, const email &rhs) {
    return std::tie(lhs.subject, lhs.who, lhs.date) < std::tie(rhs.subject, rhs.who, rhs.date);
}

std::ostream & operator<<(std::ostream &os, const email &em) {
    os << "From: " + em.who + " | Date: " + em.date + " | Subject: " + em.subject;
    return os;
}
