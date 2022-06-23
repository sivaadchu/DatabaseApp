#include <iostream>
#include <fstream>
#include <string>
#define ADMINPASS "admin" /// Admin Password

using namespace std;

int main()
{
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
            database11 << "Version 1.0.1 by Sivakumar Adchayan" << endl;
            database11 << "-----------------------------------------------------------------------------------------------" << endl;
            database11 << "Features" << endl;
            database11 << "-----------------------------------------------------------------------------------------------" << endl;
            database11 << "1. We can add users" << endl;
            database11 << "2. We can view users" << endl;
            database11 << "3. We can clear records" << endl;
            database11 << "4. You can edit admin password (#define ADMINPASS \"password\")" << endl;
            database11 << "-----------------------------------------------------------------------------------------------" << endl;
            database11.close();
        }

loop:
    ifstream database2;
    database2.open("database.txt");
    if (database2.bad()) {
        cout << "Database connection error" << endl;
    }
    int count_n;
    for (int i = 0; false == database2.eof(); i++) {
        string line;
        getline(database2, line);
          count_n = i;
    }
    database2.close();
    ofstream database3;
    database3.open("database.txt", ios::app);
    if (count_n == 0) {
        database3 << "Name" << endl;
    }
    database3.close();
    
    bool isAdd = false;
    bool isView = false;
    bool isClear = false;
    bool readme = false;
    int input;
    cout << "Welcome to credential manager.\n1.Add records\n2.View Records\n3.Clear Records\n4.About Software\n5.Exit\nEnter your choice: ";
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
        return 0;
        break;
    default:
        cout << "Invalid key pressed. Retry";
        goto loop;
    }
    if (isAdd) {
        string charName;
        cout << "Enter your name: ";
        cin >> charName;
        ofstream database4;
        database4.open("database.txt", ios::app);
        // database << "Name" << endl;
        database4 << charName << endl;
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
            if (pass == ADMINPASS) {
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
    goto loop;

}

