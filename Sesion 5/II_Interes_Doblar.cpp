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
       Problema número 19:
           Calcular cuántos años han de pasar hasta que el 
           capital introducido sea doblado, como mínimo, gracias
           al interés del plazo fijo.
			      
*/  
/*********************************************************************/


#include <iostream>              //Inclusión de recursos de E/S
#include <cstdlib>              // Inclusión de llamadas al sistema.


using namespace std;

int main(){                    //Programa principal.
           
	                   
	// Declara variables para guardar.   
	               
	double capital_variado;       //Capital acumulado cada año. 
	double interes;               //Interés introducido.  
	double total;                 //Total de capital obtenido.
	double capital_inicial;       //Capital introducido.
	
	int anios;
	            
	bool valores_correctos;        
	                           
	//Entrada de datos.
	
	
	/*
	Filtro para controlar que los valores del capital e interés
	intoducidos son correctos.
	*/
	valores_correctos = ((capital_inicial > 0) and (interes>=0 and interes<=100));
	
	do{
		
	cout << "\nIntroduzca el capital que desea depositar a plazo fijo anual: ";  
	cin >> capital_inicial;
	cout << "Introduzca el interes de su plazo fijo anual: ";              
	cin >> interes;
	
   }while(!valores_correctos);
	
	//Cálculos.
	
	/*
	Creamos una variable acumuladora que sumará 1 año cada vez
	que el total del plazo fijo sea inferior al doble de la cantidad
   inicial depositada, siendo así el número de años que deben pasar
   para doblar dicha cantidad el número de veces que se repite
   el bucle.
	*/
	
	capital_variado = capital_inicial;
	total = capital_inicial;
	anios == 0;
	
	while( total < (2*capital_inicial) ){
		
		total = capital_variado + (capital_variado*(interes/100.0));
	
	   capital_variado = total;
	   
	   anios++;
	
	}
	
	
	//Resultados.
	
	cout << "\nDeberan pasar " << anios <<" anios para doblar como minimo "
	<< capital_inicial << " euros" << " a un interes del " << interes << " %."
	<< "\n\n"; 


	//Pausa del programa.
   
   system("pause");
   
	return (0);
	
}
