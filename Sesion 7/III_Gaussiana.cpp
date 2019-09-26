/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/*        
           Problema número 12 :
              Programa simple para calcular el valor de la funcion 
				  gaussiana para un valor (x) en funcion de una esperanza 
				  y desviación típica determinadas.
*/
/*********************************************************************/

#include <iostream>               //Inclusión de recursos de E/S.
#include <cmath>                 //Inclusión de recursos matemáticos.
#include <cstdlib>              // Inclusión de llamadas al sistema.
#include <string>              //Inclusión de recursos de tipo string.

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

//Función para calcular la parte derecha de la función (exponente).
double Exponente( double valor_x, double desviacion, double esperanza ){
	
	double exponente;         //Declaracion de la variable exp.
	
  //Cálculo de la parte derecha de la función.
	exponente = exp (pow( (valor_x - esperanza) / desviacion , 2 ) / -2);

	return exponente;

}

//Función para calcular la parte izqda. de la función (división).
double Division( double desviacion ){
	
	const double PI = 3.1415926535897;    //Declaracion del valor de PI. 
      
	double div;

	div = 1/(desviacion*sqrt(2*PI)); 
	
	return div;

}

//Cálculo de la función introduciendo los 3 parámetros.
double Gaussiana(double valor_x, double esperanza, double desviacion){
                    
	double valor_y;            //Valor de la funcion. 
	double exponente;        
	double div;
	
	//Cálculo de la parte izquierda de la función.
	div = Division(desviacion);
	
  //Cálculo de la parte derecha de la función.
	exponente = Exponente(valor_x, desviacion, esperanza);
	
  //Cálculo de la función.	
	valor_y = div * exponente; 
	
	return valor_y;

}

//Cálculo de la función introduciendo solo el punto 'x'.
double Gaussiana1Parametro( double valor_x ){
   
	const double DESVIACION = 5;
	const double ESPERANZA = 12;
	                 
	double valor_y;            //Valor de la funcion. 
	double exponente;         //Declaracion de la variable exp.
	double div;
	
	
	//Cálculo de la parte izquierda de la función.
	div = Division(desviacion);
	
  //Cálculo de la parte derecha de la función.
	exponente = Exponente(valor_x, desviacion, esperanza);
	
  //Cálculo de la función.	
	valor_y = div*exponente; 
	
	return valor_y;

}


int main(){ // Programa Principal.


   //Declaración de variables.
    
	double esperanza;      //Valor de (x), esperanza y desviación.        
	double desviacion;     
	double valor_x;                              
	double valor_y;        //Valor de la funcion. 

	
	//Entrada de datos, cálculos y salida de resultados mediante las funciones
   //definidas anteriormente.
	
   //Enrada de datos 1.
	cout << "\nFuncion con tres parametros: \n";  
   
   esperanza = Filtro("\nIntroduzca el valor de la esperanza: ");
	desviacion = Filtro("Introduzca el valor de la desviacion tipica: ");   
	valor_x = Filtro("Introduzca el valor de la variable X: ");
	
	//Cálculos 1.
	valor_y = Gaussiana(valor_x, esperanza, desviacion);
	
	//Resultados 1.
	cout << "\nEl valor de la funcion en (x) sera: " << valor_y << "\n";  
	
	
	
	
	//Enrada de datos 2 .
	cout << "\nFuncion con un parametro: \n";  
	
	valor_x = Filtro("Introduzca el valor de la variable X: ");
	
	//Cálculos 2.
	valor_y = Gaussiana1Parametro(valor_x);
	
	//Resultados 2.
	cout << "\nEl valor de la funcion en (x) sera: " << valor_y << "\n"; 
	
	
	

	return (0);
	
}
