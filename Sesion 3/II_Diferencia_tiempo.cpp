/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Problema número 1 :
            Programa para calcular la diferencia en segundos entre dos 
            instantes de un día o de su consecutivo.
*/
/*********************************************************************/


#include <iostream>     // Inclusión de los recursos de E/S.
#include <cmath>       // Inclusión de los recursos matemáticos.
#include <cstdlib>    // Inclusión de llamadas al sistema.

using namespace std; 


int main() // Programa Principal.
{              
            
            system ("chcp 1252");        //Caracteres latinos.
            
   // Declara variables para guardar.
   
   const double FACT_DI = 86400;
   const double FACT_HOR = 3600;
   const double FACT_MIN = 60;
   
	double hor_i;           
	double min_i;             
   double seg_i;       
   double hor_f;
   double min_f;
   double seg_f;
   double dif;
   double inst_i;
   double inst_f;
   
   int dia; 
   
   
   //Entrada de datos.
   
   cout << "\nDatos del instante inical...: ";
   
   cout << "\nIntruduzca la hora: ";
   cin >> hor_i;
   
   cout << "Introduzca el minuto: ";
   cin >> min_i;
   
   cout << "Introduzca el segundo: ";
   cin >> seg_i;
   
   
   cout << "\n""\n";
   
   
   cout << "\nDatos del instante final: ";
   
   cout << "\nIntroduzca la hora: ";
   cin >> hor_f;
   
   cout << "Introduzca el minuto: ";
   cin >> min_f;
   
   cout << "Introduzca el segundo: ";
   cin >> seg_f;
   
   
	// Cálculos
	
	/*
	Convertimos el valor de ambos instantes a segundos y usamos una variable
	para hallar la diferencia entre ambos.
	*/
	 
  inst_i = hor_i*FACT_HOR + min_i*FACT_MIN + seg_i;
  inst_f = hor_f*FACT_HOR + min_f*FACT_MIN + seg_f;
  dif = inst_f - inst_i;
  
  /*Si esa diferencia es negativa, restamos los minutos que componen 24h
  a la diferencia anterior en positivo.
  */
  
  if (dif < 0) {
  	
  	dif = FACT_DI - (-1*dif);
  	
  	//Resultados 1.
  	
  	cout << "\nLa diferencia entre ambos ";
	cout << "instantes es de: " << dif << " seg" "\n";
	
	return (0);
  
  }
  
   else {
   	
  /*
  Si la diferencia es positiva o igual a cero, preguntamos si los 
  instantes pertenecen al mismo día o no y actuamos en consecuencia.
  */
  
  
  if (dif >=0)  {
  	
  	cout<< "\n¿Los instantes pertenecen a dias distintos? (1:Sí , 0:No): ";
  	cin >> dia;
  	
  	
  	/*
  	En el caso de pertenecer a días distintos, hallamos la diferencia
  	con respecto al primer día, y le sumamos los segundos transcurridos
  	del segundo día.
  	*/
  	
  	 if (dia == 1) {
  	 	
  	 	dif = (FACT_DI - inst_i) + inst_f;
  	 	
  	 	cout << "\nLa diferencia entre ambos ";
    	cout << "instantes es de: " << dif << " seg" "\n";
    	
	} 	
	
	/*
	En caso de que pertenezcan al mismo día, basta con realizar la diferencia
	entre el instante final y el inicial.
	*/
	
	 if (dia == 0){ 
  	 		
  	 		dif = inst_f - inst_i;
  	 		
  	 		cout << "\nLa diferencia entre ambos ";
	      cout << "instantes es de: " << dif << " seg" "\n";
  	 		
  	 	} 

  } 
}

   //Pausa del programa.
   
   system("pause");
   
	return (0);
}
