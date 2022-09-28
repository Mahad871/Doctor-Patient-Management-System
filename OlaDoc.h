//#pragma once
#pragma once
//#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

int mainmenu();
bool passwordChecker(string pass) {

	bool isValid = false, l = isValid, sp = isValid, nm = isValid, uc = isValid, lc = isValid;
	int index = -1;

	//////////////////LENGHTH CHECK
	if (pass.length() >= 8)
		isValid = true;
	l = isValid;
	//////////////////SPECIAL CHARACTERS CHECK
	isValid = false;

	for (int i = 32; i <= 47; i++) {
		index = pass.find(i);
		if (index != -1) {
			isValid = true;
			break;
		}
		else
			isValid = false;

	}
	for (int i = 58; i <= 64 && isValid == false; i++) {
		index = pass.find(i);
		if (index != -1) {
			isValid = true;
			break;
		}
		else
			isValid = false;

	}
	for (int i = 91; i <= 96 && isValid == false; i++) {
		index = pass.find(i);
		if (index != -1) {
			isValid = true;
			break;
		}
		else
			isValid = false;

	}
	for (int i = 123; i <= 126 && isValid == false; i++) {
		index = pass.find(i);
		if (index != -1) {
			isValid = true;
			break;
		}
		else
			isValid = false;

	}
	sp = isValid;
	//////////////////NUMBERS CHECK
	isValid = false;
	index = -1;
	for (int i = 48; i <= 57; i++) {
		index = pass.find(i);
		if (index != -1) {
			isValid = true;
			break;
		}
		else
			isValid = false;

	}
	nm = isValid;
	//////////////////upper_case check
	index = -1;
	isValid = false;
	if (isValid == true || 1) {
		for (int i = 65; i <= 90; i++) {
			index = pass.find(i);
			if (index != -1) {
				isValid = true;
				break;
			}
			else
				isValid = false;

		}
	}
	uc = isValid;
	//////////////////lower_case check
	index = -1;
	isValid = false;
	if (isValid == true || 1) {
		for (int i = 97; i <= 122; i++) {
			index = pass.find(i);
			if (index != -1) {
				isValid = true;
				break;
			}
			else
				isValid = false;

		}
	}
	lc = isValid;

	if (l == 1 && sp == 1 && nm == 1 && uc == 1 && lc == 1)
		return true;
	else
		return false;

}

class Feedback
{
private:

	int Stars = -1;
	char Review[1000];

public:

	void set(int rate, string review) {

		Stars = rate;
		strcpy_s(Review, review.c_str());
	}
	void setReview(string review) {

		strcpy_s(Review, review.c_str());


	}
	int getStars() { return Stars; }

	void FeedbackMenu() {

		string review;

		cout << "\n\nPlease Give Your Feedback\n\n";
	again:
		cout << "\nRate Appointmnet out of 5: ";
		cin >> Stars;
		if (Stars > 5 && Stars < 0) {
			cout << "\nINVALID INPUT !!!  TRY AGAIN :)\n";
			goto again;
		}


		cout << "\nPlease Give your review: ";
		cin >> review;
		setReview(review);

		cout << "\n\nThank You for Your Precious Feedback\n\n";


	}
};


class Payments
{
private:

	float PayPakBalance = 0;
	float UnionPayBalance = 0;
	float JazzCashBalance = 0;
	float EasypaisaBalance = 0;

	int accnum;


public:
	void setBalanceDefault() {

		setPayPakBalance(3500);
		setUnionPayBalance(3500);
		setJazzCashBalance(3500);
		setEasypaisaBalance(3500);
	}
	void setPayPakBalance(float amount) { PayPakBalance = amount; };
	void setUnionPayBalance(float amount) { UnionPayBalance = amount; };
	void setJazzCashBalance(float amount) { JazzCashBalance = amount; };
	void setEasypaisaBalance(float amount) { EasypaisaBalance = amount; };

	float getPayPakBalance() { return PayPakBalance; };
	float getUnionPayBalance() { return UnionPayBalance; };
	float getJazzCashBalance() { return JazzCashBalance; };
	float getEasypaisaBalance() { return EasypaisaBalance; };
	int getAccountNum() { return accnum; }
	void SetAccountNum(int n) { accnum = n; }

	void addPayPakBalance(float amount) { PayPakBalance += amount; }
	void subPayPakBalance(float amount) { PayPakBalance -= amount; }
	void addUnionPayBalance(float amount) { UnionPayBalance += amount; }
	void subUnionPayBalance(float amount) { UnionPayBalance -= amount; }
	void addJazzCashBalance(float amount) { JazzCashBalance += amount; }
	void subJazzCashBalance(float amount) { JazzCashBalance -= amount; }
	void addEasypaisaBalance(float amount) { EasypaisaBalance += amount; }
	void subEasypaisaBalance(float amount) { EasypaisaBalance -= amount; }


	void rechargeMenu() {

		int choice = 0;
		cout << "\n\nACCOUNT RECHARGE MENU\n\n";



		cout << "\n1. Recharge Bank account\n2. Recharge Online Account\n";
		cin >> choice;

		if (choice == 1) {
			RechargeBankAccount();
		}
		else if (choice == 2) {
			RechargeOnlineAccount();
		}


	}

	int TransferFrom(int accnum, float amount) {


		if (accnum == 1) {

			subPayPakBalance(amount);
		}
		else if (accnum == 2) {

			subUnionPayBalance(amount);

		}
		else if (accnum == 3) {

			subJazzCashBalance(amount);

		}
		else if (accnum == 4) {

			subEasypaisaBalance(amount);

		}

		return accnum;

	}

	float compare() {


		int choice = 0;

		float amount;
		cout << "\n\nHOW WOULD YOU LIKE TO PAY?\n\n";

		cout << "\n1. Bank account\n2. Online Account\n";
		cin >> choice;

		if (choice == 1) {
			cout << "\n1.Pay Pak \n2. Union Pay\n";
			cin >> choice;
			if (choice == 1) {

				//subPayPakBalance(amount);
				accnum = 1;

			}
			else if (choice == 2) {

				//subUnionPayBalance(amount);
				accnum = 2;

			}
		}
		else if (choice == 2) {
			cout << "\n1. Jazz Cash\n2. Easypaisa\n";
			cin >> choice;

			if (choice == 1) {

				//subJazzCashBalance(amount);
				accnum = 3;


			}
			else if (choice == 2) {

				//subEasypaisaBalance(amount);
				accnum = 4;

			}
		}
		float balance = -1;

		if (accnum == 1) {

			balance = getPayPakBalance();
		}
		else if (accnum == 2) {

			balance = getUnionPayBalance();

		}
		else if (accnum == 3) {

			balance = getJazzCashBalance();

		}
		else if (accnum == 4) {

			balance = getEasypaisaBalance();

		}

		cout << "\nBalance: " << balance << endl;
		return balance;

	}

