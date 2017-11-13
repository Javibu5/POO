#ifndef RULETA_H
#define RULETA_H

#include "persona.h"
#include "jugador.h"
#include "crupier.h"

#include <list>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

namespace ruleta{
class Ruleta
{

private:

int banca_;
int bola_;
list<Jugador> jugadores_; 
Crupier crupier_;


int tiradas_;


public:


//
//funciones inline cortas
	inline Ruleta(Crupier c):crupier_(c){bola_ = -1; banca_ = 1000000 ; tiradas_ = 0 ;};

	inline int getBanca()const{return banca_;};
	inline int getBola()const{return bola_;};

	inline Crupier getCrupier()const{return crupier_;};
	inline void setCrupier(Crupier c){crupier_ = c;};
	inline list<Jugador> getJugadores()const{return jugadores_;};


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
		if(x<0 || x>36){
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
			if(j.getDNI()==i->getDNI()){
				return false;
			}

			
				jugadores_.push_back(j);
				ifstream fich(nomfich.c_str());

				if(!fich){
					ofstream(nomfich.c_str());
						}

				fich.close();

				return true;

				

			
		
		
		};

//borra jugador con parametro objeto jugador
	int deleteJugador(Jugador j){
		string dni = j.getDNI();
		int i = deleteJugador(dni);

		return i;

		};

//borra jugador con parametro string

	int deleteJugador(string DNI){
	
		list<Jugador>::iterator i;
		if(jugadores_.empty()) return -1;

		for ( i = jugadores_.begin(); i != jugadores_.end(); ++i){
			if(i->getDNI()== DNI){
						jugadores_.erase(i);
						return 1;
			}

		}

		return -2;
};


void escribeJugadores(){

	list<Jugador>::iterator i;
	ofstream fich("jugadores.txt");

	for ( i = jugadores_.begin(); i != jugadores_.end(); ++i){
		
		  fich << i->getDNI() << "," << i->getCodigo() << "," << i->getNombre() << ","
              << i->getApellidos() << "," << i->getDireccion() << ","
              << i->getLocalidad() << "," << i->getProvincia() << ","
              << i->getPais() << "," << i->getDinero() << "\n";

}

	fich.close();
};

void leeJugadores(){

	Jugador j("prueba" , "prueba");
	char dni[256] , codigo[256] , nombre[256] , direccion[256] , localidad[256] , provincia[256] , pais[256] , dinero[256];
	jugadores_.clear();

	ifstream f("jugadores.txt");

	while(f.getline(dni , 256 , ',')){
		f.getline(codigo , 256 , ',');
		f.getline(nombre , 256 , ',');
		f.getline(direccion, 256 , ',');
		f.getline(localidad , 256 , ',');
		f.getline(provincia , 256 , ',');
		f.getline(pais , 256 , ',');
		f.getline(dinero , 256 , '\n');


		j.setDNI(dni);
		j.setCodigo(codigo);
		j.setNombre(nombre);
		j.setDireccion(direccion);
		j.setLocalidad(localidad);
		j.setProvincia(provincia);
		j.setPais(pais);
		j.setDinero(atoi(dinero));


		jugadores_.push_back(j);

	}
	f.close();

};

//gira ruleta

void giraRuleta(){

srand(time(NULL));

bola_ = rand() % 37;

tirada_ ++;
};


void getPremios(){
 	

	list<Jugador>::iterator j;
	list<Apuesta>::iterator a;
	list<Apuesta> la;

	for ( j = jugadores_.begin(); j != jugadores_.end(); ++j){
		j->setApuestas();
		la= j->getApuestas();
		for(a = la.begin(); a != la.end(); ++a){
			switch (a->tipo){
				case 1: {
					if(atoi(a->valor.c_str())==bola_){
						 j->setDinero(j->getDinero()+(a->cantidad*35));
               			banca_-= a->cantidad*35;

						}
					 else {
               j->setDinero(j->getDinero()-a->cantidad);
               banca_+=a->cantidad;
             }
					}break;
				case 2: {
					if(a->valor == color(bola_) && bola_!=0){
						j->setDinero(j->getDinero()+(a->cantidad));
						banca_-=a->cantidad;

					}

					else{
						 j->setDinero(j->getDinero() - a->cantidad);
						banca_ = banca_ + a->cantidad;
					}
				}break;

				case 3 :{
					if(a->valor == parimpar(bola_) && bola_!=0){
						j->setDinero(j->getDinero()+(a->cantidad));
						banca_-=a->cantidad;

					}
					 else{
					 	j->setDinero(j->getDinero() - a->cantidad);
					 banca_ = banca_ + a->cantidad;
					}
				}break;
				case 4 :{
					if(a->valor == altobajo(bola_) && bola_!=0){
						j->setDinero(j->getDinero()+(a->cantidad));
						banca_-=a->cantidad;

					}
					
					else{ banca_ = banca_ + a->cantidad;
						 j->setDinero(j->getDinero() - a->cantidad);
						}
				}
				break;

				
			}
		}	
	}
};

string color(int x){
	switch (x){
		    case 1:
          case 3:
          case 5:
          case 7:
          case 9:
          case 12:
          case 14:
          case 16:
          case 18:
          case 19:
          case 21:
          case 23:
          case 25:
          case 27:
          case 30:
          case 32:
          case 34:
          case 36:
              return "rojo";
          default:
              return "negro";
          }

	};


string parimpar(int x){

     if (x%2==0) return "par";
     return "impar";

};


string altobajo(int x){

     if (x>18) return "alto";
     return "bajo";

};

void getEstadoRuleta(int& numJugadores , int& sumDinero , int& numTiradas , int& gananciasBanca){

numJugadores = 0;
sumDinero = banca_;


		list<Jugador>::iterator j;
		for ( j = jugadores_.begin(); j != jugadores_.end(); ++j){

			numJugadores += 1;
			sumDinero += j->getDinero();

		}

	numTiradas = tiradas_;
	gananciasBanca = getBanca() - 1000000;

};
};
}
#endif