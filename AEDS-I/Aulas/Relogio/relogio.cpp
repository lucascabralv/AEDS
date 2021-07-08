#include "relogio.h"

Relogio::Relogio(){
    this->horas = 0;
    this->minutos = 0;
    this->segundos = 0;
}
Relogio::Relogio(int horas, int minutos, int segundos){
    this->horas = horas;
    this->minutos = minutos;
    this->segundos = segundos;
}