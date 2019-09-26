/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Sesión 01 - 03
         Problema número 6 :
             Calcular el precio a pagar por el estacionamiento de un
             vehículo en un parking en función del tiempo de estacionam-
             -iento y tarifas indicadas.
         
           
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.
#include <cctype>      // Inclusión de datos lógicos.
#include <cstdlib>    // Inclusión de llamadas al sistema.

using namespace std; 


int main() // Programa Principal.
{              
            
            system ("chcp 1252");        //Caracteres latinos.
            
   // Declara variables para guardar.
   
   //Precio de cada taifa.
   
   const double TARIFA_1 = 0.0412;
   const double TARIFA_2 = 0.0370;
   const double TARIFA_3 = 0.0493;
   const double TARIFA_4 = 31.55;
	
	//Tiempo de cada período máximo.
	
	const double TIEMPO_0_30 = 30;
   const double TIEMPO_31_90 = 90;
   const double TIEMPO_91_660 = 660;
   const double TIEMPO_661_24 = 24*60;
   
   //Tiempo y precios totales a pagar.
   
   int tiempo;
   double precio;
   double precio_1;
   double precio_2;

   
   //Entrada de datos.
	
	cout << "\nIntroduzca el tiempo de estacionamiento en minutos: ";
	cin >> tiempo;
	
		

	//Cálculos y resultados.
	 
	 
	 /*
	 Cuatro condicionantes más otro en caso de exceder las 24h, donde si
	 el período de estacionamiento va superando el máximo para cada tarifa
	 comienza a aplicarse la segunda... así sucesivamente hasta llegar
	 a la última.
	 Si excede una período, el de 30 min por ejemplo, se multiplican esos
	 30 min por la tarifa correspondiente y a ese total se le suma el total
	 de minutos excedidos de ese período multiplicados por la respectiva
	 tarifa.
	 Se mostrará un mensaje por consola con el total a pagar por el 
	 estacionamiento.
	 */
	 
	    if (tiempo <= TIEMPO_0_30){
	    	
	    	precio=  (tiempo * TARIFA_1);
	    	
	    	cout<< "\nTotal a pagar: " << precio <<" euros.";
	    	
	    }
	    
	     if (tiempo > TIEMPO_0_30 and tiempo <= TIEMPO_31_90 ){
	    	
	    	precio=  (TIEMPO_0_30*TARIFA_1) + ((tiempo - TIEMPO_0_30) * TARIFA_2) ;
	    	
	    	cout<< "\nTotal a pagar: " << precio <<" euros.";
	    	
	    }
	    
	      if (tiempo > TIEMPO_31_90 and tiempo <= TIEMPO_91_660 ){
	    	
	    	precio_1 = ((tiempo - TIEMPO_31_90) * TARIFA_3);
	    	
	    	precio = ((TIEMPO_31_90 - TIEMPO_0_30)* TARIFA_2) + 
			(TIEMPO_0_30 * TARIFA_1) + precio_1;
	    	
	    	
	    	cout<< "\nTotal a pagar: " << precio <<" euros.";
	    	
	    }
	    
	      if (tiempo > TIEMPO_91_660 and tiempo <= TIEMPO_661_24 ){
	    	
	    	
	    	precio_1 = ((tiempo - TIEMPO_91_660) * TARIFA_4);
	    	precio_2 = ((TIEMPO_91_660 - TIEMPO_31_90) * TARIFA_3);
	    	
	    	precio = ((TIEMPO_31_90 - TIEMPO_0_30)* TARIFA_2) + 
			(TIEMPO_0_30 * TARIFA_1) + precio_1 + precio_2;
	    	
	    	
	    	cout<< "\nTotal a pagar: " << precio <<" euros.";
	    	
	    }
	    
	      if (tiempo > TIEMPO_661_24){
			
			cout<< "\nEl tiempo máximo de estacionamiento es de 24h." << "\n";
			
			}
	
	    
		 
		 
	cout<< "\n";
	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
