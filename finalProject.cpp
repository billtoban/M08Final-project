#include <iostream>
#include <string>

using namespace std;

enum MenuItem {
    Veggie_Burger = 35,
    Hamburger = 45,
    Fried_Chicken_Sliders = 38,
    Hamburger_Sliders = 38,
    Veggie_Sliders = 38,
    Haddock_Sandwich = 38,
    BLT = 42,
    Faux_BLT = 42,
    Chicken_Burrito = 42,
    Falafel_Wrap = 42,
    Cheese_Pizza = 59,
    Pepperoni_Pizza = 59,
    Faux_meat_and_chips = 77,
    Fish_and_chips = 77
};

struct Reservation {
    string time;
    string firstName; 
    string lastName;
    int reservationSize;
    bool checkedIn = false;
};

struct Table {
    int tableNumber;
    int tableSize;
    int numberOfPeople;
    bool isOccupied = false;
};

struct Order {
    Reservation reservation;
    Table table;
    MenuItem items[10];
    int numItems;
    bool isComplete = false;
    bool isPaid = false;
};

Reservation reservations[50];
Table tables[20];
Order orders[50];
Order items[10];

int numReservations = 0;
const int numTables = 20;
int numOrders = 0;

void welcomeMessage() {
    cout << "\nWelcome to MessiJoes!\n"
        << "1. Make Reservation\n"
        << "2. Check-in reservation\n"
        << "3. Enter Order\n" 
        << "4. Complete Order\n"
        << "5. Calculate and Pay Bill\n"
        << "6. Close the Restaurant. \n";
}

void createReservation() {
    if (numReservations >= 50) {
        cout << "You are at the maximum reservation!" << endl;
    }
    cout << "Enter a name for the reservation: ";
    cin >> reservations[numReservations].firstName >> reservations[numReservations].lastName; 
    cout << "Enter the number of people in the party: ";
    cin >> reservations[numReservations].reservationSize;
    cout << "Enter the time for the reservation: ";
    cin >> reservations[numReservations].time;
    reservations[numReservations].checkedIn = false;
    numReservations++;
}

void checkInReservation() {
    cout << "Reservations waiting to be checked in: \n";
    for (int i = 0; i < numReservations; i++) {
        cout << i + 1 << ". " << reservations[i].firstName << " "
            << reservations[i].lastName << " "
            << reservations[i].time << " "
            << reservations[i].reservationSize << " people.\n"; 
    }
}

void confirmReservation() {
    int num = 0;
    char selection = ' ';
    do {
        cout << "Please confirm the reservation: "
            << "\nReservation Name: " << reservations[numReservations - 1].firstName << " " 
            << reservations[numReservations - 1].lastName
            << "\nReservation time: " << reservations[numReservations - 1].time << " " 
            << "\nNumber in party: " << reservations[numReservations - 1].reservationSize; 
        cout << "\nIs this information correct [Y]es, [N]o (make change), or [C]ancel? "; 
        cin >> selection;
        if (selection == 'N') {
            cout << "What do you want to change?"
                << "\n1. Name"
                << "\n2. Number of People"
                << "\n3. Time"
                << "\n4. Cancel\n";
            cin >> num;
            switch (num) {
                case 1:
                    cout << "Enter a name for the Reservation: ";
                    cin >> reservations[numReservations - 1].firstName >> reservations[numReservations - 1].lastName; 
                    break;
                case 2:
                    cout << "Enter the number of people in the party: ";
                    cin >> reservations[numReservations - 1].reservationSize; 
                    break;
                case 3:
                    cout << "Enter a time for the Reservation: ";
                    cin >> reservations[numReservations - 1].time; 
                    break;
                default:
                    break;
            }
        }
    } while (selection != 'Y');
}

void something()
{
    if (numReservations > 0)
    {
        cout << "Select the reservation you would like in:\n";
        for (int i = 0; i < numReservations; i++)
        {
            if (!reservation[i].checkedIn)
            {
                cout << i + 1 << ". "
                    << reservation[i].firstName << " "
                    << reservation[i].lastName << " - "
                    << reservation[i].time << " "
                    << reservation[i].reservations << " "
            }
        }
    }
}

int main()
{
    int i;
    int num = 0;

    for (int i = 0; i < numTables; i++)
    {
        if (i < 8)
        {
            tables[i] = {i + 1, 2, 0,  true};
        }
        else if (i < 14)
        {
            tables[i] = {i + 1, 4, 0,  true};
        }
        else if (i < 18)
        {
            tables[i] = {i + 1, 6, 0,  true};
        }
        else 
        {
            tables[i] = {i + 1, 10, 0,  true};
        }
    }
    
    int response = 0;
    char selection = ' ';
    int j = 1;
    string suffix;

    do
    {
        welcomeMessage();
        cin >> response;

        switch (response)
        {
            case 1:
                createReservation();
                confirmReservation();
                break;
            case 2:
                checkInReservation();
                int choice;
                int tableSelector;
                cout << "Select the number next to your reservation:\n";
                cin >> choice;
                if (choice >= 1 && choice <= numReservations)
                {
                    Reservation& chosenReservation = reservations[choice - 1];
                    chosenReservation.checkedIn = true;
                    cout << "\nReservation checked in successfully.\n"
                        << "Assigned to table: \n";
                    for (int i = 0; i < numTables; i++)
                    {
                        if (!tables[i].isOccupied && tables[i].tableSize >= chosenReservation.reservationSize)
                        {
                            cout << i + 1 << ". " << tables[i].tableSize << " people.\n";
                        }
                    }
                    cout << "\nPlease assign this reservation to a table:\n";
                    cin >> tableSelector;
                    Table& selectedTable = tables[tableSelector - 1];
                    selectedTable.isOccupied = true;
                    selectedTable.numberOfPeople = chosenReservation.reservationSize;
                }
                else 
                {
                    cout << "Invalid choice.";
                }
                break;
        }
    } while (response != 6); // Add semicolon here

    return 0;
}