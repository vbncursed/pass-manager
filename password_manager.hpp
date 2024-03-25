//
//  password_manager.hpp
//  pass-manager
//
//  Created by vbncursed on 3/25/24.
//

#ifndef PASSWORD_MANAGER_HPP
#define PASSWORD_MANAGER_HPP

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <ctime>
#include <cstdlib>

struct PassData {
    std::string url;
    std::string login;
    std::string password;
};

class PasswordManager {
public:
    PasswordManager();
    void run();

private:
    std::string getPathFromUser();
    std::string createStringForFile(PassData data);
    PassData createManualString();
    PassData generatePass();
    void viewAllPasswords(const std::string& filePath);

private:
    std::string m_filePath;
};

#endif // password_manager_hpp
