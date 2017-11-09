// dados_unittest.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//


// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "dados.h"
#include "gtest/gtest.h"

// Tests the c'tor.
TEST(Dados, Constructor) {
  Dados d;
  
  EXPECT_EQ(1, d.getDado1());
  EXPECT_EQ(1, d.getDado2());
  EXPECT_EQ(2, d.getSuma());
  
}

// Tests operación lanzamiento
TEST(Dados, Lanzamiento) {
  Dados d;
  for (int i=0; i<100; i++){
  d.lanzamiento();
  EXPECT_GT(d.getDado1(), 0);
  EXPECT_LT(d.getDado1(), 7);
  EXPECT_GT(d.getDado2(), 0);
  EXPECT_LT(d.getDado2(), 7);
}

}

// Tests operación suma
TEST(Dados, Suma) {
  Dados d;
  
  EXPECT_EQ(d.getDado1()+d.getDado2(), d.getSuma());
}

// Tests modificadores
TEST(Dados, Modificadores) {
  Dados d;
  
  EXPECT_FALSE(d.setDado1(9));
  EXPECT_FALSE(d.setDado1(-9));
  EXPECT_FALSE(d.setDado2(9));
  EXPECT_FALSE(d.setDado2(-9));
  d.setDado1(3);
  EXPECT_EQ(3, d.getDado1());
  d.setDado2(2);
  EXPECT_EQ(2, d.getDado2());
  EXPECT_EQ(5, d.getSuma());
}


TEST(Dados , Diferencia){
  Dados d;

  EXPECT_EQ(d.getDado1() - d.getDado2(), d.getDiferencia());
}

TEST(Dados , Lanzamientos){
  Dados d;
  int i;
  EXPECT_EQ(0 , d.getLanzamientos1());
  EXPECT_EQ(0 , d.getLanzamientos2());
  for (i = 1; i < 100 ; ++i){

    EXPECT_EQ(i , d.getLanzamientos1());
    EXPECT_EQ(i , d.getLanzamientos2());
    
  }
  
}


TEST(Dados , Media){
  Dados d;

  int i  ;
  for (i = 0 ; i < 100 ; ++i){
    d.lanzamiento();
    EXPECT_EQ(d.suma1()/d.getLanzamientos1() , d.getMedia1());
    EXPECT_EQ(d.suma2()/d.getLanzamientos2() , d.getMedia2());
    }
}

TEST(Dados , Ultimos){
  Dados d;
  int i;
  int v1[5] , v2[5];

  for (i = 1; i < 6; ++i) d.setDado1(i);
  for (i = 1; i < 6; ++i) d.setDado2(i);
  d.getUltimos1(v1);
  d.getUltimos2(v2);
  for (i=0;i<5;i++) EXPECT_EQ(5-i,v1[i]);
  for (i=0;i<5;i++) EXPECT_EQ(5-i,v2[i]);
  
}