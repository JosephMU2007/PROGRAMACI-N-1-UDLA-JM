struct Vehiculo {
    int id;
    char marca[50];
    char modelo[50];
    char tipo[30];
    char condicion[20];
    float precio;
    char estado[20];
};

int cargarInventario(struct Vehiculo arreglo[]);
void guardarInventario(struct Vehiculo arreglo[], int total);
int agregarVehiculo(struct Vehiculo arreglo[], int total);
void mostrarDisponibles(struct Vehiculo arreglo[], int total);
void buscarParaCliente(struct Vehiculo arreglo[], int total);
void registrarVenta(struct Vehiculo arreglo[], int total);