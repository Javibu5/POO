//dados.h 
//la clase dados representa el lanzamiento de 2 dados
#ifndef DADOS_H
#define	DADOS_H


class Dados{
private:
	int n1_ ;
	int n2_ ;
	int d1_;
	int d2_;
	int v1[5];
	int v2[5];

public:

	Dados();
	void lanzamiento();
	int getDado1();
	int getDado2();
	bool setDado1(int x);
	bool setDado2(int x);
	int getSuma();
	int getDiferencia();
	int getLanzamientos1();
	int getLanzamientos2();
	float getMedia1();
	float getMedia2();
	int suma1();
	int suma2();
	int getUltimos1(int * v1);
	int getUltimos2(int * v2);
};


#endif