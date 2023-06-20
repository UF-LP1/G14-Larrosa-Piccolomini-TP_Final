#include "headers.h"

#include "cANPA.h"
#include "cRegistro.h"
#include "cProtesis.h"

#include "cLugar.h"
#include "cPersona.h"

#include "cFabricante.h"
#include "cHospital.h"
#include "cOrtopedia.h"

// PARA HACER:
// - Creacion de registros por cada vez que se asigne una protesis a un paciente
// 
// - Francia
// 
// - La parte del medico a la hora de dar el visto bueno a la asignacion de la protesis al paciente
// 
// - El guardado de los registros en el ANPA
// 
// - El cambio del formato de fechas de los registros de time_t a struct tm
//   (Y su lectura usando string stream)
// 
// - Empezar a declarar y asignar objetos en el main, es lo mas engorroso de todo
// 
// - Hacer que los fabricantes "fabriquen" una protesis en caso de que las ortopedias no tengan stock o no haya sido encontrada
// 
// - Hacer los getters y setters necesarios donde se los use
// 
// - Generar (al menos una) custom exception
//
// - Establecer friendship entre clases que se nos haya pasado

void menu();

int main(void) {
    cANPA* anpa = new cANPA();
    cHospital* hosp1 = new cHospital("Italiano", "Alem 100");
    cHospital* hosp2 = new cHospital("Pedro Mallo","Corrientes 200");
    
    // (const string, const string, const string, string, cHospital*,double, string,)
    // Si no tiene alergias o un radio amputado, por default va vacio
    cPaciente* pac1 = new cPaciente("Matias", "Larrosa", "27/02/2001", "291", hosp1);
    cPaciente* pac2 = new cPaciente("Lionel","Messi", "24/06/1987","011", hosp1);

    *anpa + *hosp1;
    *anpa + *hosp2;

    try {
        *anpa + *pac1;
        *anpa + *pac2;
        *anpa + *pac1;
    }
    catch (exception e) {
        cout << e.what() << endl;
    }

    // NOTA-> Es horrible como queda el listado, pero es funcional, asi que worth it
    anpa->listarPacientes();

    // Por como estan armados los constructores, con solo el delete del anpa alcanza
    delete anpa;
    return 0;
}

void menu() {
    // aca va el cout con todas las opciones que va a tener nuestro menu
}