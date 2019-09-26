/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Problema n�mero 27 :
            Programa para obtener el precio final de un autom�vil sabiendo
            que es la suma del costo del veh�culo, el porentaje de ganancia
            del vendedor, y el IVA aplicado.
           
*/
/*********************************************************************/


#include <iostream>     // Inclusi�n de los recursos de E/S.
#include <cstdlib>    // Inclusi�n de llamadas al sistema.

using namespace std; 

//Clase para indicar los distintos casos.
enum class Costos {caso_interes, caso_valor_erroneo};

int main(){ // Programa Principal.
             
            
   // Declara variables para guardar.
   
   Costos costo;                     //Declaraci�n de la clase.
   
   const double IVA = 0.16;               // Porcentajes de inter�s e IVA.
   const double VENDEDOR = 0.2;         
   
   double coche;                    //Costo y precio final del veh�culo.
	double total;                
	
   
   
   //Entrada de datos.
   
   cout << "\nIntroduzca el costo del veh�culo: ";
   cin >> coche;
   
   
	// C�lculos.

  /*
  Suma del costo del vehiculo m�s el % de ganacias 
  del vendedor y la parte correspondiente al IVA.
  En caso de que el costo introducido no sea un valor l�gico,
  se muestra por pantalla el mensaje correspondiente.
  */

   if (coche > 0 ){
   	
   total = IVA*coche + VENDEDOR*coche + coche;
   costo = Costos::caso_interes;
   
    }
    
   else{
   	
   	costo = Costos::caso_valor_erroneo;
   	
   }
   	
   	
   //Resltados.
   
   /*
   Muestra los mensajes correspondientes a cada una de las condiciones. Si el
   valor introducido es un valor l�gico, se aplican los intereses y se calcula
   el precio final del veh�culo. En caso de no ser un valor l�gico, muestra un
   mensaje diciendonos que el costo no es v�lido.
   */
   
   switch (costo){
   	case Costos::caso_interes:
   	   cout << "\nAplicaci�n de inter�s e IVA...";
	      cout << "\nEl precio de venta del veh�culo es: " << total << " �" "\n";
	      break;
	      
	   case Costos::caso_valor_erroneo:
   	   cout << "\nEl costo introducido no es valido." "\n";
	      break;
	
	}
	
	
   //Pausa del programa.
   
   system("pause");
   
	return (0);
}
