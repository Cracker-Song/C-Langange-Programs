#include"hash.h"
Status InitHashTable(HashTable &H)// �������: ����һ���յĹ�ϣ��
{  
   int i;
   H.count=0; // ��ǰԪ�ظ���Ϊ0
   H.sizeindex=0; // ��ʼ�洢����Ϊhashsize[0]
   m=hashsize[0];
   H.elem=(ElemType*)malloc(m*sizeof(ElemType));
   if(!H.elem)
     exit(OVERFLOW); // �洢����ʧ��
   for(i=0;i<m;i++)
     H.elem[i].key=NULLKEY; // δ���¼�ı�־
   return OK;
}
void DestroyHashTable(HashTable &H)// ��ʼ����: ��ϣ��H���ڡ��������: ���ٹ�ϣ��H
{  free(H.elem);
   H.elem=NULL;
   H.count=0;
   H.sizeindex=0;
}
unsigned Hash(KeyType K)// һ���򵥵Ĺ�ϣ����(mΪ����ȫ�ֱ���)
{ return K%m;
}
void collision(int &p,int d) // ����̽����ɢ��
{ 
   p=(p+d)%m;// ���Ŷ�ַ�������ͻ
}
Status SearchHash(HashTable H,KeyType K,int &p,int &c)// �ڿ��Ŷ�ַ��ϣ��H�в��ҹؼ���ΪK��Ԫ��,�����ҳɹ�,��pָʾ��������
{ p=Hash(K); // ��ù�ϣ��ַ
   while(H.elem[p].key!=NULLKEY&&!EQ(K,H.elem[p].key))
   { // ��λ�������м�¼�����ҹؼ��ֲ����
     c++;
     if(c<m)
       collision(p,c); // �����һ̽���ַp
     else
       break;
   }
   if EQ(K,H.elem[p].key)
     return SUCCESS; // ���ҳɹ���p���ش�������Ԫ��λ��
   else
     return UNSUCCESS; // ���Ҳ��ɹ�(H.elem[p].key==NULLKEY)��p���ص��ǲ���λ��
}
Status InsertHash(HashTable &,ElemType); // �Ժ���������
void RecreateHashTable(HashTable &H) // �ؽ���ϣ��
{ 
   int i,count=H.count;
   ElemType *p,*elem=(ElemType*)malloc(count*sizeof(ElemType));
   p=elem;
   //printf("�ؽ���ϣ��\n");
   for(i=0;i<m;i++) // ����ԭ�е����ݵ�elem��
   if((H.elem+i)->key!=NULLKEY) // �õ�Ԫ������
   *p++=*(H.elem+i);
   H.count=0;
   H.sizeindex++; // ����洢����
   m=hashsize[H.sizeindex];
   p=(ElemType*)realloc(H.elem,m*sizeof(ElemType));
   if(!p)
     exit(OVERFLOW); // �洢����ʧ��
   H.elem=p;
   for(i=0;i<m;i++)
     H.elem[i].key=NULLKEY; // δ���¼�ı�־(��ʼ��)
   for(p=elem;p<elem+count;p++) // ��ԭ�е����ݰ����µı����뵽�ؽ��Ĺ�ϣ����
     InsertHash(H,*p);
}
Status InsertHash(HashTable &H,ElemType e)// ���Ҳ��ɹ�ʱ��������Ԫ��e�����Ŷ�ַ��ϣ��H�У�������OK��
{ int c,p;
   c=0;
   if(SearchHash(H,e.key,p,c)) // ����������e����ͬ�ؼ��ֵ�Ԫ��
     return DUPLICATE;
   else if(c<hashsize[H.sizeindex]/2) // ��ͻ����cδ�ﵽ����,(c�ķ�ֵ�ɵ�)
   { // ����e
     H.elem[p]=e;
     ++H.count;
     return OK;
   }
   else
     RecreateHashTable(H); // �ؽ���ϣ��
   return ERROR;
}
void TraverseHash(HashTable H,void(*Vi)(int,ElemType))// ����ϣ��ַ��˳�������ϣ��
{ 
   printf("��ϣ��ַ0��%d\n",m-1);
   for(int i=0;i<m;i++)
     if(H.elem[i].key!=NULLKEY) // ������
       Vi(i,H.elem[i]);
}
Status Find(HashTable H,KeyType K,int &p)// �ڿ��Ŷ�ַ��ϣ��H�в��ҹؼ���ΪK��Ԫ��,�����ҳɹ�,��pָʾ��������
{ int c=0;
   p=Hash(K); // ��ù�ϣ��ַ
   while(H.elem[p].key!=NULLKEY&&!EQ(K,H.elem[p].key))// ��λ�������м�¼�����ҹؼ��ֲ����
   { 
     asl++;
     c++;
     if(c<m)
       collision(p,c); // �����һ̽���ַp
     else
     return UNSUCCESS; // ���Ҳ��ɹ�(H.elem[p].key==NULLKEY)
   }
   if EQ(K,H.elem[p].key)
     return SUCCESS; // ���ҳɹ���p���ش�������Ԫ��λ��
   else
     return UNSUCCESS; // ���Ҳ��ɹ�(H.elem[p].key==NULLKEY)
}
void print(int p,ElemType r)//���
{
   printf("address=%d (%d,%d)\n",p,r.key,r.ord);
}
int main(void)
{
	int choice=0;
	int delnum=0;
	int insertnum=0;
	int posinsert=0;
	ElemType r[15]={{49,1},{30,2},{10,3},{41,4},{57,5},{14,6},{47,7},{23,8},{53,9},{66,10},{18,11},{68,12},{20,13},{44,14}};
	HashTable h;
	//h=(HashTable *)malloc(sizeof(HashTable));
	int i,p;
    Status j;
    KeyType k;
	while(1)
	{
		printf("1.������ϣ��\n2.��ʾ��ϣ��\n3.����\n4.����ASL\n5.ɾ��\n6.����\n7.�˳�\n");
		printf("������Ҫѡ��Ĺ���:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:printf("�������\n");break;
			case 1:
				InitHashTable(h);
				for(i=0;i<N-1;i++)// ����ǰN-1����¼
				{ 
					j=InsertHash(h,r[i]);
					if(j==DUPLICATE)
					printf("�������йؼ���Ϊ%d�ļ�¼���޷��ٲ����¼(%d,%d)\n",r[i].key,r[i].key,r[i].ord);
				}
				//printf("%d\n",m);
				break;
			case 2:
				printf("����ϣ��ַ��˳�������ϣ��:\n");
				TraverseHash(h,print);
				break;
			case 3:
				asl=0;
				printf("����������Ҽ�¼�Ĺؼ���: ");
				scanf("%d",&k);
				j=Find(h,k,p);
				if(j==SUCCESS)
					print(p,h.elem[p]);
				else
					printf("�����ڸ�Ԫ��\n");
				break;
			case 4:
				asl=0;
				Find(h,49,p);
				Find(h,30,p);
				Find(h,10,p);
				Find(h,41,p);
				Find(h,57,p);
				Find(h,14,p);
				Find(h,47,p);
				Find(h,23,p);
				Find(h,53,p);
				Find(h,66,p);
				Find(h,18,p);
				Find(h,68,p);
				Find(h,20,p);
				Find(h,44,p);
				printf("%f\n",float(asl)/14);
				break;
			case 5:
				printf("������Ҫɾ����Ԫ��ֵ\n");
				scanf("%d",&delnum);
				j=Find(h,delnum,p);
				if(j==SUCCESS)
				{
					for(int pos=h.elem[p].ord-1;pos<=14;)
					{
						//printf("%d\n",pos);
						r[pos].key=r[pos+1].key;
						//r[pos].ord=r[pos+1].ord;
						pos++;
					}
					//for(int pos=0;pos<14;printf("%d\n",r[pos].key),pos++);
					r[m].key=0;
					r[m].ord=0;
					m--;
					N--;
					//h.count--;
					DestroyHashTable(h);
					//print(p,h.elem[p]);
				}
					//print(p,h.elem[p]);
				else
					printf("�����ڸ�Ԫ��\n");
				break;
			case 6:
				printf("������Ҫ�������\n");
				scanf("%d",&insertnum);
				m++;
				N++;
				r[13].key=insertnum;
				r[13].ord=14;
				DestroyHashTable(h);
				break;
				/*printf("������Ҫ�����λ��\n");
				scanf("%d",&posinsert);
				for(int pos=posinsert-1;pos<=15;)
				{
					//printf("%d\n",pos);
					r[pos].key=r[pos+1].key;
					//r[pos].ord=r[pos+1].ord;
					pos++;
				}
				//for(int pos=0;pos<14;printf("%d\n",r[pos].key),pos++);
				r[m].key=0;
				r[m].ord=0;
				m--;
				N--;
				//h.count--;
				DestroyHashTable(h);*/
			case 7:return 0;
		}
	}
   /*j=InsertHash(h,r[i]); // �����N����¼
   if(j==ERROR) // �ؽ���ϣ��
     j=InsertHash(h,r[i]); // �ؽ���ϣ������²���
   printf("����ϣ��ַ��˳������ؽ���Ĺ�ϣ��:\n");
   TraverseHash(h,print);*/
}
