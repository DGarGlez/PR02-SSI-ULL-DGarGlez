/**
 * @file main.cc
 * @brief Implementación de funciones para limpiar texto y expandir claves para el cifrado Vigenère.
 * 
 * Este archivo contiene las implementaciones de las funciones necesarias para limpiar un texto
 * de caracteres no alfabéticos y convertirlo a mayúsculas, así como para expandir una clave para el cifrado Vigenère.
 */
#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

const string ALFABETO = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int MODULO = 26; // Se considera sin la Ñ en este caso.

/**
 * @brief Limpia un texto de caracteres no alfabéticos y los convierte a mayúsculas.
 * 
 * @param texto Texto a limpiar.
 * @return Texto limpio y en mayúsculas.
 */
string limpiarTexto(const string& texto) {
    string resultado;
    for (char c : texto) {
        if (isalpha(c)) {
            resultado += toupper(c);
        } 
    }
    return resultado;
}

/**
 * @brief Expande una clave para que coincida con la longitud del texto a cifrar.
 * 
 * @param clave Clave original.
 * @param longitud Longitud del texto a cifrar.
 * @return Clave expandida.
 */
string expandirClave(const string& clave, int longitud) {
    string claveExpandida;
    for (int i = 0; i < longitud; ++i) {
        claveExpandida += clave[i % clave.length()];
    }
    return claveExpandida;
}

/**
 * @brief Cifra un texto utilizando el cifrado Vigenère.
 * 
 * @param texto Texto a cifrar.
 * @param clave Clave para cifrar el texto.
 * @return Texto cifrado.
 */
string cifrarVigenere(const string& texto, const string& clave) {
    string textoLimpio = limpiarTexto(texto);
    string claveExpandida = expandirClave(clave, textoLimpio.length());
    string cifrado;

    cout << "Texto claro:\t\t";
    int i = 0;
    for (char c : textoLimpio) {
        i++;
        cout << c;
        if (i % clave.size() == 0) {
            cout << " ";
            i = 0;
        }
    }
    cout << endl;

    for (size_t i = 0; i < textoLimpio.length(); ++i) {
        char letra = textoLimpio[i];
        char claveLetra = claveExpandida[i];
        int desplazamiento = claveLetra - 'A';
        char letraCifrada = ((letra - 'A' + desplazamiento) % MODULO) + 'A';
        cifrado += letraCifrada;
    }
    return cifrado;
}

/**
 * @brief Descifra un texto cifrado con el cifrado Vigenère.
 * 
 * @param textoCifrado Texto cifrado.
 * @param clave Clave para descifrar el texto.
 * @return Texto descifrado.
 */
string descifrarVigenere(const string& textoCifrado, const string& clave) {
    string claveExpandida = expandirClave(clave, textoCifrado.length());
    string descifrado;

    for (size_t i = 0; i < textoCifrado.length(); ++i) {
        char letra = textoCifrado[i];
        char claveLetra = claveExpandida[i];
        int desplazamiento = claveLetra - 'A';
        char letraDescifrada = ((letra - 'A' - desplazamiento + MODULO) % MODULO) + 'A';
        descifrado += letraDescifrada;
    }
    return descifrado;
}

int main() {
    string clave, texto;
    cout << "Introduce la palabra clave: ";
    getline(cin, clave);
    clave = limpiarTexto(clave);
    
    cout << "Introduce el texto a cifrar: ";
    getline(cin, texto);
    texto = limpiarTexto(texto);
    cout << endl;
    
    string textoCifrado = cifrarVigenere(texto, clave);

    cout << "Clave: \t\t\t";
    for (int i = 0; i <= texto.size() / clave.size(); i++) {
        cout << clave << " ";
    }
    cout << endl;
    cout << "Texto cifrado:\t\t";
    int i = 0;
    for (char c : textoCifrado) {
        i++;
        cout << c;
        if (i % clave.size() == 0) {
            cout << " ";
            i = 0;
        }
    }
    cout << endl;
    
    string textoDescifrado = descifrarVigenere(textoCifrado, clave);
    cout << "Texto descifrado:\t";
    int l = 0;
    for (char c : textoDescifrado) {
        l++;
        cout << c;
        if (l % clave.size() == 0) {
            cout << " ";
            l = 0;
        }
    }
    cout << endl;
    
    return 0;
}
