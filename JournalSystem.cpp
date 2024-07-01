/**
 * @file JournalSystem.cpp
 * @author Rusho Binnabi
 * @date 2022-08-10
 * @copyright Copyright (c) 2022
 * Code File Updated: 8/11/2022 at 10:31 PM
 * Contact Information: RushoBinnabi123@yahoo.com
 */

#include <iostream> // includes the iostream library for use in this program.
#include <fstream> // includes the fstream library for use in this program.
#include <string> // includes the string library for use in this program.
#include <cstring> // includes the cstring library for use in this program.
#include <unistd.h> // includes the unistd library for use in this program.
#include <stdio.h> // includes the stdio library for use in this program.
#include <dirent.h> // includes the dirent library for use in this program.
#include <string.h> // includes the string library for use in this program.
#include <filesystem> // includes the filesystem library for use in this program.

using namespace std; // this program uses the std namespace.

using std::cout; // this program uses the cout namespace.
using std::cin; // this program uses the cin namespace.
using std::endl; // this program uses the endl namespace.
using std::string; // this program uses the std string namespaces.
using std::filesystem::current_path; // this program uses the std filesystem current path namespace.

/**
 * this createJournalEntry() method creates and writes a journal entry file whose file name is the name inside name which is the name of the file that the user inputs.
 * this method is void because it doesn't return anything.
 */

void createJournalEntry() {
    string name; // creates a string variable called name.
    string contents; // creates a string variable called contents.
    ofstream file; // creates a ofstream object called file.
    cout << "Enter the name of the journal entry to be created: "; // prompts the user to enter a name for the journal entry file.
    cin >> name; // name gets the name from the user input which is the name of the journal entry file.
    cin.ignore(INT_MAX, '\n'); // the ignore() method ignores user input until it either comes across the biggest integer number from INT_MAX or a new line character so that more than one word as well as spaces can be included in the user input.
    cout << "\nEnter the contents of the journal entry: "; // prompts the user to enter the contents of the journal entry file.
    getline(cin, contents); // the getline() method gets every input from the user input to put into the journal entry file using cin as it's 1st argument and contents, which is the string variable that will have the contents of the journal entry file, as it's 2nd argument.
    file.open(name); // using the open() method of file, it opens the file that is inside name.
    file << contents; // file will have the contents of contents written into it.
    file.close(); // using the close() method of file, it closes file.
    sleep(2); // the program sleeps for 2 seconds.
    cout << "\nJournal entry file created."; // tells the user that the journal entry file has been created.
    sleep(2); // the program sleeps for 2 seconds.
    cout << "\n\nReturning to Main Menu..."; // tells the user that the program is returning to the main menu.
    sleep(2); // the program sleeps for 2 seconds.
    system("cls"); // using the system() method and "cls" as it's argument, it clears the screen.
} // the end of the createJournalEntry() method.

/**
 * this createJournalEntry() method reads a journal entry file whose file name is the name inside name which is the name of the file that the user inputs.
 * this method is void because it doesn't return anything.
 */

void readJournalEntry() {
    string name; // creates a string variable called name.
    string contents; // creates a string variable called contents.
    ifstream file; // creates a ofstream object called file.
    cout << "Enter the name of the journal entry to be read: "; // prompts the user to enter a name for the journal entry file.
    cin >> name; // name gets the name from the user input which is the name of the journal entry file.
    cin.ignore(INT_MAX, '\n'); // the ignore() method ignores user input until it either comes across the biggest integer number from INT_MAX or a new line character so that more than one word as well as spaces can be included in the user input.
    file.open(name); // using the open() method of file, it opens the file that is inside name.
    cout << "\nContents of " << name << ": \n\n"; // shows what the contents of the journal entry file inside name is.
    while (getline(file, contents)) { // the code inside the while loop will run as long as there is text to be read from file using the getline() method and file and contents as it's two arguments.
        cout << contents; // prints out each line of contents.
    } // the end of the while loop.
    file.close(); // using the close() method, it closes file.
    cout << "\n\n\nPress Enter to exit when finished."; // tells the user to press enter when they're finished reading the contents of the journal entry file.
    cin.get(); // using the get() method of cin, it waits for the user to press enter when they're finished reading the contents of the journal entry file.
    cout << "\nReturning to Main Menu..."; // tells the user that the program is returning to the main menu.
    sleep(2); // the program sleeps for 2 seconds.
    system("cls"); // using the system() method and "cls" as it's argument, it clears the screen.
} // the end of the readJournalEntry() method.

