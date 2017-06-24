#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define status int
struct course{
	int cno;
	char cname[20];
	int mark;
}cour[6]={{1,"高等数学",6},{2,"大学英语",6},{3,"大学物理",2},{4,"计算机基础",4},{5,"中国近现代史",2},{6,"马克思主义原理",4}};
struct subject{
	char obj[10];
}sub[8];
struct student{
	int rank;
	char name[10];
	int number;
	float score[6];
	float ave;
}stu[40],stu_order[40],temp;
status readtxt(struct student stu[],struct subject sub[])
{
	int i=0;
	FILE *fp=NULL;
	fp=fopen("学生信息.txt","r");
	fscanf(fp,"%s",&sub[0].obj);
	fscanf(fp,"%s",&sub[1].obj);
	fscanf(fp,"%s",&sub[2].obj);
	fscanf(fp,"%s",&sub[3].obj);
	fscanf(fp,"%s",&sub[4].obj);
	fscanf(fp,"%s",&sub[5].obj);
	fscanf(fp,"%s",&sub[6].obj);
	fscanf(fp,"%s",&sub[7].obj);
	//printf("%s %s",sub[0].obj,sub[1].obj);
	//fscanf(fp,"%s   %s   %s   %s   %s   %s   %s   %s",&sub[0].obj,&sub[1].obj,&sub[2].obj,&sub[3].obj,&sub[4].obj,&sub[5].obj);
	while(i<40)
	{
		fscanf(fp,"%d   %s   %f   %f   %f   %f   %f   %f",&stu[i].number,&stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2],&stu[i].score[3],&stu[i].score[4],&stu[i].score[5]);
		i++;
	}
	fclose(fp);
	return 0;
}
status order(struct student stu[],struct student stu1[])
{
	for(int i=0;i<40;stu1[i]=stu[i],i++);
	for(int i=0;i<40;i++)
	{
		for(int j=i;j<40;j++)
		{
			if(stu1[i].ave<stu1[j].ave)
			{
				temp=stu1[i];
				stu1[i]=stu1[j];
				stu1[j]=temp;
			}
		}
	}
	return 0;
}
status printorigin(struct student stu[])
{
	int i=0;
	FILE *fp=NULL;
	fp=fopen("output.txt","w");
	while(i<40)
	{
		fprintf(fp,"%d %s %f %f %f %f %f %f\n",stu[i].number,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].score[5]);
		i++;
	}
	fclose(fp);
	return 0;
}
status stuave(struct student stu[])
{
	int i=0;
	while(i<40)
	{
		stu[i].ave=(stu[i].score[0]*cour[0].mark+stu[i].score[1]*cour[1].mark+stu[i].score[2]*cour[2].mark+stu[i].score[3]*cour[3].mark+stu[i].score[4]*cour[4].mark+stu[i].score[5]*cour[5].mark)/(cour[0].mark+cour[1].mark+cour[2].mark+cour[3].mark+cour[4].mark+cour[5].mark);
		i++;
	}
	return 0;
}
status outputstu(struct student stu[])
{
	int i=0;
	for(int i=0;i<40;stu[i].rank=i+1,i++);
	for(int i=0;i<40;i++)
	{
		if(fabs(stu[i].ave-stu[i+1].ave)<0.0001)
		{
			stu[i+1].rank=stu[i].rank;
		}
	}
	FILE *fp=NULL;
	fp=fopen("output1.txt","w");
	fprintf(fp,"%s %s %s %s %s %s %s %s %s\n",sub[0].obj,sub[1].obj,sub[2].obj,sub[3].obj,sub[4].obj,sub[5].obj,sub[6].obj,sub[7].obj,"平均");
	while(i<40)
	{
		fprintf(fp,"%d %d %s %f %f %f %f %f %f %f\n",stu[i].rank,stu[i].number,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].score[5],stu[i].ave);
		i++;
	}
	fclose(fp);
	return 0;
}
status classave(struct student stu[],float *ave)
{
	float sum[6]={0};
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<40;j++)
		{
			sum[i]+=stu[j].score[i];
		}
		ave[i]=sum[i]/40;
	}
	return 0;
}
status section(struct student stu[],int number_stu[][4],float max[],float min[])
{
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<40;j++)
		{
			if(j==0)
			{
				max[i]=stu[j].score[i];
				min[i]=stu[j].score[i];
			}
			else
			{
				if(max[i]<stu[j].score[i]) max[i]=stu[j].score[i];
				if(min[i]>stu[j].score[i]) min[i]=stu[j].score[i];
			}
			if(stu[j].score[i]>=60&&stu[j].score[i]<=69) number_stu[i][0]++;
			if(stu[j].score[i]>=70&&stu[j].score[i]<=79) number_stu[i][1]++;
			if(stu[j].score[i]>=80&&stu[j].score[i]<=89) number_stu[i][2]++;
			if(stu[j].score[i]>=90&&stu[j].score[i]<=100) number_stu[i][3]++;
		}
	}
	return 0;
}
status outputclass(struct subject sub[],float ave[],int number_stu[][4],float max[],float min[])
{
	FILE *fp=NULL;
	fp=fopen("output2.txt","w");
	fprintf(fp,"%s  %s  %s  %s  %s  %s  %s\n","分数段",sub[2].obj,sub[3].obj,sub[4].obj,sub[5].obj,sub[6].obj,sub[7].obj);
	for(int i=0,j=6;i<4;i++,j++)
	{
		fprintf(fp,"%d  %d  %d  %d  %d  %d  %d\n",j*10,number_stu[0][i],number_stu[1][i],number_stu[2][i],number_stu[3][i],number_stu[4][i],number_stu[5][i]);
	}
	fprintf(fp,"%s  %f  %f  %f  %f  %f  %f\n","平均",ave[0],ave[1],ave[2],ave[3],ave[4],ave[5]);
	fprintf(fp,"%s  %.1f  %.1f  %.1f  %.1f  %.1f  %.1f\n","最高分",max[0],max[1],max[2],max[3],max[4],max[5],max[6]);
	fprintf(fp,"%s  %.1f  %.1f  %.1f  %.1f  %.1f  %.1f","最低分",min[0],min[1],min[2],min[3],min[4],min[5],min[6]);
	fclose(fp);
	return 0;
}
status find_stu(struct student stu[])
{
	int number_stu=0,j=-1;
	flag1:printf("请输入要查找的学生的学号\n");
	scanf("%d",&number_stu);
	if(number_stu==0){
		printf("输入错误，请重新输入\n");
		system("pause");
		system("cls");
		goto flag1;
	}
	for(int i=0;i<40;i++)
	{
		if(number_stu==stu[i].number)
		{
			j=0;
			printf("%s %s %s %s %s %s %s %s\n",sub[0].obj,sub[1].obj,sub[2].obj,sub[3].obj,sub[4].obj,sub[5].obj,sub[6].obj,sub[7].obj);
			printf("%d %s %.3f %.3f %.3f %.3f %.3f %.3f\n",stu[i].number,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].score[5]);
		}
	}
	return 0;
}
status fail_stu(struct student stu[])
{
	FILE *fp=NULL;
	fp=fopen("output3.txt","w");
	fprintf(fp,"%s %s %s %s %s %s %s %s\n",sub[0].obj,sub[1].obj,sub[2].obj,sub[3].obj,sub[4].obj,sub[5].obj,sub[6].obj,sub[7].obj);
	printf("%s %s %s %s %s %s %s %s\n",sub[0].obj,sub[1].obj,sub[2].obj,sub[3].obj,sub[4].obj,sub[5].obj,sub[6].obj,sub[7].obj);
	for(int i=0;i<40;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(stu[i].score[j]<60)
			{
				printf("%d %s %.3f %.3f %.3f %.3f %.3f %.3f\n",stu[i].number,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].score[5]);
				fprintf(fp,"%d %s %.3f %.3f %.3f %.3f %.3f %.3f\n",stu[i].number,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].score[5]);
				break;
			}
		}
	}
	fclose(fp);
	return 0;
}
status fine_stu(struct student stu[])
{
	FILE *fp=NULL;
	fp=fopen("output4.txt","w");
	fprintf(fp,"%s %s %s %s %s %s %s %s\n",sub[0].obj,sub[1].obj,sub[2].obj,sub[3].obj,sub[4].obj,sub[5].obj,sub[6].obj,sub[7].obj);
	printf("%s %s %s %s %s %s %s %s\n",sub[0].obj,sub[1].obj,sub[2].obj,sub[3].obj,sub[4].obj,sub[5].obj,sub[6].obj,sub[7].obj);
	for(int i=0;i<15;i++)
	{
		int k=0;
		if(stu[i].ave>85)
		{
			k=0;
			for(int j=0;j<6;j++)
			{
				if(stu[i].score[j]>60) k++;
			}
			if(k==6)
			{
				printf("%d %s %.3f %.3f %.3f %.3f %.3f %.3f\n",stu[i].number,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].score[5]);
				fprintf(fp,"%d %s %.3f %.3f %.3f %.3f %.3f %.3f\n",stu[i].number,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].score[5]);
			}
		}
		else
		{
			if(stu[i].ave>80)
			{
				k=0;
				for(int j=0;j<6;j++)
				{
					if(stu[i].score[j]>60) k++;
				}
				if(k==6)
				{
					int n=0,m=0;
					for(int q=0;q<6;q++)
					{
						if(stu[i].score[q]>90) m++;
						if(stu[i].score[q]>95) n++;
					}
					if(n>=1||m>=2)
					{
						printf("%d %s %.3f %.3f %.3f %.3f %.3f %.3f\n",stu[i].number,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].score[5]);
						fprintf(fp,"%d %s %.3f %.3f %.3f %.3f %.3f %.3f\n",stu[i].number,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4],stu[i].score[5]);
					}
				}
			}
		}
	}
	fclose(fp);
	return 0;
}
int main(void)
{
	readtxt(stu,sub);
	int choice;
	while(1)
	{
		flag:choice=-1;
		printf("1.学生信息设置；\n2.课程信息设置；\n3.求个人平均分并排名；\n4.求课程平均分并分段；\n5.输出学生成绩；\n6.输出不及格学生成绩；\n7.输出优等生名单；\n0.退出；\n");
		scanf("%d",&choice);
		if(choice==0) break;
		if(choice==-1||(choice<0||choice>7))
		{
			printf("输入不合法\n");
			system("pause");
			system("cls");
			goto flag;
		}
		else
		{
			switch(choice)
			{
				case 3:stuave(stu);order(stu,stu_order);outputstu(stu_order);break;
				case 4:
					{
						float ave[6]={0};
						int number_stu[6][4]={0};
						float max[6]={0},min[6]={0};
						classave(stu,ave);
						section(stu,number_stu,max,min);
						outputclass(sub,ave,number_stu,max,min);
						break;
					}
				case 5:find_stu(stu);break;
				case 6:fail_stu(stu);break;
				case 7:stuave(stu);order(stu,stu_order);fine_stu(stu_order);break;
			}
		}
	}
	//printorigin(stu);
	return 0;
}
