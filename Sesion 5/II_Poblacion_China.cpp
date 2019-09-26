/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/*    
       Sesi�n 01-05.
       Problema n�mero 20:
           Calcular n�mero de a�os que han de pasar hasta alcanzar
           una poblaci�n introducida desde teclado, mediante ciclos
           while y filtros para controlar que la poblaci�n ha alcanzar
           sea mayor que la actual.
			      
*/  
/*********************************************************************/


#include <iostream>              //Inclusi�n de recursos de E/S
#include <cstdlib>              // Inclusi�n de llamadas al sistema.


using namespace std;

int main(){                    //Programa principal.
            
	               
// Declaraci�n de variables para guardar.
		   
   const int POBLAC_ACTUAL = 1375570814;       //Constantes para
	const int YEARS = 1;                       //modificar su valor m�s
	const double NACIM_S = 1.87;              //facilmente si fuese necesario.
	const double MUERT_S = 3.27;              
   const double EMIGRAC_S = 71.9;
   
   
	double nacimientos;            //Variables para calcular el n�mero
	double muertes;               //de nacimientos, muertes, emigraciones.
	double emigraciones;
   double tiempo_year_seg;         //Variable para conversi�n de a�os a seg.
	
	int poblacion_total;         //Poblaci�n tras cada a�o.
	int anios;                   //A�os hasta alcanzar la poblaci�n pedida.
	int poblacion_futura;        //Poblaci�n ha alcanzar.
	int poblacion_variada;       //Poblaci�n total acumulada cada a�o.
	            	
	
	//Entrada de datos.
	
	//Filtro para introducir los datos correctos.
	
	do{
		
	cout << "\nIntroduzca la poblaci�n para hallar cuantos a�os"
	<< " han de pasar hasta que se alcanze dicha poblaci�n: ";  
	cin >> poblacion_futura;
	
   }while( poblacion_futura <= POBLAC_ACTUAL );
	
	//C�lculos.
	
	//Factor de Conversi�n (a�os a segundos)	
   tiempo_year_seg = YEARS*365*24*60*60;    

   /* C�lculo del n�mero de nacimientos, muertes y emigraciones en funci�n  
   de la variable (A�OS(1)). */
   nacimientos = tiempo_year_seg/NACIM_S;           
   muertes = tiempo_year_seg/MUERT_S;             
   emigraciones = tiempo_year_seg/EMIGRAC_S; 
	
	
	/*
	Creamos una variable acumuladora que sumar� 1 a�o cada vez
	que el total de poblaci�n sea inferior al doble de la cantidad
   inicial de poblaci�n, siendo as� el n�mero de a�os que deben pasar
   para doblar dicha poblaci�n el n�mero de veces que se repite
   el bucle.
	*/
	
	poblacion_variada = POBLAC_ACTUAL;
	poblacion_total = POBLAC_ACTUAL;
	anios = 0;
	
	while( poblacion_total < poblacion_futura){
		
		poblacion_total = poblacion_variada + nacimientos - muertes - emigraciones;
		
	
	   poblacion_variada = poblacion_total;
	   
	   anios++;
	
	}
	
	
	//Resultados.
	
	cout << "\nDeberan pasar " << anios <<" anios para alcanzar una poblacion"
	<< " de " << poblacion_futura << " personas." << "\n";


	//Pausa del programa.
   
   system("pause");
   
	return (0);
	
}
