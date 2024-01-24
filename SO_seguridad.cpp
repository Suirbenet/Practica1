#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <cstdio> // eliminar archivo

using namespace std;

    string string_a_binario(string cadena_texto) {

        string cadenabinaria;

        cadenabinaria += bitset<8>('r').to_string();

            for (char c : cadena_texto) {
                cadenabinaria += bitset<8>(c).to_string();
            }

        return cadenabinaria;
}

    string binario_a_string(string cadena_binaria) {
        
    string informacion, key;

    cout << "\t Ingresa el pasword : ";
    cin >> key;

    bitset<8> byte(cadena_binaria.substr(0, 8));
    informacion = static_cast<char>(byte.to_ulong());

    if (informacion == key)
    {
        string informacion;
        
        for (int i = 0; i < cadena_binaria.length()-1; i += 8) {
            bitset<8> byte(cadena_binaria.substr(i, 8));
            if (i!=0){
                informacion += static_cast<char>(byte.to_ulong());
            }
        }
        return informacion;
    }
    
    else
    {
        return "No se puede leer el archivo codigo incorrecto";
    }

    }


int main() {

    string contenidoArchivo;
    string op;
    int cont=0;
    

    do{
        inicio:
        system("cls");
        cout << endl << endl << "\t\t\tPrograma que lee un archivo encriptado" << endl << endl;

        cout << "1.- Codificar." << endl;
        cout << "2.- Decodificar." << endl;
        cout << "3.- Salir." << endl;
        cout << "Opcion : ";
        cin >> op;

    if (op == "1")
    {
        string contenidoArchivo;
        ifstream archivo_in("ejemplo.txt");
        if (archivo_in.is_open()) {

            string linea;
            while (getline(archivo_in, linea)) {
                contenidoArchivo += linea + "\n";
            }
            archivo_in.close();
        }

        else {
            cerr << endl << "\tEl archivo a codificar no existe.\n" << endl << endl;

            system("pause");

            goto inicio;
        }

        string cadenabinaria = string_a_binario(contenidoArchivo);

        ofstream archivo_out("info_codificada.txt");

        if (archivo_out.is_open()) {
            archivo_out << cadenabinaria << endl;
            archivo_out.close();
        }
        else {
            cerr << "Error al abrir el archivo para codificar.\n";
        }

        cout << endl << "\tCodificacion Exitosa" << endl;
        system("pause");
    }

    else if (op == "2")
    {
        
        string contenidoArchivo_desencriptado;
        ifstream archivo_encrip_lectura("info_codificada.txt");

        if (archivo_encrip_lectura.is_open()) {
            string linea;
            while (getline(archivo_encrip_lectura, linea)) {
                contenidoArchivo_desencriptado += linea + "\n";
            }
            archivo_encrip_lectura.close();
        
        


            string resultado = binario_a_string(contenidoArchivo_desencriptado);
            cout << endl << "\tEl contenido del archivo es : " << endl << endl << resultado << endl << endl << endl;
        
        
   
        
        
        
        }
        else {
            cerr <<endl<< "\t No existe archivo a decodificar.\n"<< endl;
           
        }
         
        system("pause");
    }

    else if (op == "3")
    {
        cout << "Adios =)"<<endl<< endl;
        system("pause");
    }

    else
        {
        cout << "Opcion incorrecta" << endl << endl;
        system("pause");
        }

    } while (op!="3");
    

    return 0;
}