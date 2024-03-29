#include "headers.h"

#include "cANPA.h"
#include "cRegistro.h"
#include "cProtesis.h"

#include "cLugar.h"
#include "cPersona.h"

#include "cFabricante.h"
#include "cHospital.h"
#include "cOrtopedia.h"

int menu(void);

int main(void) {
    cANPA* anpa = new cANPA();
    cHospital* hosp1 = new cHospital("Italiano", "Alem 100");
    cHospital* hosp2 = new cHospital("Pedro Mallo", "Corrientes 200");

    // Si se aclara que tiene alergias o un cierto radio de miembro amputado, por default va vacio
    cPaciente* pac1 = new cPaciente("Matias", "Larrosa", "27/02/2001", "291", hosp1, 2.0, SupDer);
    cPaciente* pac2 = new cPaciente("Lionel", "Messi", "24/06/1987", "011", hosp1, 5.0, InfIzq);
    cPaciente* pac3 = new cPaciente("Franco", "Martinez", "16/06/2001", "291", hosp2, 5.5, SupIzq);
    cPaciente* pac4 = new cPaciente("Alvaro", "Matone", "25/10/2002", "291", hosp2, 4, InfDer);

    // No hay fabricantes repetidos por ortopedia, generaria conflictos
    cOrtopedia* orto1 = new cOrtopedia("Ortopedia1", "Maria");
    cFabricante* fabr1 = new cFabricante("Jose", "Perez", "234");

    cQuirurgica* prote1 = new cQuirurgica(2.0, "27/7/2019", fabr1, SupDer, "fibraCarbono");
    cQuirurgica* prote2 = new cQuirurgica(5.0, "21/7/2019", fabr1, SupIzq, "acero");
    cQuirurgica* prote3 = new cQuirurgica(5.5, "08/7/2019", fabr1, InfIzq, "aerogel");
    cQuirurgica* prote4 = new cQuirurgica(5.0, "09/7/2019", fabr1, InfDer, "bronce");

    *anpa + *hosp1;
    *anpa + *hosp2;

    *anpa + *orto1;

    *anpa + *pac1;
    *anpa + *pac2;
    *anpa + *pac3;
    *anpa + *pac4;

    *orto1 + *prote3;
    *orto1 + *prote4;

    pac1->setProtesis(*prote1);
    pac3->setProtesis(*prote2);

    *orto1 + *fabr1;

    try {
        cout << "Si quiero agregar un paciente que ya esta registrado tira:" << endl;
        *anpa + *pac1;
    }
    catch (exception e) {
        cout << e.what() << endl;
    }

    orto1->listarProtesis();

    int aux = 0;
    do {
        aux = menu();
        switch (aux) {
        case 1:
            anpa->agregarPacienteParticular();
            cout << "\n\n";
            break;
        case 2:
            cout << anpa << "\n\n";
            break;
        case 3:
            anpa->buscarPorHospital();
            cout << "\n\n";
            break;
        case 4:
            anpa->buscarPorProtesis();
            cout << "\n\n";
            break;
        }
    } while (aux != 5);

    delete anpa;
    return 0;
}

int menu(void) {
    int opcion = 0;

    cout << "\n\nMENU" << endl;

    cout << "1-Agregar Paciente\n2-Listar Pacientes\n";
    cout << "3-Buscar Paciente segun hospital\n4-Buscar Pacientes segun Protesis\n";
    cout << "5-Cerrar programa" << endl;

    cin >> opcion;
    return opcion;
}