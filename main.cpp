#include <iostream>
using namespace std;
//Sebastián Rodas Melgar
//9941-24-27220
struct Estudiante {
	int carne;
    string nombre;
    string apellido;
    string carrera;
};

struct Nodo {
	Nodo *siguiente;
	Estudiante p;
};


void BorrarElementos(Nodo *n) {
	while(n!=nullptr) {
		Nodo*temp=n;
		n=n->siguiente;
		delete temp;
		temp=nullptr;
	}
}
void RecorrerLista(Nodo *n) {
     if(n==nullptr){
        cout<<"Lista vacia"<<endl;
        return;
    }
	while(n!=nullptr) {
		cout<<"Codigo: "<<n->p.carne<<endl;
		cout<<"Nombre: "<<n->p.nombre<<endl;
		cout<<"Precio: "<<n->p.apellido<<endl;
		cout<<"Precio: "<<n->p.carrera<<endl;
		cout<<"---------------------------"<<endl;
		n=n->siguiente;
	}
}
void agregarTail(Nodo*&head,Nodo*&tail){
    int carne;
    string nombre;
    string apellido;
    string carrera;
	cin>>carne;
	cin>>nombre;
	cin>>apellido;
	cin>>carrera;
	Estudiante es={carne,nombre,apellido,carrera};
	Nodo*newNodo=new Nodo();
	newNodo->siguiente=nullptr;
	newNodo->p=es;
	if(tail==nullptr || head==nullptr){
	    tail=newNodo;
		head=newNodo;
	    return;
	}
	tail->siguiente=newNodo;
	tail=newNodo;
}
void agregarHead(Nodo*&head,Nodo*&tail){
    int carne;
    string nombre;
    string apellido;
    string carrera;
	cin>>carne;
	cin>>nombre;
	cin>>apellido;
	cin>>carrera;
	Estudiante es={carne,nombre,apellido,carrera};
	Nodo*newNodo=new Nodo();
	newNodo->siguiente=head;
	newNodo->p=es;
	if(tail==nullptr || head==nullptr){
	    tail=newNodo;
		head=newNodo;
	    return;
	}
	head=newNodo;
}
void BuscarPorCarne(Nodo* head){
    int carne=0;
    cin>>carne;
    if(head==nullptr){
        cout<<"Lista vacia"<<endl;
        return;
    }
    while(head!=nullptr) {
		if(head->p.carne==carne){
		    cout<<"---------------------------"<<endl;
		    cout<<"Codigo: "<<head->p.carne<<endl;
		    cout<<"Nombre: "<<head->p.nombre<<endl;
		    cout<<"Precio: "<<head->p.apellido<<endl;
		    cout<<"Precio: "<<head->p.carrera<<endl;
		    cout<<"---------------------------"<<endl;
		    return;
		}
		head=head->siguiente;
	}
	cout<<"Estudiante no encontrado"<<endl;
}
void EliminarPorCarne(int carne,Nodo*& head,Nodo*&tail){
    if(head==nullptr){
        cout<<"Lista vacia"<<endl;
        return;
    }
    Nodo* anterior=nullptr;
    Nodo* actual=head;
    while(actual!=nullptr) {
		if(actual->p.carne==carne){
		    if(actual==head){
		        head=head->siguiente;
		        if(head == nullptr) {
                    tail = nullptr;
                }
		        delete actual;
		        return;
		    }
		    if(actual==tail){
		        tail=anterior;
		        delete actual;
		        return;
		    }
		    anterior->siguiente=actual->siguiente;
		    delete actual;
		    return;
		}
		
		anterior=actual;
		actual=actual->siguiente;
	}
}

int main()
{
    cout<<"Sebastián Rodas Melgar"<<endl;
	int s=0;
	Nodo *head=nullptr;
	Nodo *tail=nullptr;
	while (s!=6) {
		cout<<"Elige una opción"<<endl;
		cout<<"1. Ingresar estudiante inicio"<<endl;
		cout<<"2. Ingresar estudiante fin"<<endl;
		cout<<"3. Recorrer lista"<<endl;
		cout<<"4. Buscar estudiante por carné"<<endl;
		cout<<"5. Eliminar estudiante por carné"<<endl;
		cout<<"6. Salir"<<endl;
		cin>>s;
		if(s==1) {
			cout<<"Ingresa los valores del producto"<<endl;
			agregarHead(head,tail);
		}
		if(s==2) {
		    cout<<"Ingresa los valores del producto"<<endl;
			agregarTail(head,tail);
		}
		if(s==3) {
			RecorrerLista(head);
		}
		if(s==4) {
		    cout<<"Ingresa el carne del estudiante a buscar"<<endl;
			BuscarPorCarne(head);
		}
		if(s==5) {
		    int carne=0;
		    cout<<"Ingresa el carne del estudiante a eliminar"<<endl;
		    cin>>carne;
			EliminarPorCarne(carne,head,tail);
		}
		if(s==6) {
			break;
		}

	}

	BorrarElementos(head);
	return 0;
}