	void TransferTo(int accnum, float amount) {


		if (accnum == 1) {

			addPayPakBalance(amount);
		}
		else if (accnum == 2) {

			addUnionPayBalance(amount);

		}
		else if (accnum == 3) {

			addJazzCashBalance(amount);

		}
		else if (accnum == 4) {

			addEasypaisaBalance(amount);

		}

		//return accnum;
	}

	void RechargeBankAccount() {


		int choice = 0;
		float amount = 0;

		cout << "\n\___________________________________\n\n";

		cout << "\n1.Pay Pak \n2. Union Pay\n";
		cin >> choice;

		if (choice == 1) {
			cout << "\n\nEnter Recharge Amount: ";
			cin >> amount;
			addPayPakBalance(amount);

		}
		else if (choice == 2) {
			cout << "\n\nEnter Recharge Amount: ";
			cin >> amount;
			addUnionPayBalance(amount);
		}


	}

	void RechargeOnlineAccount() {
		int choice = 0;
		float amount = 0;

		cout << "\n\___________________________________\n\n";


		cout << "\n1. Jazz Cash\n2. Easypaisa\n";
		cin >> choice;

		if (choice == 1) {
			cout << "\n\nEnter Recharge Amount: ";
			cin >> amount;
			addJazzCashBalance(amount);

		}
		else if (choice == 2) {
			cout << "\n\nEnter Recharge Amount: ";
			cin >> amount;
			addEasypaisaBalance(amount);
		}

	}

	void ShowAllBalances() {


		cout << "\n\n Pay Pak Balance: " << PayPakBalance << "\nUnion Pay Balance: " << UnionPayBalance << "\nJazzCash Balance: " << JazzCashBalance << "\nEasypaisa Balance: " << EasypaisaBalance << endl;
	}

};



class Date
{
private:

	int day;
	int month;
	int year;

public:

	void set(int day, int month, int year) {

		this->day = day;
		this->month = month;
		this->year = year;

	}

	void menu() {



		int day, month, year;
	reEnterDay:
		cout << "Enter Day: ";
		cin >> day;
		if (day > 31) {
			goto reEnterDay;
		}
	reEnterMonth:
		cout << "Enter Month: ";
		cin >> month;
		if (day > 28 && month == 2) {
			cout << "\nFebruary cannot have more than 28 days:\n";
			goto reEnterMonth;
		}
		else if (day == 31 && month != 1 || day == 31 && month != 3 || day == 31 && month != 5 || day == 31 && month != 7 || day == 31 && month != 8 || day == 31 && month != 10 || day == 31 && month != 12) {
			cout << "\nThis month cannot have 31 Days!    TRY AGAIn :)\n";
			goto reEnterMonth;
		}
		else if (month > 12) {
			cout << "\nMonth Cannot exceed 12 !!!\n";
			goto reEnterMonth;
		}
	reEnterYear:
		cout << "Enter Year: ";
		cin >> year;
		if (!(year > 0)) {
			goto reEnterYear;
		}

		this->day = day;
		this->month = month;
		this->year = year;

	}

	int getnoOfDays(Date date) {

		int noOfDays = 0;

		/*if (this->day < date.day && this->month < date.month && this->year > date.year) {
			cout << "NO of Days cannot be negative: ";
			return -1;
		}*/


		int yd = (date.year - this->year);

		if (yd >= 0 && (((date.year - this->year) * 12) - (date.month - this->month) >= 0)) {

			noOfDays += (date.year - this->year) * 365;
			noOfDays += (date.month - this->month) * 30;
			noOfDays += date.day - this->day;


		}
		else
		{
			cout << "\nDate Error!!!\n";
			return -1;

		}

		return noOfDays;
	}

	bool operator==(Date t) {

		if (this->day == t.day && this->month == t.month && this->year == t.year) {
			return true;
		}
		return false;
	}


	void showDate() {


		cout << "\n" << day << "/" << month << "/" << year << "\n";

	}
};

class Time
{
private:

	int hours, minutes;

public:

	void set(int hour, int min) {


		hours = hour;
		minutes = min;
	}

	void setTime() {

		int hour, min;
	h:
		cout << "Enter Hours (24 hours Standard): ";
		cin >> hour;
		if (hour >= 24 && hour < 0) {
			cout << "\nInvalid Hours Input! TRY AGAIN :)\n";
			goto h;
		}
	m:
		cout << "Enter Minutes: ";
		cin >> min;
		if (min >= 60 && min < 0) {
			cout << "\nInvalid Minutes Input! TRY AGAIN :)\n";
			goto m;
		}

		set(hour, min);

	}

	void addTime(int min) {

		if (minutes + min >= 60) {

			minutes += min;
			hours += minutes / 60;
			minutes -= (minutes / 60) * 60;
		}
		else {
			minutes += min;
		}

	}

	void menu() {


		setTime();
	}

	bool operator==(Time t) {

		if (this->hours == t.hours && this->minutes == t.minutes) {
			return true;
		}
		return false;
	}

	void showTime() {


		cout << "\n" << hours << ":" << minutes << "\n";

	}
};


class Appointment
{
private:

	long long int patientCNIC;
	long long int	doctorCNIC;
	char patientName[50];
	char doctorName[50];
	char specialization[50];
	char Hospital[50];
	char City[50];
	Date appointmentDate;
	Time appointmentTimeFrom;
	Time appointmentTimeto;
	char appoitmentStatus[10];
	float Charges;
	Feedback appointmentFeedback;

public:

	void set(long long int PatCNIC, string PatName, long long int DocCNIC, string DocName, string spec, string hospital, string city, Date AppDate, Time AppTimeFrom, float charge, string AppStatus = "NULL") {


		patientCNIC = PatCNIC;
		strcpy_s(this->patientName, PatName.c_str());
		doctorCNIC = DocCNIC;
		strcpy_s(doctorName, DocName.c_str());
		appointmentDate = AppDate;
		appointmentTimeFrom = AppTimeFrom;
		appointmentTimeto = AppTimeFrom;
		appointmentTimeto.addTime(29);
		Charges = charge;
		strcpy_s(this->appoitmentStatus, AppStatus.c_str());
		strcpy_s(this->specialization, spec.c_str());
		strcpy_s(this->Hospital, hospital.c_str());
		strcpy_s(this->City, city.c_str());
	}

