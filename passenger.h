#include <iostream>
using namespace std;

#ifndef PASSENGER_H
#define PASSENGER_H

#include "train.h"

class Passenger {
	protected:
		string p_name;
		int p_age;
		string p_gender;
		int phone_no;
		int booked;
		string compartment_type;
		Train &train;
	public:
		Passenger(Train &t){
			compartment_type="GENERAL";
			Train &train=t;
			booked=0;
		}
		void setName(string n){
			p_name=n;
		}
		void setAge(int a){
			p_age=a;
		}
		void setGender(string g){
			p_gender=g;
		}
		void setPhone(int n){
			phone_no=n;
		}
		
		void getPassenger(){
			cout<<"Passenger Name: "<<p_name<<endl;
			cout<<"Passenger Age: "<<p_age<<endl;
			cout<<"Gender: "<<p_gender<<endl;
			cout<<"Phone Number: "<<phone_no<<endl;
			if (booked){
				cout<<"BOOKED"<<endl;
				cout<<"Compartment Type: "<<compartment_type<<endl;
			else
				cout<<"NOT BOOKED"<<endl;
		}
		
		int getPhone(){
			return phone_no;
		}
		
		string getName(){
			return p_name;
		}
		void setBooking(){
			booked=1;
		
		void cancelBooking(){
			booked=0;
		}
		
		int getBooking(){
			return booked;
		}
		
		void setType(string type){
			compartment_type=type;
		}
		string getType(){
			return compartment_type;
		}
};

#endif