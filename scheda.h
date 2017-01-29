#ifndef scheda_h
#define scheda_h
#include <iostream>
#include <cstring>
#include <fstream>

using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::ofstream;
using std::ifstream;
using std::endl;
using std::ios;

namespace card{
	
	class scheda{
		private:
			char* cognome;
			char* cf;
			void print(ostream & of)const;
			void read(istream & in);
		public:
			scheda();
			scheda(const char* cognome, const char* codice_fiscale);
			scheda(const scheda & s);
			const scheda & operator=(const scheda & s);
			~scheda();
			void set_cognome(const char* cognome);
			void set_cf(const char* cf);
			const char* get_cognome()const{return cognome;}
			const char* get_cf()const{return cf;}
			friend ostream & operator<<(ostream & os, const scheda & s);
			friend istream & operator>>(istream & in, scheda & s);
			
	};
	
	
	
	
	
	
	
	
	
	
	
}

#endif //scheda_h
