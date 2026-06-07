struct Libro {
    int id;
    char titulo[100];
    char autor[50];
    int anio;
    char estado[15];
};

int ingresarLibro(struct Libro arreglo[], int total);
void mostrarTabla(struct Libro arreglo[], int total);
void buscarLibro(struct Libro arreglo[], int total);
void actualizarEstado(struct Libro arreglo[], int total);
int eliminarLibro(struct Libro arreglo[], int total, int idBorrar);
