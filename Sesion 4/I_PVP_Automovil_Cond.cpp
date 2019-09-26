/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Problema número 27 :
            Programa para obtener el precio final de un automóvil sabiendo
            que es la suma del costo del vehículo, el porentaje de ganancia
            del vendedor, y el IVA aplicado.
           
*/
/*********************************************************************/


#include <iostream>     // Inclusión de los recursos de E/S.
#include <cstdlib>    // Inclusión de llamadas al sistema.

using namespace std; 

//Clase para indicar los distintos casos.
enum class Costos {caso_interes, caso_valor_erroneo};

int main(){ // Programa Principal.
             
            
   // Declara variables para guardar.
   
   Costos costo;                     //Declaración de la clase.
   
   const double IVA = 0.16;               // Porcentajes de interés e IVA.
   const double VENDEDOR = 0.2;         
   
   double coche;                    //Costo y precio final del vehículo.
	double total;                
	
   
   
   //Entrada de datos.
   
   cout << "\nIntroduzca el costo del vehículo: ";
   cin >> coche;
   
   
	// Cálculos.

  /*
  Suma del costo del vehiculo más el % de ganacias 
  del vendedor y la parte correspondiente al IVA.
  En caso de que el costo introducido no sea un valor lógico,
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
   valor introducido es un valor lógico, se aplican los intereses y se calcula
   el precio final del vehículo. En caso de no ser un valor lógico, muestra un
   mensaje diciendonos que el costo no es válido.
   */
   
   switch (costo){
   	case Costos::caso_interes:
   	   cout << "\nAplicación de interés e IVA...";
	      cout << "\nEl precio de venta del vehículo es: " << total << " €" "\n";
	      break;
	      
	   case Costos::caso_valor_erroneo:
   	   cout << "\nEl costo introducido no es valido." "\n";
	      break;
	
	}
	
	
   //Pausa del programa.
   
   system("pause");
   
	return (0);
}
