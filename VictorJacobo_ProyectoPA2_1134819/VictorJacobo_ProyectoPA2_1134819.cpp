
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;
using std::cout;
using std::cin;

void LeerRegistro(int n)
{
    int j, i;
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    stack<string> album;
    stack<string> categoria;
    stack<string> stamp;
    string line, word, temp;
    fstream fin;
    fin.open("album.csv", ios::in);
    cout << "Estas son las estampas obtenidas: \n";
    cout << "\n";
    cout << "\n";
    while (fin >> temp)
    {

        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ','))
        {
            album.push(word);
        }

    }
    j = 0;
    while (!album.empty())
    {

        cout << album.top() << "";
        i = j % 2;
        if (i == 0)
        {
            stamp.push(album.top());
        }
        else
        {
            categoria.push(album.top());
        }
        album.pop();

    }
    if (n == 1)
    {
        Buscar(categoria, stamp);
    }
    else if (n == 2)
    {
        Mostrar(categoria, stamp);
    }
}

void Mostrar()
{
    
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
    switch (n)
    {
    case 1:
        LeerRegistro(n);
        break;
    case 2:
        LeerRegistro(n);
        break;
    default:
        std::cout << "Ingrese un numero valido.\n";
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