/**
 * this deleteJournalEntry() method delete a journal entry file whose file name is the name inside name which is the name of the file that the user inputs.
 * this method is void because it doesn't return anything.
 */

void deleteJournalEntry() {
    int status; // an integer variable called status gets created.
    string name; // a string variable called name gets created.
    cout << "Enter the name of the journal entry to be deleted: "; // prompts the user to enter the name of the journal entry file that will be deleted.
    cin >> name; // name gets the name from the user input which is the name of the journal entry file.
    status = remove(name.c_str()); // status will have either a 1 or a 0 which is based on whether the file inside name was able to be successfully deleted using the remove() method.
    if (status == 0) { // the code inside the if statement will be run if the value of status is a 0 which means the file inside name was succesfully deleted.
        cout << "\nJournal entry deleted."; // tells the user that the file inside name was deleted.
    } // the end of the if statement.
    else { // otherwise, the code inside the else statement gets run.
        cout << "\nError. The journal entry could not be deleted."; // tells the user that the file inside name couldn't be deleted.
    } // the end of the else statement.
    sleep(2); // the program sleeps for 2 seconds.
    cout << "\n\nReturning to Main Menu..."; // tells the user that the program is returning to the main menu.
    sleep(2); // the program sleeps for 2 seconds.
    system("cls"); // using the system() method and "cls" as it's argument, it clears the screen.
} // the end of the deleteJournalEntry() method.

/**
 * this listJournalEntries() method lists all the journal entry files as well as the location of where the program is saved.
 * this method is void because it doesn't return anything.
 */

void listJournalEntries() {
    cout << "Here are the saved journal entries: \n\n"; // shows the user the list of saved journal entries.
    DIR *d; // creates a DIR object pointer called d.
    char *p1,*p2; // creates 2 char pointers called p1 and p2.
    int ret; // creates an integer variable called ret.
    struct dirent *dir; // creates a struct dirent object pointer dir.
    d = opendir("."); // the current directory will be opened using the opendir() method and the pointer d.
    if (d) { // the code inside the if statement will run if the current directory using d was able to be opened.
        while ((dir = readdir(d)) != NULL) { // the code inside the while loop will run as long as the directory inside d is able to be read using the readdir() method and the pointer dir.
            p1=strtok(dir->d_name,"."); // the pointer p1, using the strtok() method, will have the string token of the name of the current directory element which is being accessed by the dir pointer.
            p2=strtok(NULL,"."); // the pointer p2, using the strtok() method, will have the empty string token of the current directory.
            if(p2!=NULL) { // the code inside the if statement will run if the value of pointer p2 is not empty.
                ret=strcmp(p2,"txt"); // ret will compare the string name of the current txt file.
                if(ret==0) { // the code inside the if statement will run if the value of the ret is 0.
                    cout << p1 << "\n"; // prints out the name of the current journal entry file inside the p1 pointer.
                } // the end of the if statement.
            } // the end of the if statement.
        } // the end of the while loop.
        cout << "\n"; // prints a new line to create some line spacing.
        closedir(d); // using the closedir() method, it closes the directory inside the pointer d.
    } // the end of the if statement.
    cout << "\nAnd the main program is saved here: \n\n" << current_path(); // shows where the main program is saved using the current_path() method and prints 2 new lines to create some line spacing.
    cin.get(); // using the get() method of cin, it waits for the user to press enter when they're finished looking at the location of the journal entry file.
} // the end of the listJournalEntries() method.

/**
 * this exitSystem() method exits the system.
 * this method is void because it doesn't return anything.
 */

void exitSystem() {
    exit(0); // exits the program with a code of 0 which means the program exitted successfully.
} // the end of the exitSystem() method.

