#include <iostream>
using namespace std;

#include "train.h"
#include "passenger.h"

void display_train_info(Train &train){
	Train::train.getTrainDetails();
}

void passenger_info(Passenger &passenger){
	Passenger::passenger.getPassenger();
}

int payment(Train &train, Passenger &passenger){
	cout<<"Amount to be Paid: "<<endl;
	float fare=Train::train.getFare();
	if (Passenger::passenger.getType()=="GENERAL")
		cout<<fare<<endl;
	else if (Passenger::passenger.getType()=="SLEEPER")
		cout<<fare*1.5<<endl;
	else if (Passenger::passenger.getType()=="3-TIER AC")
		cout<<fare*2<<endl;
	else if (Passenger::passenger.getType()=="2-TIER AC")
		cout<<fare*3<<endl;
	else if (Passenger::passenger.getType()=="FIRST CLASS AC")
		cout<<fare*4<<endl;
	
	int p;
	cout<<"Enter 1 if Payment Done: "<<endl;
	cin>>p;
	if (p==1)
		return 1;
	else
		return 0;
}

void type(Passenger &passenger){
	string choice;
	cout<<"Your current Seat Type is GENERAL. Do you want to upgrade? Type YES, if required, otherwise NO..."<<endl;
	cin.ignore();
	getline(cin, choice);
	if (choice=="YES"){
		cout<<"1. Sleeper"<<endl;
		cout<<"2. 3-Tier AC"<<endl;
		cout<<"3. 2-Tier AC"<<endl;
		cout<<"4. First Class AC"<<endl;
		cout<<endl;
		string type;
		cout<<"Enter the Type of Seat: "<<endl;
		cin.ignore();
		getline(cin,type);
		cout<<"Thank You. Your Seat has been Upgraded to <<type<<"."<<endl;
		Passenger::passenger.setType(string type);
	}
	
	else {
		cout<<"Your Current Seat Type is: GENERAL"<<endl;
	}
	cout<<"Proceeding to Payment..."<<endl;
}

void reservation(Train &train, Passenger &passenger){
	if (!Train::train.no_seats){
		Train::train.no_seats--;
		cout<<"Train Info: "<<endl;
		display_train_info(train);
		cout<<endl;
		cout<<"Passenger Info: "<<endl;
		passenger_info(passenger);
		cout<<endl
		type(passenger);
		a=payment(train, passenger);
		if (a){
			cout<<"Seat Confirmed."<<endl;
			Passenger::passenger.setBooking();
		}
		else
			cout<<"Payment Not Completed. Seat Not Booked."<<endl;
	}
	else
		cout<<"Seats Full. Sorry!"<<endl;
}

void cancel(Train &train, Passenger &passenger){
	Train::train.no_seats++;
	cout<<"Booking Cancelled."<<endl;
	Passenger::passenger.cancelBooking();
}

