#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>

#define max 50

struct PCB
{
	int name;
	int arrivetime; //����ʱ��
	int servicetime; //����ʱ��
	//int starttime[max]; //��ʼʱ��
	int finishtime; //���/����ʱ��
	int turntime; //��תʱ��
	int average_turntime; //��Ȩ��תʱ��
	int sign; //��־�����Ƿ����
	int remain_time; //ʣ��ʱ��
	int priority;  //���ȼ�
}pcb[max];

void init(int n)  //��ʼ��
{
	int i;
	for (i = 0; i < n; i++)
	{
		pcb[i].arrivetime = 0;
		pcb[i].servicetime = 0;
		//pcb[i].starttime=0; 
		pcb[i].finishtime = 0;
		pcb[i].turntime = 0;
		pcb[i].average_turntime = 0;
		pcb[i].remain_time = 0;
		pcb[i].sign = 0;
		pcb[i].priority = 0;
	}
}
void creat(int n) //����PCB
{
	int i;
	for (i = 1; i <= n; i++)
	{
		printf("\n%d:\n input the information of process\n input processID:", i);
		scanf("%d", &pcb[i].name);
		printf("input the arrivetime:");
		scanf("%d", &pcb[i].arrivetime);
		printf("input the servicetime:");
		scanf("%d", &pcb[i].servicetime);
		printf("input the priority:");
		scanf("%d", &pcb[i].priority);
		pcb[i].remain_time = pcb[i].servicetime;  //��ʼ��ʣ��ʱ��Ϊ����ʱ��
	}
}

void FCFS(int n) //�����ȷ���
{
	int starttime;
	printf("input the start time��\n");
	scanf("%d", &starttime);
	if (starttime >= pcb[0].arrivetime)
	{
		pcb[0].finishtime = pcb[0].servicetime + starttime;
	}
	else
	{
		pcb[0].finishtime = pcb[0].finishtime + pcb[0].servicetime;
	}
	int i;
	for (i = 1; i <= n; i++)
	{
		if (pcb[i - 1].finishtime > pcb[i].arrivetime)
			pcb[i].finishtime = pcb[i - 1].finishtime + pcb[i].servicetime;
		else
			pcb[i].finishtime = pcb[i].arrivetime + pcb[i].servicetime;
		pcb[i].turntime = pcb[i].finishtime - pcb[i].arrivetime;
		pcb[i].average_turntime = pcb[i].turntime / pcb[i].servicetime;
	}
}

void print_FCFS(int n)
{
	//printf("ProcessID, arrivetime\t Servicetime\t finishtime\t turntime\t:,,%s\t%d\t%d\t%d\t%d\t%d\t"); //������,����ʱ��,����ʱ��,���ʱ��,��תʱ��,��תʱ��
	printf("process ID  arrivetime servicetime finishtime turntime , averageturntime  .\n");
	int i;
	for (i = 1; i <= n; i++)
	{
		printf("%d  ,%d  ,%d  ,%d  ,%d  ,%d  ", pcb[i].name, pcb[i].arrivetime, pcb[i].servicetime, pcb[i].finishtime, pcb[i].turntime, pcb[i].average_turntime);
		printf("\n");
	}

}
void time_segment(int n) //ʱ��Ƭ��ת
{
	int i, j;
	int T;   //ʱ��Ƭ
	int flag = 1;   //�����������Ƿ��н���
	//int time=pcb[0].arrivetime;   //��ǰ��ʱ��
	int time = 0;
	int sum = 0;   //�Ѿ���ɵĽ�����

	//�������̵�arrivetime������������
	for (i = 1; i <= n; i++)
		for (j = i + 1; j <= n; j++)
		{
			if (pcb[j].arrivetime < pcb[i].arrivetime)
			{
				pcb[0] = pcb[j];
				pcb[j] = pcb[i];
				pcb[i] = pcb[0];
			}
		}
	//printf("output the sort result:\n");
	//for(i=1;i<=n;i++)    //��������Ƿ���ȷ
	//printf("%d\t",pcb[i].name);
	printf("input the slicetime:\n");
	scanf("%d", &T);
	//printf("\n running processID runtime resttime finishtime\n��) //  ��ʼ����ʱ��   ����ʱ��   ʣ�����ʱ��   ����ʱ��

	while (sum < n)
	{
		flag = 0;   //��ǰ����������û�н���
		int i;
		for (i = 1; i <= n; i++)
		{
			if (pcb[i].sign == 1) continue; //��ʾ�ý��������
			else
			{


				//û����ɵĽ�����Ҫ��ʱ�����һ��ʱ��Ƭ
				if (pcb[i].remain_time > T)
				{
					flag = 1;
					time = time + T;
					pcb[i].remain_time = pcb[i].remain_time - T;
					//printf("%10d%16d%12d%12d%12d\n",pcb[i].name,time-T,T,pcb[i].remain_time,time);
				}

				//û����ɵĽ�����Ҫ��ʱ��С�ڻ����һ��ʱ��Ƭ
				else if (pcb[i].remain_time <= T)
				{
					flag = 1;  //�����������
					time = time + pcb[i].remain_time;
					pcb[i].finishtime = time;
					pcb[i].sign = 1;
					//printf("%10d%16d%12d%12d%12d\n",pcb[i].name,time-pcb[i].remain_time,pcb[i].servicetime,0,time); 
					pcb[i].remain_time = 0;
				}

				if (pcb[i].sign == 1) sum++;
			}

		}//for


		if (flag == 0 && sum < n)   // ����ûִ�еĽ��̣���û����;������� 
		{
			int i;
			for (i = 1; i <= n; i++)
				if (pcb[i].sign == 0) { time = pcb[i].arrivetime; break; }
		}


	}//while

}
void print_time(int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\n processID servicetime finishtime\n");  //������   ����ʱ��   ���ʱ��
		printf("%6d%10d%10d", pcb[i + 1].name, pcb[i + 1].servicetime, pcb[i + 1].finishtime);
		printf("\n");
	}
}

