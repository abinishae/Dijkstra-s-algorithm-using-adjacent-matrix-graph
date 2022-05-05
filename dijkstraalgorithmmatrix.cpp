#include<iostream>
#include<vector>

using namespace std;
vector<int> dijs(int gra [4][4], int src,vector<int> & d){
	
	vector<bool> f (4,false);
	d[src] = 0;
	for(int c=0; c<4-1; c++){
		 int u= -1;
		 for(int i=0; i<4; i++)
		 	if(! f[i] && (u == -1 || d[i] < d[u]))
			u = i;
		
		 
		f[u] = true;
		for(int v=0; v<4; v++){
		  if(f[v] == false && gra[u][v]  )
		    d[v] = min(d[v], d[u]+gra[u][v]);
	      
		}
		
	}

	return d;
}
int main(){
	int gra[4][4] = {{0,10,30,6},
	         	   	  {10,0,20,0},
				          {30,20,0,40},
				          {6,0,40,0}};
	vector<int> d (4,INT_MAX);

 dijs(gra,0,d);
	for(int x=0; x<4; x++)
	cout<<d[x] <<" ";
	return 0;
	 
					  
}
