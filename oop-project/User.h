#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
using namespace std;

class User
{
private:
	string id, name, date, section, address;
	int borrownum;
	vector<string> itemList;

protected:
	int borrowlimit;

	string getUser() const;
	
	virtual void setItemLimit() = 0;


public:
	string getId() const;
	string getName() const;
	string getSection() const;
	string getDob() const;
	string getAddress() const;

	virtual string getInfo() const = 0;

	bool borrowItem(string itemId);
	bool returnItem(string itemId);
	bool canLoan();
	bool isAllow();		// user's privilege for borrowing item again

	User(string id, string name, string date, string section, string address);
	virtual ~User();
};

class Scout : public User
{
private:
	string rank;
	void setItemLimit();

public:
	string getRank();
	string getInfo() const;
	
	Scout(string id, string name, string date, string section, string address, string rank);
};

class VentureScout : public User
{
private:
	void setItemLimit();

public:
	string getInfo() const;

	VentureScout(string id, string name, string date, string section, string address);
};

class RoverScout : public User
{
private:
	void setItemLimit();

public:
	string getInfo() const;

	RoverScout(string id, string name, string date, string section, string address);
};

class Scouter :public User
{
private:
	string rank;
	void setItemLimit();
	
public:
	string getRank();
	string getInfo() const;

	Scouter(string id, string name, string date, string section, string address, string rank);
};

#endif