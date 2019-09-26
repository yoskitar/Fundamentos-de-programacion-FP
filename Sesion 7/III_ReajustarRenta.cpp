/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/*       
         Sesión 01-07.
         Problema número 7:
            leed datos fiscales de una persona y reajustar su renta
            bruta según una serie de criterios estipulados:
              ·-3% de retención fiscal para autónomos.
              ·Si no es autónomo:
                 ·+1% de retención a pensionistas.
                 ·+2% de retención al resto de trabajadores:
                    ADICIONAL:
                       ·+2% si renta bruta < 20.000€
                       ·+2.5% casados con renta bruta > 20.000€
                       ·+3% solteros con renta bruta > 20.000€
         Todo ello mediante la implementación de funciones para
         controlar la respuesta a las cuestiones.
         
*/
/*********************************************************************/


#include <iostream>     // Inclusión de los recursos de E/S.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cctype>       //Inclusión de reucrsos de mayúsculas.
#include <string>       //Inclusión de recursos de tipo string.

using namespace std; 

//Función con un filtro para controlar que se introduce tan solo
//o una 's' o una 'n', con independencia de ser mayúscula o minúscula;
//y una estructura condicional que devuelve un valor true o false en función
//del carácter introducido.
bool LeeOpcion2Alternativas(string mensaje){
	
	char opcion;
	bool opcion_b;
	
	do{
		
	cout << mensaje;	
	cin >> opcion;
	opcion = toupper(opcion);
	
   }while(opcion != 'N' && opcion != 'S');
	
	
	if(opcion == 'S'){
		
	opcion_b = true ;
	
   }
   
   else{
   	
   	opcion_b = false;
   	
   }
   

	return opcion_b;

}

//Filtro para controlar la entrada de datos.
int Filtro(string mensaje){
	
   double entero;

	do{
		
		cout << mensaje;
		cin >> entero;
		
	
	}while( entero<0 );
	
	
	return entero;

}


int main(){ //Programa principal.


   //Declaración de variables.
   
   const double RET_AUTON = -3.0;            //Retención si eres autonomo.
   const double RET_PENSION = 1.0;          //Retención si eres pensionista.
   const double RET_NO_PENSION = 2.0;      //Retención si no eres pensionista.
   const double COND_20000 = 20000;       //Condicion para aplicar retencion.
   const double RET_20000 = 2.0;         //Retencion si no superas los 20000€.
   const double RET_SOLTERO = 3.0;      //Retención si eres soltero.
   const double RET_CASADO = 2.5;      //Retención si eres casado.
   
   //Variables para la entrada y salida de datos.
   double renta_bruta;
	double renta_neta;
	double retencion_inicial;
	double retencion_final;
	
	
	bool autonomo;      //Expresiónes lógicas para controlar
	bool pensionista;   //los condiconales.
	bool casado;        
	
	
	//Entrada de datos controlada por las funciones anteriormente definidas..
	
   renta_bruta = Filtro("\nIntroduzca su renta bruta: ");
   retencion_inicial = Filtro("\nIntroduzca la rentencion inicial: ");
	
	cout << "\nIntroduzca una 's' (sí) o una 'n' (no) para responder "
	<< " a las siguientes cuestiones: ";
	
	autonomo = LeeOpcion2Alternativas("\n¿Es un trabajador autonomo?: ");
	pensionista = LeeOpcion2Alternativas("\n¿Es pensionista?: ");
	casado = LeeOpcion2Alternativas("\n¿Esta casado?: ");

	
	//Cálculos.
   //En caso de que el valor de las expresiones lógicas sea  true, 
   //se van realizando los cálculos correspondientes para
   //hallar la retención fnal a aplicar al final del programa.
	if ( autonomo ){
	
	  retencion_final = retencion_inicial + RET_AUTON;
	
	}
	
	else{
		
		if ( pensionista ){
			
			retencion_final = retencion_inicial + RET_PENSION;
			
		}
		
		else{
			
			retencion_final = retencion_inicial + RET_NO_PENSION;
			
		}
	}
	
	if ( renta_bruta > COND_20000){
		
		if ( casado ){
		
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
   
   
	
   return(0);
   
}
	
	
	
	
	
	
	
