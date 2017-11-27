//clase sobrecarga

#include <iostream>
#include <cstdlib>

#include "contador.h"


Contador::Contador(int valMin , int valMax , int valInicial){

valMin_ = valMin;
valMax_ = valMax;
val_ = valInicial;
val_ = rango(val_);
counter_.push_back(val_);

}



Contador Contador::operator=(const Contador &c){

	if(this != &c){
		val_ = c.val_;
		valMin_ =	c.valMin_;
		valMax_  = c.valMax_;
		val_ = rango(val_);
		counter_.push_back(val_);

	}

	return *this;


}


Contador Contador::operator=(int i){

	i = rango(i);
	val_ = i;
	counter_.push_back(val_);
	return *this;

}


Contador Contador::operator++(void){

	val_++;
	val_ = rango(val_);
	counter_.push_back(val_);

	return *this;
}

Contador Contador::operator++(int){
	Contador temp(*this);
	val_++;
	val_ = rango(val_);
	counter_.push_back(val_);
	return temp;


}

Contador Contador::operator--(void){

	val_--;
	val_ = rango(val_);
	counter_.push_back(val_);
	return *this;
}

Contador Contador::operator--(int){
	Contador temp(*this);
	val_--;
	val_ = rango(val_);
	counter_.push_back(val_);
	return temp;


}

Contador Contador::operator+(int i){

	val_ = val_ + i;
	val_ = rango(val_);
	counter_.push_back(val_);
	return *this;
}

Contador Contador::operator-(int i){

	val_ = val_ - i;
	val_ = rango(val_);
	counter_.push_back(val_);
	return *this;
}

bool Contador::undo(int noperaciones){
int tamanyo = counter_.size();
	if(noperaciones > tamanyo){
		return false;
	}
	else{
		for (int i = 0; i < noperaciones; ++i)
		{
			counter_.pop_back();

		}
	val_ = counter_.back();	
		
		return true;
	}


}

int Contador::rango(int x){
	if (x>valMax_){
		return valMax_;
	}

	if(x<valMin_){
		return valMin_;
	}

	return x;
}