#include <iostream>
#include "dados.h"

int main()
{
	int x;
	Dados d;

	d.lanzamiento();
	std::cout<<d.getDado1()<<"\n";
	std::cout<<d.getDado2()<<"\n";

	std::cout<<"Dime el numero del primer dado"<<"\n";
	std::cin>>x;

	d.setDado1(x);

	std::cout<<"Dime el numero del segundo dado"<<"\n";
	std::cin>>x;

	d.setDado2(x);


	std::cout<<"dado 1 :"<<d.getDado1()<<"\n";
	std::cout<<"dado 2 :"<<d.getDado2()<<"\n";

	std::cout<<"Suma : " <<d.getSuma()<<"\n";
	std::cout<<"Diferencia : " <<d.getDiferencia()<<"\n";




	return 0;
}
