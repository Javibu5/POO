#ifndef JUGADOR_H
#define JUGADOR_H
#include "persona.h"
#include <list>

namespace ruleta{
typedef struct apuesta
	{
		int tipo;
		string valor;
		int cantidad;
	}Apuesta;



class Jugador : public Persona{

private: 
	int dinero_;
	string codigo_;
	

	list<Apuesta> apuestas_;

public:
	inline Jugador(string DNI , string codigo , string nombre ="" , string apellidos ="",
	 string direccion = "" , string localidad = "" , string provincia= "" , string pais="") : Persona(DNI ,nombre , 
	 apellidos ,direccion, localidad, provincia , pais){setCodigo(codigo);
	 	dinero_=1000;
	 };
	
	inline void setCodigo(string codigo){codigo_=codigo;};
	inline string getCodigo(){return codigo_;}; 
	inline void setDinero(int dinero){dinero_=dinero;};
	inline int getDinero(){return dinero_;}; 
	inline list<apuesta> getApuestas(){return apuestas_;};
	void setApuestas();

	};
}
#endif