#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h> 

using namespace std;

const int MaxSize=500; //迷宫路径的最大长度
const int M=8, N=24;

/*以下定义邻接表类型*/

typedef struct ANode                     //边的节点结构类型
{ 
	int i,j;                             //该边的终点位置(i,j)
	struct ANode *nextarc;               //指向下一条边的指针
} ArcNode;

typedef struct Vnode                     //邻接表头节点的类型
{
	ArcNode *firstarc;                    //指向第一条边
} VNode;

typedef struct
{
	VNode adjlist[M+2][N+2];             //邻接表头节点数组
} ALGraph;

/*图的邻接表类型*/
typedef struct
{ 
	int i;                                //当前方块的行号
	int j;                                //当前方块的列号
} BOX;

typedef struct
{ 
	BOX data[MaxSize];
	int length;                             //当前路径的长度
} PathType;                                 //定义路径类型

/*有关栈的函数*/
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

class Game                                               //Game类功能：手动操作实现小老鼠找粮仓
{
public:
	int Draw_Map(int map[][26]);                         //功能：绘制迷宫；解决问题：为了得到迷宫的简洁界面
	void Move_key(int map[][26], int x, int y, int op);  //功能：操控小老鼠步骤一； 解决问题：用方向键操控小老鼠
	int Control_key(int map[][26], int z);               //功能：操控小老鼠步骤二； 解决问题：用方向键操控小老鼠，实现不撞墙，找粮仓
	void Change_Map(int map[][26]);                      //功能：当前迷宫墙变路，路变墙； 解决问题：改变当前迷宫
	void Play_Map(int map[][26], int p, int s);
	void Help_You();
	
private:
	int map[10][26];	                                 //建立一个二维数组，存储迷宫数据
};

class Means                                              //Means类功能：自动搜索求全部路径和最短路径
{
public:
	double dMeans;                                         //dMeans记录走出迷宫路径的条数
	double dWalkLen;                                       //dWalkLen表示前当走出迷宫最少步数//功能：为求全部路径和最短路径的指引函数 解决问题：用户可以选择是否要这个功能
	int visited[M+2][N+2];
    int count;//总的路径数
	Means(){ dMeans =0; dWalkLen = 10000;};               //功能：初始化Means类;              
	void Walk_De(int map[][26], int nx, int ny);           //功能：走迷宫，nx是列，ny是行
	void Print_Map(int map[][26], int a, int b);           //功能：打印全部路径及迷宫，同时比较获取路径较短的行走方法
	int  Judge_De(int map[][26], int nx, int ny, int i);   //功能：判定在第nx列ny行向第i个方向走是否可以,可以返回1否则返回0	//i=1表示向右，2表示向下，3表示向左，4表示向上
	void Display_Path(int map[][26]);  	
	void CreateList(ALGraph *&G, int mg[][N+2]);            //建立迷宫数组对应的邻接表G
	void DispAdj(ALGraph *G);	
	void InitStack(SqStack *&s);
	bool Push(SqStack *&s, BOX e);
	bool Pop(SqStack *&s, BOX &e);
	bool GetTop(SqStack *&s, BOX &e);
	void OutputPath(SqStack *S);
	void findAllPaths_DFS(ALGraph *G, int xi, int yi, int xe, int ye);//基于非递归的深度优先搜索，找出所有从(xi, yi)至(xe, ye)的简单路径	
	void findAllPaths_BFS(ALGraph *G, int xi, int yi, int xe, int ye);//基于广度优先搜索，找出所有从(xi, yi)至(xe, ye)的简单路径
	void Second_Display(int mg[][26]);	

private:
	int MazeFlag[10][26];                                //迷宫的标志：0表示未走过，i(i=1,2,3,4)表示已经走过了,i表示方向。
	int MazeMin[100][26];                                //路径最小的迷宫的标志
	int map[10][26];	
};


