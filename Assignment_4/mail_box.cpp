//
// Created by jonat on 2025-10-06.
//

#include "mail_box.h"
#include <algorithm>

mail_box::mail_box() : mailbox{} {
}

std::vector<email> & mail_box::get_mailbox() {
    return mailbox;
}

void mail_box::add_email(const std::string& who, const std::string& date, const std::string& subject) {
    mailbox.emplace_back(who, date, subject);
}

void mail_box::sort_who() {
    std::ranges::sort(mailbox, comp_who_date_subject());
}

void mail_box::sort_date() {
    std::ranges::sort(mailbox, comp_date_who_subject());
}

void mail_box::sort_subject() {
    std::ranges::sort(mailbox, comp_subject_who_date());
}
