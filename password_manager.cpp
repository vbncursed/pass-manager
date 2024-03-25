//
//  password_manager.cpp
//  pass-manager
//
//  Created by vbncursed on 3/25/24.
//

#include "password_manager.hpp"

using namespace std;

PasswordManager::PasswordManager() {
    m_filePath = getPathFromUser();
}

void PasswordManager::run() {
    ofstream file(m_filePath + "/pass.csv", ios_base::app);

    if (!file.is_open()) {
        cout << "Can't open file." << endl;
        return;
    }

    cout << "File successfully opened!" << endl;
    int choice;
    do {
        cout << "Menu" << endl;
        cout << "1. Create password manually" << endl;
        cout << "2. Create password with generator" << endl;
        cout << "3. View all passwords" << endl;
        cout << "4. Exit" << endl;
        cout << "Please choose a function: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                PassData data = createManualString();
                string line = createStringForFile(data);
                file << line << endl;
                cout << "Successfully!\n\n";
                break;
            }
            case 2: {
                PassData data = generatePass();
                string line = createStringForFile(data);
                file << line << endl;
                cout << "Successfully!\n\n";
                break;
            }
            case 3:
                cout << "\n";
                viewAllPasswords(m_filePath);
                cout << "\n";
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    file.close();

    cout << "File has been closed, exiting..." << endl;
}

string PasswordManager::getPathFromUser() {
    string path;
    cout << "Enter file path: ";
    getline(cin, path);
    if (path.empty()) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            path = cwd;
        } else {
            cerr << "Error getting current directory!";
        }
    }
    return path;
}

string PasswordManager::createStringForFile(PassData data) {
    return data.url + "," + data.login + "," + data.password;
}

PassData PasswordManager::createManualString() {
    PassData data;
    do {
        cout << "Enter url site: ";
        cin.ignore();
        getline(cin, data.url);
        if (data.url.empty()) {
            cout << "Enter a valid url\n";
        }
    } while (data.url.empty());
    do {
        cout << "Enter login: ";
        getline(cin, data.login);
        if (data.login.empty()) {
            cout << "Enter a valid login\n";
        }
    } while (data.login.empty());
    do {
        cout << "Enter password: ";
        getline(cin, data.password);
        if (data.password.empty()) {
            cout << "Enter a valid password\n";
        }
    } while (data.password.empty());
    return data;
}

PassData PasswordManager::generatePass() {
    PassData data;
    do {
        cout << "Enter url site: ";
        cin.ignore();
        getline(cin, data.url);
        if (data.url.empty()) {
            cout << "Enter a valid url\n";
        }
    } while (data.url.empty());
    do {
        cout << "Enter login: ";
        getline(cin, data.login);
        if (data.login.empty()) {
            cout << "Enter a valid login\n";
        }
    } while (data.login.empty());

    const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    data.password.reserve(20);

    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);

    for (int i = 0; i < 20; ++i) {
        if (i == 6 || i == 13) {
            data.password += '-';
        } else {
            int index = rand() % chars.size();
            data.password += chars[index];
        }
    }

    return data;
}

void PasswordManager::viewAllPasswords(const string& filePath) {
    ifstream file(filePath + "/pass.csv");
    if (file.is_open()) {
        string line;
        cout << "All passwords:\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file.\n";
    }
}
