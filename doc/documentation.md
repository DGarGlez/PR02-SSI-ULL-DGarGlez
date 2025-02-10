# Documentación de main.cc

## Descripción

Este archivo contiene la implementación de funciones para limpiar texto y expandir claves para el cifrado Vigenère. Las funciones incluidas permiten limpiar un texto de caracteres no alfabéticos y convertirlo a mayúsculas, así como expandir una clave para que coincida con la longitud del texto a cifrar y cifrar y descifrar el mensaje.

## Constantes

- `const string ALFABETO = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";`
  - Alfabeto utilizado para el cifrado Vigenère.
- `const int MODULO = 26;`
  - Tamaño del alfabeto utilizado (sin considerar la letra Ñ).

## Funciones

### `string limpiarTexto(const string& texto)`

Limpia un texto de caracteres no alfabéticos y los convierte a mayúsculas.

- **Parámetros:**
  - `texto`: Texto a limpiar.
- **Retorno:**
  - Texto limpio y en mayúsculas.

### `string expandirClave(const string& clave, int longitudTexto)`

Expande una clave para que coincida con la longitud del texto a cifrar.

- **Parámetros:**
  - `clave`: Clave original.
  - `longitudTexto`: Longitud del texto a cifrar.
- **Retorno:**
  - Clave expandida.

### `string cifrarVigenere(const string& texto, const string& clave)`

Cifra un texto utilizando el cifrado Vigenère.

- **Parámetros:**
  - `texto`: Texto a cifrar.
  - `clave`: Clave para el cifrado.
- **Retorno:**
  - Texto cifrado.

### `int main()`

Función principal que ejecuta el programa.

- **Retorno:**
  - Código de retorno del programa.