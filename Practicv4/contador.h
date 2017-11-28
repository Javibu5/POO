#ifndef CONTADOR_H
#define CONTADOR_H 

#include <list>

#include <cstdlib>

using namespace std;





class Contador
{
private:

	list <int> counter_;
	int val_;
	int valMin_;
	int valMax_;

	

public:
	
	Contador(int valMin = 0, int valMax = 1000 , int valInicial = 0 );
 	Contador operator=(const Contador &c);
	Contador operator=(int i);
	Contador operator++();
	Contador operator++(int);
	Contador operator--();
	Contador operator--(int);
	Contador operator+(int i);
	Contador operator-(int i);
	bool undo(int noperaciones);
	inline int get(){return val_;}
	int rango(int x);
};

#endif