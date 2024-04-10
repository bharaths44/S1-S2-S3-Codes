#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

char c1, confirm_quantity;
float quantity;
int selectedNum;
double total_amount = 0;
int flag = 0;

// Stores items with their corresponding
// price
map<string, double> items = {
    { "milk", 100 },
    { "eggs", 40 },
    { "fruits", 350 },
    { "eyeshadow", 1500 },
    { "lipstick", 750 },
    { "blush", 1200 },
    { "top", 1000 },
    { "pants", 3000 },
    { "dress", 4000 },
    { "skirt", 1500 }
};

// Stores the selected items with
// their quantity
map<string, int> selected_items;

// Function to print the bill after shopping
// is completed prints the items, quantity,
// their cost along with total amount
void printBill(map<string, double> items,
               map<string, int> selected_items,
               float total_amount)
{
    cout << "Item      "
         << "Quantity      "
         << "Cost\n";

    for (auto j = selected_items.begin();
         j != selected_items.end(); j++) {
        cout << j->first << "        ";
        cout << j->second << "          ";
        cout << (selected_items[j->first])
                    * (items[j->first])
             << endl;
    }

    cout << "-----------------------"
         << "-------------\n";
    cout << "Total amount:             "
         << total_amount << endl;
    cout << "-----------------------"
         << "-------------\n";
    cout << "*****THANK YOU && HAPPY SHOPPING*****";
}

// Function to ask the basic details of any customer
void customerDetails()
{

    cout << "Enter your name: ";
    string customer_name;
    getline(cin, customer_name);

    cout << "WELCOME ";
    for (int i = 0;
         i < customer_name.length();
         i++) {
        cout << char(toupper(
            customer_name[i]));
    }
    cout << "\n";
}

void showMenu()
{
    cout << "Menu\n";
    cout << "=  =  =  =  =  =  =  = "
         << " =  =  =  =  = \n";
    cout << "1.Elite\n2.Mac\n3"
         << "Westside\n";
    cout << "=  =  =  =  =  =  =  = "
         << " =  =  =  =  = \n";
}

void showmacMenu()
{
    cout << "- - - - - - - - - - -"
         << " - -\nItem       Cost\n";
    cout << "1.eyeshadow  Rs.1500/-\n";
    cout << "2.lipstick    Rs.750/-\n";
    cout << "3.blush    Rs.1200/-\n";
    cout << "- - - - - - - - - - - - -\n";
}

void showeliteMenu()
{
    cout << "- - - - - - - - - - -"
         << " - -\nItem       Cost\n";
    cout << "1.milk  Rs.100/-\n";
    cout << "2.eggs       Rs.40/-\n";
    cout << "3.fruits   Rs.350/-\n";
    cout << "- - - - - - - - - - - - -\n";
}

void showwestsideMenu()
{
    cout << "- - - - - - - - - - "
         << " - -\nItem       Cost\n";
    cout << "1.Top        Rs.1,000/-\n";
    cout << "2.pants      Rs.3,000/-\n";
    cout << "3.dress     Rs.4,000/-\n";
    cout << "4.skirt   Rs.1,500/-\n";
    cout << "- - - - - - - - - - - - -\n";
}

