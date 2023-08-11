#ifndef TIPO_ELEMENTO_HH
#define TIPO_ELEMENTO_HH

struct TipoElementoRep {
    int clave;
    char *valor;
};
typedef struct TipoElementoRep *TipoElemento;

TipoElemento te_crear(int clave);
TipoElemento te_crear_con_valor(int clave, char *valor);

#endif // TIPO_ELEMENTO_H