	void menuPatient() {
		int ctype = 0;
		cout << "\n=> Press 1 for In-Person Consultation\n";
		cout << "\n=> Press 2 for Video Consultation\n";
		cin >> ctype;


		calcCharges(ctype);

	}

	void DisplayAppointment() {


		cout << "\n_________________________________________\nPatient ID: " << patientCNIC << "\nPatient Name: " << patientName << "\nDoctor ID: " << doctorCNIC << "\nDoctor Name: " << doctorName;
		cout << "\nDate: "; appointmentDate.showDate();
		cout << "\nAppointment Start Time: "; appointmentTimeFrom.showTime();
		cout << "\nAppointment End Time: "; appointmentTimeto.showTime();
		cout << "\nAppointment Status: " << appoitmentStatus << "\nCharegs: " << Charges << "\n_________________________________________";
	}

	void DisplayAppointmentDocView() {


		cout << "\n_________________________________________\nPatient ID: " << patientCNIC << "\nPatient Name: " << patientName;
		cout << "\nDate: "; appointmentDate.showDate();
		cout << "\nAppointment Start Time: "; appointmentTimeFrom.showTime();
		cout << "\nAppointment End Time: "; appointmentTimeto.showTime();
		cout << "\nAppointment Status: " << appoitmentStatus << "\nCharegs: " << Charges << "\n_________________________________________";
	}
	void DisplayAppointmentPATIENTView() {

		cout << "\nDoctor ID: " << doctorCNIC << "\nDoctor Name: " << doctorName;
		cout << "\nDate: "; appointmentDate.showDate();
		cout << "\nAppointment Start Time: "; appointmentTimeFrom.showTime();
		cout << "\nAppointment End Time: "; appointmentTimeto.showTime();
		cout << "\nAppointment Status: " << appoitmentStatus << "\nCharegs: " << Charges << "\n_________________________________________";

	}

	void setPatientCNIC(long long int PatCNIC) {
		patientCNIC = PatCNIC;
	}
	void setPatientName(string PatName) { strcpy_s(this->patientName, PatName.c_str()); }
	void setAppointmentStatus(string AppStatus) {
		strcpy_s(this->appoitmentStatus, AppStatus.c_str());
	}
	long long int getPatientCNIC() { return patientCNIC; }
	long long int getDoctorCNIC() { return doctorCNIC; }
	char* getPatientName() { return patientName; }
	char* getDoctorName() { return doctorName; }
	char* getDoctorHospital() { return Hospital; }
	char* getDoctorSpecialization() { return specialization; }
	char* getDoctorCity() { return City; }
	char* getAppoitmentStatus() { return appoitmentStatus; };
	float getCharges() { return this->Charges; }
	Date getDate() { return appointmentDate; }
	Time getAppointmentTimeFrom() { return appointmentTimeFrom; };
	Time getAppointmentTimeTo() { return appointmentTimeto; };
	int getStars() { return appointmentFeedback.getStars(); }

	void setScheduleTime() {

		cout << "\nEnter new Time\n";
		appointmentTimeFrom.menu();
		appointmentTimeto.addTime(29);
	}


	int getNOofDays(Date d) {

		return appointmentDate.getnoOfDays(d);

	}

	void giveFeedback() {

		appointmentFeedback.FeedbackMenu();
	}
	void calcCharges(int type) {

		if (type == 1) {
			cout << "\nIn-Person Consultation Booked Successfuly\n";

		}
		else if (type == 2)
		{
			cout << "\nVideo Consultation Booked Successfuly\n";

			this->Charges *= 0.7;

		}



	}

};

class User {

protected:
	long long int CNIC;
	char name[50];
	char password[50];
	Payments Money;

public:

	void set(long long int id, string name, string pass) {

		this->CNIC = id;
		strcpy_s(this->name, name.c_str());
		strcpy_s(this->password, pass.c_str());

	}
	long long int getID() { return CNIC; }
	char* getName() { return name; }
	void display() {


		cout << "\n_________________________________________\nID: " << CNIC << "\nName: " << name << "\nPassword: " << password << "\n_________________________________________";
	}

	void setPassword(string pass) {

		strcpy_s(this->password, pass.c_str());


	}


	void RechargeUserMenu() {

		Money.rechargeMenu();

	}

	void DisplayAllMoney() {
		Money.ShowAllBalances();
	}

	/*void TransferMoneyFrom() {

		Money.TransferFromMenu();

	}

	void TransferMoneyTo() {

		Money.TransferToMenu();

	}

	void ShowAllUserBalances() {

		Money.ShowAllBalances();
	}*/


};


class Patient : public User
{
private:

public:

	void Register() {

		bool isValid = true;
		string name, pass, passval;
		long long int CNIC = 99;

		cout << "\n\n__________________________________________________________________________________________\n\n PATIENT REGISTRATION \n__________________________________________________________________________________________\n\n";


	reEnterCNIC:
		cout << "Enter Patient CNIC: ";
		cin >> CNIC;
		if (!(CNIC >= 1000000000000 && CNIC <= 9999999999999)) {
			cout << "Invalid CNIC! Enter a Valid 13 digit CNIC :)\n";
			goto reEnterCNIC;
		}
		fstream ud("Patients.bin", ios::binary | ios::in);
		Patient p;
		while (ud.read((char*)&p, sizeof(p)))
		{
			if (p.CNIC == CNIC) {
				cout << "CNIC Already Exists! \n";
				goto reEnterCNIC;
			}
		}

		ud.close();

		cin.ignore(1000, '\n');
		cout << "Enter Patient name: ";
		getline(cin, name);
		cout << "Enter Password: ";
		getline(cin, pass);
	reEnterPass:
		cout << "re-Enter Password: ";
		getline(cin, passval);

		if (pass != passval) {
			cout << "Passwords don\'t match!  Try Again :)\n";
			goto reEnterPass;
		}



		set(CNIC, name, pass);
		Money.setBalanceDefault();

		ud.open("Patients.bin", ios::binary | ios::out | ios::app);
		p.set(CNIC, name, pass);
		p.Money.setBalanceDefault();

		ud.write((char*)&p, sizeof(p));

		ud.close();
		mainmenu();

	}

