#include<C:\Users\liang\Desktop\cpp\zhead.h>
int main(void)
{
	complex z;
	float zreal,zimag,a,b;
	scanf("%f%f",&a,&b);
	initcomplex(z,a,b);
	getreal(z,zreal);
	getimag(z,zimag);
	printf("%.3f+%.3fi\nʵ��Ϊ%.3f�鲿Ϊ%.3f",zreal,zimag,zreal,zimag);
	system("pause");
	return ok;
}
