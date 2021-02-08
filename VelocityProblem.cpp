
#include <iostream>
using namespace std;
#include <string>

int day(int day, int month, int year) 
{   
    int tab[] = { 0, 3, 2, 5, 0, 3, 5, 1, 
                       4, 6, 2, 4 }; 
    year -= month < 3; 
    return ( year + year/4 - year/100 + 
             year/400 + tab[month-1] + day) % 7; 
} 

struct part{

int s ;
};
int main()
{
/*
    int speed;
    cin >> speed; cin.ignore();
    int lightCount;
    int k[4];
    cin >> lightCount; cin.ignore();
    int distance;
    int duration;
    float sum1;
    float sum2;
    float sum3;
    if(lightCount==1){
    	cin >> distance >> duration; cin.ignore();
    	if((distance/(duration)) <= speed){
    		cout << speed << endl;
    	}
    }
    else{
	    for (int i = 0; i < lightCount; i++) {
	    	k[i] =1;
		cin >> distance >> duration; cin.ignore();
		sum1=distance/duration;
			if(sum1 <= speed){
				 k[i]=1;
			}
			else{
				sum2= (distance/(k[i]*duration));
				if(sum2 > speed){
					k[i]++;
					sum3=(distance/(2*(k[i]-1)*duration));
					while(sum3 > speed){
						//cout << (distance/(2*k[i]*duration)) <<"\n"<< endl;
						    k[i]++;
					}
				}
			}
		
	    }
	    
	    int max_k =1;
	    for(int i = 0; i < lightCount; i++){
		if(k[i]>max_k){
		    max_k = k[i];
		}
	    }
	    float vel =0;
	if(max_k>1)
	    vel = (distance/(2*max_k*duration));
	else
	    vel = speed;
	    // Write an answer using cout. DON'T FORGET THE "<< endl"
	    // To debug: cerr << "Debug messages..." << endl;
	
	    cout << vel << endl;
    
	}		    

*/

struct part* part ; 
part = (struct part *)malloc(sizeof(struct part));
(*part).s = 8;
cout << (*part).s <<endl;
return 0; 


}