	void resetPassword() {

		string pass;
		cout << "\n\n__________________________________________________________________________________________\n\n  PASSWORD RESET \n__________________________________________________________________________________________\n\n";
	reEnter:
		cout << "Enter New PASSWORD: ";
		cin >> pass;

		if (passwordChecker(pass) == false) {
			goto reEnter;
		}

		fstream ud("Patients.bin", ios::binary | ios::in | ios::out);

		Patient ou;

		while (ud.read((char*)&ou, sizeof(ou))) {

			if (ou.getID() == this->CNIC) {

				ou.setPassword(pass);

				ud.seekp((int)ud.tellg() - sizeof(ou), ios::beg);
				ud.write((char*)&ou, sizeof(ou));
				cout << "\nPASSWORD RESET SUCCESSFUL";
				break;

			}
		}

	}

	int login() {

		string name, pass;
		cout << "\n\n__________________________________________________________________________________________\n\n PATIENT LOGIN \n__________________________________________________________________________________________\n\n";
		cin.ignore(1000, '\n');
	reEnterUserORPass:
		cout << "\nEnter Username: ";
		getline(cin, name);
		cout << "Enter Password: ";
		getline(cin, pass);

		bool success = false;

		fstream ud("Patients.bin", ios::binary | ios::in);
		Patient d;
		while (ud.read((char*)&d, sizeof(d)))
		{
			if (d.name == name && d.password == pass) {

				cout << "\n__________________________________________________________________________________________\n\nLogin Successful\nWelcome " << d.name;
				success = true;
				break;
			}

		}

		ud.close();

		if (success == false) {
			cout << "INVALID USERNAME OR PASSWORD     TRY AGAIN :)\n";
			goto reEnterUserORPass;
		}

		/*cout << "\nEnter Password to reset: ";
		getline(cin, pass);

		d.resetPassword(pass);*/


	reDisplay:
		int Offmainmenu = 1;

		int choice = -1;

		cout << "\n___________________________________________________________________________________________\n1. reset Password\n2. Show Appointments \n3. Book Appointment\n4. Approve Appointments\n5. Go For Checkup\n6. Cancel Appointment\n7. Search Appointment\n8. Show Profile \n9. Show Money  \n0. MainMenu\n";
		cin >> choice;
		if (choice == 1) {
			d.resetPassword();
		}
		else if (choice == 2) {
			d.ShowAppointments();
		}
		else if (choice == 3) {
			d.BookAppointment();

		}
		else if (choice == 4) {
			d.RechargeUserMenu();
		}
		else if (choice == 5) {

			d.GoForCheckup();
		}
		else if (choice == 6) {
			d.CancelAppointment();

		}
		else if (choice == 7) {
			d.ShowAppointments();

		}
		else if (choice == 8) {
			d.display();

		}
		else if (choice == 9) {
			d.DisplayAllMoney();

		}
		else if (choice == 0) {
			mainmenu();

		}


		goto reDisplay;
		/*d.ShowAppointments();*/

		cout << "\n\n\nEND ";

		return Offmainmenu;
	}





	void readPatients() {

		ifstream ud("Patients.bin");

		Patient ou;
		//ud.write((char*)&inu, sizeof(inu));
		while (ud.read((char*)&ou, sizeof(ou))) {

			ou.display();
		}
		ud.close();
	}
	void ShowAppointments() {
		int choice = -1;

		cout << "\n\n__________________________________________________________________________________________\n\n  APPOINTMENT SEARCH MENU \n__________________________________________________________________________________________\n\n";

		string docName, docCity, docSpec, docHospital;



		cout << "\n Search by ?\n1. Specialization\n2. Hospital\n3. City\n";
		cin >> choice;

		if (choice == 1) {

			cin.ignore(1000, '\n');
			cout << "Enter Specialization: ";
			getline(cin, docSpec);

		}
		else if (choice == 2) {
			cout << "Enter Hospital: ";
			cin >> docHospital;
		}
		else if (choice == 3) {
			cout << "Enter City: ";
			cin >> docCity;
		}


		fstream Appdata("Appointments.bin", ios::binary | ios::in);

		Appointment ou;

		while (Appdata.read((char*)&ou, sizeof(ou))) {
			if (ou.getDoctorSpecialization() == docSpec && choice == 1) {

				ou.DisplayAppointmentPATIENTView();
			}
			else if (ou.getDoctorHospital() == docHospital && choice == 2) {

				ou.DisplayAppointmentPATIENTView();
			}
			else if (ou.getDoctorCity() == docCity && choice == 3) {

				ou.DisplayAppointmentPATIENTView();
			}
		}

		Appdata.close();


	}

	bool BookAppointment() {

		bool success = false;
		string statusPending = "Pending", statusNULL = "NULL";
		char isNULL[10];
		strcpy_s(isNULL, statusNULL.c_str());
		string docName, docCity, docSpec, docHospital;
		Date date;
		Time time;
		cout << "\n\n__________________________________________________________________________________________\n\n APPOINTMENT BOOKING MENU \n__________________________________________________________________________________________\n\n";

		//Money.ShowAllBalances();

		char cdocName[50];

		//cin.ignore(1000, '\n');

		cout << "\nEnter Doctor Name: ";
		cin >> docName;

		cout << "\nEnter Date of Appointment\n ";
		date.menu();

		cout << "Enter Time of Appointment\n ";
		time.menu();
		strcpy_s(cdocName, docName.c_str());


		fstream Appdata("Appointments.bin", ios::binary | ios::in | ios::out);

		Appointment ou;


		while (Appdata.read((char*)&ou, sizeof(ou))) {
			//cout << "\n$$$$1";

			if ((ou.getDoctorName() == docName) == true) {
				//cout << "\n$$$$2";

				if ((ou.getDate() == date) == true) {
					//cout << "\n$$$$3";

					if ((ou.getAppointmentTimeFrom() == time) == true) {
						//Money.ShowAllBalances();
						//cout << "\n$$$$4";
						if (ou.getPatientCNIC() == -1) {

							ou.menuPatient();
							//RechargeAccount();
							float money = Money.compare();

							if (money >= ou.getCharges()) {

								//cout << "\n########" << ou.getAppoitmentStatus();
								Appdata.seekp((int)Appdata.tellg() - sizeof(ou), ios::beg);
								ou.setAppointmentStatus(statusPending);
								ou.setPatientCNIC(this->CNIC);
								ou.setPatientName(this->name);
								Appdata.write((char*)&ou, sizeof(ou));
								success = true;

								Patient p;
								fstream ud("Patients.bin", ios::binary | ios::in | ios::out);
								while (ud.read((char*)&p, sizeof(p)))
								{
									if (p.CNIC == this->CNIC) {
										p.setAccountNUM(Money.getAccountNum());
										ud.seekp((int)ud.tellg() - sizeof(p), ios::beg);
										ud.write((char*)&p, sizeof(p));
										cout << "\nAPPOINTMENT BOOKED SUUCCESSFULLY !\n";
										break;
									}
								}

								ud.close();




								break;

							}


						}
					}



				}

			}

		}

		Appdata.close();


		if (success == false) {
			cout << "\nEnterted Slot does\'t Exist!  TRY AGAIN :)";
			return success;
		}

		return success;

	}

