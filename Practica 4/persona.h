#ifndef PERSONA_H
#define PERSONA_H
#include <string>

using namespace std;

namespace ruleta{
class Persona
{
private:
	string DNI_;
	string nombre_;
	string apellidos_;
	string direccion_;
	string localidad_;
	string provincia_;
	string pais_;

public:
	
	Persona(string DNI , string nombre ="" , string apellidos =""  , string direccion = "" , string localidad = "" , string provincia= "" , string pais="");

	inline void setDNI(string nuevo){DNI_ = nuevo;};
	inline void setNombre(string nuevo){nombre_ = nuevo;};
	inline void setApellidos(string nuevo){apellidos_ = nuevo;};
	inline void setDireccion(string nuevo){direccion_ =nuevo;};
	inline void setLocalidad(string nuevo){localidad_ =nuevo;};
	inline void setProvincia(string nuevo){provincia_ = nuevo;};
	inline void setPais(string nuevo){pais_ = nuevo;};


	inline string getDNI(){return DNI_;};
	inline string getNombre(){return nombre_;};
	inline string getApellidos(){return apellidos_;};
	inline string getDireccion(){return direccion_;};
	inline string getLocalidad(){return localidad_;};
	inline string getProvincia(){return provincia_;};
	inline string getPais(){return pais_;};


	inline string getApellidosyNombre(){return apellidos_ + ", " + nombre_;};

};
}

#endif