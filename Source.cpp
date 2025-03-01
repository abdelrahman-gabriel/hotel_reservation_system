#include<iostream>
#include"functions.h"
#include"arrayListType.h"
#include"hotel_assets.h"

using namespace std;

int main()
{
	//room initalization
	room R1(1, "suite", "vacant", 4.5);
	room R2(2, "suite", "vacant", 5);
	room R3(3, "single", "occupied", 3.8);
	room R4(4, "double", "vacant", 4.2);
	room R5(5, "single", "occupied", 4.4);
	rooms.insert(R1);
	rooms.insert(R2);
	rooms.insert(R3);
	rooms.insert(R4);
	rooms.insert(R5);

	//reservation initalization
	reservation r1(1, "3 days", "Walter", 1,"Great stay!",1115,229866);
    reservation r2(2, "1 days", "Arthur", 2, "Horrble service.", 3123, 229876);
    reservation r3(3, "5 days", "Yelda", 3, "Terrible experience!", 6510, 329208);
	reservation r4(4, "2 days", "Thomas", 4, "Not Bad", 1230,229208);
    reservation r5(5, "3 days", "Edward", 5, "-----", 1560, 129208);

	reservations.insert(r1);
	reservations.insert(r2);
	reservations.insert(r3);
    reservations.insert(r4);
    reservations.insert(r5);

	//guest initialization
    guest g1("Arthur", "01028057010", 229876);
    guest g2("Walter", "01018510750", 229866);
    guest g3("Thomas", "011260417781", 229208);
    guest g4("Yelda", "011260417781", 229208);
    guest g5("Edward", "011260417781", 229208);

	guests.insert(g1);
	guests.insert(g2);
	guests.insert(g3);
    guests.insert(g4);
    guests.insert(g5);

	//functions
    char choice;
    do {
        cout << "\n Menu: \n";
        cout << "a. Update Reservation Period \n";
        cout << "b. Update Room Rating \n";
        cout << "c. Search Rooms by Status \n";
        cout << "d. display reservations and rooms \n";
        cout << "e. display all rooms \n";
        cout << "f. search Room By Type \n";
        cout << "g. show room reservation history \n";
        cout << "h. display all guests \n";
        cout << "i. update room status \n";
        cout << "j. guest Reservation History \n";
        cout << "k. insert Guest \n";
        cout << "l. insert Reservation \n";
        cout << "x. Exit \n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 'a':
        case 'A':
        {
            int resNum;
            string newPeriod;
            cout << "Enter reservation number: ";
            cin >> resNum;
            cout << "Enter new period (days): ";
            cin.ignore();
            getline(cin, newPeriod);
            updateReservationPeriod(reservations, resNum, newPeriod);
            break;
        }
        case 'b':
        case 'B':
        {
            double rating;
            int room;
            cout << "Enter Room Number\n";
            cin >> room;
            cout << "Enter new rating: ";
            cin >> rating;
            updateRoomRating(room, rating);
            break;
        }
        case 'c':
        case 'C':
        {
            string status;
            cout << "Enter room status to search (e.g.: vacant, occupied): ";
            cin >> status;
            searchRoomByStatus(status);
            break;
        }
        case 'd':
        case'D':
        {
            displayallRoomsAndReservations();
        }
        case'e':
        case 'E':
        {
            displayAllRooms();
            break;
        }
        case'f':
        case 'F':{
            searchRoomByType();
            break;
        }
        case'g':
        case'G':
        {
            ReservationRoomhistory();
            break;
        }
        case'h':
        case'H':
        {
            displayallguests();
            break;
        }
        case'i':
        case'I':
        {
            updateroomstatus();
            break;
        }
        case'j':
        case'J':
        {
            guestReservationHistory();
            break;
        }
        case'k':
        case'K':
        {
            insertGuest(guests);
            break;
        }
        case'l':
        case'L':
        {
            insertReservation(reservations);
            break;
        }
        case 'x':
        case'X':
        {
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    } while (choice != 'x');
	
	return 0;
}