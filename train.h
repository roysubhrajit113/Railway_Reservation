#include <iostream>
#include <string>
using namespace std;

#ifndef TRAIN_H
#define TRAIN_H

class Train {
	private:
		const string train_name;
		const int train_no;
	protected:
		float ticket_fare;
	public:
		int no_seats;
		string dep_station;
		string arr_station;
		
		Train(string n, int n, int seats, float f, string d, string a){
			train_name=n;
			train_no=n;
			no_seats=seats;
			ticket_fare=f;
			dep_station=d;
			arr_station=a;
		}
		void setSeats(int n){
			no_seats=n;
		}
		void setFare(float f){
			ticket_fare=f;
		}
		void setDeparture(string d){
			dep_station=d;
		}
		void setArrival(string a){
			arr_station=a;
		}
		void getTrainDetails() const{
			cout<<"Train Name: "<<train_name<<endl;
			cout<<"Train Number: "<<train_no<<endl;
			cout<<"Departure Station: "<<dep_station<<endl;
			cout<<"Arrival Station: "<<arr_station<<endl;
			cout<<"Available Seats: "<<no_seats<<endl;
		}
		
		string getTrainName(){
			return train_name;
		}
		
		int getTrainNo(){
			return train_no;
		}
		int getSeats(){
			return no_seats;
		}
		
		float getFare(){
			return ticket_fare;
		}
};

#endif