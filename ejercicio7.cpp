#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, int> contador_errores;
    string linea;
    
    // Abre el archivo de log para leer los errores.
    ifstream archivo_log("C:/Users/renat/Desktop/ejercicio7/ejercicio7.txt");
    if (archivo_log.is_open()) {
        while (getline(archivo_log, linea)) {
            // Busca la palabra 'ERROR' en la línea.
            size_t pos = linea.find("ERROR");
            if (pos != string::npos) {
                // Extrae el tipo de error y actualiza el contador.
                string tipo_error = linea.substr(0, linea.find(":"));
                contador_errores[tipo_error]++;
            }
        }
        archivo_log.close();
    } else {
        cerr << "No se pudo abrir el archivo de log." << endl;
        return 1;
    }
    
    // Abre el archivo de salida para escribir el resumen.
    ofstream archivo_resumen("C:/Users/renat/Desktop/ejercicio7/resumen.txt");
    if (archivo_resumen.is_open()) {
        for (const auto& par : contador_errores) {
            archivo_resumen << par.first << ": " << par.second << endl;
        }
        archivo_resumen.close();
    } else {
        cerr << "No se pudo abrir el archivo de resumen." << endl;
        return 1;
    }
    
    cout << "El resumen de errores ha sido escrito en resumen.txt" << endl;
    return 0;
}

