#include "VG.h"


VG::VG(void)
{





	GID = 1000001;


	name = "Game";


	System = "PC";


	price = 59.95;







}
VG::~VG(void)
{

}
long VG::getgid() const
{





	return GID;







}
string VG::getname() const
{





	return name;







}
string VG::getsystem() const
{





	return System;







}
double VG::getprice() const
{





	return price;







}
void VG::setgid(long id)
{





	GID = id;







}
void VG::setname(string n)
{





	name = n;







}
void VG::setsystem(string c)
{





	System = c;







}
void VG::setprice(double p)
{





	if (p > 0)


		price = p;







}
bool operator<(const VG & a, const VG & b)
{





	if (a.System < b.System)


		return true;


	else


		return false;







}
bool operator>(const VG & a, const VG & b)
{





	if (a.price > b.price)


		return true;


	else


		return false;







}
bool operator==(const VG & a, const VG & b)
{
		if ((a.GID == b.GID) &&


		(a.name == b.name) &&


		(a.price == b.price) &&


		(a.System == b.System))


		return true;


	else


		return false;







}
ostream & operator<<(ostream & out, const VG & v)
{





	cout << "GID: ";


	out << v.GID << endl;


	cout << "name: ";


	out << v.name << endl;


	cout << "System: ";


	out << v.System << endl;


	cout << "price: $ ";


	out << v.price << endl;


	return out;







}
istream & operator>>(istream & in, VG & v)
{





	cout << "GID: ";


	in >> v.GID;


	in.ignore();


	cout << "name: ";


	getline(in, v.name);


	cout << "console: ";


	getline(in, v.System);


	cout << "price: $ ";


	in >> v.price;


	return in;






}