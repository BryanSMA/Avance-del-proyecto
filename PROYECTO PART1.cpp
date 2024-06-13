#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct Empleado {
    string nombre;
    string apellido1;
    string apellido2;
    string numeroSegu;
    int edad;
    string departamento;
    int antiguedad;
}empleados[50];

int main() {
  
    int numE;

    cout << "Ingrese el numero de empleados: ";
    cin >> numE;
    fflush(stdin); 

    for (int i = 0; i < numE; i++) {
        cout << "Ingrese los datos del empleado " << i + 1 << ":" << endl;

        char entrada[100];

        cout << "Nombre: ";
        cin.getline(entrada, 100);
        empleados[i].nombre = entrada;

        cout << "Primer apellido: ";
        cin.getline(entrada, 100);
        empleados[i].apellido1 = entrada;

        cout << "Segundo apellido: ";
        cin.getline(entrada, 100);
        empleados[i].apellido2 = entrada;

        cout << "Numero de Seguridad Social: ";
        cin.getline(entrada, 100);
        empleados[i].numeroSegu = entrada;

        cout << "Edad: ";
        cin >> empleados[i].edad;
        fflush(stdin); 

        cout << "Departamento: ";
        cin.getline(entrada, 100);
        empleados[i].departamento = entrada;

        cout << "Antiguedad : ";
        cin >> empleados[i].antiguedad;
        fflush(stdin); 

 
    }


    for (int i = 0; i < numE - 1; i++) {
        for (int j = 0; j < numE - i - 1; j++) {
            if (strcmp(empleados[j].apellido1.c_str(), empleados[j + 1].apellido1.c_str()) > 0 ||
                (strcmp(empleados[j].apellido1.c_str(), empleados[j + 1].apellido1.c_str()) == 0 && 
                 strcmp(empleados[j].apellido2.c_str(), empleados[j + 1].apellido2.c_str()) > 0) ||
                (strcmp(empleados[j].apellido1.c_str(), empleados[j + 1].apellido1.c_str()) == 0 && 
                 strcmp(empleados[j].apellido2.c_str(), empleados[j + 1].apellido2.c_str()) == 0 &&
                 strcmp(empleados[j].nombre.c_str(), empleados[j + 1].nombre.c_str()) > 0)) {
                
                Empleado temp = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = temp;
            }
        }
    }

    int opc;
    char entrada[60];

    do {
        cout << "Menu de busqueda:"<<endl;
        cout << "1. Buscar por nombre"<<endl;
        cout << "2. Buscar por primer apellido"<<endl;
        cout << "3. Buscar por segundo apellido"<<endl;
        cout << "4. Buscar por numero de Seguridad Social"<<endl;
        cout << "5. Buscar por edad"<<endl;
        cout << "6. Buscar por departamento"<<endl;
        cout << "7. Salir"<<endl;
        cout << "Seleccione una opcion: "<<endl;
        cin >> opc;
        fflush(stdin); 

        if (opc >= 1 && opc<= 6) {
            string campo;
            switch (opc) {
                case 1:
                    campo = "nombre";
                    break;
                case 2:
                    campo = "apellido1";
                    break;
                case 3:
                    campo = "apellido2";
                    break;
                case 4:
                    campo = "numeroSeguridadSocial";
                    break;
                case 5:
                    campo = "edad";
                    break;
                case 6:
                    campo = "departamento";
                    break;
               
                default:
                    cout << "numero incorreto ." << endl;
                    continue;
            }

            cout << "Ingrese el valor de busqueda: ";
            cin.getline(entrada, 60);
            string valor = entrada;

            for (int i = 0; i < numE; i++) {
                bool enc = false;
                if (campo == "nombre" && strcasecmp(empleados[i].nombre.c_str(), valor.c_str()) == 0) {
                    enc = true;
                } else if (campo == "apellido1" && strcasecmp(empleados[i].apellido1.c_str(), valor.c_str()) == 0) {
                    enc = true;
                } else if (campo == "apellido2" && strcasecmp(empleados[i].apellido2.c_str(), valor.c_str()) == 0) {
                    enc = true;
                } else if (campo == "numeroSeguridadSocial" && strcasecmp(empleados[i].numeroSegu.c_str(), valor.c_str()) == 0) {
                    enc = true;
                } else if (campo == "edad") {
                    int edadB;
                    cin >> edadB;
                    fflush(stdin); 
                    if (empleados[i].edad == edadB) {
                        enc= true;
                    }
                } else if (campo == "departamento" && strcasecmp(empleados[i].departamento.c_str(), valor.c_str()) == 0) {
                    enc = true;
                } else if (campo == "antiguedad") {
                    int antiB;
                    cin >> antiB;
                    fflush(stdin); 
                    if (empleados[i].antiguedad == antiB) {
                        enc= true;
                    }
                }

                if (enc) {
                    cout << "Nombre: " << empleados[i].nombre << " " << empleados[i].apellido1 << " " << empleados[i].apellido2 << endl;
                    cout << "Numero de Seguridad Social: " << empleados[i].numeroSegu << endl;
                    cout << "Edad: " << empleados[i].edad << endl;
                    cout << "Departamento: " << empleados[i].departamento << endl;
                    cout << "Antiguedad: " << empleados[i].antiguedad << " años" << endl;
                   
                }
            }
        } else if (opc == 7) {
            cout << "fin del programa" << endl;
        } else {
            cout << "Opcion no valida." << endl;
        }
    } while (opc!= 7);

}
