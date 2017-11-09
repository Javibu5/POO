#ifndef CRUPIER_H
#define CRUPIER_H
#include "persona.h"

class Crupier : public Persona{

private: 
	string codigo_;

public:

	inline Crupier(string DNI, string codigo, string nombre="", string apellidos="" , string direccion = "" , 
	string localidad = "" , string provincia= "" , string pais="") : Persona(DNI, nombre, apellidos, direccion , localidad , provincia, pais){setCodigo(codigo);};
	inline void setCodigo(string nuevo){codigo_=nuevo;};
	inline string getCodigo(){return codigo_;};
};




#endif