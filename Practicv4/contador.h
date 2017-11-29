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
	inline int get(){return val_;};


 	Contador operator=(const Contador &c);
	Contador operator=(int i);
	Contador operator++(void);
	Contador operator++(int);
	Contador operator--(void);
	Contador operator--(int);
	
	friend Contador operator+(int i , Contador c);
	friend Contador operator+(Contador c , int i);
	friend Contador operator-(int i ,Contador c);
	friend Contador operator-(Contador c , int i);
	


	bool undo(int noperaciones = 1);
	
	int rango(int x);
};

#endif