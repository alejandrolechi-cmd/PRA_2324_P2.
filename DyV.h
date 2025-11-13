 #include<vector>
#include<vector>
#include<iostream>
template<typename T>
int BusquedaBinaria(T x, std::vector<T> v, int ini, int fin){
	if (ini>fin){
		// std::cout<< "No se ha encontrado en el array";
		return -1;
	}
	int medio=(ini+fin)/2;
	if(v.at(medio)==x){
		return medio;
	}
	else if(v.at(medio)>x){
		
		return BusquedaBinaria(x,v,ini,medio-1);
	}
	else{
		return BusquedaBinaria(x,v,medio+1,fin);
	}
}
template<typename T>
int BusquedaBinaria_INV(T x, std::vector<T> &v, int ini, int fin){
	if (ini>fin){
        // std::cout<< "No se ha encontrado en el array";
		return -1;
	}
	int medio=(ini+fin)/2;
	if(v.at(medio)==x){
		return medio;
	}
	else if(v.at(medio)<x){
		
		return BusquedaBinaria_INV(x,v,ini,medio-1);
	}
	else{
		return BusquedaBinaria_INV(x,v,medio+1,fin);
	}
}
template<typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
// quick sort pivot last element
template<typename T>
int partitionPiLast(std::vector<T> &v,int ini, int fin){
    T pivot=v[fin];//pivot to last element
    int i = ini - 1;
    for(int j = ini; j < fin; j++){
        if(v[j]<=pivot){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[fin]);
    return i+1;
}
template<typename T>
void quickSortPiLast(std::vector<T> &v, int ini, int fin){
    if(ini<fin){
        T pi=partitionPiLast(v, ini, fin);
        quickSortPiLast(v, ini, pi-1);
        quickSortPiLast(v, pi+1, fin);
    }
}
//quick sort pivot to first element
template<typename T>
int partitionPiFirst(std::vector<T> &v,int ini, int fin){
    T pivot=v[ini];//pivot to first element
    int i = ini + 1;
    for(int j = ini + 1; j <= fin; j++){
        if(v[j]<pivot){
            swap(v[i],v[j]);
            i++;
        }
    }
    swap(v[ini], v[i - 1]);
    return i - 1;
}
template<typename T>
void quickSortPiFirst(std::vector<T> &v, int ini, int fin){
    if(ini<fin){
        T pi=partitionPiFirst(v,ini, fin);
        quickSortPiFirst(v, ini, pi-1);
        quickSortPiFirst(v, pi+1, fin);
    }
}
template<typename T>
int partitionPiCentral(std::vector<T> &v,int ini, int fin){
    int mid=(ini+fin)/2;
    T pivot=v[mid];//pivot to central element
    int i = ini;
    int j = fin;
    while (true) {
        // Move i to the right while elements < pivot
        while (v[i] < pivot) i++;
        // Move j to the left while elements > pivot
        while (v[j] > pivot) j--;

        if (i >= j)
            return j; // return the partition point

        swap(v[i], v[j]);
        i++;
        j--;
    }
}
template<typename T>
void quickSortPiCentral(std::vector<T> &v, int ini, int fin){
    if(ini<fin){
        T pi=partitionPiCentral(v, ini,  fin);
        quickSortPiCentral(v, ini, pi);
        quickSortPiCentral(v, pi+1, fin);
    }
}
