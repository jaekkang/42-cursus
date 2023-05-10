#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact {
    private :
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;

    public :
        Contact();
        ~Contact();

        void PrintContact();
        void PrintDetail();
        void AddContact();
        std::string get_fname(void);
        std::string get_lname(void);
        std::string get_nname(void);
        std::string get_pnumber(void);
        std::string get_secret(void);
        std::string LengthCheck(std::string str);
};

#endif