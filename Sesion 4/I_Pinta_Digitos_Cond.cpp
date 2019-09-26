/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Sesi�n 01-04.
         Problema n�mero 14:
            Escribid en pantalla los d�gitos de un entero de 
            tres cifras separados por tres espacios.
            En caso de introducir un valor que no coincida
            con dichas caracter�sticas mostrar el respectivo 
            mensaje por pantalla.
           
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.os.
#include <cstdlib>     // Inclusi�n de llamadas al sistema.

using namespace std; 

enum class Digitos {caso_digitos, caso_erroneo, caso_erroneo_1};

int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
      Digitos digito;   //Declaraci�n de clase.
   
   	double num_1;        //Real introducido.
   	int num;            //Valor del real en entero para comprobaci�n.
		int cen;        //Valor de las centenas.
   	int dec;        //Valor de las decenas.
   	int uni;        //Valor de las unidades.
   
   //Entrada de datos.
	
	cout << "\nIntroduzca un numero entero de tres cifras: ";
	cin >> num_1;
	
		
	//C�lculos.
	
	/*
	Estructura condicional donde en caso de ser un entero de tres cifras se muestra
	en resultados el mensaje determinado para este caso; y viceversa en caso de no
	ser de tres cifras.
   En caso de que el valor no sea un entero, se mostrar� un mensaje indicando
	que es un real. Ello es compraobado si al restar al numero real introducido 
	su parte entera, el resultado es cero. 
	*/
	
	if (num_1>=100 and num_1<=999){
		
	 num = num_1;
	 cen = num / 100;
	 dec = (num % 100);
	 dec = dec / 10.0;
	 uni = num - ((cen*100) + (dec*10));
	 
	   if( (((num-num) == 0) and ((num_1 - num) == 0))){
	   
	   digito = Digitos::caso_digitos;
	   
    	}
	   else{
	   	
	   digito = Digitos::caso_erroneo_1;
      
	   }
	}
	
	else{
		
		digito = Digitos::caso_erroneo;

	}
	
	//Resultados.
	
	switch (digito){
		
		case Digitos::caso_digitos:
			cout << "\nLos digitos serian:   " << cen <<"   " << dec 
	      <<"   " <<uni <<"\n";
	      break;
	      
	   case Digitos::caso_erroneo:
			cout << "\nEl numero introducido no es un entero de 3 cifras." "\n";
	      break;
	      
	   case Digitos::caso_erroneo_1:
			cout << "\nEl numero introducido no es un entero." "\n";
	      break;
			
	}
		
	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