int main(){
	Train train1("Rajdhani Express",12576,590,560,"New Delhi","Bhopal");
	Train train2("Shatabdi Express",12578,620,380,"Jaipur","Ahmedabad");
	Train train3("Vande Bharat Express",13900,1345,1800,"Kozhikode","Kolkata");
	Train train4("Gatimaan Express",11198,789,650,"Agartala","Jamshedpur");
	
	Passenger passenger1[5](train1);
	Passenger passenger2[5](train2);
	Passenger passenger3[5](train3);
	Passenger passenger4[5](train4);
	string name, gender;
	int age, phone
	for (int i=0; i<5; i++){
		cout<<"Enter Passenger Name: ";
		cin.ignore();
		getline(cin,name);
		cout<<"Enter Age: ";
		cin.ignore();
		getline(cin,age);
		cout<<"Enter Gender: ";
		cin.ignore();
		getline(cin,gender);
		cout<<"Enter Phone Number: ";
		cin.ignore();
		getline(cin,phone);
		passenger1[i].setName(name);
		passenger1[i].setAge(age);
		passenger1[i].setGender(gender);
		passenger1[i].setPhone(phone);
	}
	for (int i=0; i<5; i++){
		cout<<"Enter Passenger Name: ";
		cin.ignore();
		getline(cin,name);
		cout<<"Enter Age: ";
		cin.ignore();
		getline(cin,age);
		cout<<"Enter Gender: ";
		cin.ignore();
		getline(cin,gender);
		cout<<"Enter Phone Number: ";
		cin.ignore();
		getline(cin,phone);
		passenger2[i].setName(name);
		passenger2[i].setAge(age);
		passenger2[i].setGender(gender);
		passenger2[i].setPhone(phone);
	}
	for (int i=0; i<5; i++){
		cout<<"Enter Passenger Name: ";
		cin.ignore();
		getline(cin,name);
		cout<<"Enter Age: ";
		cin.ignore();
		getline(cin,age);
		cout<<"Enter Gender: ";
		cin.ignore();
		getline(cin,gender);
		cout<<"Enter Phone Number: ";
		cin.ignore();
		getline(cin,phone);
		passenger3[i].setName(name);
		passenger3[i].setAge(age);
		passenger3[i].setGender(gender);
		passenger3[i].setPhone(phone);
	}
	for (int i=0; i<5; i++){
		cout<<"Enter Passenger Name: ";
		cin.ignore();
		getline(cin,name);
		cout<<"Enter Age: ";
		cin.ignore();
		getline(cin,age);
		cout<<"Enter Gender: ";
		cin.ignore();
		getline(cin,gender);
		cout<<"Enter Phone Number: ";
		cin.ignore();
		getline(cin,phone);
		passenger4[i].setName(name);
		passenger4[i].setAge(age);
		passenger4[i].setGender(gender);
		passenger4[i].setPhone(phone);
	}

	while (1){
		cout<<"1. Reservation"<<endl;
		cout<<"2. Cancel Booking"<<endl;
		cout<<"3. Display Train Details"<<endl;
		cout<<"4. Display Passenger Details"<<endl;
		cout<<"5. Check for Available Seats"<<endl;
		cout<<"6. View Booked Passengers"<<endl;
		cout<<"0. Exit"<<endl;
		cout<<endl;
		int ch;
		cout<<"Enter the Choice: ";
		cin>>ch;
		
		if (ch==1){
			string name;
			int ph_no;
			string t_name;
			int t_no;
			cout<<"Enter Passenger's Name: ";
			cin.ignore();
			getline(cin,name);
			cout<<"Enter Passenger's Phone Number: ";
			cin>>ph_no;
			cout<<"Enter Train Name: ";
			cin.ignore();
			getline(cin,t_name);
			cout<<"Enter Train Number: ";
			cin>>t_no;
			if (t_name==train1.getTrainName() && t_no==train1.getTrainNo()){
				for (int i=0;i<5;i++){
					if (passenger1[i].getName()==name && passenger1[i].getPhone()==ph_no){
						reservation(train1,passenger1[i]);
						break;
					}
				}
				cout<<"Correct Details Not Inputted"<<endl;
			}
			
			else if (t_name==train2.getTrainName() && t_no==train2.getTrainNo()){
				for (int i=0;i<5;i++){
					if (passenger2[i].getName()==name && passenger2[i].getPhone()==ph_no){
						reservation(train2,passenger2[i]);
						break;
					}
				}
				cout<<"Correct Details Not Inputted"<<endl;
			}

			else if (t_name==train3.getTrainName() && t_no==train3.getTrainNo()){
				for (int i=0;i<5;i++){
					if (passenger3[i].getName()==name && passenger3[i].getPhone()==ph_no){
						reservation(train3,passenger3[i]);
						break;
					}
				}
				cout<<"Correct Details Not Inputted"<<endl;
			}

			else if (t_name==train4.getTrainName() && t_no==train4.getTrainNo()){
				for (int i=0;i<5;i++){
					if (passenger4[i].getName()==name && passenger4[i].getPhone()==ph_no){
						reservation(train4,passenger4[i]);
						break;
					}
				}
				cout<<"Correct Details Not Inputted"<<endl;
			}
		}
		
		else if (ch==2){
			string name;
			int ph_no;
			string t_name;
			int t_no;
			cout<<"Enter Passenger's Name: ";
			cin.ignore();
			getline(cin,name);
			cout<<"Enter Passenger's Phone Number: ";
			cin>>ph_no;
			cout<<"Enter Train Name: ";
			cin.ignore();
			getline(cin,t_name);
			cout<<"Enter Train Number: ";
			cin>>t_no;
			if (t_name==train1.getTrainName() && t_no==train1.getTrainNo()){
				for (int i=0;i<5;i++){
					if (passenger1[i].getName()==name && passenger1[i].getPhone()==ph_no){
						cancel(train1,passenger1[i]);
						break;
					}
				}
				cout<<"Correct Details Not Inputted"<<endl;
			}
			
			else if (t_name==train2.getTrainName() && t_no==train2.getTrainNo()){
				for (int i=0;i<5;i++){
					if (passenger2[i].getName()==name && passenger2[i].getPhone()==ph_no){
						cancel(train2,passenger2[i]);
						break;
					}
				}
				cout<<"Correct Details Not Inputted"<<endl;
			}

			else if (t_name==train3.getTrainName() && t_no==train3.getTrainNo()){
				for (int i=0;i<5;i++){
					if (passenger3[i].getName()==name && passenger3[i].getPhone()==ph_no){
						cancel(train3,passenger3[i]);
						break;
					}
				}
				cout<<"Correct Details Not Inputted"<<endl;
			}

			else if (t_name==train4.getTrainName() && t_no==train4.getTrainNo()){
				for (int i=0;i<5;i++){
					if (passenger4[i].getName()==name && passenger4[i].getPhone()==ph_no){
						cancel(train4,passenger4[i]);
						break;
					}
				}
				cout<<"Correct Details Not Inputted"<<endl;
			}
		}
		
		else if (ch==3){
			string t_name;
			int t_no;
			cout<<"Enter Train Name: ";
			cin.ignore();
			getline(cin,t_name);
			cout<<"Enter Train Number: ";
			cin>>t_no;
			if (t_name==train1.getTrainName() && t_no==train1.getTrainNo()){
				train1.getTrainDetails();
			}
			else if (t_name==train2.getTrainName() && t_no==train2.getTrainNo()){
				train2.getTrainDetails();
			}
			else if (t_name==train3.getTrainName() && t_no==train3.getTrainNo()){
				train3.getTrainDetails();
			}
			else if (t_name==train4.getTrainName() && t_no==train4.getTrainNo()){
				train4.getTrainDetails();
			}
		}
		
		else if (ch==4){
			string name;
			int ph_no;
			cout<<"Enter Passenger's Name: ";
			cin.ignore();
			getline(cin,name);
			cout<<"Enter Passenger's Phone Number: ";
			cin>>ph_no;
			for (int i=0;i<5;i++){
				if (passenger1[i].getPhone==ph_no && passenger1[i].getName()==name){
					passenger_info(passenger1[i]);
					break;
				}
				else if (passenger2[i].getPhone==ph_no && passenger2[i].getName()==name){
					passenger_info(passenger2[i]);
					break;
				}
				else if (passenger3[i].getPhone==ph_no && passenger3[i].getName()==name){
					passenger_info(passenger3[i]);
					break;
				}
				else if (passenger4[i].getPhone==ph_no && passenger4[i].getName()==name){
					passenger_info(passenger4[i]);
					break;
				}
			}
		}
		
		else if (ch==5){
			string t_name;
			int t_no;
			cout<<"Enter Train Name: ";
			cin.ignore();
			getline(cin,t_name);
			cout<<"Enter Train Number: ";
			cin>>t_no;
			if (train1.getTrainName()==t_name && train1.getTrainNo()==t_no){
				int a=train1.getSeats();
				cout<<"Available Seats: "<<a<<endl;
			}
			else if (train2.getTrainName()==t_name && train2.getTrainNo()==t_no){
				int a=train2.getSeats();
				cout<<"Available Seats: "<<a<<endl;
			}
			else if (train3.getTrainName()==t_name && train3.getTrainNo()==t_no){
				int a=train3.getSeats();
				cout<<"Available Seats: "<<a<<endl;
			}
			else if (train4.getTrainName()==t_name && train4.getTrainNo()==t_no){
				int a=train4.getSeats();
				cout<<"Available Seats: "<<a<<endl;
			}
		}
		
		else if (ch==6){
			string t_name;
			int t_no;
			cout<<"Enter Train Name: ";
			cin.ignore();
			getline(cin,t_name);
			cout<<"Enter Train Number: ";
			cin>>t_no;
			if (train1.getTrainName()==t_name && train1.getTrainNo()==t_no){
				for (int i=0; i<5; i++){
					if (passenger1[i].getBooking()){
						passenger_info(passenger1[i]);
						cout<<endl;
					}
				}
			}
			else if (train2.getTrainName()==t_name && train2.getTrainNo()==t_no){
				for (int i=0; i<5; i++){
					if (passenger2[i].getBooking()){
						passenger_info(passenger2[i]);
						cout<<endl;
					}
				}
			}
			else if (train3.getTrainName()==t_name && train3.getTrainNo()==t_no){
				for (int i=0; i<5; i++){
					if (passenger3[i].getBooking()){
						passenger_info(passenger3[i]);
						cout<<endl;
					}
				}
			}
			else if (train4.getTrainName()==t_name && train4.getTrainNo()==t_no){
				for (int i=0; i<5; i++){
					if (passenger4[i].getBooking()){
						passenger_info(passenger4[i]);
						cout<<endl;
					}
				}
			}
		}
		
		else
			break;
	}
}