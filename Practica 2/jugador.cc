#include <iostream>
#include <cstdlib>

#include <fstream>
#include "jugador.h"


void Jugador :: setApuestas(){
	

	char tipo[10] , valor[10] , cantidad[10];
	string nomfich = getDNI() + ".txt";
	Apuesta a;
	ifstream f;
	f.open(nomfich.c_str());

	apuestas_.clear();

	if(f.is_open()){

	while (f.getline(tipo , 256 , ',')){


		f.getline(valor , 256 , ',');
		f.getline(cantidad , 256 );


		a.tipo = atoi(tipo);
		a.valor = valor;
		a.cantidad = atoi(cantidad);

		apuestas_.push_back(a);
		}

	f.close();	

}

else cout<<"el fichero no se ha abierto"<<endl;

}