#ifndef NODOLISTACOMPRAS_H
#define NODOLISTACOMPRAS_H
class NodoListaCompras {
    public:
        NodoListaCompras(int, int);
        int idCliente;
        int idCarreta;
        NodoListaCompras *siguiente;
};
#endif