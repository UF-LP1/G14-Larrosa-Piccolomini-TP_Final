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
// - Verificar que los deletes sean efectivos a mas no poder
//
// - Hacer los getters y setters necesarios donde se los use
// 
// - Dearrollar los metodos "imprimir" y "toString" de casi todas las clases
// 

int main(void) {
    cANPA* anpa = new cANPA();

    

    delete anpa;
    return 0;
}