// Function to display the grocery category
void selectedgroceries()
{
    cout << "Do you wish to continue?(for yes press (Y/y ), if no press other letter ): ";
    cin >> c1;

    if (c1 == 'Y' || c1 == 'y') {
        cout << "Enter respective number: ";
        cin >> selectedNum;

        if (selectedNum == 1
            || selectedNum == 2
            || selectedNum == 3) {

            // Selected milk
            if (selectedNum == 1) {

                cout << "selected milk\n";
                do {
                    cout << "Quantity: ";

                    cin >> quantity;

                    cout << "You have selected milk - "
                         << quantity << endl;
                    cout << "Are you sure?"
                         << "(for yes press (Y/y ), "
                         << " if no press other letter): ";

                    cin >> confirm_quantity;

                } while ((confirm_quantity != 'y'
                          && confirm_quantity != 'Y')
                         || (quantity < 0)
                         || (ceil(quantity) != floor(quantity)));

                if (confirm_quantity == 'y'
                    || confirm_quantity == 'Y') {
                    total_amount += quantity
                                    * items["milk"];
                    selected_items["milk"] = quantity;
                    cout << "amount  =  "
                         << total_amount << endl;
                }
            }

            // Selected egg
            if (selectedNum == 2) {

                cout << "selected eggs\n";

                do {
                    cout << "Quantity: ";
                    cin >> quantity;
                    cout << "You have selected eggs - "
                         << quantity << endl;
                    cout << "Are you sure? for yes press (Y/y ), if no press other letter ): ";
                    cin >> confirm_quantity;
                } while ((confirm_quantity != 'y'
                          && confirm_quantity != 'Y')
                         || (quantity < 0)
                         || (ceil(quantity)
                             != floor(quantity)));

                if (confirm_quantity == 'y'
                    || confirm_quantity == 'Y') {

                    total_amount += quantity
                                    * items["eggs"];
                    selected_items["eggs"] = quantity;
                    cout << "amount  =  "
                         << total_amount << endl;
                }
            }

            // Selected fruits
            if (selectedNum == 3) {

                cout << "You have selected fruits\n";

                do {
                    cout << "Quantity: ";
                    cin >> quantity;
                    cout << "You have selected"
                         << " fruits - "
                         << quantity
                         << endl;
                    cout << "Are you sure?"
                         << "(for yes press (Y/y )"
                         << ", if no press other letter ): ";
                    cin >> confirm_quantity;
                } while ((confirm_quantity != 'y'
                          && confirm_quantity != 'Y')
                         || (quantity < 0)
                         || (ceil(quantity)
                             != floor(quantity)));

                if (confirm_quantity == 'y'
                    || confirm_quantity == 'Y') {
                    total_amount += quantity
                                    * items["fruits"];
                    selected_items["fruits"] = quantity;
                    cout << "amount  =  "
                         << total_amount
                         << endl;
                }
            }
        }
        else {
            flag = 1;
        }
    }
    else {
        flag = 1;
    }
}

// If makeup category is selected
void selectedmakeup()
{
    cout << "Do you wish to continue?"
         << "(for yes press (Y/y ), "
         << "if no press other letter): ";
    cin >> c1;
    if (c1 == 'Y' || c1 == 'y') {

        cout << "Enter respective number: ";
        cin >> selectedNum;

        if (selectedNum == 1
            || selectedNum == 2
            || selectedNum == 3) {

            // selected eyeshadow
            if (selectedNum == 1) {
                cout << "selected eyeshadow\n";
                do {

                    cout << "Quantity: ";
                    cin >> quantity;

                    cout << "You have selected"
                         << " eyeshadow - "
                         << quantity << endl;
                    cout << "Are you sure?"
                         << "(for yes press (Y/y ), "
                         << " if no press other letter ): ";
                    cin >> confirm_quantity;
                } while ((confirm_quantity != 'y'
                          && confirm_quantity != 'Y')
                         || (quantity < 0)
                         || (ceil(quantity)
                             != floor(quantity)));

                if (confirm_quantity == 'y'
                    || confirm_quantity == 'Y') {
                    total_amount += quantity
                                    * items["eyeshadow"];
                    selected_items["eyeshadow"] = quantity;
                    cout << "amount  =  "
                         << total_amount
                         << endl;
                }
            }

            // selected lipstick
            if (selectedNum == 2) {
                cout << "selected lipstick\n";
                do {
                    cout << "Quantity: ";
                    cin >> quantity;
                    cout << "You have selected"
                         << " lipstick - "
                         << quantity << endl;
                    cout << "Are you sure?"
                         << "(for yes press (Y/y ), "
                         << " if no press other letter ): ";
                    cin >> confirm_quantity;
                } while ((confirm_quantity
                              != 'y'
                          && confirm_quantity != 'Y')
                         || (quantity < 0)
                         || (ceil(quantity)
                             != floor(quantity)));

                if (confirm_quantity == 'y'
                    || confirm_quantity == 'Y') {
                    total_amount += quantity
                                    * items["lipstick"];
                    selected_items["lipstick"] = quantity;
                    cout << "amount  =  "
                         << total_amount
                         << endl;
                }
            }

            // selected blush
            if (selectedNum == 3) {
                cout << "selected blush\n";
                do {

                    cout << "Quantity: ";
                    cin >> quantity;

                    cout << "You have selected"
                            " blush - "
                         << quantity << endl;
                    cout << "Are you sure?"
                         << "(for yes press (Y/y ), "
                         << "if no press other letter ): ";
                    cin >> confirm_quantity;
                } while ((confirm_quantity != 'y'
                          && confirm_quantity != 'Y')
                         || (quantity < 0)
                         || (ceil(quantity)
                             != floor(quantity)));

                if (confirm_quantity == 'y'
                    || confirm_quantity == 'Y') {
                    total_amount += quantity
                                    * items["blush"];
                    selected_items["blush"] = quantity;
                    cout << "amount  =  "
                         << total_amount
                         << endl;
                }
            }
        }
        else {
            flag = 1;
        }
    }
    else {
        flag = 1;
    }
}

