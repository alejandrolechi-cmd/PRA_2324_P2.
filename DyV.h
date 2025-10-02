 #include<vector>

using namespace std;
  
void BusquedaBinaria(vector<int> a, int x, int ini, int fin){

     if(ini>fin){
	     return -1;
     }
     int medio=(ini + fin)/2;

     if(a[medio] == x){
	     return medio;
     }
     else if(a[medio] >x){
	     return BusquedaBinaria(x,a,ini,medio-1);
     }else{
		     return BusquedaBinaria(x,a,medio+1,fin)
     }

}

void function2(std::vector<int>& a){



}


void main()
{
	vector<int> a(20);

	BusquedaBinaria(a,x,ini,fin);

	function2(a);
}
    
