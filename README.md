# Keylogger en C
Este proyecto es un Keylogger en C que captura las teclas presionadas en Linux y las guarda en un archivo de texto (.txt).

## Contenido
- [Descripción](#descripción)
- [Instrucciones de uso](#instrucciones-de-uso)
- [Supuestos del programa](#supuestos-del-programa)
- [Casos de uso](#casos-de-uso)
- [Advertencias legales](#advertencias-legales)

## Descripción
El keylogger caotura las letras presionadas por el usuario y las guarda en un archivo de registro. Utiliza la API de entrada de Linux para leer los eventos de teclado directamente desde el teclado.

## Instrucciones de uso
### Requisitos
- Se requiere un dispositivo con acceso a "/dev/input/" y contar con permisos de superusuario.
- Compilador de C.

### Compilación
Para compilar el código se usa el comando: 
gcc -o jeylogger keylogger.c

### Ejecución
Ya que el acceso a los dispositivos de entrada necesitan permisos de superusuario se debe ejecutar como superusuario, el código a utilizar es el siguiente: 
sudo ./keylogger

### Detener ejecución
Para detener el proceso se usa "Ctrl+C".

### Acceso a logs
El archivo de texto en el que se registran las teclas presionadas por el usuario se encuentra en la ruta escrita en el código. 
Esta ruta se debe modificar antes de compilar el programa y remplazarla con la ruta de su preferencia.

## Supuestos del programa
- El código está diseñado para Linux, no funcionará en algún otro sistema operativo.
- El archivo de texto debe tener permisos de escritura para el usuario que ejecuta el programa.
- El código solo mapea las teclas alfanuméricas y las teclas especiales 'enter' y 'space'.

## Casos de uso
### Monitoreo personal
Puede ser utilizado por un usuario para monitorear sus propias entradas de teclado.

### Estudio de seguridad
Puede ser utilizado en un entorno controlado para analizar su funcionamiento y así encontrar maneras de detectarlos o prevenirlos.

### Desarrollo de software de seguridad
Puede servir como base para desarrollar software complejo que tenga la capacidad de detectar y neutralizar amenazas similares.

## Advertencias legales
El mal uso de este programa es ilegal y conlleva consecuencias legales graves, por lo tanto solo debe ser utilizado con fines educativos o en situaciones donde se tenga el consentimiento explícito de los afectados.
Este programa fue creado con fines educativos, la autora del código no se responsabiliza por el uso indebido del mismo.
