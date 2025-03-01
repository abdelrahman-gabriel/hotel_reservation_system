#pragma once
#include<iostream>
using namespace std;
struct guest
{
	string name;
	string phone_no;
	int ID;
	guest();	
	guest(string n, string p, int i);
	bool operator==(const guest&);
	friend  ostream& operator <<(ostream&, guest&);
	inline bool operator>=(const guest& rhs) { return ID>=rhs.ID; }
};

guest::guest() 
{
	name = "empty";
	phone_no = "0";
	ID = 0;
}

guest::guest(string n,string p, int i)
{
	name = n;
	phone_no = p;
	ID = i;
}

ostream& operator <<(ostream& cout, guest& output) {

	cout << "ID: " << output.ID << '\n';
	cout << "Name: " << output.name << '\n';
	cout << "Phone number " << output.phone_no << '\n';

	return cout;
}

bool guest::operator== (const guest& otherguest)
{
	if (ID == otherguest.ID)
		return true;
	else
		return false;
}


struct room
{
	int room_no;
	string type;
	string status;
	double rating;
	room();
	void updateRating(double newRating);
	room(int r1, string t, string s, double r2);
	bool operator==(const room&);
	friend  ostream& operator <<(ostream&, room&);

};

room::room()
{
	room_no = 0;
	type = "empty";
	status = "empty";
	rating = 0.0;
}

room::room(int r1, string t, string s, double r2)
{
	room_no = r1;
	type = t;
	status = s;
	rating = r2;

}
void room::updateRating(double newRating)
{
	rating = newRating;
}
ostream& operator <<(ostream& cout, room& output) {

	cout << "Room number:" << output.room_no << '\n';
	cout << "Type:" << output.type << '\n';
	cout << "Status:" << output.status << '\n';
	cout << "Rating:" << output.rating << '\n';
	return cout;
}

bool room::operator== (const room& otherguest)
{
	if (room_no == otherguest.room_no)
		return true;
	else
		return false;
}

struct reservation
{
	int reservation_no;
	string period;
	string guest_name;
	int room_no;
	string review;
	int price;
	int id;
	reservation();
	reservation(int r2, string p, string g, int r1, string r3, int p2, int ID);
	bool operator==(const reservation&);
	void updatePeriod(const string& newPeriod);
	friend  ostream& operator <<(ostream&, reservation&);
	inline bool operator>=(const reservation& rhs) { return reservation_no >= rhs.reservation_no; }

};

reservation::reservation()
{
	reservation_no = 0;
	period = "empty";
	guest_name = "empty";
	room_no = 0;
	review = "empty";
	price = 0;
	id = 0;
	
}

reservation::reservation(int r2, string p, string g, int r1, string r3, int p2,int ID )
{
	reservation_no = r2;
	period = p;
	guest_name = g;
	room_no = r1;
	review = r3;
	price = p2;
	id = ID;
	
}
void reservation::updatePeriod(const string& newPeriod)
{
	period = newPeriod;
}
ostream& operator <<(ostream& cout, reservation& output)
{
	cout << "Reservation number:" << output.room_no << '\n';
	cout << "Period:" << output.period << '\n';
	cout << "Guest name:" << output.guest_name << '\n';
	cout << "Room number:" << output.room_no << '\n';
	cout << "Review:" << output.review << '\n';
	cout << "Price:" << output.price << '\n';
	cout << "ID:" << output.id << '\n';
	return cout;
}

bool reservation::operator== (const reservation& otherguest)
{
	if (reservation_no == otherguest.reservation_no)
		return true;
	else
		return false;
}
