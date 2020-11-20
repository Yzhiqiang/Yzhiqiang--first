/*
�����ַ�����Ȼ��һ������ʱ���ƽ�ʡ�ռ䣬��������һ������ʱ��Ҫ����һ����������ʽ�������ʽ��ʵ���˷��ڴ� 
���ڴ�������������������������Ľ������һ�㣬�����ڲ��ƻ�ԭ����Ļ����Ͻ������� 
*/ 



#include<iostream>
#include<cstdlib> 
#include<cmath>
using namespace std;

typedef struct multinomail
{
	int Z_num, X_num;
	struct multinomail *next;
}node;


node *CreatList() ;
void PrintLinkList(node *head);
void Free(node *head);
node *AdditTheMult(node *head1, node *head2);
node *SubTheMult(node *head1, node *head2);
node *PreTheLinkList(node *head);
node *HBTheLinklist(node *head);
node *Multiply(node *head1, node *head2);
int main()
{
	node *head1, *head2, *h, *h2, *s, *t, *h3, *p, *q;
	cout << "�������һ������ʽ��ֵ����ָ���������룩\n";
	head1 = CreatList();
	cout << "������ڶ�������ʽ��ֵ����ָ���������룩\n";
	head2 = CreatList();
	s = PreTheLinkList(head1);    //���Ƶ�һ������ʽ 
	t = PreTheLinkList(head2);    //���Ƶڶ�������ʽ 
	p = PreTheLinkList(head1);    //���Ƶ�һ������ʽ 
	q = PreTheLinkList(head2);    //���Ƶ�һ������ʽ 
	
	cout << "pa = ";
	HBTheLinklist(head1);
	PrintLinkList(head1);
	cout << endl;
	
	cout << "pb = ";
	HBTheLinklist(head2);
	PrintLinkList(head2);
	cout << endl;
	
	h = AdditTheMult(head1, head2);           //�ӷ� 
	cout << "pc = ";
	HBTheLinklist(h);
	PrintLinkList(h);
	cout << endl;
	
	h2 = SubTheMult(s, t);                //����
	cout << "pd = ";
	HBTheLinklist(h2);
	PrintLinkList(h2);
	cout << endl;
	
	
	h3 = Multiply(p, q);                //�˷� 
	cout << "pe = ";
	HBTheLinklist(h3);
	PrintLinkList(h3);
	cout << endl;
	
	Free(head1);
	Free(head2);
	Free(h2);
	Free(h);
}

node *Multiply(node *head1, node *head2)
{
	int flag = 1;
	node *hc, *p, *num, *s, *t, *rail;
	hc = rail = NULL; 
	s = head1->next;
	while(s != NULL)
	{
		hc = (node *)malloc(sizeof(node));
		hc->next = NULL;
		rail = hc;
		t = head2->next;
		while(t != NULL) 
		{
			p = (node *)malloc(sizeof(node));
			p->X_num = s->X_num * t->X_num;
			p->Z_num = s->Z_num + t->Z_num;
			t = t->next;
			rail->next = p;
			rail = p;
		}
		rail->next = NULL;
		if(flag == 1) 
		{
			num = hc;
		}
		flag ++;
		if(flag > 2)
		{
			num = AdditTheMult(num, hc);
		}
		s = s->next;
	}
	return num;	
}
node *CreatList()   //�˴���Ҫ�õ�β�巨�����������洢����ʽ 
{
	node *head, *p, *rail;
	head = (node *)malloc(sizeof(node));
	head->next = NULL;
	rail = head;
	int factor, index;               //�������ʽ������ϵ����ָ�������ϵ��Ϊ���������˴δ��� 
	cout << "����������ϵ��/ָ��\n";
	cin >> factor >> index; 
	while(factor != 0)
	{
		p = (node *)malloc(sizeof(node));
		p->X_num = factor;
		p->Z_num = index;
		rail->next = p;
		rail = p;
		cout << "����������ϵ��/ָ��\n";
		cin >> factor >> index; 
	}
	rail->next = NULL; 
	return head; 
}



void PrintLinkList(node *head)    //��ӡ����ʽ���� 
{ 
	node * p = head->next;
	while(p != NULL)
	{
		if(p->X_num != 0)  
		{
			if(p->Z_num != 0) cout << p->X_num << "*x^" << p->Z_num;
			else  cout << p->X_num;
		}
		p = p->next;
	 	if(p != NULL && p->X_num > 0) cout << "+";
	}
}



node *AdditTheMult(node *head1, node *head2)   //����ʽ�ӷ� 
{
	node *p, *q, *r;
	p = head1->next;
	q = head2->next;
	r = head1;
	while(q != NULL)       //ͨ����һ������ʽ��ÿһ������һ������ʽÿһ����бȽ�Ȼ������ 
	{
		head2->next = q->next;
		q->next = NULL;
		while(p != NULL && p->Z_num < q->Z_num)
		{
			r = p;
			p = p->next;
		}
		if(p != NULL)
		{
			if(p->Z_num > q->Z_num)
			{
					q->next = p;
					r->next = q;
					
			}	
			else{
				p->X_num = p->X_num + q->X_num;
				free(q);
			}	
		}
		else	r->next = q;
		q = head2->next;
		p = head1->next;
		r = head1; 
	}
	return head1;
}


node *SubTheMult(node *head1, node *head2)   //����ʽ���� 
{
	node *p, *q, *r;
	p = head1->next;
	q = head2->next;
	r = head1;
	while(q != NULL)
	{
		head2->next = q->next;
		q->next = NULL;
		while(p != NULL && p->Z_num < q->Z_num)
		{
			r = p;
			p = p->next;
		}
		if(p != NULL)
		{
			if(p->Z_num > q->Z_num)
			{
					q->next = p;
					r->next = q;
					q->X_num = (-1) * (q->X_num);
			}	
			else	
			{
				p->X_num = p->X_num - (q->X_num);
				free(q);
			}
		}
		else	
		{
			r->next = q;
			q->X_num = (-1) * (q->X_num);
		}
		q = head2->next;
		p = head1->next;
		r = head1; 
	}
	return head1;
}

void Free(node *head)    //�ͷ�����ռ� 
{
	node *p, *q;
	p = head;
	while(p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
}
node *PreTheLinkList(node *head)          //���ڶ���ʽ�ӷ���ԭ�����ƻ����˺�����ֵԭ���� 
{
	node *h, *p, *rail, *q;
	p = head->next;
	h = (node *)malloc(sizeof(node));
	h->next = NULL;
	rail = h;
	while(p != NULL)
	{
		q = (node *)malloc(sizeof(node));
		q->X_num = p->X_num;
		q->Z_num = p->Z_num;
		rail->next = q;
		rail = q;
		p = p->next;
	}
	rail->next = NULL;
	return h;
}
node *HBTheLinklist(node *head)
{
	node *p, *q, *s;
	p = head->next;
	while(p != NULL)
	{
		q = p->next;
		s = p;
		while(q != NULL)
		{
			if(q->Z_num == p->Z_num)
			{
				p->X_num = p->X_num + q->X_num;
				s->next = q->next;
				q = q->next;
			}
			s = q;
			q = q->next;
		}
		p = p->next;
	}
} 
