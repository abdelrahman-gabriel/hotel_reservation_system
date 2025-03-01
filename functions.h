#pragma once
#include<iostream>
#include "hotel_assets.h"
#include "arrayListType.h"
#include "orderedLinkedList.h"
using namespace std;
arrayListType<room> rooms(40);
orderedLinkedList<guest> guests;
orderedLinkedList<reservation> reservations;
//displaying all reservations
void displayallRoomsAndReservations()
{
    reservations.print();
}
//displaying all rooms

void displayAllRooms()
{
	rooms.print();
}
//searching room by type
void searchRoomByType()
{
	string roomtype;
	room t;
	cout << "input room type\n";
	while(1){
		cin >> roomtype;
		if (roomtype != "suite" && roomtype != "double" && roomtype != "single")
		{
			cout << "room type is not valid plese input a valid roomtype\n";
		}
		else
			break;
	}
	for (int i = 0; i < rooms.listSize(); i++)
	{
		rooms.retrieveAt(i, t);
		if (t.type == roomtype)
			cout << t << endl;
	}
}
//show room reservation history
void ReservationRoomhistory()
{
    int  roomNumber;
    cout << "enter the room number you want to view it's reservation history \n";
    cin >> roomNumber;
    reservation temp;
    temp.reservation_no = 0;
    reservation finder = searchReservationByRoomNumber(reservations, roomNumber);
    if (finder == temp)
        cout << "the room is not found";
    else
        cout << finder;
}


// display all guests

void displayallguests()
{
   
    guests.print();
}

// update room status
void updateroomstatus()
{
    int room_num;
    string stat;
    cout << "enter the number of the room you want to update: \n ";
    cin >> room_num;
    cout << "enter room new status: (vacant or occupied) \n ";
    cin >> stat;

    int index = -1;
    for (int i = 0; i < rooms.listSize(); ++i) {
        room roomneeded;
        rooms.retrieveAt(i, roomneeded);
        if (roomneeded.room_no == room_num) {
            index = i;
            break;
        }
    }
    if (stat == "vacant" || stat == "occupied") {
        if (index != -1) {
            room roomToUpdate;
            rooms.retrieveAt(index, roomToUpdate);
            if (roomToUpdate.status == stat)
                cout << "room is already " << stat << endl;
            else
            {
                roomToUpdate.status = stat;
                rooms.replaceAt(index, roomToUpdate);
                cout << "Room status updated successfully." << endl;
                cout << "room # " << room_num << " is now " << stat << endl;
            }
        }
        else {
            cout << "Room not found." << endl;
        }
    }
    else
        cout << "invalid status try again " << endl;
}
// show guest  reservation history
void guestReservationHistory()
{
    string name;
    int id;
    
    cout << "Enter guest's name: " << endl;
    cin >> name;
    cout << "Enter guest's ID: " << endl;
    cin >> id;

    cout << "Reservation history for guest: " << name << " ID: " << id << endl;

    bool found = false;
    found = searchReservationByid(reservations, id);
    if (found == false)
    {
        cout << "there is no reservation for this guest " << endl;
    }
    
}

//update reservation period
void updateReservationPeriod(orderedLinkedList<reservation>& reservations, int reservationNumber, const string& newPeriod)
{
    nodeType<reservation>* current = reservations.first;

    while (current != nullptr)
    {
        if (current->info.reservation_no == reservationNumber)
        {
            current->info.updatePeriod(newPeriod);
            cout << "Reservation period updated successfully.\n";
            return;
        }
        current = current->link;
    }

    cout << "Reservation not found. Unable to update period.\n";
}
//update searching room by status
void searchRoomByStatus(const string& roomStatus)
{
    cout << "Searching for rooms with status: " << roomStatus << endl;

    bool found = false; 

    for (int i = 0; i < rooms.listSize(); i++)
    {
        room tempRoom;
        rooms.retrieveAt(i, tempRoom);

        if (tempRoom.status == roomStatus)
        {
            cout << "Room found:\n";
            cout << tempRoom;
            found = true; 
        }
    }

    if (!found)
    {
        cout << "No rooms with status '" << roomStatus << "' found.\n";
    }
}

//updating the room rating
void updateRoomRating(int roomNumber, double newRating)
{
    room temp;
    temp.room_no = roomNumber;

    // Search for the room in the rooms arrayList
    int index = rooms.seqSearch(temp);

    if (index != -1)
    {
        rooms.retrieveAt(index, temp);
        if (newRating >= 1.0 && newRating <= 5.0) { 
            temp.updateRating(newRating);
            rooms.replaceAt(index, temp);
            cout << "Room rating updated successfully.\n";
        }
        else {
            cout << "Error: Invalid rating. Rating must be between 1 and 5.\n";
        }
    }
    else
    {
        cout << "Room not found. Unable to update rating.\n";
    }
}

//insert guest
void insertGuest(orderedLinkedList<guest>& guestList) {
    string name, phone_no;
    int ID;

    cout << "Enter guest name: ";
    cin >> name;
    cout << "Enter guest phone number: ";
    cin >> phone_no;
    cout << "Enter guest ID: ";
    cin >> ID;

    guest newGuest(name, phone_no, ID);


    if (guestList.search(newGuest)) {
        cout << "Guest with ID " << ID << " already exists in the system." << endl;
    }
    else {
        guestList.insert(newGuest);
        cout << "Guest " << name << " has been inserted into the system." << endl;
    }
}
//insert reservation
void insertReservation(orderedLinkedList<reservation>& reservationList) {
    int reservation_no;
    string period;
    string guest_name;
    int room_no;
    string review;
    int price;
    int id;

    cout << "Enter reservation number: ";
    cin >> reservation_no;
    cout << "Enter period: ";
    cin >> period;
    cout << "Enter guest name: ";
    cin >> guest_name;
    cout << "Enter room number: ";
    cin >> room_no;
    cout << "Enter price: ";
    cin >> price;
    cout << "enter guest id: ";
    cin >> id;

    if (review == "none") {
        review = "No review yet";
    }

    reservation newReservation(reservation_no, period, guest_name, room_no, review, price,id);

    if (reservationList.search(newReservation)) {
        cout << "Reservation with number " << reservation_no << " already exists." << endl;
    }
    else {
        reservationList.insert(newReservation);
        cout << "Reservation has been successfully added." << endl;
    }
}
