/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Sesi�n 01 - 03
         Problema n�mero 8:
            Pasar una letra may�scula a min�scula y viceversa, o advertir
            de que es un caracter en caso de no ser una letra,sin usar 
				toupper ni tolower.
*/
/*********************************************************************/


#include <iostream>     // Inclusi�n de los recursos de E/S.
#include <cstdlib>    // Inclusi�n de llamadas al sistema.

using namespace std; 


int main() // Programa Principal.
{              
            
            system ("chcp 1252");        //Caracteres latinos.
            
   // Declara variables para guardar.

   char letra_original;
   char letra_convertida;
   char diferencia;
   
	//Entrada de datos.
	
	cout << "\nIntroduzca la letra: ";
	cin >> letra_original;
	
	
	//C�lculos.
	
		/*
	Si la letra introducida esta dentro de los valores en la tabla ASCII
	de las may�sculas, restamos la diferencia hasta las min�sculas
	y mostramos un mensaje con la respectiva min�scula.
	*/
	
	diferencia = 'A' - 'a';
  
	if (letra_original >= 'A' and letra_original <= 'Z'){
		
		letra_convertida = letra_original - diferencia;
		
	   cout << "\nLa letra era una mayuscula. Una vez convertida es: "
	   << letra_convertida << "\n";
	   
	}
	
   /*
	Si la letra introducida esta dentro de los valores en la tabla ASCII
	de las min�scula, sumamos la diferencia hasta las may�suclas
	y mostramos un mensaje con la respectiva may�scula.
	*/
	
	if (letra_original >= 'a' and letra_original <= 'z') {
		
		letra_convertida = letra_original + diferencia;
		
		 cout << "\nLa letra era una minuscula. Una vez convertida es: "
	   << letra_convertida << "\n";
		 
	}
	
	/*
	En caso de no ser una letra, se imprime el caracter correspondiente.
	*/
	
		else  {
		
		letra_convertida = letra_original;
		
		 cout << "\nEl caracter no era una letra: "
	   << letra_convertida << "\n";
		 
	}

	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
