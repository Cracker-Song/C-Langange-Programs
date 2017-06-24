#include<C:\Users\liang\Desktop\cpp\head.h>
typedef struct{
float real,imag;	
}complex;
int initcomplex(complex &z,float v1,float v2){
	z.real=v1;
	z.imag=v2;
	return ok;
}
int getreal(z,&realpart)
{
	realpart=z.real;
	return ok;
}
int getimag(z,&imagpart)
{
	imagpart=z.imag;
	return ok;
}