	void RechargeAccount() {

		Patient p;
		fstream ud("Patients.bin", ios::binary | ios::in | ios::out);
		while (ud.read((char*)&p, sizeof(p)))
		{
			if (p.CNIC == CNIC) {
				p.RechargeUserMenu();

				ud.seekp((int)ud.tellg() - sizeof(p), ios::beg);
				ud.write((char*)&p, sizeof(p));
				cout << "\nRECHARGE SUCCESSFUL";
				break;
			}
		}

		ud.close();

	}


	void GoForCheckup() {

		Date date, attdate;
		Time time;

		string docName;
		cout << "\nEnter Doctor Name: ";
		cin >> docName;



		cout << "\nEnter Scheduled Date of Appointment\n ";
		date.menu();

		cout << "Enter Scheduled Time of Appointment\n ";
		time.menu();

		cout << "\nEnter Attending Date of Appointment\n ";
		attdate.menu();

		fstream Appdata("Appointments.bin", ios::binary | ios::in | ios::out);

		Appointment ou;

		while (Appdata.read((char*)&ou, sizeof(ou))) {
			cout << "\n\nIFFFFFFFFFFFFFFFFFFFFFFs1";

			if (ou.getPatientCNIC() == this->CNIC && ou.getDoctorName() == docName) {
				cout << "\n\nIFFFFFFFFFFFFFFFFFFFFFFs2";
				if (strcmp(ou.getAppoitmentStatus(), "Approved") == 0) {
					cout << "\n\nIFFFFFFFFFFFFFFFFFFFFFFs3";

					if ((ou.getAppointmentTimeFrom() == time) == true) {

						cout << "\n\nIFFFFFFFFFFFFFFFFFFFFFFs";

						ou.giveFeedback();
						ou.setAppointmentStatus((string)"Completed");
						Appdata.seekp((int)Appdata.tellg() - sizeof(ou), ios::beg);
						cout << "\nCHECKUP COMPLETED\n";
						Appdata.write((char*)&ou, sizeof(ou));

						if ((ou.getDate() == attdate) == true) {
							cout << "\nYOU ARE ON TIME\n";
							Money.TransferFrom(getAccNUM(), 0);
						}
						else if (ou.getNOofDays(attdate) == 1) {
							cout << "\nYOU ARE LATE 1 Day\n";
							Money.TransferFrom(getAccNUM(), ou.getCharges() * 0.3);
						}
						else if (ou.getNOofDays(attdate) == 2) {
							cout << "\nYOU ARE LATE 2 Days\n";
							Money.TransferFrom(getAccNUM(), ou.getCharges() * 0.6);
						}
						else if (ou.getNOofDays(attdate) > 2) {
							cout << "\nYOU ARE LATE MORE THAN TWO DAYS\n";
							Money.TransferFrom(getAccNUM(), ou.getCharges());
						}



						break;


					}
				}
			}
		}

		Appdata.close();



	}
	void CancelAppointment() {

		Date date, attdate;
		Time time;

		cout << "\nEnter Appointment Cancellation Date\n ";
		date.menu();

		cout << "\nEnter Appointment Cancellation Time\n ";
		time.menu();

		cout << "\nEnter Cancellation Date of Appointment\n ";
		attdate.menu();

		fstream Appdata("Appointments.bin", ios::binary | ios::in | ios::out);

		Appointment ou;

		while (Appdata.read((char*)&ou, sizeof(ou))) {
			if (ou.getPatientCNIC() == this->CNIC) {
				if (strcmp(ou.getAppoitmentStatus(), "Approved") == 0) {

					if ((ou.getAppointmentTimeFrom() == time) == true) {


						/*ou.setPatientCNIC(-1);
						ou.setPatientName("-1");*/
						ou.setAppointmentStatus("CANCELED");
						Appdata.seekp((int)Appdata.tellg() - sizeof(ou), ios::beg);
						cout << "\nCANCELLATION COMPLETED\n";
						Appdata.write((char*)&ou, sizeof(ou));

						if ((ou.getDate() == attdate) == true) {
							cout << "\nFULL Refund\n";
							Money.TransferTo(getAccNUM(), ou.getCharges());
						}
						else if (ou.getNOofDays(attdate) == 1) {
							cout << "\n60% Refund\n";
							Money.TransferTo(getAccNUM(), ou.getCharges() * 0.6);
						}
						else if (ou.getNOofDays(attdate) == 2) {
							cout << "\n30% Refund\n";

							Money.TransferTo(getAccNUM(), ou.getCharges() * 0.3);
						}
						else if (ou.getNOofDays(attdate) > 2) {
							cout << "\nNo Refund\n";

							Money.TransferTo(getAccNUM(), 0);
						}



						break;


					}
				}
			}
		}

		Appdata.close();


	}
	void TransferFrom(int accnum, float amount) {
		Money.TransferFrom(accnum, amount);
	}
	void setAccountNUM(int n) { Money.SetAccountNum(n); }
	int getAccNUM() { return Money.getAccountNum(); };
	void editPatientAppointmentTime() {

		Time time;
		cout << "\n\nEnter old Appointment Time ";
		time.setTime();


		fstream Appdata("Appointments.bin", ios::binary | ios::in | ios::out);

		Appointment ou;

		while (Appdata.read((char*)&ou, sizeof(ou))) {
			if (ou.getPatientCNIC() == this->CNIC && (ou.getAppointmentTimeFrom() == time) == true) {

				ou.setScheduleTime();

				Appdata.seekp((int)Appdata.tellg() - sizeof(ou), ios::beg);

				Appdata.write((char*)&ou, sizeof(ou));
			}
		}

		Appdata.close();

	}
};