void Priority(int n)
{
	int i, j;
	int time = pcb[1].arrivetime;
	//�������̵�arrivetime������������,���絽��Ľ�����ִ��
	for (i = 1; i <= n; i++)
		for (j = i + 1; j <= n; j++)
		{
			if (pcb[j].arrivetime < pcb[i].arrivetime)
			{
				pcb[0] = pcb[j];
				pcb[j] = pcb[i];
				pcb[i] = pcb[0];
			}
		}

	//printf("output the sort result: \n"); //���������
	//for(i=1;i<=n;i++)    //��������Ƿ���ȷ
	//printf("%d\t",pcb[i].name);

	printf("\n processID runtime priority fihishtime \n");//������   ����ʱ��   ���ȼ�  ���ʱ��
	//�ȵ���Ľ��̵�һ��ִ��
	if (i = 1)
	{
		pcb[i].finishtime = pcb[i].arrivetime + pcb[i].servicetime;
		time = pcb[i].arrivetime + pcb[i].servicetime;
		printf("%6d%10d%10d%10d", pcb[i].name, pcb[i].servicetime, pcb[i].priority, pcb[i].finishtime);
		printf("\n");
		//���Ե�һ�����������ȷ
	/*	printf("output the first process:\n");//�����һ�������
		printf("processID arrivetime finishtime\n");//����  ����ʱ��  ���ʱ��
		printf("%4d%8d%8d",pcb[i].name,pcb[i].arrivetime,pcb[i].finishtime);
		printf("\n"); */
		i++;
	}

	//�������̵�priority���н�������,���ȼ���ߵĽ�����ִ��
	for (i = 2; i <= n; i++)
		for (j = i + 1; j <= n; j++)
		{
			if (pcb[j].priority > pcb[i].priority)
			{
				pcb[0] = pcb[j];
				pcb[j] = pcb[i];
				pcb[i] = pcb[0];
			}
		}

	for (i = 2; i <= n; i++)
	{
		time = time + pcb[i].servicetime;
		pcb[i].finishtime = time;
		printf("%6d%10d%10d%10d", pcb[i].name, pcb[i].servicetime, pcb[i].priority, pcb[i].finishtime);
		printf("\n");
	}//for

}//void

void layout(int n)
{
	int ch = 0;
	printf("\t\t************schedule algorithm************\n");
	printf("\t\t1.FSFS\n");
	printf("\t\t2.timesegment\n");
	printf("\t\t3.priority\n");
	printf(" choose the algorithm:\n");
	scanf("%10d", &ch);
	switch (ch)
	{
	case 1:
		FCFS(n);
		print_FCFS(n); break;
	case 2:
		time_segment(n);
		print_time(n); break;
	case 3:
		Priority(n); break;
	default:printf("enter error data!\n");
		//P:int���͵ı���,case���治Ҫ��''
	}
}

int main()
{
	int n;
	printf("input the number of process\n");
	scanf("%d", &n);
	init(n);
	creat(n);
	layout(n);
	//FCFS(n);
	//print_FCFS(n);
	//time_segment(n);
	//print_time(n);
	//Priority(n);
	return 0;
}

//����ҵ����

void SJF(int n) {
	int start = pcb[1].arrivetime, end = pcb[1].servicetime, ch = 1, i, servce = 0, i_piois = 0;
	pcb[1].finishtime = pcb[1].servicetime;

	while (ch < n) {
		i = 1;
		servce = 9999;
		while (pcb[i].arrivetime <= end && i <= n) {
			if (pcb[i].servicetime < servce && pcb[i].finishtime == 0) {
				servce = pcb[i].servicetime;
				i_piois = i;

			}
			i++;
		}

		pcb[i_piois].finishtime = end + pcb[i_piois].servicetime;

		end = pcb[i_piois].finishtime;
		ch++;
	}
	for (int j = 1; j <= n; j++) {
		printf("%d,%d,%d\n", pcb[j].name, pcb[j].arrivetime, pcb[j].finishtime);
	}
}
