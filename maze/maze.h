#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h> 

using namespace std;

const int MaxSize=500; //�Թ�·������󳤶�
const int M=8, N=24;

/*���¶����ڽӱ�����*/

typedef struct ANode                     //�ߵĽڵ�ṹ����
{ 
	int i,j;                             //�ñߵ��յ�λ��(i,j)
	struct ANode *nextarc;               //ָ����һ���ߵ�ָ��
} ArcNode;

typedef struct Vnode                     //�ڽӱ�ͷ�ڵ������
{
	ArcNode *firstarc;                    //ָ���һ����
} VNode;

typedef struct
{
	VNode adjlist[M+2][N+2];             //�ڽӱ�ͷ�ڵ�����
} ALGraph;

/*ͼ���ڽӱ�����*/
typedef struct
{ 
	int i;                                //��ǰ������к�
	int j;                                //��ǰ������к�
} BOX;

typedef struct
{ 
	BOX data[MaxSize];
	int length;                             //��ǰ·���ĳ���
} PathType;                                 //����·������

/*�й�ջ�ĺ���*/
typedef struct 
{
	BOX data[MaxSize];
	int top;
}SqStack;

typedef struct
{
	BOX box;
	int parent;
}Quere;

class Game                                               //Game�๦�ܣ��ֶ�����ʵ��С����������
{
public:
	int Draw_Map(int map[][26]);                         //���ܣ������Թ���������⣺Ϊ�˵õ��Թ��ļ�����
	void Move_key(int map[][26], int x, int y, int op);  //���ܣ��ٿ�С������һ�� ������⣺�÷�����ٿ�С����
	int Control_key(int map[][26], int z);               //���ܣ��ٿ�С��������� ������⣺�÷�����ٿ�С����ʵ�ֲ�ײǽ��������
	void Change_Map(int map[][26]);                      //���ܣ���ǰ�Թ�ǽ��·��·��ǽ�� ������⣺�ı䵱ǰ�Թ�
	void Play_Map(int map[][26], int p, int s);
	void Help_You();
	
private:
	int map[10][26];	                                 //����һ����ά���飬�洢�Թ�����
};

class Means                                              //Means�๦�ܣ��Զ�������ȫ��·�������·��
{
public:
	double dMeans;                                         //dMeans��¼�߳��Թ�·��������
	double dWalkLen;                                       //dWalkLen��ʾǰ���߳��Թ����ٲ���//���ܣ�Ϊ��ȫ��·�������·����ָ������ ������⣺�û�����ѡ���Ƿ�Ҫ�������
	int visited[M+2][N+2];
    int count;//�ܵ�·����
	Means(){ dMeans =0; dWalkLen = 10000;};               //���ܣ���ʼ��Means��;              
	void Walk_De(int map[][26], int nx, int ny);           //���ܣ����Թ���nx���У�ny����
	void Print_Map(int map[][26], int a, int b);           //���ܣ���ӡȫ��·�����Թ���ͬʱ�Ƚϻ�ȡ·���϶̵����߷���
	int  Judge_De(int map[][26], int nx, int ny, int i);   //���ܣ��ж��ڵ�nx��ny�����i���������Ƿ����,���Է���1���򷵻�0	//i=1��ʾ���ң�2��ʾ���£�3��ʾ����4��ʾ����
	void Display_Path(int map[][26]);  	
	void CreateList(ALGraph *&G, int mg[][N+2]);            //�����Թ������Ӧ���ڽӱ�G
	void DispAdj(ALGraph *G);	
	void InitStack(SqStack *&s);
	bool Push(SqStack *&s, BOX e);
	bool Pop(SqStack *&s, BOX &e);
	bool GetTop(SqStack *&s, BOX &e);
	void OutputPath(SqStack *S);
	void findAllPaths_DFS(ALGraph *G, int xi, int yi, int xe, int ye);//���ڷǵݹ����������������ҳ����д�(xi, yi)��(xe, ye)�ļ�·��	
	void findAllPaths_BFS(ALGraph *G, int xi, int yi, int xe, int ye);//���ڹ�������������ҳ����д�(xi, yi)��(xe, ye)�ļ�·��
	void Second_Display(int mg[][26]);	

private:
	int MazeFlag[10][26];                                //�Թ��ı�־��0��ʾδ�߹���i(i=1,2,3,4)��ʾ�Ѿ��߹���,i��ʾ����
	int MazeMin[100][26];                                //·����С���Թ��ı�־
	int map[10][26];	
};


