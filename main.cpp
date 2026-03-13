#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //esta libreria me permita facilitar algunas operaciones

using namespace std;

struct Asistente {
	int id;
	string nombre;
};

class gestionAsistentes {
	private:
		vector<Asistente> lista;
		
	public:
		void insertar(int _id, string _nombre){
			Asistente nuevo = {_id, _nombre};
			lista.push_back(nuevo);
			cout << "Asistente " << _nombre << " agregado exitosamente" << endl;
		}
		
		void eliminar(int _id){
			bool encontrado = false;
			for(int i=0; i<lista.size(); i++){
				if(lista[i].id == _id){
					cout << "Eliminando a: " << lista[i].nombre << endl;
					lista.erase(lista.begin() + i);
					encontrado = true;
					break;
				}
			}
			if(!encontrado){
				cout << "El ID no ha sido reconocido" << endl;
			}
		}
		
		void buscar(int _id){
			for(int i=0; i<lista.size(); i++){
				if(lista[i].id == _id){
					cout << "Nombre: " << lista[i].nombre << endl;
					return;
				}
			}
			cout << "El ID ingresado no se ha reconocido" << endl;
		}
		
		void mostrar(){
			if(lista.empty()){
				cout << "La lista se encuentra vacia" << endl;
				return;
			}
			cout << "\n--- Lista de asistentes al evento ---" << endl;
			for(int i=0; i<lista.size(); i++){
            cout << "ID: " << lista[i].id << " / Nombre: " << lista[i].nombre << endl;
        }
		}
		
		int size(){
			return lista.size();
		}
};

int main (){
	gestionAsistentes evento;
	
	evento.insertar(1, "Jeampierre Ortiz");
	evento.insertar(2, "Steven Palma");
	evento.insertar(3, "Manuel Torres");
	
	evento.mostrar();
	cout << "\nTotal asistentes: " << evento.size() << endl;

    cout << "\nBuscando asistente con ID 2:" << endl;
    evento.buscar(2);

    cout << "\nEliminando asistente con ID 1" << endl;
    evento.eliminar(1);

    evento.mostrar();
    cout << "Nuevo total de asistentes: " << evento.size() << endl;

    return 0;
}
