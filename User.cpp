


#include "User.h"


 User::User(string usena, string pass) {
     this->usena=usena;
     this->password=pass;
}


void User::set_use(string a) {
    usena=a;
    return;
}


string User::get_use() {
    return usena;
}


void User::set_pa(string a) {
    password=a;
    return;
}


string User::get_pa() {
    return password;
}

 User::~User() {

}
