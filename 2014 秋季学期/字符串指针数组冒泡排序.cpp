#include<stdio.h>
#define N 8
int udf_strcmp(char *s,char *t){//∂‘c1µΩc8  ”√ 
	for(;*s==*t;s++,t++)
	    if(*s=='\0')
	        return 0;
	return *s-*t;
}

void upbubblesort(char *s[],int n){
	int i,j;
	char *t;
	for(i=0;i<n-1;i++)
	    for(j=0;j<n-i-1;j++)
	        if(udf_strcmp(s[j],s[j+1])>0){
	            t=s[j];
	            s[j]=s[j+1];
	            s[j+1]=t;
	        }
	return;
}
void pripstr(char *ps[],int n){
	int i;
	for(i=0;i<n;i++)
	    printf("%s %c",ps[i],(i+1)%10==0?'\n':' ');
	return; 
}
int main(){
	char c1[]="dfhedfgh",c2[]="asdfg",c3[]="csd",c4[]="bsdf",c5[]="xyz",c6[]="bsdfg",c7[]="asdf",c8[]="dsd";
	char *s[]={c1,c2,c3,c4,c5,c6,c7,c8};
	pripstr(s,N);
	printf("\n");
	upbubblesort(s,N);
	pripstr(s,N);
	return 0;
}
