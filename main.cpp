#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <vector>

using namespace std;
void menu();
//se define los vectores donde se almacenaran todos los datos
int numeroclientes=0;
vector<int> codigousuario;
vector<string> nombreyape;
vector<string> direccionvec;
vector<string> celularvec;
vector<int> edadvec;
int numeromateriales=0;
vector<int> codigomaterial;
vector<string> descripcionvec;
vector<float> preciovec;
vector<int> cantidadvec;
//se ingresa de forma directa a los vectores un usuario
void directousuario(string nombre,string direccion,string celular,int edad){
    nombreyape.push_back(nombre);
    direccionvec.push_back(direccion);
    celularvec.push_back(celular);
    edadvec.push_back(edad);
    numeroclientes=numeroclientes+1;
    codigousuario.push_back(numeroclientes);
}
//se ingresa de forma directa a los vectores un material
void directomaterial(string descrip,float precio,int cant){
    descripcionvec.push_back(descrip);
    preciovec.push_back(precio);
    cantidadvec.push_back(cant);
    numeromateriales=numeromateriales+1;
    codigomaterial.push_back(numeromateriales);
}
//ingresa y valida el nombre y apellidos de un nuevo usuario
void ingresarnombre(){
    string nombre;
    cout<<"Ingresar nombre y apellidos: "<<endl;
    cin.ignore();
    getline(cin, nombre);
    int ext=0;
    for(int i=0;i<nombreyape.size();i++){
        if(nombre==nombreyape[i]){
            ext=1;
        }
    }
    if(ext==1){
        cout<<"Usuario ya existente vuelva a ingresar"<<endl;
        ingresarnombre();
    }
    else{
        cout<<endl;
        nombreyape.push_back(nombre);
        cout<<"Usuario ingresado correctamente"<<endl;
        cout<<""<<endl;
    }
}
//ingresa y valida la direccion de un usuario
void ingresardireccion(){
    string nombre;
    cout<<"Ingresar direccion: "<<endl;
    getline(cin, nombre);
    direccionvec.push_back(nombre);
    cout<<"Direccion ingresada correctamente"<<endl;
    cout<<""<<endl;
}
//ingresa y valida el celular del usuario
void ingresarcelular(){
    string nombre;
    cout<<"Ingresar celular: "<<endl;
    getline(cin, nombre);
    if(nombre.length()!=9){
        cout<<"Numero invalido"<<endl;
        ingresarcelular();
    }
    else{
        celularvec.push_back(nombre);
        cout<<"Celular ingresado correctamente"<<endl;
        cout<<""<<endl;
    }
}
//ingresa y valida la edad del nuevo usuario
void ingresaredad(){
    int edad;
    cout<<"Ingresar edad: "<<endl;
    cin>>edad;
    if(edad>0 && edad<=120){
        edadvec.push_back(edad);
        cout<<"Edad ingresada correctamente"<<endl;
        cout<<""<<endl;

    }
    else{
        cout<<"Edad invalida"<<endl;
        ingresaredad();
    }
}
//funcion que llama a las funciones para ingresar y validar los datos de un nuevo usuario
void nuevosclientes(){
    system("cls");
    ingresarnombre();
    ingresardireccion();
    ingresarcelular();
    ingresaredad();
    numeroclientes=numeroclientes+1;
    codigousuario.push_back(numeroclientes);
    cout<<" "<<endl;
    cout<<"Codigo: "<<codigousuario[numeroclientes-1]<<endl;
    cout<<"Nombre y apellidos: "<<nombreyape[numeroclientes-1]<<endl;
    cout<<"Direccion: "<<direccionvec[numeroclientes-1]<<endl;
    cout<<"Celular: "<<celularvec[numeroclientes-1]<<endl;
    cout<<"Edad: "<<edadvec[numeroclientes-1]<<endl;
    cout<<"Usuario registrado correctamente"<<endl;
    cout<<endl;
    cout<<"Presione enter para continuar"<<endl;
    getch();
    menu();
}
//ingresa y valida la descripcion de un nuevo producto
void ingresardescripcion(){
    string nombre;
    cout<<"Ingresar descripcion del producto: "<<endl;
    cin.ignore();
    getline(cin, nombre);
    int ext=0;
    for(int i=0;i<descripcionvec.size();i++){
        if(nombre==descripcionvec[i]){
            ext=1;
        }
    }
    if(ext==1){
        cout<<"Producto ya registrado"<<endl;
        ingresardescripcion();
    }
    else{
        cout<<endl;
        descripcionvec.push_back(nombre);
        cout<<"Descripcion ingresada correctamente"<<endl;
        cout<<""<<endl;
    }
}
//ingresa y valida el precio del nnuevo producto
void ingresarprecio(){
    float edad;
    cout<<"Ingresar precio: "<<endl;
    cin>>edad;
    if(edad>0.0){
        preciovec.push_back(edad);
        cout<<"Precio ingresado correctamente"<<endl;
        cout<<""<<endl;

    }
    else{
        cout<<"Precio invalido"<<endl;
        ingresarprecio();
    }
}
//ingresa y valida la cantidad del nuevo producto
void ingresarcantidad(){
    int cantidad;
    cout<<"Ingresar cantidad: "<<endl;
    cin>>cantidad;
    if(cantidad<=0){
        cout<<"Numero invalido"<<endl;
        ingresarcantidad();
    }
    else{
        cantidadvec.push_back(cantidad);
        cout<<"Cantidad ingresada correctamente"<<endl;
        cout<<""<<endl;
    }
}
//funcion que llama a las funciones para ingresar un nuevio material y validar cada uno de sus datos
void nuevosmateriales(){
    system("cls");
    if(numeromateriales>=15)
    {
        cout<<"Almacen lleno"<<endl;
    }
    else{
    ingresardescripcion();
    ingresarprecio();
    ingresarcantidad();
    numeromateriales=numeromateriales+1;
    codigomaterial.push_back(numeromateriales);
    cout<<" "<<endl;
    cout<<"Codigo: "<<codigomaterial[numeromateriales-1]<<endl;
    cout<<"Descripcion: "<<descripcionvec[numeromateriales-1]<<endl;
    cout<<"Precio: "<<preciovec[numeromateriales-1]<<endl;
    cout<<"Cantidad: "<<cantidadvec[numeromateriales-1]<<endl;
    cout<<"Producto registrado correctamente"<<endl;
    }
    cout<<endl;
    cout<<"Presione enter para continuar"<<endl;
    getch();
    menu();
}
//funcion que ordena los materiales y luego los imprime en pantalla
void listamateriales(){
    system("cls");
    vector<string> listaordenadamat=descripcionvec;
    //burbuja que ordena los materiales en un vector auxiliar
    for(int i=0;i<numeromateriales;i++){
        for(int j=0;j<numeromateriales-1;j++){
            if(listaordenadamat[j].compare(listaordenadamat[j+1])>0){
                string temp=listaordenadamat[j];
                listaordenadamat[j]=listaordenadamat[j+1];
                listaordenadamat[j+1]=temp;
            }
        }
    }
    //los materiales ya ordenados se imprimen
    cout<<"     COD     PRODUCTO    CANTIDAD    PRECIO"<<endl;
    cout<<"     ---     --------    --------    ------"<<endl;
    for(int i=0;i<numeromateriales;i++){
        for(int j=0;j<numeromateriales;j++){
            if(listaordenadamat[i]==descripcionvec[j]){
                cout<<"    * "<<codigomaterial[j]<<"   "<<descripcionvec[j]<<"        "<<cantidadvec[j]<<"       "<<preciovec[j]<<"$"<<endl;
            }
        }
    }
    cout<<"Presione enter para continuar"<<endl;
    getch();
    menu();
}
//funcion que busca e imprime un material por su codigo
void buscarmaterial(){
    cout<<"Ingrese el codigo del material";
    int codigo;
    cin>>codigo;
    if(codigo>numeromateriales or codigo<=0){
        cout<<"Proveedor no encontrado"<<endl;
        buscarmaterial();
    }
    else{
        cout<<"     COD     PRODUCTO    CANTIDAD    PRECIO"<<endl;
        cout<<"     ---     --------    --------    ------"<<endl;
        cout<<"    * "<<codigomaterial[codigo-1]<<"   "<<descripcionvec[codigo-1]<<"        "<<cantidadvec[codigo-1]<<"       "<<preciovec[codigo-1]<<"$"<<endl;
        cout<<endl;
        cout<<"Presione enter para continuar"<<endl;
        getch();
        menu();
    }
}
//******************VENTA*************
//funciones que validan los datos en la venta
//funcion que valida el codigo del cliente
int codigocli(){
    cout<<"Ingrese el codigo del cliente"<<endl;
    int cod;
    cin>>cod;
    if(cod>numeroclientes or cod<=0){
        cout<<"usuario no registrado, operacion invalida"<<endl;
        return codigocli();
    }
    else{
        return cod;
    }
}
//funcion que valida el codigo del producto a vender y verifica si no es repetido en la venta
int codigoproduc(vector<int> codigos){
    cout<<"Ingrese el codigo del producto"<<endl;
    int cod;
    int num=0;
    cin>>cod;
    for(int i=0;i<codigos.size();i++){
        if(cod==codigos[i]){
            num=1;
        }
    }
    if(cod>numeromateriales or cod<=0 or num!=0){
        cout<<"codigo no registrado o repetido, operacion invalida"<<endl;
        return codigoproduc(codigos);
    }
    else{
        return cod;
    }
}
//funcion que valida si existe la cantidad deseada en el inventario
int vercantidad(int cod){
    cout<<"Ingrese la cantidad deseada"<<endl;
    int cant;
    cin>>cant;
    if(cant<=cantidadvec[cod-1]){
        return cant;
    }
    else{
        cout<<"cantidad no disponible, operacion invalida"<<endl;
        return vercantidad(cod);
    }
}
//funcion que valida que el numero de productos a vender sea menor o igual al numero de productos en el inventario
int capproductos(){
    cout<<"¿Cuantos productos desea vender?";
    int prod;
    cin>>prod;
    if(prod>0 and prod<=numeromateriales){
        return prod;
    }
    else{
        cout<<"No existe esa capacidad en el almacen"<<endl;
        return capproductos();
    }
}
//funcion que llama a todas las validaciones imprime las boletas y realiza la venta
void ventas(){
    int codigocliente=codigocli();
    int productos=capproductos();
    vector<int> codigosventas;
    vector<int> cantidadventas;
    for(int i=0;i<productos;i++){
        int codigopro;
        codigopro=codigoproduc(codigosventas);
        codigosventas.push_back(codigopro);
        int cantidad=vercantidad(codigopro);
        cantidadventas.push_back(cantidad);
    }
    cout<<"Desea boleta(1) o factura(2): ";
    int eleccion;
    cin>>eleccion;
    if(eleccion==1){
        float total=0;
        for(int i=0;i<productos;i++){
            total=total+(preciovec[codigosventas[i]-1]*cantidadventas[i]);
        }
        cout<<"     COD     PRODUCTO    CANTIDAD    PRECIO      SUBTOTAL"<<endl;
        cout<<"     ---     --------    --------    ------      --------"<<endl;
        for(int i=0;i<productos;i++){
            cout<<"   * "<<codigosventas[i]<<"      "<<descripcionvec[codigosventas[i]-1]<<"        "<<cantidadventas[i]<<"         "<<preciovec[codigosventas[i]-1]<<"$        "<<cantidadventas[i]*preciovec[codigosventas[i]-1]<<"$"<<endl;
        }
        cout<<"SUBTOTAL                                         "<<total<<"$"<<endl;
        cout<<"__________________________________________________________"<<endl;
        cout<<"TOTAL                                              "<<total<<"$"<<endl;
    }
    else if(eleccion==2){
        float total=0;
        for(int i=0;i<productos;i++){
            total=total+(preciovec[codigosventas[i]-1]*cantidadventas[i]);
        }
        cout<<"     COD     PRODUCTO    CANTIDAD    PRECIO      SUBTOTAL"<<endl;
        cout<<"     ---     --------    --------    ------      --------"<<endl;
        for(int i=0;i<productos;i++){
            cout<<"   * "<<codigosventas[i]<<"      "<<descripcionvec[codigosventas[i]-1]<<"        "<<cantidadventas[i]<<"         "<<preciovec[codigosventas[i]-1]<<"$        "<<cantidadventas[i]*preciovec[codigosventas[i]-1]<<"$"<<endl;
        }
        cout<<"SUBTOTAL                                              "<<total<<"$"<<endl;
        cout<<"IGV                                                   "<<(total/100)*18<<"$"<<endl;
        cout<<"__________________________________________________________"<<endl;
        cout<<"TOTAL                                              "<<total+((total/100)*18)<<"$"<<endl;

    }
    cout<<endl;
    cout<<"¿Confima la venta?"<<endl;
    string confirmacion;
    cin>>confirmacion;
    if(confirmacion=="si" or confirmacion=="Si" or confirmacion=="SI" or confirmacion=="sI"){
        cout<<"Venta realizada"<<endl;
    }
    else{
        cout<<"Venta cancelada"<<endl;
    }
    cout<<endl;
    cout<<"Presione enter para continuar"<<endl;
    getch();
    menu();

}
//menu principal
void menu(){
    system("cls");
    cout<<"             SISTEMA DE FACTURACIONDE MATERIALES - UCSP          "<<endl;
    cout<<" "<<endl;
    cout<<"         1.- NUEVOS CLIENTES"<<endl;
    cout<<"         2.- NUEVOS MATERIALES"<<endl;
    cout<<"         3.- LISTAR MATERIALES"<<endl;
    cout<<"         4.- BUSCAR MATERIAL"<<endl;
    cout<<"         5.- VENDER MATERIALES"<<endl;
    cout<<"         6.- SALIR"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Ingrese una opcion: ";
    int eleccion;
    cin>>eleccion;
    if(eleccion==1){
        nuevosclientes();
    }
    else if(eleccion==2){
        nuevosmateriales();
    }
    else if(eleccion==3){
        listamateriales();
    }
    else if(eleccion==4){
        buscarmaterial();
    }
    else if(eleccion==5){
        ventas();
    }
    else if(eleccion==6){
        cout<<"GRACIAS POR UTILIZAR NUESTRO SOFTWARE"<<endl;
    }
}
//funcion principal que llena los datos precargados y llama a la funcion menu
int main(){
    directousuario("pedro gomez meza","av los incas 152","876356278",56);
    directousuario("carla florez medina","urb los arces 312","128734647",23);
    directousuario("ruben cuba lajo","villa corpac c-3","192753233",45);
    directousuario("maria pinto carpio","av el sol 2345","837765453",25);
    directousuario("nicole diaz torres","av los incas 453","984700542",37);
    directousuario("jose torres cabrera","urb lavilla b-34","128833654",56);
    directousuario("juan meza flores","av el sol 6341","232365654",45);
    directousuario("maria diez canseco","urb los arces c-12","239764222",40);
    directousuario("renato martinez diaz","av los incas 032","253765899",20);
    directousuario("claudia diaz martinez","av los incas 999","123994566",18);
    directomaterial("barras de acero 45",16.45,40);
    directomaterial("aguarras",12.00,20);
    directomaterial("lamina de acero",20.99,100);
    directomaterial("bloque de hierro",32.45,20);
    directomaterial("codos de pbc(5)",10.5,250);
    directomaterial("tubo de media",9.8,35);
    directomaterial("cemento yura",30.23,50);
    directomaterial("cemento el sol",26.34,50);
    directomaterial("tubo de cuarta",11.99,60);
    directomaterial("barras de hierro corrugada",17.89,125);
    menu();
    return 0;
}
