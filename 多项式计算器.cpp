#include"polyheadxy.h"
Status Printpolyn(Linklist);
Status Printaggregationpolyn(int,int,Linklist *);
Status Fullprotection(Linklist *,int *);
Status Createpolyn(Linklist &);
Status Copypolyn(Linklist,Linklist &);
Status Destroypolyn(Linklist &);
Status Clearpolyn(Linklist &);
Status Addpolyn(Linklist,Linklist,Linklist &);
Status Destroypolyn(Linklist &);
Status Clearpolyn(Linklist &);
Status Negtivepolyn(Linklist,Linklist &);
Status Negtiveselfpolyn(Linklist &);
Status Substractpolyn(Linklist,Linklist &,Linklist &);
Status Envaluepolyn(Linklist,double &,double);
Status Modifypolyn(Linklist &);
Status Coefexpnpolyn(Linklist,Linklist &,double,int);
Status Addlocalpolyn(Linklist,Linklist &);
Status Substractlocalpolyn(Linklist &,Linklist);
Status Multiplypolyn(Linklist,Linklist,Linklist &);
Status Dividepolyn(Linklist,Linklist,Linklist &,Linklist &);
Status Powerpolyn(Linklist,Linklist &,int);
Status Diffcoefpolyn(Linklist,Linklist &);
Status Ndiffcoefpolyn(Linklist,Linklist &,int);
Status Indfintegralpolyn(Linklist,Linklist &);
Status Dfintegralpolyn(Linklist,double &,double,double);
Status Gcdpolyn(Linklist,Linklist,Linklist &);
Status Lcmpolyn(Linklist,Linklist,Linklist &);
Status Printtaylorpolyn(Linklist,double);
Status ScanfDprotection(char *,double &);
Status ScanfIprotection(char *,int &);
Status Judgeoperator(char);
Status Judgeoperand(char *,int &);
char Prior(char,char);
Status Cleararray(char *);
Status Calculatepolyn(char,Linklist,Linklist,Linklist &);
Status Multicalculation(char *,Linklist *,Linklist &,int *);
int main(void)
{
	//system("color 70");
    int menu=-1,submenu,pos1=-1,pos2,pos3,pos4,sumpolyn=List_Init_Size,ifquit,polynlength,travel,undefined,empty,full,power,diff,i,j;
    double value,x,x1,x2,taylor;
    int *psumpolyn=&sumpolyn;
    char ch;
    char input[30]={'\0'};
    Linklist L=NULL;
    Linklist Polynlink[List_Init_Size]={NULL};
    for(;1;){
    	for(int i=0;i<10;){
			for(int j=0;j<10;f[i][j]=0,j++);
			i++;
		}
	    flag:printf("                                    �˵�\n***************************************************************************\n00:�˳����˵�     01:����ʽ����     02:����ʽ��ʾ     03:���ƶ���ʽ\n04:����ʽ����     05:����ʽ����     06:����ʽ��ֵ     07:����ʽ����\n08:����ʽ����     09:����ʽ�޸�     10:����ʽ�˷�     11:����ʽ����\n12:����ʽ�˷�     13:����ʽ������   14:����ʽ�������� 15:����ʽ������\n16:��������ʽ     17:��С����ʽ     18:����ʽ��������\n***************************************************************************\n��ѡ�����蹦��\n");
		scanf("%d",&menu); //ճ������ʽ������ʽ������
	    if(menu<0||menu>18||menu==-1){
	    	int choice=MessageBox(NULL,"������������������ѡ��yes���˳�����ѡ��no","��ѡ��",MB_YESNO);
	    	if(choice==IDYES) fflush(stdin);
			else return 0;
			system("cls");
	    }
	    switch(menu){
		    case 0:printf("�˳�.��ӭ�ٴ�ʹ��!");
		           return 0;
		    case 1:printf("����ʽ����\n");
		           while(1){
                       printf("�������¶���ʽ��λ��(1--%d)\n",*psumpolyn);
	                   scanf("%d",&pos1);
	                   if((pos1>=1)&&(pos1<=(*psumpolyn))&&(Polynlink[pos1-1]==NULL))
	    	               break;
	                   else
	                   {
	                	   	int choice=MessageBox(NULL,"������������������ѡ��yes���˳�����ѡ��no","��ѡ��",MB_YESNO);
	   					 	if(choice==IDYES) fflush(stdin);
							else return 0;
							//system("cls");
	                   }
	               }
	               Fullprotection(Polynlink,psumpolyn);
		           Createpolyn(L);
		           printf("��������\n");
		           Polynlink[pos1-1]=L;
		           break;
		    case 2:printf("��ʾ����ʽ\n");
		           ifquit=0;
			       for(;1;){
			       	   printf("     �˵�\n***************\n00:�˳�������\n01:��ʾһ������ʽ\n02:��ʾ��������ʽ\n03:��ʾȫ������ʽ\n***************\n���������蹦��\n");
			       	   scanf("%d",&submenu);
			       	   if(submenu<0||submenu>3)
			       	       return error;
			       	   switch(submenu){
			       	   	   case 0:printf("�˳�������\n");
			       	   	          ifquit++;
								  break;
			       	   	   case 1:printf("��������ʾ����ʽ����\n");
		                          scanf("%d",&pos1);
		                          while(1){
			       	                  if((pos1>=1)&&(pos1<=(*psumpolyn)))
			       	                      break;
			       	                  int choice=MessageBox(NULL,"������������������ѡ��yes���˳�ѡ��no","��ѡ��",MB_YESNO);
	   					 		      if(choice==IDYES)
										  {
											fflush(stdin);
										  	scanf("%d",&pos1);
									      }
									      else return 0;
			                      }
		                          Printpolyn(Polynlink[pos1-1]);
		                          break;
			               case 2:printf("��ʾ��������ʽ\n");
			                      printf("��������������\n");
			                      scanf("%d",&pos1);
			                      while(1){
			       	                  if((pos1>=1)&&(pos1<=(*psumpolyn)))
			       	                      break;
			       	                  printf("������������������\n");
			       	                  scanf("%d",&pos1);
			                      }
			                      printf("��������������\n");
			                      scanf("%d",&pos2);
			                      while(1){
			       	                  if((pos2>=1)&&(pos2<=(*psumpolyn))&&(pos2>=pos1))
			       	                      break;
			       	                  printf("������������������\n");
			       	                  scanf("%d",&pos2);
			                      }
			                      if(Printaggregationpolyn(pos1,pos2,Polynlink)==ok)
								      printf("��ʾ����ʽ�ɹ�\n");
								  else
								      printf("��ʾ����ʽʧ��\n");
								  break;
						   case 3:printf("��ʾȫ������ʽ\n");
						          if(Printaggregationpolyn(1,sumpolyn,Polynlink)==ok)
								      printf("��ʾ����ʽ�ɹ�\n");
								  else
								      printf("��ʾ����ʽʧ��\n");
								  break;
			       	   }
			       	   if(ifquit==1)
			       	       break;
			       }
		           break;
		    case 3:printf("����ʽ����\n");
		           printf("������ԭ����ʽ��λ��\n");
		           scanf("%d",&pos1);
		           while(1){
		           	   if((pos1>=1)&&(pos1<=(*psumpolyn))&&(Polynlink[pos1-1]!=NULL))
		           	       break;
		           	   printf("���������������ƶ���ʽ��λ��\n");
			       	   scanf("%d",&pos1);
		           }
	    	       printf("�������¶���ʽλ��\n");
			       scanf("%d",&pos2);
			       while(1){
			       	   if((pos2>=1)&&(pos2<=(*psumpolyn))&&(Polynlink[pos2-1]==NULL))
			       	       break;
	    	           printf("�����������¶���ʽλ��\n");
			           scanf("%d",&pos2);
			       }
			       Fullprotection(Polynlink,psumpolyn);
			       Initpolyn(L);
			       if(!L)
			           return overflow;
			       Polynlink[pos2-1]=L;
				   if(Copypolyn(Polynlink[pos1-1],Polynlink[pos2-1]))
				       printf("���Ƴɹ�\n");
				   break;
			case 4:printf("����ʽ����\n");
			       printf("���������͵ĵ�һ������ʽ����\n");
				   scanf("%d",&pos1);
				   while(1){
				       if((pos1>=1)&&(pos1<=(*psumpolyn))&&(Polynlink[pos1-1]))
				           break;
				       printf("�������������͵ĵ�һ������ʽ����\n");
				       scanf("%d",&pos1);
				   }
				   printf("���������͵ĵڶ�������ʽ����\n");
				   scanf("%d",&pos2);
				   while(1){
				   	   if((pos2>=1)&&(pos2<=(*psumpolyn))&&(Polynlink[pos2-1]))
				   	       break;
				   	   printf("�������������͵ĵڶ�������ʽ����\n");
				       scanf("%d",&pos2);
				   }
				   printf("�������Ͷ���ʽ������\n");
				   scanf("%d",&pos3);
				   while(1){
				   	   if((pos3>=1)&&(pos3<=(*psumpolyn))&&(!Polynlink[pos3-1]))
				   	       break;
					   printf("�����������Ͷ���ʽ������\n");
				       scanf("%d",&pos3);
				   }
				   Fullprotection(Polynlink,psumpolyn);
				   Initpolyn(L);
			       if(!L)
			           return overflow;
			       Polynlink[pos3-1]=L;
				   if(Addpolyn(Polynlink[pos1-1],Polynlink[pos2-1],Polynlink[pos3-1]))
				       printf("���ͳɹ�\n");
				   break;
			case 5:printf("����ʽ����\n");
			       printf("�����뱻������ʽ����\n");
			       scanf("%d",&pos1);
			       while(1){
			       	   if((pos1>=1)&&(pos1<=(*psumpolyn))&&(Polynlink[pos1-1]!=NULL))
			       	       break;
			       	   printf("���������뱻������ʽ����\n");
			       	   scanf("%d",&pos1);
			       }
			       printf("������������ʽ����\n");
			       scanf("%d",&pos2);
			       while(1){
			       	   if((pos2>=1)&&(pos2<=(*psumpolyn))&&(Polynlink[pos2-1]!=NULL))
			       	       break;
			       	   printf("����������������ʽ����\n");
			       	   scanf("%d",&pos2);
			       }
			       printf("�������¶���ʽ����\n");
			       scanf("%d",&pos3);
			       while(1){
			       	   if((pos3>=1)&&(pos3<=(*psumpolyn))&&(Polynlink[pos3-1]==NULL))
			       	       break;
			       	   printf("�����������¶���ʽ����\n");
			       	   scanf("%d",&pos3);
			       }
			       Fullprotection(Polynlink,psumpolyn);
			       Initpolyn(L);
			       Polynlink[pos3-1]=L;
			       if(Substractpolyn(Polynlink[pos1-1],Polynlink[pos2-1],Polynlink[pos3-1]))
				       printf("�����ɹ�\n");
				   break;
			case 6:printf("����ʽ��ֵ\n");
			       printf("����������ֵ����ʽ����\n");
			       scanf("%d",&pos1);
			       while(1){
			       	   if((pos1>=1)&&(pos1<=(*psumpolyn))&&(Polynlink[pos1-1]!=NULL))
			       	       break;
			       	   printf("��������������ֵ����ʽ����\n");
			       	   scanf("%d",&pos1);
			       }
			       printf("������X��ֵ\n");
			       scanf("%lf",&x);
			       value=0;
			       if(Envaluepolyn(Polynlink[pos1-1],value,x)){
			       	   printf("��ֵ�ɹ�\n");
			           printf("��������ʽ��ֵ\n");
			           printf("%lf",value);
				   }
				   else
				       printf("��ֵʧ��\n");
			       break;
			case 7:printf("����ʽ����\n");
			       printf("�����������ٶ���ʽ����\n");
			       scanf("%d",&pos1);
			       while(1){
			       	   if((pos1>=1)&&(pos1<=(*psumpolyn))&&(Polynlink[pos1-1]!=NULL))
			       	       break;
			       	       if(pos1==0)
			       	       {
			       	       	system("cls");
			       	       	goto flag;
			       	       }
			       	   printf("���������������ٶ���ʽ����\n");
			       	   scanf("%d",&pos1);
			       }
			       if(Destroypolyn(Polynlink[pos1-1]))
			           printf("ɾ���ɹ�\n");
			       else
				       printf("ɾ��ʧ��\n");
				   break;
			case 8:printf("����ʽ����\n");
			       printf("�����������ն���ʽ����\n");
			       scanf("%d",&pos1);
			       while(1){
			       	   if((pos1>=1)&&(pos1<=(*psumpolyn))&&(Polynlink[pos1-1]!=NULL))
			       	       break;
			       	       if(pos1==0){
			       	       	  system("cls");
			       	       	  goto flag;
			       	       }
			       	   printf("���������������ն���ʽ����\n");
			       	   scanf("%d",&pos1);
			       }
			       if(Clearpolyn(Polynlink[pos1-1]))
			           printf("���ճɹ�\n");
			       else
				       printf("����ʧ��\n");
				   break;
		   case 9:{printf("�޸Ķ���ʽ\n");
		           ifquit=0;
		           flag1:printf("������Ҫ�޸ĵĶ���ʽ����\n");
		           pos1=-1;
		           scanf("%d",&pos1);
		           if(pos1==-1||((pos1<1)&&(pos1>(*psumpolyn))&&(Polynlink[pos1-1]==NULL)))
		           {
		           	int choice=MessageBox(NULL,"������������������ѡ��yes���˳�����ѡ��no","��ѡ��",MB_YESNO);
	   				if(choice==IDYES)
					   {
					   	fflush(stdin);
					   	goto flag1;
					   }
					else return 0;
		           }
		           float newcoe;
		           printf("������Ҫ�޸ĵ�����ָ��,�µ�ϵ��\n");
		           Linklist exchange=Polynlink[pos1-1];
		           int countex=0,exexp;
		           scanf("%d%f",&exexp,&newcoe);
		           while(exchange!=NULL)
		           {
		           	if(exchange->expn==exexp)
					   {
					   	exchange->coef=newcoe;
					   	countex++;
					   }
		           	exchange=exchange->next;
		           }
		           if(countex==0) printf("������ָ��������\n");
		           break;}
			 case 10:printf("����ʽ�˷�\n");
			         printf("��������һ���˶���ʽ����\n");
			         scanf("%d",&pos1);
			         while(1){
			       	   if((pos1>=1)&&(pos1<=(*psumpolyn))&&(Polynlink[pos1-1]!=NULL))
			       	       break;
			       	   printf("������������һ���˶���ʽ����\n");
			       	   scanf("%d",&pos1);
			         }
			         printf("�������ڶ����˶���ʽ����\n");
			         scanf("%d",&pos2);
			         while(1){
			       	     if((pos2>=1)&&(pos2<=(*psumpolyn))&&(Polynlink[pos2-1]!=NULL))
			       	         break;
			       	     printf("�����������ڶ����˶���ʽ����\n");
			       	     scanf("%d",&pos2);
			         }
			         printf("�������˻�����ʽ����\n");
			         scanf("%d",&pos3);
			         while(1){
			       	     if((pos3>=1)&&(pos3<=(*psumpolyn))&&(Polynlink[pos3-1]==NULL))
			       	         break;
			       	     printf("�����������˻�����ʽ����\n");
			       	     scanf("%d",&pos3);
			         }
			         Fullprotection(Polynlink,psumpolyn);
			         Initpolyn(L);
			         Polynlink[pos3-1]=L;
			         if(Multiplypolyn(Polynlink[pos1-1],Polynlink[pos2-1],Polynlink[pos3-1])==ok)
				         printf("�����ɹ�\n");
				     break;
             case 11:printf("����ʽ����\n");
			         printf("�����뱻������ʽ����\n");
				     scanf("%d",&pos1);
				     while(1){
				         if((pos1>=1)&&(pos1<=(*psumpolyn))&&(Polynlink[pos1-1]!=NULL))
				             break;
				         printf("���������뱻������ʽ����\n");
				         scanf("%d",&pos1);
				     }
				     printf("������������ʽ����\n");
				     scanf("%d",&pos2);
				     while(1){
				   	     if((pos2>=1)&&(pos2<=(*psumpolyn))&&(Polynlink[pos2-1]!=NULL))
				   	         break;
				   	     printf("����������������ʽ����\n");
				         scanf("%d",&pos2);
				     }
				     printf("�������̶���ʽ������\n");
				     scanf("%d",&pos3);
				     while(1){
				   	     if((pos3>=1)&&(pos3<=(*psumpolyn))&&(Polynlink[pos3-1]==NULL))
				   	         break;
					     printf("�����������̶���ʽ������\n");
				         scanf("%d",&pos3);
				     }
				     //Fullprotection(Polynlink,psumpolyn);
				     Initpolyn(L);
			         if(!L)
			             return overflow;
			         Polynlink[pos3-1]=L;
			         printf("������������ʽ������\n");
				     scanf("%d",&pos4);
				     while(1){
				   	     if((pos4>=1)&&(pos4<=(*psumpolyn))&&(Polynlink[pos4-1]==NULL))
				   	         break;
					     printf("����������������ʽ������\n");
				         scanf("%d",&pos4);
				     }
				     Fullprotection(Polynlink,psumpolyn);
				     Initpolyn(L);
			         if(!L)
			             return overflow;
			         Polynlink[pos4-1]=L;
				     if(Dividepolyn(Polynlink[pos1-1],Polynlink[pos2-1],Polynlink[pos3-1],Polynlink[pos4-1])==ok)
				         printf("�����ɹ�\n");
				     else
				         printf("����ʧ��\n");
				     break;
			 case 12:printf("����ʽ�˷�\n");
			         printf("���������˷�����ʽ����\n");
				     scanf("%d",&pos1);
				     while(1){
				         if((pos1>=1)&&(pos1<=(*psumpolyn))&&(Polynlink[pos1-1]!=NULL))
				             break;
				         printf("�������������˷�����ʽ����\n");
				         scanf("%d",&pos1);
				     }
				     printf("�������˷�����ʽ����\n");
				     scanf("%d",&pos2);
				     while(1){
				   	     if((pos2>=1)&&(pos2<=(*psumpolyn))&&(Polynlink[pos2-1]==NULL))
				   	         break;
				   	     printf("�����������˷�����ʽ����\n");
				         scanf("%d",&pos2);
				     }
				     Initpolyn(L);
				     if(!L)
					     return overflow;
					 Polynlink[pos2-1]=L;
				     printf("�������η���\n");
					 scanf("%d",&power);
					 while(1){
					 	if(power>0||power<1000)
					 	    break;
					 	printf("�����������˷���\n");
					 	scanf("%d",&power);
					 }
					 if(Powerpolyn(Polynlink[pos1-1],Polynlink[pos2-1],power)==ok)
					     printf("�˷��ɹ�\n");
					 else
					     printf("�˷�ʧ��\n");
					 break;
			 case 13:printf("����ʽ��N�׵���\n");
			         printf("����������N�׵�������ʽ����\n");
				     scanf("%d",&pos1);
				     while(1){
				         if((pos1>=1)&&(pos1<=(*psumpolyn))&&(Polynlink[pos1-1]!=NULL))
				             break;
				         printf("��������������N�׵�������ʽ����\n");
				         scanf("%d",&pos1);
				     }
				     printf("������N�׵�������ʽ����\n");
				     scanf("%d",&pos2);
				     while(1){
				   	     if((pos2>=1)&&(pos2<=(*psumpolyn))&&(Polynlink[pos2-1]==NULL))
				   	         break;
				   	     printf("����������N�׵�������ʽ����\n");
				         scanf("%d",&pos2);
				     }
				     Initpolyn(L);
				     if(!L)
					     return overflow;
					 Polynlink[pos2-1]=L;
				     printf("�������󵼽���\n");
					 scanf("%d",&diff);
					 while(1){
					 	if(diff>0||diff<1000)
					 	    break;
					 	printf("�����������󵼽���\n");
					 	scanf("%d",&diff);
					 }
					 if(Ndiffcoefpolyn(Polynlink[pos1-1],Polynlink[pos2-1],diff)==ok)
					     printf("��N�׵����ɹ�\n");
					 else
					     printf("��N�׵���ʧ��\n");
					 break;
			 case 14:printf("���Ǹ�ָ������ʽ��������\n");
			         printf("���������󲻶����ֶ���ʽ����\n");
				     scanf("%d",&pos1);
				     while(1){
				         if((pos1>=1)&&(pos1<=(*psumpolyn))&&(Polynlink[pos1-1]!=NULL))
				             break;
				         printf("�������������󲻶����ֶ���ʽ����\n");
				         scanf("%d",&pos1);
				     }
				     printf("�����벻�����ֶ���ʽ����\n");
				     scanf("%d",&pos2);
				     while(1){
				   	     if((pos2>=1)&&(pos2<=(*psumpolyn))&&(Polynlink[pos2-1]==NULL))
				   	         break;
				   	     printf("���������벻�����ֶ���ʽ����\n");
				         scanf("%d",&pos2);
				     }
				     Initpolyn(L);
				     if(!L)
					     return overflow;
					 Polynlink[pos2-1]=L;
					 if(Indfintegralpolyn(Polynlink[pos1-1],Polynlink[pos2-1])==ok)
					     printf("�󲻶����ֳɹ�\n");
					 else
					     printf("�󲻶�����ʧ��\n");
					 break;
			 case 15:{
			 	printf("����ѡ���밴1������ʽ�����밴2\n");
				 int choice=0;
				 scanf("%d",&choice);
				 if(choice==1)
				 {
				 	system("start definte.bat");
				 	break;
				 }
				 else
				 {
			         printf("���Ǹ�ָ������ʽ������\n");
			         printf("���������󶨻��ֶ���ʽ����\n");
				     scanf("%d",&pos1);
				     while(1){
				         if((pos1>=1)&&(pos1<=(*psumpolyn))&&(Polynlink[pos1-1]!=NULL))
				             break;
				         printf("�������������󶨻��ֶ���ʽ����\n");
				         scanf("%d",&pos1);
				     }
				     printf("�����붨��������\n");
				     scanf("%lf",&x1);
				     printf("�����붨��������\n");
				     scanf("%lf",&x2);
				     if(Dfintegralpolyn(Polynlink[pos1-1],value,x1,x2)==ok)
					     printf("�󶨻��ֳɹ���������ֵΪ%lf\n",value);
					 else
					     printf("�󶨻���ʧ��\n");
					 break;
				}
					}
			 case 16:printf("������ʽ��������ʽ\n");
			         printf("��������һ������ʽ����\n");
			         scanf("%d",&pos1);
			         while(1){
			       	   if((pos1>=1)&&(pos1<=(*psumpolyn))&&(Polynlink[pos1-1]!=NULL))
			       	       break;
			       	   printf("������������һ������ʽ����\n");
			       	   scanf("%d",&pos1);
			         }
			         printf("�������ڶ�������ʽ����\n");
			         scanf("%d",&pos2);
			         while(1){
			       	     if((pos2>=1)&&(pos2<=(*psumpolyn))&&(Polynlink[pos2-1]!=NULL))
			       	         break;
			       	     printf("�����������ڶ�������ʽ����\n");
			       	     scanf("%d",&pos2);
			         }
			         printf("��������������ʽ����\n");
			         scanf("%d",&pos3);
			         while(1){
			       	     if((pos3>=1)&&(pos3<=(*psumpolyn))&&(Polynlink[pos3-1]==NULL))
			       	         break;
			       	     printf("������������������ʽ����\n");
			       	     scanf("%d",&pos3);
			         }
			         Fullprotection(Polynlink,psumpolyn);
			         Initpolyn(L);
			         if(!L)
			             return overflow;
			         Polynlink[pos3-1]=L;
			         if(Gcdpolyn(Polynlink[pos1-1],Polynlink[pos2-1],Polynlink[pos3-1])==ok)
				         printf("����������ʽ�ɹ�\n");
					 else
					     printf("����������ʽʧ��\n");
                     break;
			 case 17:printf("������ʽ��С����ʽ\n");
			         printf("��������һ������ʽ����\n");
			         scanf("%d",&pos1);
			         while(1){
			       	   if((pos1>=1)&&(pos1<=(*psumpolyn))&&(Polynlink[pos1-1]!=NULL))
			       	       break;
			       	   printf("������������һ������ʽ����\n");
			       	   scanf("%d",&pos1);
			         }
			         printf("�������ڶ�������ʽ����\n");
			         scanf("%d",&pos2);
			         while(1){
			       	     if((pos2>=1)&&(pos2<=(*psumpolyn))&&(Polynlink[pos2-1]!=NULL))
			       	         break;
			       	     printf("�����������ڶ�������ʽ����\n");
			       	     scanf("%d",&pos2);
			         }
			         printf("��������С����ʽ����\n");
			         scanf("%d",&pos3);
			         while(1){
			       	     if((pos3>=1)&&(pos3<=(*psumpolyn))&&(Polynlink[pos3-1]==NULL))
			       	         break;
			       	     printf("������������С������ʽ����\n");
			       	     scanf("%d",&pos3);
			         }
			         Fullprotection(Polynlink,psumpolyn);
			         Initpolyn(L);
			         if(!L)
			             return overflow;
			         Polynlink[pos3-1]=L;
			         if(Lcmpolyn(Polynlink[pos1-1],Polynlink[pos2-1],Polynlink[pos3-1])==ok)
				         printf("����С����ʽ�ɹ�\n");
					 else
					     printf("����С����ʽʧ��\n");
					 break;
			 case 18:printf("����ʽ��������\n");
			         printf("��������������,����#����\n");
			         Cleararray(input);
			         fflush(stdin);
			         for(j=0;(ch=getchar())!='#';j++){
			         	input[j]=ch;
			         }
			         printf("%c",input[0]);
			         input[j++]='#';
			         input[j]='\0';
			         printf("�������¶���ʽ����\n");
			         scanf("%d",&pos1);
			         while(1){
			       	        if((pos1>=1)&&(pos1<=(*psumpolyn))&&(Polynlink[pos1-1]==NULL))
			       	            break;
			       	        printf("�����������¶���ʽ����\n");
			       	        scanf("%d",&pos1);
			         }
			         Initpolyn(L);
			         if(!L)
			             return overflow;
			         Polynlink[pos1-1]=L;
			         if(Multicalculation(input,Polynlink,Polynlink[pos1-1],psumpolyn)==ok)
					     printf("����ʽ���������ɹ�\n");
					 else
					     printf("����ʽ��������ʧ��\n");
					 break;
	    }
    }
    return ok;
}
Status Printpolyn(Linklist L){
	Lnode *p=NULL;
	if(!L){
		printf("����ʽδ������.\n");
	    return error;
	}
	p=L->next;
	if(!p){
		printf("NULL\n");
		return ok;
	}
	if(!(fabs(p->coef)<0.000001)){
		if(p->expn!=1&&p->expn!=0)
	    printf("%.3lfX^%d",p->coef,p->expn);
		else{
			if(p->expn==0)
			    printf("%.3lf",p->coef);
			else
			    printf("%.3lfX",p->coef);
		}
	}
	for(p=p->next;p;p=p->next){
        if(p->coef>0){
		    if(p->expn!=1&&p->expn!=0)
	        printf("+%lfX^%d",p->coef,p->expn);
	    	else{
		    	if(p->expn==0)
			        printf("+%lf",p->coef);
			    else
			        printf("+%lfX",p->coef);
		    }
	    }
	    if(p->coef<0){
		    if(p->expn!=1&&p->expn!=0)
		        printf("%lfX^%d",p->coef,p->expn);
 	        else{
		   	    if(p->expn==0)
			        printf("%lf",p->coef);
			    else
			        printf("%lfX",p->coef);
		    }
	    }
    }
	printf("\n");
	return ok;
}
Status Printaggregationpolyn(int m,int n,Linklist *Polynlink){
	if(m>n)
	    return error;
	int i;
	for(i=m;i<=n;i++){
		printf("%d:",i);
		Printpolyn(Polynlink[i-1]);
	}
	printf("\n");
	return ok;
}
Status Fullprotection(Linklist *a,int *psum){
	int i;
	int newsize,oldsize;
	Linklist *newbase;
	if(Arrfull(a,psum)){
		newsize=*psum+ListIncrement;
		oldsize=*psum;
		newbase=(Linklist*)realloc(a,newsize*sizeof(Linklist));
		if(!newbase)
		    return overflow;
	    a=newbase;
		*psum+=ListIncrement;
		for(i=oldsize;i<newsize;i++)
		    a[i]=NULL;
	}
	return ok;
}
Status Createpolyn(Linklist &L){
	/*for(int i=0;i<10;){
		for(int j=0;j<10;f[i][j]=0,j++);
		i++;
	}*/
	double coef;
	int expn;
	Lnode *s;
	char F[100]={0},coe[10]={0},exp[10]={0};
	printf("����������ʽ\n");
	fflush(stdin);
	gets(F);
	cut(F);
	int i=0,countx=0;
	/*while(f[i][0]!=0)
	{
		puts(f[i]);
		i++;
	}*/
	i=0;
	Initpolyn(L);
	while(f[i][0]!=0){
		int j=0,k=0;
		countx=0;
		for(k=0;f[i][k]!=0;)
		{
			if(f[i][k]=='x') countx++;
			k++;
		}
		//printf("X: %d\n",countx);
		if(f[i][0]=='x') coef=1;
		else
		{
			for(j=0;f[i][j]!='x'&&f[i][j]!=0;)
			{
				coe[j]=f[i][j];
				j++;
			}
			coef=atof(coe);
		}
		//printf("%c\n",f[i][j]);
		if(countx==0) expn=0;
		else
		if(f[i][j+1]==0) expn=1;
		else
		{
			if(f[i][j+1]=='^'){
				j=j+2;
				//printf("right\n");
			}
			for(int z=0;f[i][j]!=0;)
			{
				exp[z]=f[i][j];
				z++;
				j++;
			}
			//puts(exp);
			expn=atoi(exp);
		}
		//printf("%f\n",coef);
		//printf("%d\n",expn);
		s=Makenode();
		if(!s)
		    return overflow;
		Setnode(s,coef,expn);
		Orderinsert(L,s,coef,expn);
		i++;
		for(int z=0;z<10;exp[z]=0,coe[z]=0,z++);
    }
	/*while(1){
		printf("������ϵ����ָ��(ϵ��Ϊ0ʱ����)\n");
		scanf("%lf",&coef);
		scanf("%d",&expn);
		if(fabs(coef)<0.000001)
		    break;
		s=Makenode();
		if(!s)
		    return overflow;
		Setnode(s,coef,expn);
		Orderinsert(L,s,coef,expn);
    }*/
	return ok;
}
Status Destroypolyn(Linklist &L){
	Lnode *p=L,*q=NULL;
	while(p){
		q=p->next;
		p=NULL;
		free(p);
		p=q;
	}
	L=NULL;
	return ok;
}
Status Clearpolyn(Linklist &L){
	Lnode *p,*q;
	if(!L)
	    return error;
	p=L->next;
	while(p){
		q=p->next;
		free(p);
		p=q;
	}
	L->next=NULL;
	return ok;
}
Status Copypolyn(Linklist La,Linklist &Lb){
	if(!La||!Lb)
	    return error;
	Lnode *pa=NULL,*pb=NULL,*p;
	for(pa=La->next,pb=Lb;pa;pa=pa->next,pb=pb->next){
		p=Makenode();
		if(!p)
		    return overflow;
	    pb->next=p;
		pb->next->coef=pa->coef;
		pb->next->expn=pa->expn;
	}
	pb->next=NULL;
	return ok;
}
Status Addpolyn(Linklist La,Linklist Lb,Linklist &Lc){//ǰ����lalblc����ͷ����
    if(!La||!Lb||!Lc)
        return error;
    Lnode *pa=NULL,*pb=NULL,*pc=NULL,*p=NULL;
    pa=La->next;
    pb=Lb->next;
    pc=Lc;
    while(pa&&pb){
    	if(pa->expn>=pb->expn){
    		if(pa->expn>pb->expn){
    			p=Makenode();
    			if(!p)
    			    return overflow;
    			pc->next=p;
    			Setnode(pc->next,pa->coef,pa->expn);
    			pa=pa->next;
    			pc=pc->next;
    		}
    		else{
    			if(!(fabs(pa->coef+pb->coef)<0.000001)){
    				p=Makenode();
    		     	if(!p)
    			        return overflow;
    			    pc->next=p;
    			    Setnode(pc->next,pa->coef+pb->coef,pa->expn);
    			    pa=pa->next;
    			    pb=pb->next;
    			    pc=pc->next;
    			}
    			else{
    				pa=pa->next;
    				pb=pb->next;
    			}
    	    }
        }
    	else{
    		p=Makenode();
    		if(!p)
    		    return overflow;
    		pc->next=p;
   			Setnode(pc->next,pb->coef,pb->expn);
   			pb=pb->next;
   			pc=pc->next;
    	}
    }
    while(pa){
    	p=Makenode();
    	if(!p)
   		    return overflow;
   		pc->next=p;
 		Setnode(pc->next,pa->coef,pa->expn);
   		pa=pa->next;
		pc=pc->next;
   	}
   	while(pb){
   		p=Makenode();
    	if(!p)
    	    return overflow;
    	pc->next=p;
   		Setnode(pc->next,pb->coef,pb->expn);
   		pb=pb->next;
   		pc=pc->next;
   	}
   	pc=NULL;
    return ok;
}
Status Negtivepolyn(Linklist La,Linklist &Lb){//ǰ����La��Lb����ͷ���㣻
	if(!La||!Lb)
	    return error;
	Lnode *pa=NULL,*pb=NULL,*p=NULL;
	for(pa=La->next,pb=Lb;pa;pa=pa->next){
		p=Makenode();
		if(!p)
		    return error;
		pb->next=p;
		Setnode(pb->next,-pa->coef,pa->expn);
		pb=pb->next;
    }
	pb->next=NULL;
	return ok;
}
Status Negtiveselfpolyn(Linklist &La){
	if(!La)
	    return error;
	Lnode *pa=La;
	for(;pa->next;pa=pa->next)
		pa->next->coef=-(pa->next->coef);
	return ok;
}
Status Substractpolyn(Linklist La,Linklist &Lb,Linklist &Lc){//LaΪ��������ʽ��Lb������ʽ��
	if(!La||!Lb)
	    return error;
	Negtiveselfpolyn(Lb);
	Addpolyn(La,Lb,Lc);
	Negtiveselfpolyn(Lb);
	return ok;
}
Status Envaluepolyn(Linklist La,double &value,double x){
	Lnode *pa=NULL;
	if(!La)
	    return error;
	for(pa=La,value=0;pa->next;pa=pa->next)
		value+=pa->next->coef*pow(x,(pa->next->expn));
	return ok;
}
Status Modifyonlycoef(Linklist &L){
	double newcoef=0;
	Lnode *p=NULL,*q=NULL;
	if(!L)
	    return error;
	for(p=L;p->next;p=p->next){
		printf("�Ƿ��޸�ָ��Ϊ%d�Ľ�����ϵ��?\n���޸�������#�����޸�����������\n",p->next->expn);
		if(getchar()=='#'){
			printf("�������޸ĺ���ϵ��\n");
			scanf("%lf",newcoef);
			if(fabs(newcoef)<0.000001){
				q=p->next->next;
				free(p->next);
				 p->next=q;
				 continue;
			}
			else
			    p->next->coef=newcoef;
			printf("�޸ĳɹ�\n");
		}
	}
	return ok;
}
Status Modifyonlyexpn(Linklist &L){//////////////////��û���ã�������
	int newexpn=0,notequal=0;
	Lnode *p=NULL,*q=NULL,*r=NULL,*s=NULL,*t=NULL;
	if(!L)
	    return error;
	for(p=L;p->next;){
		printf("�Ƿ��޸�ָ��Ϊ%d�Ľ�����ָ��?\n���޸�������#�����޸�����������\n",p->next->expn);
		if(getchar()=='#'){
			printf("�������޸ĺ���ָ��\n");
			scanf("%d",&newexpn);

			}

		}
}
Status Modifypolyn(Linklist &L){
	if(!L)
	    return error;
	double coef;
	int expn;
	Lnode *s;
	Clearpolyn(L);
	while(1){
		printf("������ϵ����ָ��(ϵ��Ϊ0ʱ����)\n");
		scanf("%lf",&coef);
		scanf("%d",&expn);
		if(fabs(coef)<0.000001)
		    break;
		s=Makenode();
		if(!s)
		    return overflow;
		Setnode(s,coef,expn);
		Orderinsert(L,s,coef,expn);
    }
	return ok;
}
Status Coefexpnpolyn(Linklist La,Linklist &Lb,double c,int e){//��La��ϵ������c������La��ָ������e��,�浽Lb�У�
	Lnode *pa=NULL,*pb=NULL,*p=NULL;
	if(!La||!Lb)
	    return error;
	if(fabs(c)<0.000001){
		return ok;
	}
	for(pa=La,pb=Lb;pa->next;pa=pa->next){
	    p=Makenode();
	    if(!p)
	        return overflow;
	    Setnode(p,c*pa->next->coef,e+pa->next->expn);
	    pb->next=p;
	    pb=pb->next;
	}
	return ok;
}
Status Addlocalpolyn(Linklist La,Linklist &Lb){//���ؼӷ� ,�ӵ�Lb��; //������orderinsert��Ϊ��ʱ�䣬Ҳ���ܹ��ý��㣡���� if else �����ã�����;
	if(!La||!Lb)
	    return error;
	Lnode *pa=NULL,*pb=NULL,*p=NULL,*q=NULL;
	for(pa=La,pb=Lb;pa->next&&pb->next;){
		if(pa->next->expn>=pb->next->expn){
			if(pa->next->expn>pb->next->expn){
				p=Makenode();
			    if(!p)
			        return overflow;
			    Setnode(p,pa->next->coef,pa->next->expn);
			    p->next=pb->next;
			    pb->next=p;
			    pa=pa->next;
			    pb=pb->next;
			}
			else{
				if(fabs(pa->next->coef+pb->next->coef)<0.000001){
				    q=pb->next;
				    pb->next=q->next;
				    free(q);
				    pa=pa->next;
			    }
		        else{
		    	    pb->next->coef+=pa->next->coef;
		            pa=pa->next;
			        pb=pb->next;
			    }
		    }
	    }
	    else
	        pb=pb->next;
	}
	while(pa->next){
		p=Makenode();
		if(!p)
		    return overflow;
		Setnode(p,pa->next->coef,pa->next->expn);
		pb->next=p;
		pb=pb->next;
		pa=pa->next;
	}
	return ok;
}
Status Substractlocalpolyn(Linklist &La,Linklist Lb){//���ؼ�������������ʽ�ϣ�
	if(!La||!Lb)
	    return error;
	if(Negtiveselfpolyn(Lb)==overflow)
	    return overflow;
	if(Addlocalpolyn(Lb,La)==overflow)
	    return overflow;
	if(Negtiveselfpolyn(Lb)==overflow)
	    return overflow;
	return ok;
}
Status Multiplypolyn(Linklist La,Linklist Lb,Linklist &Lc){         //////��ȷ��������
	if(!La||!Lb||!Lc)
	    return error;
	Lnode *pa=NULL;
	Linklist Ld=NULL;
	int status;
	if(Initpolyn(Ld)==overflow)
	    return overflow;
	for(pa=La;pa->next;pa=pa->next){
		status=Coefexpnpolyn(Lb,Ld,pa->next->coef,pa->next->expn);
		if(status==overflow)
		    return overflow;
		if(status==error)
		    return error;
	    Addlocalpolyn(Ld,Lc);
	    Clearpolyn(Ld);
	}
	Destroypolyn(Ld);
	return ok;
}
Status Dividepolyn(Linklist La,Linklist Lb,Linklist &Lc,Linklist &Ld){//La����ʽ,Lb��ʽ,Lc��ʽ,Ld��ʽ
	if(!La||!Lb||!Lc||!Ld)
	    return error;
    Lnode *pc=NULL,*p=NULL;
    Linklist Le=NULL,Lf=NULL;
    double division=0;
    if(Initpolyn(Le)==overflow)
        return overflow;
    if(Initpolyn(Lf)==overflow)
        return overflow;
    Copypolyn(La,Le);
    for(pc=Lc;Le->next&&Lb->next&&Le->next->expn>=Lb->next->expn;){
    	division=Le->next->coef/Lb->next->coef;
    	p=Makenode();
    	if(!p)
    	    return overflow;
		Setnode(p,division,Le->next->expn-Lb->next->expn);
		pc->next=p;
		pc=pc->next;
    	Coefexpnpolyn(Lb,Lf,division,Le->next->expn-Lb->next->expn);
    	Substractlocalpolyn(Le,Lf);
		Clearpolyn(Lf);//���ؼ�������������ʽ�ϣ�
    }
    Copypolyn(Le,Ld);
    Destroypolyn(Le);
    Destroypolyn(Lf);
    return ok;
}
Status Powerpolyn(Linklist La,Linklist &Lb,int n){
	if(!La||!Lb||n<=0)
	    return error;
	int i,j;
	Linklist Lc=NULL;
	if(Initpolyn(Lc)==overflow)
	    return overflow;
	for(i=1,j=1;i<n;i++,j++){
		Copypolyn(Lb,Lc);
		Multiplypolyn(La,La,Lc);
		Copypolyn(Lc,Lb);
		Clearpolyn(Lc);
	}
	return ok;
}
Status Diffcoefpolyn(Linklist La,Linklist &Lb){
	if(!La||!Lb)
	    return error;
	Lnode *pa=NULL,*pb=NULL,*p=NULL;
	for(pa=La,pb=Lb;pa->next;pa=pa->next){
		p=Makenode();
    	if(!p)
    	    return overflow;
    	if(pa->next->expn!=0){
    	    Setnode(p,(pa->next->expn)*(pa->next->coef),pa->next->expn-1);
    	    pb->next=p;
			pb=pb->next;
        }
	}
	return ok;
}
Status Ndiffcoefpolyn(Linklist La,Linklist &Lb,int n){
	if(!La||!Lb||n<0)
	    return error;
	if(n==0){
		Copypolyn(La,Lb);
		return ok;
	}
	int i,j;
	Linklist Lc=NULL,Ld=NULL;
	Initpolyn(Lc);
	if(!Lc)
	    return overflow;
	Initpolyn(Ld);
	if(!Ld)
	    return overflow;
	i=0;
	j=0;
	Copypolyn(La,Ld);
	do{
		Diffcoefpolyn(Ld,Lc);
		Copypolyn(Lc,Lb);
		Clearpolyn(Ld);
		Copypolyn(Lc,Ld);
		Clearpolyn(Lc);
		i++;
		j++;
	}
	while(i<n&&Lb->next!=NULL);
	Copypolyn(Ld,Lb);
	Destroypolyn(Lc);
	Destroypolyn(Ld);
	if(Lb->next==NULL)
		printf("�ڵ�%d���󵼺�����ʽΪNULL\n",j);
	return ok;
}
Status Indfintegralpolyn(Linklist La,Linklist &Lb){
	if(!La||!Lb)
	    return error;
	Lnode *pa=NULL,*pb=NULL,*p=NULL;
	for(pa=La,pb=Lb;pa->next;pa=pa->next){
		p=Makenode();
		if(!p)
		    return overflow;
		Setnode(p,pa->next->coef/(pa->next->expn+1),pa->next->expn+1);
		pb->next=p;
		pb=pb->next;
	}
	return ok;
}
Status Dfintegralpolyn(Linklist La,double &value,double x1,double x2){
	if(!La)
	    return error;
	Linklist Lb=NULL;
	double value1=0,value2=0;
	Initpolyn(Lb);
	if(!Lb)
	    return overflow;
	Indfintegralpolyn(La,Lb);
	Envaluepolyn(Lb,value1,x1);
	Envaluepolyn(Lb,value2,x2);
	value=value2-value1;
	Destroypolyn(Lb);
	return ok;
}
/*Status Minimum(double a,double b){
	if(a>b)
	    return b;
	else
	    return a;
}*/
Status Gcdpolyn(Linklist La,Linklist Lb,Linklist &Lc){
	if(!La||!Lb||!Lc)
	    return error;
	if(!La->next||!Lb->next){
		Lc=NULL;
		return ok;
	}
	Linklist Le=NULL,Lf=NULL,Lg=NULL,Lz=NULL;
	Initpolyn(Le);
	if(!Le)
	    return overflow;
	Initpolyn(Lf);
	if(!Lf)
	    return overflow;
	Initpolyn(Lg);
	if(!Lg)
	    return overflow;
	Initpolyn(Lz);
	if(!Lz)
	    return overflow;
	if(La->next->expn>=Lb->next->expn){
	    Copypolyn(La,Le);
	    Copypolyn(Lb,Lf);
    }
    else{
    	Copypolyn(La,Lf);
	    Copypolyn(Lb,Le);
    }
	do{
	    Dividepolyn(Le,Lf,Lz,Lg);
	    Clearpolyn(Le);
	    Copypolyn(Lf,Le);
	    Clearpolyn(Lf);
	    Copypolyn(Lg,Lf);
	    Clearpolyn(Lg);
	}
	while(Lf->next!=NULL);
	Copypolyn(Le,Lc);
	Destroypolyn(Le);
	Destroypolyn(Lf);
	Destroypolyn(Lg);
	Destroypolyn(Lz);
	return ok;
}
Status Lcmpolyn(Linklist La,Linklist Lb,Linklist &Lc){
	int a,b,c;
	Linklist Ld=NULL,Le=NULL,Lf=NULL;
	Initpolyn(Ld);
	if(!Ld)
	    return overflow;
	Initpolyn(Le);
	if(!Le)
	    return overflow;
	Initpolyn(Lf);
	if(!Lf)
	    return overflow;
	a=Multiplypolyn(La,Lb,Ld);
	if(a==error)
	    return error;
	if(a==overflow)
	    return overflow;
	b=Gcdpolyn(La,Lb,Le);
	if(b==error)
	    return error;
	c=Dividepolyn(Ld,Le,Lc,Lf);
	if(c==error)
	    return error;
	if(c==overflow)
	    return overflow;
	return ok;
}
Status ScanfDprotection(char str[],double &sum){//������ϵ������;
	int i,j,k,m,n,sum1,l,p,q;
	double sum2;
	for(p=0,q=0,l=0;str[l]!='\0';l++){
	    if(str[l]<'0'||str[l]>'9')
	        p++;
	    if(str[l]=='.')
	        q++;
	    }
	if(p==1&&q==1&&str[0]!='.'&&str[l-1]!='.'){
	for(i=0,m=0;str[i]!='.';i++,m++);
	sum1=str[0]-'0';
	for(j=1;j<=m-1;j++)
	    sum1=(sum1*10+(str[j]-'0'));
	for(k=0,n=0;str[m+k+1]!='\0';k++,n++);
	sum2=(str[m+n]-'0');
	for(j=n-1;j>=1;j--)
	    sum2=(sum2/10.000000+str[m+j]-'0');
	sum2/=10.000000;
	sum=sum1+sum2;
	return ok;
    }
	return error;
}
Status ScanfIprotection(char str[],int &sum){
    int i,j;
    sum=0;
	if(str[0]=='\0')
	    return error;
	if(str[0]=='-'){//Ϊ����ʱ��
		for(i=0,j=0;str[i]!='\0';i++){//iͳ���м���Ԫ�أ�jͳ�Ƽ���������Ԫ��
			if(str[i]<'0'||str[i]>'9')
			    j++;
		}
		if(j>1)
		    return error;
		else{
			if((i>1&&str[1]=='0')||i==1)//�׸����� Ϊ0��error! ,û�����֣�error!
			    return error;
			else{
				sum=str[1]-'0';
	            for(i=2;str[i]!='\0';i++)
	                sum=sum*10+str[i]-'0';
	            sum=(-sum);
	            return ok;
     		}
		}
	}
	else{
		if(str[0]=='0'){//������Ϊ0ʱ������������ȫΪ0��sum=0��������error!
			if(str[1]=='0')
			    return ok;
			return error;
		}
		if(str[0]>'0'||str[0]<'9'){//����ʱ��
			for(i=0,j=0;str[i]!='\0';i++){//iͳ���м���Ԫ�أ�jͳ�Ƽ���������Ԫ��
			    if(str[i]<'0'||str[i]>'9')
			        j++;
	    	}
		    if(j!=0)
		        return error;
		    else{
		    	sum=str[0]-'0';
		        for(i=1;str[i]!='\0';i++)
		            sum=sum*10+str[i]-'0';
	            return ok;
		    }
		}
		else
		    return error;
	}
}
Status Printtaylorpolyn(Linklist L,double taylor){
	Lnode *p=NULL;
	if(!L){
		printf("����ʽδ������.\n");
	    return error;
	}
	p=L->next;
	if(!p){
		printf("NULL\n");
		return ok;
	}
	if(fabs(taylor)<0.000001){
		printf("��������չ��\n");
		Printpolyn(L);
		return ok;
	}
	double ntaylor=-taylor;
	if(taylor>0){
		if(!(fabs(p->coef)<0.000001)){
		    if(p->expn!=1&&p->expn!=0)
	            printf("%lf(X-%lf)^%d",p->coef,taylor,p->expn);
		    else{
			    if(p->expn==0)
			        printf("%lf",p->coef);
			    else
			        printf("%lf(X-%lf)",p->coef,taylor);
		    }
	    }
	    for(p=p->next;p;p=p->next){
            if(p->coef>0){
		        if(p->expn!=1&&p->expn!=0)
	            printf("+%lf(X-%lf)^%d",p->coef,taylor,p->expn);
	    	    else{
		    	    if(p->expn==0)
			            printf("+%lf",p->coef);
			        else
			            printf("+%lf(X-%lf)",p->coef,taylor);
		        }
	        }
	        if(p->coef<0){
		        if(p->expn!=1&&p->expn!=0)
		            printf("%lf(X-%lf)^%d",p->coef,taylor,p->expn);
 	            else{
		   	        if(p->expn==0)
			            printf("%lf",p->coef);
			        else
			            printf("%lf(X-%lf)",p->coef,taylor);
		        }
	        }
        }
	    printf("\n");
	}
	else{
		if(!(fabs(p->coef)<0.000001)){
		    if(p->expn!=1&&p->expn!=0)
	            printf("%lf(X+%lf)^%d",p->coef,ntaylor,p->expn);
		    else{
			    if(p->expn==0)
			        printf("%lf",p->coef);
			    else
			        printf("%lf(X+%lf)",p->coef,ntaylor);
		    }
	    }
	    for(p=p->next;p;p=p->next){
            if(p->coef>0){
	            if(p->expn!=1&&p->expn!=0)
	                printf("+%lf(X+%lf)^%d",p->coef,ntaylor,p->expn);
	    	    else{
			        if(p->expn==0)
    	                printf("+%lf",p->coef);
		            else
		                printf("+%lf(X+%lf)",p->coef,ntaylor);
		        }
            }
			if(p->coef<0){
		        if(p->expn!=1&&p->expn!=0)
		            printf("%lf(X+%lf)^%d",p->coef,ntaylor,p->expn);
 	            else{
		            if(p->expn==0)
	                    printf("%lf",p->coef);
    	            else
		                printf("%lf(X+%lf)",p->coef,ntaylor);
			    }
	        }
        }
	    printf("\n");
	}
	return ok;
}
Status Deletennode(Linklist L,int n){
	Lnode *q=NULL;
	if(!L)
	    return error;
	int i;
	Lnode *p=NULL;
	for(i=0,p=L;p->next&&i<n-1;p=p->next,i++);//��ǰ��!!!
	if(!p->next||i>n){
	    printf("����ֵ�Ƿ�\n");
	    return error;
	}
	else{
		q=p->next;
		p->next=q->next;
		free(q);
		return ok;
	}
}
Status Deletenode(Linklist L,int expn){
	if(!L)
	    return error;
	Lnode *p=NULL,*q=NULL;
	for(p=L;p->next;p=p->next){
		if(p->next->expn==expn){
			q=p->next->next;
			free(p->next);
			p->next=q;
			return ok;
		}
	}
	return error;
}
Status Insertnode(Linklist L,double newcoef,int newexpn){
	if(!L)
	    return ok;
	int notequal=0;
	Lnode *p=NULL,*q=NULL,*r=NULL;
	if(fabs(newcoef)<0.000001)
	    return ok;
	for(p=L;p->next;p=p->next){
		if(p->next->expn<newexpn){
			r=Makenode();
			if(!r)
			    return overflow;
			Setnode(r,newcoef,newexpn);
			r->next=p->next->next;
			p->next=r;
			return ok;
		}
		else{
			if(p->next->expn==newexpn){
		 	    if(fabs(newcoef+p->next->coef)<0.000001){
				    q=p->next->next;
				    free(p->next);
				    p->next=q;
				    return ok;
			    }
		     	else{
			        p->next->coef+=newcoef;
			        return ok;
				}
		    }
		}
	}
    r=Makenode();
	if(!r)
	    return overflow;
	Setnode(r,newcoef,newexpn);
	r->next=p->next->next;
	p->next=r;
	return ok;
}
Status Modifycoefexpn(Linklist L){
	if(!L||!(L->next))
	    return error;
	int newcoef,newexpn;
	Lnode *p=NULL,*q=NULL,*r=NULL,*s=NULL;
	for(p=L;p->next;){
		printf("�Ƿ��޸�ָ��Ϊ%d�Ľ�����ϵ����ָ��?\n���޸�������#�����޸�����������\n",p->next->expn);
		if(getchar()=='#'){
			printf("��������ϵ����ָ��\n");
			scanf("%d%d",&newcoef,&newexpn);
			if(fabs(newcoef)<0.000001){
				r=p->next->next;
				free(p->next);
				p->next=r;
			}
			else{
				if(p->next->expn<=newexpn){
					if(p->next->expn==newexpn){
						p->next->coef=newcoef;
						p=p->next;
					}
					else{
						s=Makenode();
						if(!s)
						    return overflow;
						Setnode(s,newcoef,newexpn);
						s->next=p->next->next;
						p->next=s;
						p=p->next;
					}
				}
				else
					p=p->next;
			}
		}
		else
		    p=p->next;
	}
}
Status Judgeoperator(char c){
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='%'||c=='#'||c=='('||c==')')
	    return True;
	return False;
}
Status Judgeoperand(char *s,int &sum){
    if(ScanfIprotection(s,sum)==ok)
	    return ok;
	else
	    return error;
}
char Prior(char left,char right){
	if(Judgeoperator(left)==False||Judgeoperator(right)==False)
	    return '!';
	if(left=='+'){
		if(right=='+')
		    return '>';
		if(right=='-')
		    return '>';
		if(right=='*')
		    return '<';
		if(right=='/')
		    return '<';
		if(right=='(')
		    return '<';
		if(right==')')
		    return '>';
		if(right=='#')
		    return '>';
	}
	if(left=='-'){
		if(right=='+')
		    return '>';
		if(right=='-')
		    return '>';
		if(right=='*')
		    return '<';
		if(right=='/')
		    return '<';
		if(right=='(')
		    return '<';
		if(right==')')
		    return '>';
		if(right=='#')
		    return '>';
	}
	if(left=='*'){
		if(right=='+')
		    return '>';
		if(right=='-')
		    return '>';
		if(right=='*')
		    return '>';
		if(right=='/')
		    return '>';
		if(right=='(')
		    return '<';
		if(right==')')
		    return '>';
		if(right=='#')
		    return '>';
	}
	if(left=='/'){
		if(right=='+')
		    return '>';
		if(right=='-')
		    return '>';
		if(right=='*')
		    return '>';
		if(right=='/')
		    return '>';
		if(right=='(')
		    return '<';
		if(right==')')
		    return '>';
		if(right=='#')
		    return '>';
	}
	if(left=='('){
		if(right=='+')
		    return '<';
		if(right=='-')
		    return '<';
		if(right=='*')
		    return '<';
		if(right=='/')
		    return '<';
		if(right=='(')
		    return '<';
		if(right==')')
		    return '=';
		if(right=='#')
		    return '!';
	}
	if(left==')'){
		if(right=='+')
		    return '>';
		if(right=='-')
		    return '>';
		if(right=='*')
		    return '>';
		if(right=='/')
		    return '>';
		if(right=='(')
		    return '!';
		if(right==')')
		    return '>';
		if(right=='#')
		    return '>';
	}
	if(left=='#'){
		if(right=='+')
		    return '<';
		if(right=='-')
		    return '<';
		if(right=='*')
		    return '<';
		if(right=='/')
		    return '<';
		if(right=='(')
		    return '<';
		if(right==')')
		    return '!';
		if(right=='#')
		    return '=';
	}
}
Status Cleararray(char *s){
    char *p=NULL;
    for(p=s;*p!='\0';p++)
        *p='\0';
    return ok;
}
Status Calculatepolyn(char ch,Linklist La,Linklist Lb,Linklist &Lc){
	if(!La||!Lb||!Lc)
	    return error;
	Linklist Ld=NULL;
	switch(ch){
		case '+':Addpolyn(La,Lb,Lc);
		         break;
		case '-':Substractpolyn(La,Lb,Lc);
		         break;
		case '*':Multiplypolyn(La,Lb,Lc);
		         break;
	    case '/':Initpolyn(Ld);
	             if(!Ld)
	                 return overflow;
	             if(Lb->next==NULL)
	                 return error;
		         Dividepolyn(La,Lb,Lc,Ld);
	             Destroypolyn(Ld);
	             break;
	    case '%':Initpolyn(Ld);
	             if(!Ld)
	                 return overflow;
	             if(Ld->next==NULL)
	                 return error;
		         Dividepolyn(La,Lb,Ld,Lc);
		         break;
	}
	return ok;
}
Status Multicalculation(char *input,Linklist *Polynlink,Linklist &L,int *psumpolyn){
	int position,j;
	char topchar;
	char operand[30];
    char *traverse=input;
    Linklist La=NULL,Lb=NULL,Lc=NULL,Ld=NULL;
    Linkopnd opndtop=NULL;
    Linkoptr optrtop=NULL;
    Cleararray(operand);
	if(Initlinkliststack(opndtop)==ok&&Initcharstack(optrtop)==ok);
	else{
		printf("�������˳�\n");
		return overflow;
	}
	Pushchar(optrtop,'#');
	for(;*traverse!='\0';traverse++){
		if(*traverse=='P'){
			traverse++;
			for(j=0;Judgeoperator(*traverse)!=True;j++,traverse++)//operand����Ӧ���㣡����
				operand[j]=*traverse;
			if(Judgeoperand(operand,position)==error&&position<=0){
				printf("�����ַ��Ƿ��������˳�������������\n");
				return error;
			}
			else{
				Cleararray(operand);
				if(position>0&&position<=*psumpolyn&&Polynlink[position-1]!=NULL){
					Pushlinklist(opndtop,Polynlink[position-1]);
					traverse--;
				}
				else{
					printf("�������ݷ�Χ�Ƿ�,�����˳�������������\n");
						return error;
				}
			}
		}
		else{
			for(;Judgeoperator(*traverse)==True;){
				Getchartop(optrtop,topchar);
				if(Prior(topchar,*traverse)=='<'){
					Pushchar(optrtop,*traverse);
					break;
				}
				else{
					if(Prior(topchar,*traverse)=='='){
						if(topchar=='#'){
							Getlinklisttop(opndtop,Ld);
			                Copypolyn(Ld,L);
			                return ok;
						}
						else{
				    	    Popchar(optrtop,topchar);
						    break;
						}
					}
					else{
						if(Prior(topchar,*traverse)=='>'){
							Poplinklist(opndtop,Lb);
							Poplinklist(opndtop,La);
							Popchar(optrtop,topchar);
			                Initpolyn(Lc);
			                if(!Lc)
			                    return overflow;
							if(Calculatepolyn(topchar,La,Lb,Lc)!=ok){
								printf("�����Ƿ�����ĸΪNULL�������˳�������������\n");
								return error;
							}
							Pushlinklist(opndtop,Lc);
						}
						else{
							printf("�����Ƿ��������ַ���Ϊ�������������˳�������������\n");
							return error;
						}
					}
				}
			}
		}
	}
}
