
#include <stdio.h>

#define MAX 100
#define INF 0x3f3f3f3f

int graph[MAX][MAX];

/*
7 11
A B 7
A D 5
B C 8
B D 9
B E 7
C E 5
D E 15
D F 6
E F 8
E G 9
F G 11
*/

//Prime�㷨 
int Prim(int graph[][MAX], int n)
{
	
    int lowcost[MAX], mst[MAX];
    /*
        lowcost[i]��¼��iΪ�յ�ıߵ���СȨֵ����lowcost[i]=0ʱ��ʾ�յ�i����������
        mst[i]��¼��Ӧlowcost[i]����㣬��mst[i]=0ʱ��ʾ���i����������
    */
    int i, j, min, minid, sum = 0;

	//��ʼ��   lowcost��ʾ��СȨֵ��mist��ʾ�����СȨֵ��Ӧ�Ľڵ� 
    for (i = 2; i <= n; i++)  //Ĭ��ѡ��1�Žڵ��������������2�Žڵ㿪ʼ��ʼ��
    {
        lowcost[i] = graph[1][i];  //��̾����ʼ��Ϊ�����ڵ㵽1�Žڵ�ľ���
        mst[i] = 1;  //������нڵ������ΪĬ�ϵ�1�Žڵ�
    }

    mst[1] = 0;  //���1�Žڵ����������

    for (i = 2; i <= n; i++)  //n���ڵ�������Ҫn-1���߹�����С������
    {
        min = INF;
        minid = 0;
		
		//�ҵ���С�Ľڵ㣬���뵽���� 
        for (j = 2; j <= n; j++)  //��������������СȨֵ�ߵĽڵ�minid
        {
            if (lowcost[j] < min && lowcost[j] != 0)  //��Ȩֵ��С�Ҳ�����������
            {
                min = lowcost[j];
                minid = j;
            }
        }
        printf("%c - %c : %d\n", mst[minid] + 'A' - 1, minid + 'A' - 1, min);  //����������ߵ���Ϣ:��㣬�յ㣬Ȩֵ

        sum += min;  //�ۼ�Ȩֵ
        lowcost[minid] = 0;  //��ǽڵ�minid����������

		//���µ�ǰ�ڵ� 
        for (j = 2; j <= n; j++)  //���µ�ǰ�ڵ�minid�������ڵ��Ȩֵ
        {
            if (graph[minid][j] < lowcost[j])  ///���ָ�С��Ȩֵ
            {
                lowcost[j] = graph[minid][j];  //����Ȩֵ��Ϣ
                mst[j] = minid;  //������СȨֵ�ߵ����
            }
        }
    }
    return sum;  //������СȨֵ��
}

int main()
{
    int m, n, weight;
    char chx, chy;
	
	printf("������ڵ����ͱ���");
    scanf("%d %d", &m, &n);  //��ȡ�ڵ�ͱߵ���Ŀ
    getchar();
    for (int i = 1; i <= m; i++)  //��ʼ��ͼ�����нڵ�����Ϊ�����
        for (int j = 1; j <= m; j++)
            graph[i][j] = INF;
	
	//����ߵ���Ϣ 
    for (int k = 0; k < n; k++)  //��ȡ����Ϣ
    {
        scanf("%c %c %d", &chx, &chy, &weight);
        getchar();
        int i = chx - 'A' + 1, j = chy - 'A' + 1;  ///ABCDEFת���� 12345 
        //����ͼ�����߶�Ҫ����Ȩֵ 
        graph[i][j] = weight;
        graph[j][i] = weight;
    }
	
	//��ӡ��Ȩֵ 
    printf("Total: %d\n", Prim(graph, m));

    return 0;
}
