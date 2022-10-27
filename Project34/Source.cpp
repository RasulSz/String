#include <iostream>
using namespace std;

//class User :
//	string username;
//string password;
//
//class Database :
//	User * users;
//
//bool SignIn(User& user)  Method
//bool SignUp(User& user)  Method in DataBase


class User {
	string username;
	string password;
public:

	User() {
		SetUsername("");
		SetPass("");
	}

	User(string user, string pass) {
		SetUsername(user);
		SetPass(pass);
	}

	User(const User& other) {
		SetUsername(other.username);
		SetPass(other.password);
		this;
	}

#pragma region SetGet

	void SetUsername(string username) {
		this->username = username;
	}

	void SetPass(string password) {
		this->password = password;
	}

	string GetUsername() const{
		return this->username;
	}

	string GetPassword() const {
		return this->password;
	}

#pragma endregion

	friend ostream& operator<<(ostream& out, const User& obj) {
		out << "================================" << endl;
		out << "User Information" << endl;
		out << "Username : " << obj.username << endl;
		out << "Password : " << obj.password << endl;

		return out;
	}

	friend istream& operator>>(istream& in, User& obj) {

		cout << "Enter Username : " << endl;
		string buffer = { 100 };
		in >> buffer;
		obj.SetUsername(buffer);

		cout << "Enter Password : " << endl;
		buffer = { 100 };
		in >> buffer;
		obj.SetPass(buffer);

		return in;
	}
	bool operator==(const User& user) {
		return username == user.username && password == user.password;
	}

};


istream& operator>>(istream& in, User& obj);
ostream& operator<<(ostream& out, const User& obj);


class DataBase {
	bool FindByUsername(string username) {
		for (size_t i = 0; i < size; i++)
		{
			if (users[i].GetUsername() == username)
				return true;
		}
		return false;
	}
public:
	User* users = nullptr;
	int size = 0;
	
	bool SignUp(const User& user) {
		if (!FindByUsername(user.GetUsername()))
			return false;
		User* temp = new User[size + 1];

		for (size_t i = 0; i < size; i++)
		{
			temp[i] = users[i];
		}
		temp[size] = user;
		delete[]users;
		users = temp;
		size++;
		temp = nullptr;

	}
	bool SignIn(const User& user) {
		for (size_t i = 0; i < size; i++)
		{
			if (users[i] == user)
				return true;
		}
		return false;
	}
};

void main() {



	
}