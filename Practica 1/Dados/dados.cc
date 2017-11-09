//dados.cc
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "dados.h"


Dados::Dados(){

	d1_=1;
	d2_=1;
	srand(time(NULL));
	n1_=0;
	n2_=0;
}

void Dados::lanzamiento(){

	d1_=(rand() % 6) + 1 ;
	n1_++;
	d2_=(rand() % 6) + 1 ;
	n2_++;

}

int Dados::getDado1(){

	return d1_;
	

}


int Dados::getDado2(){

	return d2_;
	
}


bool Dados::setDado1(int x){

	if(x<1 || x>6){
		return false;
	}
	n1_++;
	d1_=x;
	return true;

	}


bool Dados::setDado2(int x){

	if(x<1 || x>6){
		return false;
	}
	n2_++;
	d2_=x;
	return true;

	}

int Dados::getSuma(){
	 return (d1_ + d2_);
}

int Dados::getDiferencia(){

	if(d1_ > d2_ ){
		 return (d1_ - d2_);

		}
		else{
			return (d2_ - d1_);
		}
}


int Dados::getLanzamientos1(){
	return n1_;
}


int Dados::getLanzamientos2(){
	return n2_;
}

int Dados::suma1(){
	int suma = 0 ;
	suma = suma + d1_;
	return suma;

}


float Dados::getMedia1(){
	
float media = 0;

	if(getLanzamientos1()!=0){
	media = suma1()/ getLanzamientos1();
	
	}
	return media;
}

int Dados::suma2(){
	int suma = 0 ;
	suma = suma + d2_;
	return suma;

}


float Dados::getMedia2(){
	float media = 0;
	if(getLanzamientos2()!=0){
	media = suma2()/ getLanzamientos2();

	}
return media;
}

int Dados::getUltimos1(int * v1){
	
	int i;

	for (i = 3; i > 1; i--)
	{
		v1[i+1]=v1[i];
	}

	v1[0]=d1_;
}

int Dados::getUltimos2(int * v2){
	
	int i;

	for (i = 3; i > 1; i--)
	{
		v2[i+1]=v2[i];
	}

	v2[0]=d2_;
}
