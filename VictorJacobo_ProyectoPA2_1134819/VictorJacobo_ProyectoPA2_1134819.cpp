
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
#include <list>

using namespace std;
using std::cout;
using std::cin;

void Buscar(list<string>Registro)
{
    fstream fout;
    string nuevo = "";
    fout.open("registro.csv", ios::out | ios::app);

    string actualizar;
    list<string> RegistroTemp;
    int n;
    cout << "Ingrese el medicamento a buscar. \n";
    cin >> actualizar;

    while (n > Registro.size())
    {
        RegistroTemp.push_front(Registro.front());
        if (actualizar == Registro.front())
        {
            RegistroTemp.push_front(actualizar);
            cout << actualizar;
        }
        else 
        {
            cout << "Medicamento no encontrado. \n";
        }

    }
    Menu();
}

void ActualizarMedicamento(list<string>Registro)
{
    fstream fout;
    string nuevo = "";
    fout.open("registro.csv", ios::out | ios::app);

    string actualizar;
    list<string> RegistroTemp;
    int n;
    cout << "Ingrese el medicamento a actualizar: \n";
    cin >> actualizar;

    while (n > Registro.size())
    {
        RegistroTemp.push_front(Registro.front());
        if (actualizar == Registro.front())
        {
            RegistroTemp.push_front(actualizar);
            cout << "Medicamento Actualizado. \n";
        }
        
    }
    std::ofstream ofs;
    ofs.open("registro.csv", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    while (n > Registro.size())
    {
        fout << RegistroTemp.front() << ",";
        fout << "\n";
        RegistroTemp.pop_front();
    }
}

void IngresarMedicamento(list<string>Registro)
{
    fstream fout;
    string nuevo;
    fout.open("registro.csv", ios::out | ios::app);

    cout << "ingrese el medicamento con su proveedor y precio en Q. \n";
    cin >> nuevo;
    Registro.push_front(nuevo);
    fout << nuevo << ",";
    fout << "\n";

    
    cout << "===================================== \n";
    cout << "Medicamento ingresado correctamente. \n";
    cout << "\n";
    std::cin;
    Menu();
}

void LeerRegistro(int n)
{
    int j, i;
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    list<string> Registro;
    string line, word, temp;
    fstream fin;
    fin.open("registro.csv", ios::in);
    //cout << "Estas son las estampas obtenidas: \n";
    cout << "\n";
    cout << "\n";
    while (fin >> temp)
    {

        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ','))
        {
            Registro.push_front(word);
        }

    }
    j = 0;
   
    switch (n) {
    case 1:
        IngresarMedicamento(Registro);
        break;
    case 2:
        ActualizarMedicamento(Registro);
        break;
    case 3:
        Buscar(Registro);
        break;
    case 4:
        LeerRegistro(n);
        break;
    case 5:

        break;
    case 6:

        break;

    default:
        cout << "Error en seleccion \n";

        Menu();
        break;
    }
    
}

void Mostrar(list<string>Registro)
{
    int i;
    list<string>Registro2;

    cout << "Este es todo el registro.\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";

    while (i < Registro.size())
    {
        cout << Registro.front() << " \n";
        cout << "\n";
        Registro2.push_front(Registro.front());
        Registro.pop_front();
        i++;

    }
}



void Menu() 
{
    int n;
    cout << "Para registrar un nuevo medicamento presione 1.\n";
    cout << "Para actualizar los detalles de un medicamento presione 2.\n";
    cout << "Para consultar un medicamento presione 3.\n";
    cout << "Para generar un archivo con todos los medicamentos presione 4.\n";
    cout << "Para calcular el precio promedio de los medicamentos presione 5.\n";
    cout << "Para buscar el medicamento con el precio mas alto de un proveedor presione 6.\n";
    cout << "\n";
    cin >> n;

    switch (n) {
    case 1:
        LeerRegistro(n);
        break;
    case 2:
        LeerRegistro(n);
        break;
    case 3:
        LeerRegistro(n);
        break;
    case 4:
        LeerRegistro(n);
        break;
    case 5:
        LeerRegistro(n);
        break;
    case 6:
        LeerRegistro(n);
        break;

    default:
        cout << "Error en seleccion \n";

        Menu();
        break;
    }
    
}

int main()
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "       Bienvenido al Sistema de datos de la farmacia      \n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\n";
    cout << "\n";

    Menu();
}

