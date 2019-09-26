/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Sesión 01-05.
         Problema número 15 :
            Programa para calcular la diferencia en segundos entre dos 
            instantes de un día o de su consecutivo.
*/
/*********************************************************************/


#include <iostream>     // Inclusión de los recursos de E/S.
#include <cmath>       // Inclusión de los recursos matemáticos.
#include <cstdlib>    // Inclusión de llamadas al sistema.

using namespace std; 

enum class TipoInstante {mismo_dia, distinto_dia, distinto_dia_1,};

int main() // Programa Principal.
{              
            
   // Declara variables para guardar.
   
   TipoInstante instante;
   
   const double FACT_DI = 86400;
   const double FACT_HOR = 3600;
   const double FACT_MIN = 60;
   const int TERMINADOR = -1;
   
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
   
   bool operar;
   bool datos_correctos_i;
   bool datos_correctos_f;
   
   //Entrada de datos.
   
   //Primer filtro para los cálculos.
   
   do{	
    
    //Filtro para los datos introducidos.
	 do{
   
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
    
	////Primera condición de valores para que salte el ciclo do-while.
	datos_correctos_i = ( (hor_i >= -1) && (min_i >= 0) && (seg_i >= 0) && 
	(hor_i <= 23) && (min_i <= FACT_MIN) && (seg_i <= FACT_MIN) );
	
	//Segunda condición de valores para que salte el ciclo do-while.
	datos_correctos_f =( (hor_f >= 0) && (min_f >= 0) && (seg_f >= 0) && 
	(hor_f <= 23) && (min_f <= FACT_MIN) && (seg_f <= FACT_MIN) );
	
   }while(!datos_correctos_i || !datos_correctos_f);
   
   
  // Cálculos
	
	/*
	Convertimos el valor de ambos instantes a segundos y usamos 
	una variable para hallar la diferencia entre ambos.
	*/
	 
  inst_i = hor_i*FACT_HOR + min_i*FACT_MIN + seg_i;
  inst_f = hor_f*FACT_HOR + min_f*FACT_MIN + seg_f;
  dif = inst_f - inst_i;
  
  /*
  Si esa diferencia es negativa, restamos los minutos que componen 24h
  a la diferencia anterior en positivo.
  */
  
  //Empleamos un valor lógico para actuar con el filtro.
  operar = (hor_i == TERMINADOR);
  
  /*
  Si el valor de la hora inicial es -1, no se realizan los
  cálculos.
  */
  
  if(!operar){
  
  if (dif < 0) {
  	
  	dif = FACT_DI - (-1*dif);
  	
  	instante = TipoInstante::distinto_dia;
  	
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
  	 	
  	 	instante = TipoInstante::distinto_dia_1;
  	 	
	 } 	
	
	/*
	En caso de que pertenezcan al mismo día, basta con realizar la diferencia
	entre el instante final y el inicial.
	*/
	
	
	 if (dia == 0){ 
  	 		
  	 		dif = inst_f - inst_i;
  	 		
  	 		instante = TipoInstante::mismo_dia;
  	 		
  	  	} 

     } 
   
    } 
    
    //Resultados.
  
   switch(instante){
		case TipoInstante::mismo_dia:
			cout << "\nLa diferencia entre ambos ";
	      cout << "instantes es de: " << dif << " seg" << "\n";
	  	   break;
	  	   
	  	case TipoInstante::distinto_dia:
			cout << "\nLa diferencia entre ambos ";
	      cout << "instantes es de: " << dif << " seg" << "\n";
	  	   break;
	  	   
	  	case TipoInstante::distinto_dia_1:
			cout << "\nLa diferencia entre ambos ";
    	   cout << "instantes es de: " << dif << " seg" << "\n";
	  	   break;
	  	   
	  	}
	  	   
   }
	
  /*Si el valor de la hora inicial es -1, el valor de 
  "operar" sera true y por tanto mediante la condición 
  "!operar" el ciclo se cerrará, 
  */
  
   }while(!operar);
   
   cout<< "\nFin del programa." << "\n";
 
   //Pausa del programa.
   
   system("pause");
   
	return (0);
}
