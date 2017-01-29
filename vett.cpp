#include "vett.h"

namespace ns_vett{
	
	vett::vett(){
		riemp=N; //per default non ha riempimento
		nelem=0;
	}
	
	vett::vett(const int r){
		riemp=r; //inizializzo il riempimento
		nelem=0;
		
	}
	
	vett::vett(const vett & vet){
		riemp=vet.riemp;
		nelem=vet.nelem;
		for(int i=0;i<nelem;i++){
			v[i]=vet.v[i];
		}
	}
	

	const vett & vett::operator=(const vett & vet){
		for(int i=0;i<nelem;i++){
			delete &v[i];
		}
		
		nelem=vet.nelem;
		riemp=vet.riemp;
		
		for(int i=0;i<nelem;i++){
			v[i]=vet.v[i];
		}
		
		
	}
	
	
	void vett::set_riemp(const int r) throw(const char*){
		if(r>=N) throw "errore! il vettore e allocato staticamente e non ha abbastanza spazio\n\n";
		riemp=r;
	}
	
	
	void vett::set_r(const int r){
		try{
			set_riemp(r);
		}catch(const char* s){
			cout << s << endl;
			cout << "riprova ad inserire un riempimento valido per continuare: ";
			int r1;
			cin >> r1;
			set_r(r1);
		}
	}
	
	void vett::stampa()const{
		for(int i=0;i<nelem;i++){
			cout << "elemento numero " << i+1 << " : " << v[i] << endl;
		}
	}
	
	
	bool vett::elimina_cf(const char* cf){
		for(int i=0;i<nelem;i++){
			if(!strcmp(cf,v[i].get_cf())){
				for(int j=i;j<nelem;j++){
					v[j]=v[j+1];
				}
				nelem--;
				return true;
			}
		}
		return false;
	}
	
	
	bool vett::elimina_codice_fiscale(const char* cf){
		if(elimina_cf(cf)){
			cout << cf << " eliminato!";
			return true;
		}
		else {
			cout << "codice fiscale " << cf << " non trovato nel vettore, inserirne uno valido per continuare: ";
			char buff[800];
			cin.getline(buff,799);
			elimina_codice_fiscale(buff);
		}
	}
	
	const T & vett::operator[](const int index)const{
		return v[index];
	}
	
	T & vett::operator[](const int index){
		return v[index];
	}
	
	
	void vett::add(const int pos, const T & e){
		v[pos]=e;
		nelem++;
	}
	
	
}
