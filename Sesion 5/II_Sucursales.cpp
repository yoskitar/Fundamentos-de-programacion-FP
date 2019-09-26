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
       Problema número 24: 
		        Programa para calcular que sucursal ha conseguido
		        un mayor número de ventas, mediante ciclo while 
		        y filtros para introducir valores correctos.
           
			      
*/  
/*********************************************************************/


#include <iostream>              //Inclusión de recursos de E/S
#include <cstdlib>              // Inclusión de llamadas al sistema.


using namespace std;



int main(){                    //Programa principal.
           
	 
                
	// Declarción de variables para guardar.  
	
	const int sucursal_1 = 1;
   const int sucursal_2 = 2;
   const int sucursal_3 = 3;
	
	char producto;
	
	int sucursal; 
	int unidades;
	int sucursal_mayor;
	int unidades_mayor;
  
	int unidades_1 = 0;
   int unidades_2 = 0;
   int unidades_3 = 0;
   
   
	//Entrada de datos.
   
   //Filtro para introducir la sucursal correcta.
   
	 do{
	 cout << "Introduzca el numero de sucursal (1,2,3): ";
	 cin >> sucursal;
    }while(sucursal < -1 || sucursal > 3);
	
	/*
	Ciclo while para calcular el número de unidades vendidas
	por cada sucursal mediante una estructira condiional, que 
	se repetirá hasta que el valor introducido para la variable 
	sucursal sea -1. Dentro encontramos otro filtropara introducir 
	correctamente el producto.
	*/
	
	 while (sucursal != -1){
    
	 do{
	 cout << "Introduzca el codigo de producto (a,b,c): ";
	 cin >> producto;
    }while(producto <'a' || producto > 'c');
    
	 cout << "Introduzca la cantidad de unidades: ";
	 cin >> unidades;
	 
	
	 if (sucursal == 1){
	 
	   unidades_1 = unidades_1 + unidades;
	   
	 }
	 
	 else{
	 	
	   if(sucursal == 2){
	   	
	 	   
	      unidades_2 = unidades_2 + unidades;
	      
	   }
	   
	   else{
	 	
	      unidades_3 = unidades_3 + unidades;
	 
	   }
	 
	 }
	 
	 do{
	 cout << "Introduzca el numero de sucursal: ";
	 cin >> sucursal;
    }while(sucursal < -1 || sucursal > 3);
    
	}
	
	
	
	//Resultados.
	
	/*
	Estructura condicional para estudiar cada uno de los diez
	casos posibles de resultados.
	*/
	
	if( (unidades_1 > unidades_2) && (unidades_1 > unidades_3) ){
	 	
	    unidades_mayor = unidades_1;
	    sucursal_mayor = sucursal_1;
	    cout << "\nLa sucursal que mas unidades ha vendido es la "
      << sucursal_mayor << " con " << unidades_mayor 
		<< " unidades vendidas."
     	<< "\n\n";
	    
	   }
	   
	   else{
	 	
	     if(unidades_3>unidades_2 && unidades_3 > unidades_1){
	   	
		   unidades_mayor = unidades_3;
		   sucursal_mayor = sucursal_3;
		   cout << "\nLa sucursal que mas unidades ha vendido es la "
         << sucursal_mayor << " con " << unidades_mayor
			 << " unidades vendidas."
       	<< "\n\n";
		
		  } 
		
		  else{
			
			if(unidades_2 > unidades_3 && unidades_2 > unidades_1){
		   unidades_mayor = unidades_2;
		   sucursal_mayor = sucursal_2;
		   cout << "\nLa sucursal que mas unidades ha vendido es la "
         << sucursal_mayor << " con " << unidades_mayor 
			<< " unidades vendidas."
       	<< "\n\n";
		
		  }
		  
		  else{
		  	
		  	if(unidades_1 == unidades_2 && unidades_1 < unidades_3){
		  		unidades_mayor = unidades_3;
		  		sucursal_mayor = sucursal_3;
		  		cout << "\nLa sucursal que mas unidades ha vendido es la "
            << sucursal_mayor << " con " << unidades_mayor 
				<< " unidades vendidas."
       	   << "\n\n";
		  		
		  	}
		  	else{
			  
			  if (unidades_1 == unidades_2 && unidades_1 > unidades_3){
			  
			  unidades_mayor = unidades_1;
			  cout << "\nLas sucursales 1 y 2 tienen el mismo numero de ventas: " 
		     << unidades_mayor << " unidades venidas." << "\n";
			  
			  }
			  else{
			  
			  if(unidades_1 == unidades_3 && unidades_1 < unidades_2){
			  
			  unidades_mayor = unidades_2;
			  sucursal_mayor = sucursal_2;
			  cout << "\nLa sucursal que mas unidades ha vendido es la "
           << sucursal_mayor << " con " << unidades_mayor 
			  << " unidades vendidas."
           << "\n\n";
			  
			  }
			  else{
			  
			  if(unidades_1 == unidades_3 && unidades_1 > unidades_2){
			  
			  unidades_mayor = unidades_1;
			   cout<< "\nLas sucursales 1 y 3 tienen el mismo numero de ventas: " 
		      << unidades_mayor << " unidades vendidas." << "\n";
			  
			  }
			  else{
			  
			  if(unidades_2 == unidades_3 && unidades_2 < unidades_1){
			  
			  unidades_mayor = unidades_1;
			  sucursal_mayor = sucursal_1;
			  cout << "\nLa sucursal que mas unidades ha vendido es la "
           << sucursal_mayor << " con " << unidades_mayor 
			  << " unidades vendidas."
       	  << "\n\n";
			  
			  }
			  else{
			  
			  if(unidades_2 == unidades_3 && unidades_2 > unidades_1){
			  
			  unidades_mayor = unidades_2;
			  cout<< "\nLas sucursales 2 y 3 tienen el mismo numero de ventas: " 
		     << unidades_mayor << " unidades vendidas." << "\n";
			  
			  }
			  else{
			  	unidades_mayor = unidades_1;
			  cout << "\nLas sucursales 1, 2 y 3 tienen el mismo "
			  << "numero de ventas: " << unidades_mayor << " unidades venidas." 
			  << "\n";
			  
			  }
			   
			  }
			  
			  }
			  
			  }
			  
			  }
			   
			}
		  
		  }
		  
	    }
	 
	   }
   

	//Pausa del programa.
   
   system("pause");
   
	return (0);
	
}
