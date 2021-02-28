#ifndef NODOCOLAPAGAR_H
#define NODOCOLAPAGAR_H
class NodoColaPagar {
    public:
        NodoColaPagar(int, int);
        NodoColaPagar *siguiente;
        int idCliente;
        int idCarreta;
};
#endif