class Doctor : public User
{

private:
	char email[50];
	long long int yearsOFExperience;
	char specialization[50];
	char Hospital[50];
	char City[50];
	float Fee;
	float Rating=0;
	Appointment appointments;
	Patient pat;
	//Appointment appointment;


public:
	void set(long long int id, string name, string pass, string mail, long long int exp, string spec, string hospital, string city, float fees) {

		this->CNIC = id;
		strcpy_s(this->name, name.c_str());
		strcpy_s(this->password, pass.c_str());
		strcpy_s(this->email, mail.c_str());
		this->yearsOFExperience = exp;
		strcpy_s(this->specialization, spec.c_str());
		strcpy_s(this->Hospital, hospital.c_str());
		strcpy_s(this->City, city.c_str());
		Fee = fees;

	}
	void display() {


		cout << "\n_________________________________________\nID: " << CNIC << "\nName: " << name << "\nPassword: " << password << "\nEmail: " << email << "\nYears of Experience: " << yearsOFExperience <<
			"\nSpecialization: " << specialization << "\nHospital: " << Hospital << "\nCity: " << City << "\nFee per Appointment: " << Fee << "\nRating: " << Rating << endl;
	}

	void setFee() {

		float fees;
		cout << "Enter fee Amount: ";
		cin >> fees;
		Fee = fees;
	}
	void Register() {
		cout << "\n\n__________________________________________________________________________________________\n\n DOCTOR REGISTRATION \n__________________________________________________________________________________________\n\n";

		bool isValid = true;
		string name, pass, passval, mail, spec = "none", hospital, city;
		int exp = 0;
		long long int CNIC = -1;
		float fees;

	reEnterDoctorCNIC:
		cout << "Enter Doctor CNIC: ";
		cin >> CNIC;
		if (!(CNIC >= 1000000000000 && CNIC <= 9999999999999)) {
			cout << "Invalid CNIC! Enter a Valid 13 digit CNIC :)\n";
			goto reEnterDoctorCNIC;
		}
		fstream ud("Doctors.bin", ios::binary | ios::in);
		Doctor d;
		while (ud.read((char*)&d, sizeof(d)))
		{
			if (d.CNIC == CNIC) {
				cout << "CNIC Already Exists! \n";
				goto reEnterDoctorCNIC;
			}
		}

		ud.close();



		cin.ignore(1000, '\n');

	reEnterDoctorEmail:
		cout << "Enter Doctor email: ";
		getline(cin, mail);
		ud.open("Doctors.bin", ios::binary | ios::in);
		while (ud.read((char*)&d, sizeof(d)))
		{
			if (d.email == mail) {
				cout << "mail Already Exists! \n";
				goto reEnterDoctorEmail;
			}
		}

		ud.close();
	reEnterDoctorName:
		cout << "Enter Doctor name: ";
		getline(cin, name);

		ud.open("Doctors.bin", ios::binary | ios::in);

		while (ud.read((char*)&d, sizeof(d)))
		{
			if (d.name == name) {
				cout << "Username Already Exists! \n";
				goto reEnterDoctorName;
			}
		}

		ud.close();


	reEnterDoctorPass:
		cout << "Enter Password: ";
		getline(cin, pass);

		if (passwordChecker(pass) == false) {
			cout << "Password Must include atleast one special character, one number and one uppercase letter.\nTRY AGAIN :)\n";
			goto reEnterDoctorPass;

		}
	reEnterDoctorPassVal:
		cout << "re-Enter Password: ";
		getline(cin, passval);

		if (pass != passval) {
			cout << "Passwords don\'t match!  Try Again :)\n";
			goto reEnterDoctorPassVal;
		}


		cout << "Enter Years of Experience: ";
		cin >> exp;
		cin.ignore(1000, '\n');
		cout << "Enter Specialization: ";
		getline(cin, spec);
		cout << "Enter Hospital: ";
		getline(cin, hospital);
		cout << "Enter City: ";
		getline(cin, city);
		cout << "Enter Fee per Appointment: ";
		cin >> fees;



		set(CNIC, name, pass, mail, exp, spec, hospital, city, fees);

		d.set(CNIC, name, pass, mail, exp, spec, hospital, city, fees);

		ud.open("Doctors.bin", ios::binary | ios::out | ios::in | ios::app);

		ud.write((char*)&d, sizeof(d));

		ud.close();

		mainmenu();

		//showAvaibility();


	}

	void updateRating(long long int docCNIC) {

		int i = 0;
		Rating = 0;
		fstream Appdata("Appointments.bin", ios::binary | ios::in);

		Appointment ou;

		while (Appdata.read((char*)&ou, sizeof(ou))) {

			if (ou.getStars() != -1 && ou.getDoctorCNIC() == docCNIC) {

				i++;
				Rating += ou.getStars();
			}
		}

		Rating /= i;

		Appdata.close();


	}

	void displayDoctors() {
		ifstream ud("Doctors.bin");

		Doctor ou;
		//ud.write((char*)&inu, sizeof(inu));
		while (ud.read((char*)&ou, sizeof(ou))) {

			ou.display();


		}
		ud.close();
	}

	int login() {

		updateRating(this->CNIC);
		cout << "\n\n__________________________________________________________________________________________\n\n DOCTOR LOGIN \n__________________________________________________________________________________________\n\n";

		cin.ignore(1000, '\n');
		/*cout << "\n";*/
		string name, pass;

	reEnterUserORPass:
		cout << "\nEnter Username: ";
		getline(cin, name);
		cout << "Enter Password: ";
		getline(cin, pass);


		bool success = false;

		fstream ud("Doctors.bin", ios::binary | ios::in | ios::out);
		Doctor d;
		while (ud.read((char*)&d, sizeof(d)))
		{
			//d.display();

			if (d.password == pass && d.getName() == name) {
				cout << "Login Successful\nWelcome " << d.name;
				success = true;
				break;
			}

		}
		ud.close();

		if (success == false) {
			cout << "INVALID USERNAME OR PASSWORD     TRY AGAIN :)\n";
			goto reEnterUserORPass;
		}
	reDisplay:
		int Offmainmenu = 1;

		int choice = 0;

		cout << "\n___________________________________________________________________________________________\n1. Add Avaibility\n2. Show Avaibility \n3. Show Pending Appointments \n4. Approve Appointments\n5. Show Approved Appoitment\n6. Display Money\n7. Show Profile\n0. MainMenu\n";
		cin >> choice;
		if (choice == 1) {
			d.addAvaibility();
		}
		else if (choice == 2) {
			d.showAvaibility();

		}
		else if (choice == 3) {
			d.showPendingAppointments();

		}
		else if (choice == 4) {
			d.ApproveAppointment();
		}
		else if (choice == 5) {
			d.showApprovedAppointments();

		}
		else if (choice == 6) {
			d.DisplayAllMoney();
		}
		else if (choice == 7) {
			d.display();
		}
		else if (choice == 0) {
			mainmenu();

		}
		goto reDisplay;
		return Offmainmenu;

		cout << "####" << d.name;
		/*d.addAvaibility();
		d.showAvaibility();*/

		cout << "\n\n\n________________________________________________\n\n";


		//d.showPendingAppointments();

		cout << "\n\nEND ";

		//return true;
	}

