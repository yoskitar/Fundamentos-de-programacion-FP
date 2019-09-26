/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/*       Sesion 01-04.
         Problema n�mero 9:
            Aplicar un 3% de descuento si el n�mero de unidades vendidas 
				es superior a 100 y en este caso, si la venta supera los 700�
				se le aplicar� otro descuento acumulable de un 2%.
            
           
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.
#include <cstdlib>     // Inclusi�n de llamadas al sistema.


using namespace std; 

enum class Descuentos{nulo, medio, maximo};

int main(){ // Programa Principal.
            
            
   // Declara variables para guardar.
   
   Descuentos descuento;        //Declaraci�n de la clase.
   
   const double INTERES3 = 0.03;     //Inter�s del 3%.
   const double INTERES2 = 0.02;    //Inter�s del 2%.
   
	int unidades;              //N�mero de unidades vendidas.
   double precio;            //Precio con el 5% o sin inter�s aplicado.
   double precio_3;         //Precio con el 3% aplicado.
   
   //Entrada de datos.
	
	cout << "\nIntroduzca la cantidad de unidades vendidas: ";
	cin >> unidades;
	
	cout << "\nIntroduzca el precio de la compra: ";
	cin >> precio;
	
		
	//C�lculos y resultados.
	
	/*
	Estructura condicional para controlar el descuento que debe ser aplicado
	en cada una de las condiciones. Si la cantidad supera las 100 unidades,
	al precio de venta se le aplica un 3% de descuento. En caso de que el 
	precio inicial de compra supere los 700� se le aplicar� un 5% resultante
	del 3% anterior m�s un 2% por cumplir esta nueva condici�n.
	Si no cumple la primera condici�n, el precio se mantiene sin decuentos.
	En cada caso muestra por consola el descuento aplicado y el precio final.
	*/
	

	
	if (unidades > 100 ){
	
	precio_3 = ( precio - (precio * INTERES3) );  
	  
	  if (precio > 700 ){
	  	
	  	precio = (precio - (precio * (INTERES3 + INTERES2)));
	  	
	  	descuento = Descuentos::maximo;
	  
	  }	
	  	
	  	else {
	  		
	  		descuento = Descuentos::medio;
		  	
	  	}
	  
	}
	else {
		
		descuento = Descuentos::nulo;
	  	
	}	
	
	switch(descuento){
		case Descuentos::maximo:
			cout<< "\nEl precio tiene un descuento del 5%,"
	  	   <<" su precio ahora es de: " << precio <<" euros." ;
	  	   break;
	  	   
	  	case Descuentos::medio:
			cout<< "\nEl precio tiene un descuento del 3%,"
	  	   <<" su precio ahora es de: " << precio_3 <<" euros." ;
	  	   break;
	  	   
	  	case Descuentos::nulo:
			cout<< "\nEl precio no tiene descuento,"
	  	   <<" sigue costando: " << precio <<" euros.";
	  	   break;
			
	}
		 
	cout << "\n";
	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
