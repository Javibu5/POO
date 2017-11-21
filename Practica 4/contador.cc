//clase sobrecarga

#include <iostream>
#include <cstdlib>

#include "contador.h"


Contador::Contador(int valMin , int valMax , int valInicial){

valMin_ = valMin;
valMax_ = valMax;
counter_ = valInicial;

}


Contador Contador::operator=(const Contador &c){

	if(this != &c){
		counter_ =  c.counter_;
		valMin_ =	c.valMin_;
		valMax_  = c.valMax_;
		

	}

	return *this;


}


Contador Contador::operator=(int i){

	
	counter_ = i;
	return *this;

}


Contador Contador::operator++(){

	counter_++;
	return *this;
}

Contador Contador::operator++(int){
	Contador temp(*this);
	counter_++;
	return temp;


}