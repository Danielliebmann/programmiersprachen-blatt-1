#include <iostream>
#include <string>


int main()
{
	double meilen;
	std::cout << "Bitte geben Sie die Meilen an: " << std::endl;//Ausgabe
	std::cin >> meilen; //Eingabeaufforderung
	
	double km = meilen * 1.60934;
	std::cout << meilen << " Meilen sind insgesamt" << km << "Kilometer" << std::endl; //Ausgabe

  return 0;
}