int main() {
    int choice; // an integer variable called choice gets created.
    cout << "\n------ Welcome to The Journal System ------\n"; // welcomes the user to the Journal System.
    cout << "\nPlease choose from the following options: \n"; // tells the user to choose from the following options.
    cout << "\n1: Create Journal Entry"; // tells the user that option 1 will create journal entries.
    cout << "\n2: Read Journal Entry"; // tells the user that option 2 will read journal entries.
    cout << "\n3: Delete Journal Entry"; // tells the user that option 3 will delete journal entries.
    cout << "\n4: List Journal Entries and Program Location"; // tells the user that option 4 will list the journal entries as well as where the main program file is saved at.
    cout << "\n5: Exit Program"; // tells the user that option 5 will exit the program.
    cout << "\n\nChoice: "; // prompts the user to select a choice.
    cin >> choice; // choice gets the choice from the user input which is what option that the user chose.
    while (choice != 5) { // the code inside the while loop will run as long the user doesn't select option 5.
        if (choice == 1) { // the code inside the if statement will run if the user selected option 1.
            sleep(2); // the program sleeps for 2 seconds.
            system("cls"); // using the system() method and "cls" as it's argument, it clears the screen.
            createJournalEntry(); // calls the createJournalEntry() method.
        } // the end of the if statement.
        else if (choice == 2) { // the code inside the else if statement will run if the user selected option 2.
            sleep(2); // the program sleeps for 2 seconds.
            system("cls"); // using the system() method and "cls" as it's argument, it clears the screen.
            readJournalEntry(); // calls the readJournalEntry() method.
        } // the end of the else if statement.
        else if (choice == 3) { // the code inside the else if statement will run if the user selected option 3.
            sleep(2); // the program sleeps for 2 seconds.
            system("cls"); // using the system() method and "cls" as it's argument, it clears the screen.
            deleteJournalEntry(); // calls the deleteJournalEntry() method.
        } // the end of the else if statement.
        else if (choice == 4) { // the code inside the else if statement will run if the user selected option 4.
            sleep(2); // the program sleeps for 2 seconds.
            system("cls"); // using the system() method and "cls" as it's argument, it clears the screen.
            listJournalEntries(); // calls the listJournalEntries() method.
            cout << "\n\n\n\nPress Enter to exit when finished."; // tells the user to press enter when they're finished.
            cin.get(); // using the get() method of cin, it waits for the user to press enter.
            sleep(2); // the program sleeps for 2 seconds.
            system("cls"); // using the system() method and "cls" as it's argument, it clears the screen.
        } // the end of the else if statement.
        else if (choice == 5) { // the code inside the else if statement will run if the user selected option 5.
            sleep(2); // the program sleeps for 2 seconds.
            system("cls"); // using the system() method and "cls" as it's argument, it clears the screen.
            exitSystem(); // calls the exitSystem() method.
        } // the end of the else if statement.
        sleep(2); // the program sleeps for 2 seconds.
        system("cls"); // using the system() method and "cls" as it's argument, it clears the screen.
        cout << "\nWould you like to use the Journal System again?\n"; // asks the user if they want to use the Journal System again.
        cout << "\n1: Yes"; // tells the user that option 1 means that they want to use the system again.
        cout << "\n2: No\n"; // tells the user that option 2 means that they don't want to use the system again.
        cout << "\nChoice: "; // prompts the user to select a choice.
        cin >> choice; // choice gets the choice from the user input which is what option that the user chose.
        sleep(2); // the program sleeps for 2 seconds.
        system("cls"); // using the system() method and "cls" as it's argument, it clears the screen.
        if (choice == 1) { // the code inside the if statement will run if the value of choice is 1.
            cout << "\n------ Welcome to The Journal System ------\n"; // welcomes the user to the Journal System.
            cout << "\nPlease choose from the following options: \n"; // tells the user to choose from the following options.
            cout << "\n1: Create Journal Entry"; // tells the user that option 1 will create journal entries.
            cout << "\n2: Read Journal Entry"; // tells the user that option 2 will read journal entries.
            cout << "\n3: Delete Journal Entry"; // tells the user that option 3 will delete journal entries.
            cout << "\n4: List Journal Entries and Program Location"; // tells the user that option 4 will list the journal entries as well as where the main program file is saved at.
            cout << "\n5: Exit Program"; // tells the user that option 5 will exit the program.
            cout << "\n\nChoice: "; // prompts the user to select a choice.
            cin >> choice; // choice gets the choice from the user input which is what option that the user chose.
            sleep(2); // the program sleeps for 2 seconds.
            system("cls"); // using the system() method and "cls" as it's argument, it clears the screen.
        } // the end of the if statement.
        else if (choice == 2) { // the code inside the else if statement will run if the value of choice is equal to 2.
            sleep(2); // the program sleeps for 2 seconds.
            system("cls"); // using the system() method and "cls" as it's argument, it clears the screen.
            exit(0); // exits the program by calling the exit() method with a value of 0 for the argument which means the program exited successfully.
        } // the end of the else if statement.
    } // the end of the while loop.
    return 0; // returns a 0 which means the program ran successfully.
} // the end of the main() method.