//
// Created by jonat on 2025-10-06.
//

#ifndef LAB_4_MAIL_BOX_H
#define LAB_4_MAIL_BOX_H
#include <vector>
#include "email.h"


class mail_box {
private:
    std::vector<email> mailbox;
public:
    mail_box();
    std::vector<email>& get_mailbox();
    void add_email(const std::string& who, const std::string& date, const std::string& subject);

    void sort_who();
    void sort_date();
    void sort_subject();
};




#endif //LAB_4_MAIL_BOX_H
