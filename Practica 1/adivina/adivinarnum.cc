//guess.cc
//Un programa que adivina un numero

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){

	srand(time(NULL));
	int a , b;

	std::cout<<"Dime un numero\n";
	std::cin>>a;

	b = rand()%10 + 1;
	

		while(a!=b){
				if(a<b){
					std::cout<<"Tu numero es menor\n";
					std::cout<<"introduce un numero mas grande:\n";
					std::cin>>a;
					}
				else{
					std::cout<<"Tu numero es mayor\n";
					std::cout<<"introduce un numero mas pequeño:\n";
					std::cin>>a;
				}

			}

		std::cout<<"El número es correcto\n";
	
	}
