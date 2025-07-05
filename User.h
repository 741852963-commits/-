/**
 * Project Untitled
 */


#ifndef _USER_H
#define _USER_H
#include<string>
using namespace std;
class User {
public:
    

 User(string usena="", string pass="");
    

void set_use(string a);
    
string get_use();

void set_pa(string a);
    
string get_pa();

    
~ User();
private: 
    string usena;
    string password;
};

#endif //_USER_H
