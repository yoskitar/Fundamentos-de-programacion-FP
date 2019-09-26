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
       Problema número 20:
           Calcular número de años que han de pasar hasta alcanzar
           una población introducida desde teclado, mediante ciclos
           while y filtros para controlar que la población a alcanzar
           sea mayor que la actual.
			      
*/  
/*********************************************************************/


#include <iostream>              //Inclusión de recursos de E/S
#include <cstdlib>              // Inclusión de llamadas al sistema.


using namespace std;

int main(){                    //Programa principal.
            
	               
// Declaración de variables para guardar.
		   
   const int POBLAC_ACTUAL = 1375570814;       //Constantes para
	const int YEARS = 1;                       //modificar su valor más
	const double NACIM_S = 1.87;              //facilmente si fuese necesario.
	const double MUERT_S = 3.27;              
   const double EMIGRAC_S = 71.9;
   
   
	double nacimientos;            //Variables para calcular el número
	double muertes;               //de nacimientos, muertes, emigraciones.
	double emigraciones;
   double tiempo_year_seg;         //Variable para conversión de años a seg.
	
	int poblacion_total;         //Población tras cada año.
	int anios;                   //Años hasta alcanzar la población pedida.
	int poblacion_futura;        //Población ha alcanzar.
	int poblacion_variada;       //Población total acumulada cada año.
	            	
	
	//Entrada de datos.
	
	//Filtro para introducir los datos correctos.
	
	do{
		
	cout << "\nIntroduzca la población para hallar cuantos años"
	<< " han de pasar hasta que se alcanze dicha población: ";  
	cin >> poblacion_futura;
	
   }while( poblacion_futura <= POBLAC_ACTUAL );
	
	//Cálculos.
	
	//Factor de Conversión (años a segundos)	
   tiempo_year_seg = YEARS*365*24*60*60;    

   /* Cálculo del número de nacimientos, muertes y emigraciones en función  
   de la variable (AÑOS(1)). */
   nacimientos = tiempo_year_seg/NACIM_S;           
   muertes = tiempo_year_seg/MUERT_S;             
   emigraciones = tiempo_year_seg/EMIGRAC_S; 
	
	
	/*
	Creamos una variable acumuladora que sumará 1 año cada vez
	que el total de población sea inferior al doble de la cantidad
   inicial de población, siendo así el número de años que deben pasar
   para doblar dicha población el número de veces que se repite
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
