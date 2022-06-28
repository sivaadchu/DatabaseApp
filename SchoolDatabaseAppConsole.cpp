// Load Neccessary Libraries
#include <iostream>
#include <fstream>
#include <string> 

using namespace std;


// Initializing Global Variables
int count_n3;

void setDefault() {
    ifstream myfile3;
    myfile3.open("password.txt");
    if (myfile3) {
        cout << "Admin Password Detected." << endl;
    }
    else {
        cout << "Setting up Admin Password" << endl;
        ofstream database15;
        database15.open("password.txt");
        database15 << "admin";
        database15.close();
    }
    myfile3.close();
} // Admin Pass Default Setting Function

void setAdminPass(string password) {
    ofstream data;
    data.open("password.txt");
    data << password;
    data.close();
} // Admin Pass Changing Function

int main()
{
    cout << "Pre-loading Works" << endl;
    cout << "----------------------------------------------------------" << endl;

        setDefault();
        ifstream myfile;
        myfile.open("database.txt");
        if(myfile) {
            cout << "Database Detected." << endl;
        }
        else {
            cout << "Database not detected. Creating one..." << endl;
            ofstream database10;
            database10.open("database.txt", ios::app);
            database10.close();
        }
        ifstream myfile2;
        myfile2.open("readme.txt");
        if (myfile2) {
            cout << "Readme file Detected." << endl;
        }
        else {
            cout << "Readme file not Detected. Creating one..." << endl;
            ofstream database11;
            database11.open("readme.txt", ios::app);
            database11 << "-----------------------------------------------------------------------------------------------" << endl;
            database11 << "School Database App" << endl;
            database11 << "-----------------------------------------------------------------------------------------------" << endl;
            database11 << "Version 1.0.2 by Sivakumar Adchayan" << endl;
            database11 << "-----------------------------------------------------------------------------------------------" << endl;
            database11 << "Features" << endl;
            database11 << "-----------------------------------------------------------------------------------------------" << endl;
            database11 << "1. We can add users & their details" << endl;
            database11 << "2. We can view users with their details" << endl;
            database11 << "3. We can clear all the user records" << endl;
            database11 << "4. You can change admin password. (default is admin, You can change with password.txt too)" << endl;
            database11 << "-----------------------------------------------------------------------------------------------" << endl;
            database11.close();
        }

loop:
    ifstream database2;
    database2.open("database.txt");
    if (database2.bad()) {
        cout << "Database connection error" << endl;
    }
    
    for (int i = 0; false == database2.eof(); i++) {
        string line;
        getline(database2, line);
          count_n3 = i;
    }
    database2.close();
    ofstream database3;
    database3.open("database.txt", ios::app);
    if (count_n3 == 0) {
        database3 << "Index\tName\tRoll No.\tDivision\tAverage" << endl;
    }
    database3.close();
    cout << "----------------------------------------------------------" << endl;
    bool isAdd = false;
    bool isView = false;
    bool isClear = false;
    bool readme = false;
    bool isChangeAdmin = false;

    int input;
    cout << "Welcome to credential manager.\n1.Add records\n2.View Records\n3.Clear Records\n4.About Software\n5.Admin Password Change\n6.Exit\nEnter your choice: ";
    cin >> input;
    switch (input) {
    case 1:
        isAdd = true;
        break;
    case 2:
        isView = true;
        break;
    case 3:
        isClear = true;
        break;
    case 4:
        readme = true;
        break;
    case 5:
        isChangeAdmin = true;
        break;
    case 6:
        return 0;
        break;
    default:
        cout << "Invalid key pressed. Retry" << endl;
        goto loop;
    }
    if (isAdd) {
        int rollno;
        cout << "Enter your admission number: ";
        cin >> rollno;
        string charName;
        cout << "Enter your name: ";
        cin >> charName;
        string division;
        cout << "Enter your class with division: ";
        cin >> division;
        double average;
        cout << "Enter your last exam average: ";
        cin >> average;
        fstream database4;
        database4.open("database.txt", ios::in | ios::app);
        database4 << count_n3 << "\t" << rollno << "\t" << charName << "\t" << division << "\t\t" << average << endl;
        if (database4.is_open()) {
            cout << "Record added" << endl;
        }
        database4.close();
    }
    if (isView) {
        ifstream database;
        database.open("database.txt");
        if (database.is_open()) {
            while (!database.eof()) {
                string line;
                getline(database, line);
                cout << line << endl;
             }
             cout << "" << endl;
             database.close();
         }  else {
            cout << "Unable to connect to database" << endl;
         }
    }
    if (isClear) {
        bool retry = false;
        do {
            retry = false;
            string pass;
            cout << "Enter Admin Password: ";
            cin >> pass;
            fstream getAdminPass2;
            getAdminPass2.open("password.txt");
            string passl2;
            getAdminPass2 >> passl2;
            if (pass == passl2) {
                ofstream database5;
                database5.open("database.txt");
                database5 << "";
                database5.close();
                cout << "Successfully cleared." << endl;
            }
            else {
                cout << "Incorrect Password. Check it out ." << endl;
                retry = true;
            }
        } while (retry == true);
    }
    if (readme) {
        ifstream database6;
        database6.open("readme.txt");
        while (!database6.eof()) {
            string line;
            getline(database6, line);
            cout << line << endl;
        }
    }
    if (isChangeAdmin) {
        bool retry2 = false;
        do {
            string currentPass;
            string newPass1;
            string newPass2;
            bool valueGot = false;
            do {
                retry2 = false;
                cout << "Enter your current password: ";
                cin >> currentPass;
                cout << "Enter your new password: ";
                cin >> newPass1;
                cout << "Re-enter your new password: ";
                cin >> newPass2;
                if (currentPass == "") {
                    valueGot = false;
                }
                else {
                    valueGot = true;
                }
            } while (valueGot == false);
            if (newPass1 == newPass2) {
                ifstream getAdminPass;
                getAdminPass.open("password.txt");
                string passl;
                getAdminPass >> passl;
                getAdminPass.close();
                if (passl == currentPass) {
                    setAdminPass(newPass2);
                    cout << "Password Updated." << endl;
                }
                else {
                    cout << "Old Password is incorrect" << endl;
                    retry2 = true;
                }
                
            }
            else {
                cout << "New passwords doesn't match" << endl;
                retry2 = true;
            }
        } while (retry2 == true);
    }
    goto loop;

} // Main Function