void selectedclothes()
{
    cout << "Do you wish to continue?"
         << "(for yes press (Y/y ), "
         << " if no press other letter ): ";
    cin >> c1;
    if (c1 == 'Y' || c1 == 'y') {
        cout << "Enter the respective number: ";
        cin >> selectedNum;
        if (selectedNum == 1
            || selectedNum == 2
            || selectedNum == 3
            || selectedNum == 4) {

            // selected top
            if (selectedNum == 1) {
                cout << "selected top"
                     << " course\n";
                total_amount += items["top"];
                selected_items["top"]++;
                cout << "amount  =  "
                     << total_amount
                     << endl;
            }

            // selected pants
            if (selectedNum == 2) {
                cout << "selected pants\n";
                total_amount += items["pants"];
                selected_items["pants"]++;
                cout << "amount  =  " << total_amount << endl;
            }

            // selected dress
            if (selectedNum == 3) {
                cout << "selected dress\n";
                total_amount += items["dress"];
                selected_items["dress"]++;
                cout << "amount  =  " << total_amount << endl;
            }

            // selected skirt
            if (selectedNum == 4) {
                cout << "selected skirt\n";
                total_amount += items["skirt"];
                selected_items["skirt"]++;
                cout << "amount  =  "
                     << total_amount
                     << endl;
            }
        }
        else {
            flag = 1;
        }
    }
    else {
        flag = 1;
    }
}

// Driver code
int main()
{
    // function call
    customerDetails();
    cout<<"Welcome to the mall"<<endl;
    do {
        showMenu();
        cout << "Do you wish to continue?"
             << "(for yes press (Y/y ), "
             << " if no press other letter ): ";
        char c;
        cin >> c;
        if (c == 'Y' || c == 'y') {
            cout << "Enter respective number: ";
            int num;
            cin >> num;
            if (num == 1 || num == 2
                || num == 3) {
                switch (num) {
                case 1:

                    // For groceries
                    showeliteMenu();
                    selectedgroceries();
                    break;

                case 2:

                    // For makeup
                    showmacMenu();
                    selectedmakeup();
                    break;

                case 3:

                    showwestsideMenu();
                    selectedclothes();
                    break;
                }
            }
            else {
                flag = 1;
            }
        }
        else {
            flag = 1;
        }

    } while (flag == 0);

    // print bill
    printBill(items, selected_items,
              total_amount);
}
