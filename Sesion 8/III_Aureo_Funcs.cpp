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
         Problema n�mero 18:
         Programa para hallar el valor de n en la secuencia de Fibonacci
         que cumple que la diferencia entre an y el n�mero aureo sea
         menor a fi, mediante la implementaci�n de funciones, donde an
         es el cociente de la secuencia de Fibonacci de orden 'n+1' entre 
			la de orden 'n'.
          
           
*/        
/*********************************************************************/

#include <iostream>      // Inclusi�n de los recursos de E/S.
#include <cstdlib>      // Inclusi�n de llamadas al sistema.
#include <string>     //Inclusi�n de recursos de tipo string.
#include <cmath>    //Inclusi�n de recursos matem�ticos.

using namespace std; 

//Funci�n para filtrar los valores de fi.
double Filtro(string mensaje){
	
	bool valores_correctos;
	double numero;
	
	do{
		
	cout << mensaje;            
	cin >> numero;
	
	valores_correctos = ( numero >= 0 );
	
	}while(!valores_correctos);
	
	return numero;
	
}

//Funci�n para el c�lculo del valor de la sucesi�n en un punto determinado.
//Si el valor de 'n' es 1 � 2, la funci�n valdr� 1.
//En caso de ser un valor mayor, encontramos un ciclo for que va sumando 
//y actualizando los valores de las variables hasta llegar al valor de
//'n' introducido.
double Fibonacci(int n){
	
	//Declaraci�n de variables.

   const int F1 = 1;
   const int F2 = 2;
   
   int fa;
   int fb;
   int fc;
	int fn;
   int inicio_n;
   
   
   //C�lculos.
   
   fa = F1;
   fb = F1;
   fc = F1;
   
   if( (n == F1) || (n == F2) ){
   	
   	fn = F1;
	
	}
	
	else{
		
		for(inicio_n=3 ; inicio_n<=n ; inicio_n++){
			
			fn = fa+fb;
			fa = fn;
			fb = fc;
			fc = fa;
			
		}
		
	}
	
	return fn;
	
}


//Funci�n para hallar el valor de 'n' que cumple que 'an' difiere en menos de
//un valor introducido 'fi' del n�mero aureo.
int Diferencia(double fi){
	
	//Declaraci�n de variables.
	
	double aureo;          //N�mero aureo.
	double an;             // ( fn+1 / fn )
	double dif_aur_fib;    //Diferencia de (an - aureo).
	
	int n;         //Valor de n el la secuencia de Fibonacci.
	
	
	//C�lculos.
	
	//Hallamos el pimer valor de la diferencia.
	
	n = 1;
	an = (Fibonacci(n+1) / Fibonacci(n));
	aureo = ( (1.0 + sqrt(5.0) ) / 2.0 );	
	dif_aur_fib = abs(an - aureo);
	
	/*
	Mediante un ciclo while vamos comparando si la diferencia difiere
	en menos del valor de 'fi' y va probando as� con los valores de 'n'
	hasta llegar al que cumple la condici�n.
	*/
	
   while (fi < dif_aur_fib){
		
		n++;
		an = (Fibonacci(n+1.0) / Fibonacci(n));
		aureo = ( (1.0 + sqrt(5.0) ) / 2.0 );
		
		dif_aur_fib = abs(an - aureo);
		
	}
	
	return n;	
	
}



int main(){
	
	//Declaraci�n de variables.
	
	double fi;     //Valor de fi.
	int n;         //Valor 'n' en la secuencia de Fibonacci.
	
	
	//Entrada de datos.
	
	fi = Filtro( "\nIntroduzca un valor para 'fi': " );
	
	
	//C�lculos.
	
	n = Diferencia(fi);
	
	
	//Resultados.
	
	cout << "\nEl menor valor de 'n' para que la diferencia sea menor a " << fi 
	<< " es " << n;

 
	return(0);
}
