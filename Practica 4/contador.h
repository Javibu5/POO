#ifndef CONTADOR_H
#define CONTADOR_H 

class Contador
{
private:

	int counter_;
	int valMin_;
	int valMax_;
	int valinicial_;

public:
	
	Contador(int valMin = "" , int valMax = "" , int valInicial = "");


};

Contador Contador::operator= (const Contador &c){
	

}
#endif