	void addAvaibility() {

		cout << "\n\n__________________________________________________________________________________________\n\n ADD AVAIBILITY MENU \n__________________________________________________________________________________________\n\n";


		Patient dp;
		//Doctor doc = *this;
		dp.set(-1, "-1", "-1");

		Date date;
		Time startTime, endTime;
		cout << "\nEnter Date for Avaibility\n";
		date.menu();
		cout << "\nEnter Starting Time\n";
		startTime.menu();
		cout << "\nEnter Ending Time\n";
		endTime.menu();

		//cout << "#############" << this->name;
		string DocName(this->name);
		string PatName(dp.getName());
		string spec(specialization);
		string hospital(this->Hospital);
		string city(this->City);
		//cout << "\n#############" << DocName;
		long long int DocCNIC = this->CNIC;
		//cout << "\n#############" << DocCNIC;
		//int j = 0;
		ofstream Appdata("Appointments.bin", ios::binary | ios::out | ios::app);

		Appointment ino;
		for (Time i = startTime; !(i == endTime); i.addTime(30)) {
			ino.set(dp.getID(), PatName, DocCNIC, DocName, spec, hospital, city, date, i, Fee, "NULL");
			Appdata.write((char*)&ino, sizeof(ino));
			/*if (j == 1) {
				i.addTime(1);
			}*/
		}


		Appdata.close();
	}
	void editAvaibility() {
		addAvaibility();
	}
	void viewPatient() {

		long long int id;

		cout << "Enter Patient CNIC: ";
		cin >> id;

		fstream Appdata("Appointments.bin", ios::binary | ios::in);

		Appointment ou;

		while (Appdata.read((char*)&ou, sizeof(ou))) {
			cout << "\n###" << name;
			if (ou.getPatientCNIC() == id) {

				pat.display();
				break;
			}
		}

		Appdata.close();


	}

	void showAvaibility() {

		//addAvaibility();
		cout << "\nAVAIBILE APPOINTMENTS FOR Dr." << this->name << endl;

		fstream Appdata("Appointments.bin", ios::binary | ios::in);

		Appointment ou;

		while (Appdata.read((char*)&ou, sizeof(ou))) {
			cout << "\n###" << name;
			if (ou.getDoctorCNIC() == CNIC) {


				ou.DisplayAppointmentDocView();
			}
		}

		Appdata.close();
	}

	void editDoctorProfile() {

		string city;
		int choice;

		cout << "\n\nEdit Profile MENU\n\n";

		cout << "\n1. Avaibility\n2. location\n3. Fee \n";


		if (choice == 1) {
			editAvaibility();
		}
		else if (choice == 2) {

			cout << "Enter Location: ";
			cin >> city;
			strcpy_s(this->City, city.c_str());

		}
		else if (choice == 3) {

			setFee();
		}

	}

	void showPendingAppointments() {

		cout << "\n\n__________________________________________________________________________________________\n\n  PENDING APPOINTMENTS \n__________________________________________________________________________________________\n\n";


		fstream Appdata("Appointments.bin", ios::binary | ios::in | ios::out);

		Appointment ou;


		while (Appdata.read((char*)&ou, sizeof(ou))) {

			if (ou.getDoctorCNIC() == this->CNIC && (strcmp(ou.getAppoitmentStatus(), "Pending") == 0)) {
				ou.DisplayAppointmentDocView();
			}

		}

		Appdata.close();



	}

	void ApproveAppointment() {



		Date AppDate;
		Time AppTime;
		cout << "\n\n__________________________________________________________________________________________\n\n  APPROVE APPOINTMENT MENU\n__________________________________________________________________________________________\n\n";






		cout << "\nEnter Appointment Date\n ";
		AppDate.menu();
		cout << "\nEnter Appointment Time\n ";
		AppTime.menu();


		fstream Appdata("Appointments.bin", ios::binary | ios::in | ios::out);


		Appointment ou;

		while (Appdata.read((char*)&ou, sizeof(ou))) {

			if (ou.getDoctorCNIC() == this->CNIC && (strcmp(ou.getAppoitmentStatus(), "Pending") == 0)) {


				fstream pd("Patients.bin", ios::binary | ios::in | ios::out);
				Patient p;
				while (pd.read((char*)&p, sizeof(p)))
				{
					if (ou.getPatientCNIC() == p.getID()) {

						p.TransferFrom(p.getAccNUM(), ou.getCharges());
						Money.TransferTo(p.getAccNUM(), ou.getCharges());
						pd.seekp((int)pd.tellg() - sizeof(p), ios::beg);
						pd.write((char*)&p, sizeof(p));

						fstream ud("Doctors.bin", ios::binary | ios::in | ios::out);
						Doctor d;
						while (ud.read((char*)&d, sizeof(d)))
						{
							if (d.CNIC == this->CNIC) {
								//d.transferTo(p.getAccNUM(), ou.getCharges());
								d = *this;
								d.updateRating(d.CNIC);
								ud.seekp((int)Appdata.tellg() - sizeof(d), ios::beg);
								ud.write((char*)&d, sizeof(d));
								ou.setAppointmentStatus("Approved");
								Appdata.seekp((int)Appdata.tellg() - sizeof(ou), ios::beg);
								Appdata.write((char*)&ou, sizeof(ou));

								cout << "\nAPPOINTMENT APPROVED SUCCESSFULLY\n";
								break;
							}
						}

						ud.close();
						break;

					}
				}

				pd.close();


				break;
			}

		}

		Appdata.close();


	}
	void rejectAppointment() {



		Date AppDate;
		Time AppTime;
		cout << "\n\REJECT APPOINTMENT MENU\n\n ";




		cout << "\nEnter Appointment Date\n ";
		AppDate.menu();
		cout << "\nEnter Appointment Time\n ";
		AppTime.menu();

		fstream Appdata("Appointments.bin", ios::binary | ios::in | ios::out);

		Appointment ou;


		while (Appdata.read((char*)&ou, sizeof(ou))) {

			if (ou.getDoctorCNIC() == this->CNIC && (strcmp(ou.getAppoitmentStatus(), "Rejected") == 0)) {
				ou.setAppointmentStatus("Approved");
				Appdata.seekp((int)Appdata.tellg() - sizeof(ou), ios::beg);
				Appdata.write((char*)&ou, sizeof(ou));
				break;
			}

		}

		Appdata.close();


	}

