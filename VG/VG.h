#pragma once

#include <iostream>

#include <string>

using namespace std;

class VG

{

private:

	long GID; // Universal Product Code

	string name;

	string System;

	double price;

public:

	VG(void);

	~VG(void);

	long getgid() const;

	string getname() const;

	string getsystem() const;

	double getprice() const;

	void setgid(long id);

	void setname(string n);

	void setsystem(string c);

	void setprice(double p);

	friend bool operator<(const VG & a, const VG & b);

	friend bool operator>(const VG & a, const VG & b);

	friend bool operator==(const VG & a, const VG & b);

	friend ostream & operator<<(ostream & out, const VG & v);

	friend istream & operator>>(istream & in, VG & v);

};





