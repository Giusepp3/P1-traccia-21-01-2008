#include "scheda.h"

namespace card{
	
	scheda::scheda(){
		cognome = new char[1];
		strcpy(cognome,"");
		cf=new char[1];
		strcpy(cf,"");
		
	}
	
	scheda::scheda(const char* cogn, const char* c){
		cognome =  new char[strlen(cogn)+1];
		strcpy(cognome,cogn);
		cf=new char[strlen(c)+1];
		strcpy(cf,c);
	}
	
	scheda::scheda(const scheda & s){
		cognome = new char[strlen(s.cognome)+1];
		strcpy(cognome,s.cognome);
		cf = new char[strlen(s.cf)+1];
		strcpy(cf,s.cf);
	}
	
	scheda::~scheda(){
		delete [] cognome;
		delete [] cf;
	}


	void scheda::set_cognome(const char* cogn){
		if(cognome) delete[] cognome;
		cognome = new char[strlen(cogn)+1];
		strcpy(cognome,cogn);
	}
	
	void scheda::set_cf(const char* c){
		if (cf) delete [] cf;
		cf = new char [strlen(c)+1];
		strcpy(cf,c);
 	}
 	
 	const scheda& scheda::operator=(const scheda & s){
 		if(this==&s) return *this;
 		set_cognome(s.cognome);
 		set_cf(s.cf);
 		return *this;
	 }
	 
	 
	 void scheda::print(ostream & os)const{
	 	os << cognome << ' ' << cf << ' ';
	 }
	 
	ostream & operator<<(ostream & os, const scheda & s){
		s.print(os);
		return os;
	}
	
	void scheda::read(istream & in){
		char buff[800];
		cout << "inserisci cognome: ";
		in.getline(buff,799);
		set_cognome(buff);
		cout << "inserisci cf: ";
		in.getline(buff,799);
		set_cf(buff);
		
	}
	
	istream & operator>>(istream & in, scheda & s){
		s.read(in);
		return in;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
}