	void transferTo(int acc, float amt) { Money.TransferTo(acc, amt); }
	void showApprovedAppointments() {

		cout << "\n\n__________________________________________________________________________________________\n\n  APPROVED APPOINTMENTS \n__________________________________________________________________________________________\n\n";


		fstream Appdata("Appointments.bin", ios::binary | ios::in | ios::out);

		Appointment ou;


		while (Appdata.read((char*)&ou, sizeof(ou))) {

			if (ou.getDoctorCNIC() == this->CNIC && (strcmp(ou.getAppoitmentStatus(), "Approved") == 0)) {
				ou.DisplayAppointmentDocView();
			}

		}

		Appdata.close();



	}


};

class Admin : public User {

protected:

	Doctor d;
	Patient p;
public:

	
	void AdminMenu() {

		cout << "\n\n__________________________________________________________________________________________\n\n ADMIN LOGIN \n__________________________________________________________________________________________\n\n";

		cin.ignore(100, '\n');
		string name, pass;
	reEnter:
		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter Password: ";
		getline(cin, pass);
		if (name != "admin" && pass != "123")
			goto reEnter;


		int choice = -1;
	reDisplay:
		cout << "\n___________________________________________________________________________________________\n1. AddD octor \n2. updateDoctor \n3. deleteDoctor\n4. viewPatients\n5. viewDoctors\n6. Doctor Related Options\n0. MainMenu\n";
		cin >> choice;
		if (choice == 1) {
			AddDoctor();
		}
		else if (choice == 2) {
			updateDoctor();
		}
		else if (choice == 3) {
			deleteDoctor();

		}
		else if (choice == 4) {

			viewPatients();
		}
		else if (choice == 5) {
			viewDoctors();
		}
		else if (choice == 6) {
			d.login();

		}
		else if (choice == 0) {
			mainmenu();
		}


		goto reDisplay;
		/*d.ShowAppointments();*/

		cout << "\n\n\nEND ";





	}

	void AddDoctor() {


		d.Register();


	}



	void viewDoctors() {

		ifstream ud("Doctors.bin");

		Doctor ou;
		//ud.write((char*)&inu, sizeof(inu));
		while (ud.read((char*)&ou, sizeof(ou))) {

			ou.display();


		}
		ud.close();
	}

	void viewPatients() {

		ifstream ud("Patients.bin");

		Patient ou;
		//ud.write((char*)&inu, sizeof(inu));
		while (ud.read((char*)&ou, sizeof(ou))) {

			ou.display();
		}
		ud.close();
	}


	void updateDoctor() {


		long long int id;

		cout << "\nEnter Doctor CNIC: ";
		cin >> id;

		fstream ud("Doctors.bin", ios::binary | ios::in | ios::out);

		Doctor ou;
		while (ud.read((char*)&ou, sizeof(ou))) {

			if (ou.getID() == id) {
				ou.Register();
				ud.seekp((long long int)ud.tellg() - sizeof(ou), ios::beg);
				ud.write((char*)&ou, sizeof(ou));

				cout << "\n\nSUCCESS";
				break;
			}


		}


		ud.close();

	}
	void deleteDoctor() {

		long long int id;

		cout << "\nEnter Doctor CNIC: ";
		cin >> id;

		fstream ud("Doctors.bin", ios::binary | ios::in | ios::out);
		ofstream t("temp.bin", ios::binary);
		Doctor ou;
		while (ud.read((char*)&ou, sizeof(ou))) {

			if (ou.getID() != id) {

				t.write((char*)&ou, sizeof(ou));

				cout << "\n\ndeleted";

			}


		}

		ud.close();
		t.close();

		remove("Doctors.bin");
		rename("temp.bin", "Doctors.bin");
	}



};







int mainmenu() {


	int choice = -1;

	Admin a;
	Patient p;
	Doctor d;
mainmenu:
	cout << "\n\n\n__________________________________________________________________________________________\n\n MAIN MENU \n__________________________________________________________________________________________\n";

	cout << "\n1. Admin\n2. Doctor\n3. Patient\n";
	cin >> choice;

	if (choice == 1) {
		a.AdminMenu();
	}
	else if (choice == 2) {
		cout << "\n___________________________________________________________________________________________\n1. Login\n2. Register\n0. MainMenu\n";
		cin >> choice;
		if (choice == 1) {
			d.login();
		}
		else if (choice == 2) {
			d.Register();

		}
		else if (choice == 0) {

			mainmenu();
		}
	}
	else if (choice == 3) {
		cout << "\n___________________________________________________________________________________________\n1. Login\n2. Register\n0. MainMenu\n";
		cin >> choice;
		if (choice == 1) {
			p.login();
		}
		else if (choice == 2) {
			p.Register();

		}
		else if (choice == 0) {

			mainmenu();

		}
	}
	mainmenu();


	return 0;
}







//void create(User inu) {
//
//	ofstream ud("UserData.bin", ios::binary | ios::app);
//
//
//
//	ud.write((char*)&inu, sizeof(inu));
//	//while(ud.read((char*)&ou, sizeof(ou)));
//
//
//
//	ud.close();
//
//}
//
//void read() {
//
//	ifstream ud("UserData.bin");
//
//	User ou;
//	//ud.write((char*)&inu, sizeof(inu));
//	while (ud.read((char*)&ou, sizeof(ou))) {
//
//		if (ou.getID() == 11) {
//		}
//		ou.display();
//
//
//	}
//	ud.close();
//}
//
//void update(long long int id, User inu) {
//
	//fstream ud("UserData.bin", ios::binary | ios::in | ios::out);

	//User ou = inu;
	//inu.set(69, "asd", "zxczc");

	//while (ud.read((char*)&ou, sizeof(ou))) {

	//	if (ou.getID() == id) {
	//		//ou.display();
	//		//ud.seekp(ud.tellg() - sizeof(ou), ios::beg);
	//		ud.write((char*)&inu, sizeof(inu));


	//	}
//
//
//	}
//
//
//	ud.close();
//}