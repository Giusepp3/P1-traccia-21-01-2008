#ifndef vett_h
#define vett_h
#include <iostream>
#include <cstring>
#include <fstream>
#include "scheda.h"

using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::ofstream;
using std::ifstream;
using std::endl;
using std::ios;

using namespace card;

namespace ns_vett{
	
	typedef scheda T;
	
	class vett{
		private:
			static const int N = 100;
			T v[N];
			int riemp;
			int nelem;
			void set_riemp(const int)throw (const char*);
			bool elimina_cf(const char*);
		public:
			vett();
			vett(const int); //predichiara un riempimento
			vett(const vett & v);
			const vett& operator=(const vett & v);
			void set_r(const int);
			int get_riemp()const{return riemp;}
			int get_nelem()const{return nelem;}
			const T & operator[](const int)const; //operatore in lettura
			T & operator[](const int); //operatore in scrittura
			bool elimina_codice_fiscale(const char*);
			void stampa()const;
			void add(const int pos, const T &);
			
	};
	
}


#endif //vett_h
