/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
// 
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
// 
// 
/* 
         Sesi�n 01-08.
         Problema n�mero 19:
         Programa para calcular la distribuci�n acumulada en un punto
         mediante la implementaci�n de funciones.
          
           
*/        
/*********************************************************************/

#include <iostream>      // Inclusi�n de los recursos de E/S.
#include <cstdlib>      // Inclusi�n de llamadas al sistema.
#include <string>     //Inclusi�n de recursos de tipo string.
#include <cmath>    //Inclusi�n de recursos matem�ticos.

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




double Valor_T(double x){
	
	//Declaraci�n de variables.
	
	const double B0 = 0.2316419;
	double t;
	
	//C�lculo del valor de la variable 't'.
	
	t = (1.0 / ( 1.0 + (B0 * x) ) );
	
	
	return t;
}


//Funci�n para calcular la secuencia de 't' cuya expresi�n viene indicada en 
//los apuntes.
double Sucesion_T(double t){
	
	//Declaraci�n de variables.
	
	const double B1 = 0.319381530;
	const double B2 = -0.356563782;
	const double B3 = 1.781477937;
	const double B4 = -1.821255978;
	const double B5 = 1.330274429;
   
   double sucesion_t;
   
   
   //C�lculos.   
   
	sucesion_t = ( B1 * t ) + ( B2 * (pow(t,2)) ) + ( B3 * (pow(t,3)) ) + 
	( B4 * (pow(t,4)) )	+ ( B5 * (pow(t,5)) ) ;
	
	return sucesion_t;
}

//Funci�n para el c�lculo de CDF(x) a partir de su expresi�n y de los
//valores para la gaussiaa y de la sucesion de 't' ya calculados en 
//funciones anteriores.
double DistribucionAcumulada(double sucesion_t, double gaussiana){
	
	double cdf;
	
	cdf = 1.0 - (gaussiana * sucesion_t);
	
	return cdf;
}



int main(){ // Programa Principal.


   //Declaraci�n de variables.
    
	double esperanza;      //Valor de (x), esperanza y desviaci�n.        
	double desviacion;     
	double valor_x;                              
	double valor_y;        //Valor de la funcion. 
	double var_t;
	double sucesion_t;
	double cdf;
	
	//Entrada de datos, c�lculos y salida de resultados mediante las funciones
   //definidas anteriormente.
	
   //Enrada de datos 1.
   
	cout << "\nFuncion con tres parametros: \n";  
   
   esperanza = Filtro("\nIntroduzca el valor de la esperanza: ");
	desviacion = Filtro("Introduzca el valor de la desviacion tipica: ");   
	valor_x = Filtro("Introduzca el valor de la variable 'X': ");
	
	
	//C�lculos de la gausiana en (x) mediante su funci�n.
	valor_y = Gaussiana(valor_x, esperanza, desviacion);
	
	//C�lculo del valor de 't' mediante su funci�n.
	var_t = Valor_T(valor_x);
	
	//C�lculo de la suecsi�n en 't' mediante su funci�n.
	sucesion_t = Sucesion_T(var_t);
	
	//C�lculos del CDF(x) atendiendo a la funci�n.
	cdf = DistribucionAcumulada(sucesion_t, valor_y);  
	
	
	//Resultados.
	
	cout << "\nEl valor de la distribuci�n acumulada en 'x' (CDF(x)) valdra: "
	<< cdf;
	
	
	return(0);
}
