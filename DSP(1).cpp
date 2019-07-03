#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define pi 3.1415926536

struct com {
     double real;
     double imj;
    };
class complex_num{

public:
    double real;
    double imj;
public:
    complex_num(com c){
    real = c.real;
    imj = c.imj;
    }
    complex_num(){
    real = 0;
    imj = 0;
    }
    com summation(complex_num n1 , complex_num n2){
    com c={0,0};
    c.real = n1.real + n2.real;
    c.imj = n1.imj + n2.imj;

    return c;
    }
    com  multiplication(complex_num n1 , complex_num n2){

    com c = {0,0};

    c.real = n1.real*n2.real - n1.imj*n2.imj;
    c.imj = n1.imj*n2.real + n1.real*n2.imj;

    return c;
    }
};




com pow_func(int n,com power,com c1){
complex_num result;

 while (n!=1){

        power=result.multiplication(power,c1);


        n=n-1;

    }
     //cout<<power.real<<"j"<<power.imj<<"\n";
return  power;
}

int main()
{
    cout<<fixed;
    cout<<setprecision(2);


    int n;

    cout<<"\nEnter the number samples in the sequence X(n) in freq domain 'N' =";
    cin>>n;
    cout<<"\n";
    com x[n];
    cout<<"Please enter x[n] \n";

    for(int i=0;i<n;i++)
    {

         cin>>x[i].real;



    }
    cout<<"\n";

    com c1={cos((2*pi)/n),-sin((2*pi)/n)};


    complex_num result;

    com p[n][n];
    com y[n]={0};
    com z[n];
    double o[n];
    double H[n];




    for (int i=0;i<n;i++){
        p[i][0].real=1;
        p[i][0].imj=0;

        p[0][i].real=1;
        p[0][i].imj=0;
        }


    com power;
    power = c1;


    for(int i=1 ; i<n;i++){
        for(int y=1 ; y<n ;y++){
            int os=i*y;
            p[i][y]=pow_func(os,c1,c1);
            //cout<<"\n"<<os<<"\n";
        }


    }
    for(int i=0 ; i<n;i++){
        for(int j=0 ; j<n ;j++){
            z[i]=result.multiplication(p[i][j],x[j]);
            y[i]=result.summation(y[i],z[i]);

        }
    }
   cout<<"the result:\n\n";
   cout<<"x(k)={ ";
   for(int i=0 ; i<n;i++){
    if(i!=n)
     {
         cout<<y[i].real<<"+j("<<y[i].imj<<") \t";

     }
     else
     {
            break;
     }

   }
   cout <<"}";
   cout<<"\n\n";
   cout<<"The Magnitude:\n";
   for(int i=0 ; i<n;i++){

    int q;
    q=y[i].real*y[i].real ;
    int a;
    a=y[i].imj*y[i].imj;
    int x;
    x=q+a;
    o[i]=sqrt(x);
    x=0;
    a=0;
    q=0;
}

cout<<"|x(k)|={ ";
   for(int i=0 ; i<n;i++){
    if(i!=n-1)
     {cout<<o[i]<<" , ";}


   else
   {
       cout<<o[i]<<" }\n";
   }
}



cout<<"\nThe Phase of X[K]:\n\n";
double test;
 cout<<"arc(x[k])={ ";
 for(int i=0 ; i<n;i++){

    H[i]=atan(y[i].imj/y[i].real)*180/pi;
     if (y[i].imj==0 )
         cout<<H[i]<<"   ";


     else if (y[i].imj>0 && y[i].real>0)
        {
        cout<<H[i]<<"   ";
        }

    else if ((y[i].imj>0 && y[i].real<0)||(y[i].imj<0&& y[i].real<0))
         {
        test=H[i]+180;
        cout<<test<<"  ";
        test=0;
         }
    else if (y[i].imj<0&& y[i].real>0)
      {

       test=H[i]+360;
        cout<<test<<"  ";
        test=0;
       }
    else
        break;

    }

  cout<<"}";
 return 0;
}


