#define CATCH_CONFIG_RUNNER
#define _USE_MATH_DEFINES 
#include "catch.hpp"
#include <cmath>


int gcd(int a, int b)
{ 
	if (a < 0 || b < 0)  //a oder b negativ
		return 1;
	else if (b==0)		//b abgeglichen 0
		return a;		
	else if (a==0)		//a abgeglichen 0
		return b;
	else
		return gcd(b, a % b); //ggT
}


TEST_CASE("describe_gcd", "[gcd]")	//Testfaelle
{
	REQUIRE(gcd(2,4) == 2);
	REQUIRE(gcd(6,9) == 3);
	REQUIRE(gcd(3,7) == 1);
	REQUIRE(gcd(0,5) == 5);
	REQUIRE(gcd(5,-1) == 1);
}

int checksum(int x) {
    int summe = 0;
    	while (x > 0) //Schleife wenn ueber 0
	{
        	summe += x % 10; //Zahl mod 10
        	x /= 10; //Ergebnis von Zahl mod 10 durch 10 (ganzzahlig teilen ohne Rest)
    	}
    return summe;
}
TEST_CASE("describe_checksum", "[checksum]")	//Testfaelle
{
	REQUIRE(checksum(23) == 5);
	REQUIRE(checksum(115704) == 18);
	REQUIRE(checksum(2016) == 9);
	REQUIRE(checksum(44) == 8);
	REQUIRE(checksum(11) == 2);
}


int sumMultiples(int z)
{
	int summod = 0;
	for (int i = 1; i <= z; i++) //Zahlen von 1 bis z durchlaufen
	{
		if (i % 3 == 0 || i % 5 == 0) //Zahl durch 3 und 5 teilbar
		{
			summod += i; //summod = summod+i
		}		
	}
	return summod;
}
TEST_CASE("describe_sumMultiples", "[sumMultiples]")
{
	REQUIRE(sumMultiples(10) == 33);//3+5+6+9+10 
	REQUIRE(sumMultiples(1000) == 234168);
}

float fract(float f)
{
	
	
	if (f < 0)
		f = (-1)*f;
	int a = f;		//Zahl casten
		return (f - a); //wenn float groeßer als a

}
TEST_CASE("describe_fract", "[fract]")
{
	REQUIRE(fract(6.77) == Approx(0.77));
	REQUIRE(fract(-6.25) == Approx(0.25));
}	

double Volumen(double r, double h)//M_PI = pi, Volumen Zylinder
{
	return M_PI*r*r*h; //Volumenformel Grundflaeche*Hoehe
}			
TEST_CASE("describe_Volumen", "[Volumen]") 
{
	REQUIRE(Volumen(6, 4) == Approx(452.389342117)); //6=r, 4=h
	REQUIRE(Volumen(2.3, 10.15) == Approx(168.683105146));
}

double Oberflaeche(double r, double h)//Zylinder Oberflaeche
{
	return(2*M_PI*r*r+2*M_PI*r*h);
}
TEST_CASE("describe_Oberflaeche", "[Oberflaeche]") 
{
	REQUIRE(Oberflaeche(6, 4) == Approx(376.9911184308)); //6=r, 4=h
	REQUIRE(Oberflaeche(2.3, 10.15) == Approx(179.919));
}

double Miki(double m) //Meilen zu Kilometer
{
	return(m * 1.60934); //Meilen mal Km
}
TEST_CASE("describe_Miki", "[Miki]") 
{
	REQUIRE(Miki(5) == Approx(8.046720)); //6=r, 4=h
	REQUIRE(Miki(1000) == Approx(1609.344));
	REQUIRE(Miki(55.556) == Approx(89.40872));
}





int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv); 
}
