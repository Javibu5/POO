#ifndef RULETA_H
#define RULETA_H

#include "jugador.h"
#include "crupier.h"
#include <list>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;


class ruleta
{

private:

int banca_;
int bola_;
list<Jugador> jugadores_; 
Crupier crupier_;



public:


//
//funciones inline cortas
	inline ruleta(Crupier c):crupier_(c){bola_ = -1; banca_ = 1000000 ;};

	inline int getBanca(){return banca_;};
	inline int getBola(){return bola_;};

	inline Crupier getCrupier(){return crupier_;};
	inline void setCrupier(Crupier c){crupier_ = c;};
	inline list<Jugador> getJugadores(){return jugadores_;};


	bool setBanca(int x){
		if(x<0){
			return false;
		}
		else {
			banca_ = x;
			return true;
		}
	};


	bool setBola(int x){
		if(x<0 && x>36){
			return false;

		}
		else {
			bola_ = x ;
			return true;
		}
	};

//añade Jugador
	bool addJugador(Jugador j){

		list<Jugador>::iterator i;
		string nomfich= j.getDNI() + ".txt";

		for ( i = jugadores_.begin(); i != jugadores_.end(); ++i)
		{
			if(j==i){
				return false;
			}
			else{
				jugadores.pushback(j);
				ifstream fich(nomfich.c_str());

				if(!nomfich){
					ofstream(nomfich.c_str());
						}

				fs.close();

				return true

			}
		}
		};

//borra jugador con parametro objeto jugador
	int deleteJugador(Jugador j){
		string dni = j.getDNI();
		deleteJugador(dni);

		};

//borra jugador con parametro string

	int deleteJugador(string DNI){
		
		list<Jugador>::iterator i;
		if(jugadores_.empty()) return -1;

		for ( i = jugadores_.begin(); i != jugadores_.end(); ++i){
			if(i.getDNI()== DNI){
						jugadores_.erase(i);
						return 1;
			}

		}

		return -2;
};


void escribeJugador(){

	list<Jugador>::iterator i;
	ofstream fich("jugadores.txt");

	for ( i = jugadores_.begin(); i != jugadores_.end(); ++i){
		
		fich << i.getDNI()+","+i.getCodigo();

		if(i.getNombre()=""){
			fich<< ",,,,,,";
		}else fich<<","+i.getNombre();

		if(i.getApellidos()=""){
			fich<< ",,,,,,";
		}else fich<<","+i.getApellidos();

		if(i.getDireccion()=""){
			fich<< ",,,,,,";
		}else fich<<","+i.getDireccion();

		if(i.getApellidos()=""){
			fich<< ",,,,,,";
		}else fich<<","+i.getApellidos();

		if(i.getLocalidad()=""){
			fich<< ",,,,,,";
		}else fich<<","+i.getLocalidad();

		if(i.getProvincia()=""){
			fich<< ",,,,,,";
		}else fich<<","+i.getProvincia();

		if(i.getPais()=""){
			fich<< ",,,,,,";
		}else fich<<","+i.getPais();

		if(i.getProvincia()=""){
			fich<< ",,,,,,";
		}else fich<<","+i.getProvincia();

		if(i.getDinero()=""){
			fich<< ",,,,,,";
		}else fich<<","+i.getDinero();

}

	fich.close();
};

void leeJugadores(){

	Jugador j;
	string dni , codigo , nombre , direccion , localidad , provincia , pais , dinero;
	jugadores_.clear();

	ifstream f("jugadores.txt");

	while(f.getline(dni , 256 , ',')){
		f.getline(codigo , 256 , ',');
		f.getline(nombre , 256 , ',');
		f.getline(direccion, 256 , ',');
		f.getline(localidad , 256 , ',');
		f.getline(provincia , 256 , ',');
		f.getline(pais , 256 , ',');
		f.getline(dinero , 256 , ',');


		j.setDNI(dni);
		j.setCogido(codigo);
		j.setNombre(nombre);
		j.setDirecion(direccion);
		j.setLocalidad(localidad);
		j.setProvincia(provincia);
		j.setPais(pais);
		j.setDinero(dinero);


		jugadores_.push_back(j);

	}

}

//gira ruleta

void giraRuleta(){

	int a;


srand(time(NULL));

a = rand() % 36;
setBola(a);

printf("%d\n", getBola());

}






};
#endif