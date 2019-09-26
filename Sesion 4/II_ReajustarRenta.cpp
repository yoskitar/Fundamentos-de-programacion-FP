/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/*       
         Sesi�n 01-04.
         Problema n�mero 11:
            leed datos fiscales de una persona y reajustar su renta
            bruta seg�n una serie de criterios estipulados:
              �-3% de retenci�n fiscal para aut�nomos.
              �Si no es aut�nomo:
                 �+1% de retenci�n a pensionistas.
                 �+2% de retenci�n al resto de trabajadores:
                    ADICIONAL:
                       �+2% si renta bruta < 20.000�
                       �+2.5% casados con renta bruta > 20.000�
                       �+3% solteros con renta bruta > 20.000�
*/
/*********************************************************************/


#include <iostream>     // Inclusi�n de los recursos de E/S.
#include <cstdlib>     // Inclusi�n de llamadas al sistema.
#include <cctype>      //Inclusi�n de reucrsos de may�sculas.

using namespace std; 

//Clase para indicar los distintos casos.
enum class Costos {caso_interes, caso_valor_erroneo};

int main(){ // Programa Principal.
             
            
   // Declara variables para guardar.

   const double RET_AUTON = -3.0;            //Retenci�n si eres autonomo.
   const double RET_PENSION = 1.0;          //Retenci�n si eres pensionista.
   const double RET_NO_PENSION = 2.0;      //Retenci�n si no eres pensionista.
   const double COND_20000 = 20000;       //Condicion para aplicar retencion.
   const double RET_20000 = 2.0;         //Retencion si no superas los 20000�.
   const double RET_SOLTERO = 3.0;      //Retenci�n si eres soltero.
   const double RET_CASADO = 2.5;      //Retenci�n si eres casado.
   
   //Variables de car�cter para estipular cada caso en la condicional.
   char autonomo;
	char pensionista; 
	char estado_civil; 
	
	//Retenciones finales e iniciales y renta bruta e inicial.
	double renta_bruta;
	double renta_neta;
	double retencion_inicial;
	double retencion_final;
	
	         
   //Entrada de datos.
   
   cout << "\nPulsa la letra indicada para marcar dicha opci�n, o "
   << "cualquier otra para indicar la opcion contraria." << "\n";
   
   cout << "\n\t�Es un trabajador autonomo? (Y:yes) ";
   cin >> autonomo;
   
   cout << "\n\t�Es pensionista? (P:yes) ";
   cin >> pensionista;
   
   cout << "\n\t�Esta soltero o casado? (C:casado) ";
   cin >> estado_civil;
   
   cout << "\n\tIntroduzca su renta bruta: ";
   cin >> renta_bruta;
   
   cout << "\n\tIntroduzca la rentencion inicial: ";
   cin >> retencion_inicial;
   
   
	// C�lculos. 
	
	/*
	Estructura condicional en la que si la persona es aut�noma
	se aplica la retenci�n correspodiente; en caso de no serlo,
	puede ser pensionista o no, cada uno de los casos con la 
	aplicaci�n de sus respectivas retenciones.
	Formando otro condicional aparte, si la renta bruta de la 
	persona supera los 20.000�, encontramos los casos de si
	es soltero o casado, nuevamente cada uno con la aplicacion
	de su correspondiente retenci�n adicionl a las anteriores;
	y en caso de que la renta no supere esos 20.000�, estariamos
	ante el ultimo caso con su debida retencion.
	Por ultimo se calcula la renta neta, aplicando a la renta 
	bruta las respectivas retenciones en funci�n de los
	valores introducidos por cada persona.
	*/
	
	if ((autonomo == 'Y') || (autonomo == 'y')){
	
	retencion_final = retencion_inicial + RET_AUTON;
	
	}
	
	else{
		
		if ((pensionista == 'P') || (pensionista == 'p')){
			
			retencion_final = retencion_inicial + RET_PENSION;
			
		}
		
		else{
			
			retencion_final = retencion_inicial + RET_NO_PENSION;
			
		}
	}
	
	if ( renta_bruta > COND_20000){
		
		if ((estado_civil == ('C')) || (estado_civil == ('c'))){
		
			retencion_final = retencion_final + RET_CASADO;
			
		}
		
		else{
			
			retencion_final = retencion_final + RET_SOLTERO;
			
		}
	
	}
	
	else{
		
		retencion_final = retencion_final + RET_20000;
		
	}
	
	renta_neta = (renta_bruta - ((renta_bruta)*(retencion_final/100.0)));
		
   
   //Resultados.
   
   cout << "\nLa renta final del trabajador sera de: "
   << renta_neta <<" euros." "\n\n";
	
   //Pausa del programa.
   
   system("pause");
   
	return (0);
}
