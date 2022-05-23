// addition .cpp pseduo code pre writing IBCM


#include<iostream>
using namespace std;
int main()
{
  int num1, num2, num3;
  int sum=0;

  cin>>num1;
  cin>>num2;
  cin>>num3;
  
  sum = num1+num2+num3;

  if (sum!=0){
    cout<<sum<<endl;
  }

  else if (sum==0){
    while (sum==0){
  cin>>num1;
  cin>>num2;
  cin>>num3;
  sum = num1+num2+num3;
    }
  cout<<sum<<endl;
  }
      


  return 0;
}
  
  
  
  

  

  
