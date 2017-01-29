#include <iostream>
#include "scheda.h"
#include "vett.h"

using namespace std;

using namespace card;

using namespace ns_vett;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	
	vett v(4);
	scheda a;
	
	for(int i=0;i<4;i++){
		cin >> a;
		v.add(i,a);
	}
	
	v.stampa();
	
	
	if(v.elimina_codice_fiscale("FRRGPP96E08F839J")) cout << "\n\ndeleted\n\n"; 
	
	v.stampa();
	
	return 0;
}



