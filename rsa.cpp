#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a%h;
        if (temp == 0)
          return h;
        a = h;
        h = temp;
    }
}

int main()
{
string line;
char v;
vector<double>  valuesX, valuesY, valuesZ;
vector<char> vec;
string x,y,z,dum;

double xd;
ifstream myfile ("3D model.obj");
getline(myfile,dum);
do
{
    
        myfile >> v >> x >> y >> z;
    
        if(v=='v'||v=='f'){
            vec.push_back(v);
            valuesX.push_back(stod(x));
            valuesY.push_back(stod(y));
            valuesZ.push_back(stod(z));
        }
    
    
}while(!myfile.eof());

double p = 3;
double q = 7;
double n=p*q;
double count;
double totient = (p-1)*(q-1);
double e=2;
while(e<totient){
count = gcd(e,totient);
if(count==1)
    break;
else
    e++;
}
double d;
double k = 2;

d = (1 + (k*totient))/e;
long siz=vec.size();

vector<double> cX(siz),cY(siz),cZ(siz),mX(siz),mY(siz),mZ(siz);

ofstream newfile("Encrypted.obj");
for(int i=0;i<siz;i++){
    cX[i]=pow(valuesX[i],e);
    cY[i]=pow(valuesY[i],e);
    cZ[i]=pow(valuesZ[i],e);
    
    cX[i]=fmod(cX[i],n);
    cY[i]=fmod(cY[i],n);
    cZ[i]=fmod(cZ[i],n);
    newfile<<vec[i]<<" "<<cX[i]<<" "<<cY[i]<<" "<<cZ[i]<<endl;
} 




ofstream newfile2("Decrypted.obj");

for(int i=0;i<siz;i++){
    mX[i]=pow(cX[i],d);
    mY[i]=pow(cY[i],d);
    mZ[i]=pow(cZ[i],d);
    mX[i]=fmod(mX[i],n);
    mY[i]=fmod(mY[i],n);
    mZ[i]=fmod(mZ[i],n);
    newfile2<<vec[i]<<" "<<mX[i]<<" "<<mY[i]<<" "<<mZ[i]<<endl;
} 



return 0;
}