#ifndef CONTADOR_H
#define CONTADOR_H 

class Contador
{
private:

	int counter_;
	int valMin_;
	int valMax_;
	

public:
	
	Contador(int valMin = 0, int valMax = 1000 , int valInicial = 0 );
 	Contador operator=(const Contador &c);
	Contador operator=(int i);
	Contador operator++();
	Contador operator++(int);
	Contador operator+(int i);
	Contador operator-(int i);
};

#endif