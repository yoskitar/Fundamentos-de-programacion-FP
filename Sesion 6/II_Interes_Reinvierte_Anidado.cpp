/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/*    
       Sesi�n 01-06.
       Problema n�mero 31:
         Dados un inter�s, un capital y un n�mero de a�os,
         decir el capital obtenido en cada a�o hasta el introducido,
         y con cada uno de los intereses hasta llegar al introducido.
			      
*/  
/*********************************************************************/


#include <iostream>              //Inclusi�n de recursos de E/S
#include <cstdlib>              // Inclusi�n de llamadas al sistema.


using namespace std;

int main(){                    //Programa principal.
           
	                   
	// Declara variables para guardar.   
	               
	double capital_variado;       //Capital acumulado cada a�o. 
	int interes;                  //Inter�s introducido.  
	double capital_total;         //Total de capital obtenido.
	double capital_inicial;       //Capital introducido.
	double interes_double;        //Inter�s intoducido.
	
	int anios;           //N�mero de a�os del lazo fijo. 
	int inter_inicio;    //Inicio del primer ciclo for.
	int anio_inicio;     //Inicio del segundo ciclo for.
	            
	bool valores_correctos_capital;    //Condicionales para los
	bool valores_correctos_interes;    //filtros.
	bool valores_correctos_anios;        
	                           
	//Entrada de datos.
	
	
	/*
	Filtro para controlar que los valores del capital e inter�s
	intoducidos son correctos.
	*/
	
	
	do{
		
	cout << "\nIntroduzca el capital que desea depositar a plazo fijo anual: ";  
	cin >> capital_inicial;
	
	valores_correctos_capital = ( capital_inicial > 0);
	
	}while(!valores_correctos_capital);
	
	do{
		
	cout << "Introduzca el interes de su plazo fijo anual: ";              
	cin >> interes_double;
	
	interes = interes_double;
	
	valores_correctos_interes = ( interes > 0 ) && 
	(interes_double - interes == 0);
	
	}while(!valores_correctos_interes);
	
	do{
		
	cout << "Introduzca el numero de a�os: ";              
	cin >> anios;
	
	valores_correctos_anios = ( anios>0 );
	
   }while(!valores_correctos_anios);
	
	
	
	//C�lculos y resultados.
	
	/*
	Anidamiento de ciclos for en el que mientras el interes inicio 
	no sea superior al inter�s m�ximo introducido, nos dar� la
	salida correspondiente del capital a dicho inter�s, en
	funci�n del segundo ciclo for atendidendo al n�mero de 
	a�os que se depositar� el capital a plazo fijo.
	*/
	
	for( inter_inicio = 1 ; inter_inicio <= interes ; inter_inicio++ ){
		
		cout << "\nCalculos realizados al " << inter_inicio 
		<< " %:" <<"\n";
		
		capital_variado = capital_inicial;
		
	
	   for( anio_inicio = 1 ; anio_inicio <= anios ; anio_inicio++ ){
		
		capital_total = capital_variado + 
	   ( capital_variado * inter_inicio / 100 );
	   cout <<"\tDinero obtenido en el anio numero "
	   <<anio_inicio << " = " << capital_total << "\n";
	   
	   capital_variado = capital_total;
	  
	   }
	
	}
	
	cout << "\n";

	//Pausa del programa.
   
   system("pause");
   
	return (0);
	
}
