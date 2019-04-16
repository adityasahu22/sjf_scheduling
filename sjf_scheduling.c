#include <iostream>
using namespace std;
int main() 
{
 int i,j=0,n,temp2,temp1,temp[100],temp_pro[100];
 float avg=0,tt=0;
  cout<<"enter no. of process :";
  cin>>n;
float* arrive=new float[n];
int* burst=new int[n];
int* process=new int[n];
int** gant=new int*[n];
 for(int i=0;i<n;i++)
 {
 	gant[i]=new int[2];
 }

 for(i=0;i<n;i++)
 {
 	process[i]=i+1;
 	cout<<"enter arrival time of process "<<i+1<<" : ";
 	cin>>arrive[i];
 	gant[i][0]=i+1;
 	cout<<"enter burst time of process "<<i+1<<" : ";
 	cin>>burst[i];
 	gant[i][1]=burst[i];
 }
 	
 	cout<<"\n\n \t\t Process \t Arrival time \t Burst Time"<<endl;
 	for(int i=0;i<n;i++)
 	{
 		cout<<"\t\t\t"<<process[i]<<"\t\t"<<arrive[i]<<"\t\t"<<burst[i]<<endl;
	}
 for(i=0;i<n;i++){
 
  for(j=i+1;j<n;j++){
  
   if(gant[i][1]>gant[j][1])
   {
    temp1=gant[i][0];
    gant[i][0]=gant[j][0];
    gant[j][0]=temp1;
    
    temp2=gant[i][1];
    gant[i][1]=gant[j][1];
    gant[j][1]=temp2;
   }
}
}

 temp[0]=0;
 for(i=0;i<n;i++)
 {
	temp[i+1]=temp[i]+gant[i][1];
 	temp_pro[i]=gant[i][0]; 
 }
 
 cout<<"\nGantt Chart\n";
cout<<"\t"<< temp[0]<<"-->";
 for(i=1;i<n+1;i++)
 {
 	j=i-1;
	cout<<"p"<<temp_pro[j]<<"-->"<<temp[i]<<"-->";
	
 }
 
 for(i=1;i<n;i++)
  avg=avg+temp[i]-arrive[i];
 avg=avg/n;
 cout<<"\nThe Average WT is "<<avg<<" ms";
  
 for(i=2;i<n+1;i++)
 tt=tt+temp[i]-arrive[i-1];
 tt+=temp[1];
 tt=tt/n;
 cout<<"\nThe Average TT is"<< tt<<" ms";
return 0; 
}
