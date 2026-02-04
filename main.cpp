#include <iostream>
#include "cuentas.h"
//g++ main.cpp cuentas.cpp -o banco 
//.\banco
int main() {
    Cuentas cuentas[100];

    int contador = CargarCuentas(cuentas);
    int opcion;

    std::cout << "Cuentas cargadas: " << contador << std::endl;

    do {
        std::cout << "\nMenu de Cuentas Bancarias\n";
        std::cout << "1. Crear Cuenta\n";
        std::cout << "2. Buscar Cuenta\n";
        std::cout << "3. Mostrar Saldo\n";
        std::cout << "4. Ingresar Saldo\n";
        std::cout << "5. Retirar Saldo\n";
        std::cout << "6. Mostrar Todas las Cuentas\n";
        std::cout << "7. Dar de baja una cuenta\n";
        std::cout << "8. Editar Titular de la Cuenta\n";
        std::cout << "9. Reactivar Cuenta\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;




        switch (opcion) {
        case 1:
            CrearCuenta(cuentas, contador);
            GuardarCuentas(cuentas, contador);
            break;

        case 2: {
            int id;
            if (contador == 0) {
                std::cout << "No hay cuentas disponibles.\n";
                break;
            }
            std::cout << "Ingrese ID: ";
            std::cin >> id;

            int pos = BuscarCuenta(cuentas, contador, id);
            if (pos == -1) {
                std::cout << "Cuenta no encontrada\n";
            } else {
                std::cout << "Nombre: " << cuentas[pos].nombre << "\n";
                std::cout << "Saldo: $" << cuentas[pos].saldo << "\n";
            }
            break;
        }
        case 3:
            MostrarSaldo(cuentas, contador);
            break;
        case 4: {
            DepositarSaldo(cuentas, contador);
            break;
        }
        case 5: {
            RetirarSaldo(cuentas, contador);
            break;
        }
        case 6:
            MostrarTodasC(cuentas, contador);
            break;
        case 7:
            BajaCuenta(cuentas, contador);
            break;
        case 8: {
            EditarTitular(cuentas, contador);
            break;
        }
        case 9: {
            ReactivarCuenta(cuentas, contador);
            break;
        }
        
        case 0:{
            std::cout << "Saliendo del programa.\n";
            break;
        }
         default:
        std::cout << "Opcion invalida, intente de nuevo.\n";
        break;
    }

    } while (opcion != 0);

    GuardarCuentas(cuentas, contador);
    return 0;
}
