/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/*        
           Problema n�mero 12 :
              Programa simple para calcular el valor de la funcion 
				  gaussiana para un valor (x) en funcion de una esperanza 
				  y desviaci�n t�pica determinadas.
*/
/*********************************************************************/

#include <iostream>               //Inclusi�n de recursos de E/S.
#include <cmath>                 //Inclusi�n de recursos matem�ticos.
#include <cstdlib>              // Inclusi�n de llamadas al sistema.
#include <string>              //Inclusi�n de recursos de tipo string.

using namespace std;


//Filtro para introducir un real positivo.
double Filtro(string mensaje){
	
	bool valores_correctos;
	double numero_double;
	
	
	do{
		
	cout << mensaje;            
	cin >> numero_double;

	valores_correctos = ( numero_double > 0);
	
	}while(!valores_correctos);
	
	return numero_double;
	
}

//Funci�n para calcular la parte derecha de la funci�n (exponente).
double Exponente( double valor_x, double desviacion, double esperanza ){
	
	double exponente;         //Declaracion de la variable exp.
	
  //C�lculo de la parte derecha de la funci�n.
	exponente = exp (pow( (valor_x - esperanza) / desviacion , 2 ) / -2);

	return exponente;

}

//Funci�n para calcular la parte izqda. de la funci�n (divisi�n).
double Division( double desviacion ){
	
	const double PI = 3.1415926535897;    //Declaracion del valor de PI. 
      
	double div;

	div = 1/(desviacion*sqrt(2*PI)); 
	
	return div;

}

//C�lculo de la funci�n introduciendo los 3 par�metros.
double Gaussiana(double valor_x, double esperanza, double desviacion){
                    
	double valor_y;            //Valor de la funcion. 
	double exponente;        
	double div;
	
	//C�lculo de la parte izquierda de la funci�n.
	div = Division(desviacion);
	
  //C�lculo de la parte derecha de la funci�n.
	exponente = Exponente(valor_x, desviacion, esperanza);
	
  //C�lculo de la funci�n.	
	valor_y = div * exponente; 
	
	return valor_y;

}

//C�lculo de la funci�n introduciendo solo el punto 'x'.
double Gaussiana1Parametro( double valor_x ){
   
	const double DESVIACION = 5;
	const double ESPERANZA = 12;
	                 
	double valor_y;            //Valor de la funcion. 
	double exponente;         //Declaracion de la variable exp.
	double div;
	
	
	//C�lculo de la parte izquierda de la funci�n.
	div = Division(desviacion);
	
  //C�lculo de la parte derecha de la funci�n.
	exponente = Exponente(valor_x, desviacion, esperanza);
	
  //C�lculo de la funci�n.	
	valor_y = div*exponente; 
	
	return valor_y;

}


int main(){ // Programa Principal.


   //Declaraci�n de variables.
    
	double esperanza;      //Valor de (x), esperanza y desviaci�n.        
	double desviacion;     
	double valor_x;                              
	double valor_y;        //Valor de la funcion. 

	
	//Entrada de datos, c�lculos y salida de resultados mediante las funciones
   //definidas anteriormente.
	
   //Enrada de datos 1.
	cout << "\nFuncion con tres parametros: \n";  
   
   esperanza = Filtro("\nIntroduzca el valor de la esperanza: ");
	desviacion = Filtro("Introduzca el valor de la desviacion tipica: ");   
	valor_x = Filtro("Introduzca el valor de la variable X: ");
	
	//C�lculos 1.
	valor_y = Gaussiana(valor_x, esperanza, desviacion);
	
	//Resultados 1.
	cout << "\nEl valor de la funcion en (x) sera: " << valor_y << "\n";  
	
	
	
	
	//Enrada de datos 2 .
	cout << "\nFuncion con un parametro: \n";  
	
	valor_x = Filtro("Introduzca el valor de la variable X: ");
	
	//C�lculos 2.
	valor_y = Gaussiana1Parametro(valor_x);
	
	//Resultados 2.
	cout << "\nEl valor de la funcion en (x) sera: " << valor_y << "\n"; 
	
	
	

	return (0);
	
}
