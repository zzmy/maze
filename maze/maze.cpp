#include "maze.h"


void Game::Help_You()
{
	system("cls");
	cout << endl;
	cout << endl;
	
	cout << "                                新手攻略                   "<< endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "               1.每一关闯关前需要自己规定闯关时间; 转到2                     "<< endl;
	cout << "               2.设置完游戏时间后可看到生成的地图; 转到3                     "<< endl;
	cout << "               3.可修改地图~~~~~~~按y,转到4;  按n, 转到5                     "<< endl;
	cout << "               4.即修改地图~~~~~~~路变墙,  墙变路; 转到6                     "<< endl;
	cout << "               5.不修改地图~~~~~~~继续使用当前地图;转到6                     "<< endl;
	cout << "               6.开始当局游戏;                     转到7                     "<< endl;
	cout << "               7.按方向键(↑ ↓ ← →)移动，按'ESC'建退出游戏;转到8          "<< endl;
	cout << "               8.若找到粮仓,显示所花时间,判断是否闯关成功;转到9              "<< endl;
	cout << "               9.若超时提示闯关失败,重新游戏,转到6;否则转到10;               "<< endl;
	cout << "               10.找到粮仓,是否需要显示全部路径和最短路径;是(y)转到11;否(n)转12;"<< endl;
	cout << "               11.显示全部路径和最短路径;转到12                              "<< endl;
	cout << "               12.进入下一关;转到6                                           "<< endl;
    
    getch();
	cout << endl;
	cout << endl;
	cout << "                     闯关共三关.益智游戏即将开始......                             "<< endl;
	system("pause");
	system("cls");
}

void Game::Play_Map(int map[][26], int p, int s)
{
	Means means;	
	int i;
	int j;
	int i_mx;
	int j_my;
	char m;    
	int m_flag = 0;	           
	double time;                                    //用户规定时间
	double  duration;                               //实际所用时间
	clock_t start, finish;                          //分别记录老鼠开始与结束时间的系统时间
	int map_1[10][26];
	int map_11[10][26];
	int map_run[10][26];             
	
	while(m_flag != 1)                              //实现没在规定时间内找到粮仓而设置的while语句  
	{                                           
		cout << "你可以设置小老鼠找到粮仓的规定时间!" << endl;
		cout << "根据你的实力，输入第" << p <<"关规定时间吧!  时间：";
		cin  >> time;
		system ("cls");
		cout << "目前得分为" << s << "分" << " 第" << p <<"关规定时间为" << time <<"秒" << endl;
		cout << "未修改前迷宫如下：" << endl;  
		
		Draw_Map(map);                          //显示未修改前的迷宫，调用Draw_Map函数
		
		cout << "即将生成既定迷宫，是否要修改" << endl;
		cout << "是，请按y； 否，请按n；" << endl;
		//判断是否修改迷宫
		cin >> m;
		cout << endl;
		
		switch(m)
		{
		case 'y':
			{
				
				Change_Map(map);
				getch();
				break;
			}
			
		case 'n':
			{
				cout << "继续使用修改当前迷宫!" <<endl;
				getch();
				break;
			}
		}
		
		for(i = 0; i < 10 ; i++)                               //为求全部路径和最短路径而实现保存原始迷宫
		{
			for(j = 0; j < 26; j++)
			{
				map_1[i][j] = map[i][j];
			}
		}
		for(i_mx = 0; i_mx < 10; i_mx++)           //为后面超出规定时间后实现重复游戏而保存原始迷宫
		{
			for(j_my = 0; j_my < 26; j_my++)
			{
				map_run[i_mx][j_my] = map[i_mx][j_my];
			}
		}
		
		start = clock();                                //捕捉开始走迷宫时的系统时间
		Control_key(map_run,p);                         //调用Circle函数，开始方向键控制小老
		finish = clock();                               //捕捉找到粮仓时的系统时间
		duration = (double)(finish - start) / CLOCKS_PER_SEC; //计算从起点到终点的时间差 
		cout << duration << "seconds" << endl;          //输出所耗费时间
		
		if (duration <= time)                           //根据直到找到粮仓的时间，判断是否闯关成功，否则重新游戏
		{
			if(p != 3)
			{
				cout << "在本关规定" << time << "秒内完成!恭喜你，请进入下一关!..." << endl;
				
				ofstream fin("map11.txt");
				for(i = 0; i < 10; i++)
				{
					for(j = 0; j < 26; j++)
					{
						fin << map_run[i][j];
					}			
				}
				
				m_flag = 1;
			}
			
			else 
			{
				system("color 0F"); 
				cout << "在本关规定" << time << "秒内完成!恭喜你,闯关成功!..." << endl;
				s = s + 10;                              //规定时间内完成任务，则累加分数
				cout << "         总分为" << s <<  "分" << endl;
				m_flag = 1;		
				system("pause"); 
			}
			
			system("color 70"); 
			
			cout << "----显示全部路径和最短路径 y-----不显示 n-----" << endl;	
			cin >> m;
			
			switch(m)
			{
			case 'y':
				{
					char way;
					cout << "方式1:只看图形展示(深度遍历递归求全部路径,穷举比较求最短路径)" << endl;
					cout << "方式2:先坐标展示后图形展示(深遍非递归求全部路径,广度遍历求最短路径)" << endl;
					cout << "选择方式:";
					cin >> way;
					switch(way)
					{
					case '1':
						{
							means.Display_Path(map_1);            //调用Display_Path函数
							getch();
							system("cls");
							break;
						}
					case '2':
						{
							means.Second_Display(map_1);            //调用Dispaly_Path函数
							getch();
							system("cls");
							for(i = 0; i < 10 ; i++)                               //为求全部路径和最短路径而实现保存原始迷宫
							{
								for(j = 0; j < 26; j++)
								{
									map_1[i][j] = map[i][j];
								}
							}
							means.Display_Path(map_1);            //调用Dispaly_Path函数
							break;
						}
					default:
						break;
					}		
				}
				
			case 'n':
				break;
				
			default:
				break;			
			}			
		}
		
		else
		{
			cout << "对不起，您没有在" << time << "秒内完成，请重新游戏!" << endl;
			getch();
			m_flag = 0;
			
			for (i = 0; i < 100; i++)                        //再次使用原始迷宫
			{	
				for(i_mx = 0; i_mx < 10; i_mx++)           //为后面超出规定时间后实现重复游戏而保存原始迷宫
				{
					for(j_my = 0; j_my < 26; j_my++)
					{
						map_run[i_mx][j_my] = map[i_mx][j_my];
					}
				}
				
				start = clock(); 
				Control_key(map_run, p);	
				finish = clock(); 
				duration = (double)(finish - start) / CLOCKS_PER_SEC; 
				cout << duration << "seconds" << endl;
				
				if (duration <= time )
				{
					if(p != 3)
					{
						cout << "在本关规定" << time << "秒内完成!恭喜你，请进入下一关!..." << endl;
						
						ofstream fin("map11.txt");
						for(i = 0; i <10; i++)
						{
							for(j = 0; j<26; j++)
							{
								fin << map_11[i][j];
							}			
						}
						m_flag = 1;
					}
					
					else 
					{
						system("color 0F"); 
						cout << "在本关规定" << time << "秒内完成!恭喜你,闯关成功!..." << endl;
						s = s + 10;
						cout << "         总分为" << s <<  "分" << endl;
						m_flag = 1;
						system("pause"); 
					}
					
					system("color 70");
					cout << "----显示全部路径和最短路径 y-----不显示 n-----" << endl;
					cin >> m;
					
					switch(m)
					{
					case 'y':	
						{
							char way;
							cout << "方式1:图形展示(深度遍历递归求全部路径,穷举比较求最短路径)" << endl;
							cout << "方式2:坐标展示(深度遍历非递归求全部路径,广度遍历求最短路径)" << endl;
							cout << "选择方式:";
							cin >> way;
							switch(way)
							{
							case '1':
								{
									means.Display_Path(map_1);            //调用Dispaly_Path函数
									getch();
									system("cls");
									break;
								}
							case '2':
								{
									means.Second_Display(map_1);            //调用Dispaly_Path函数
									getch();
									system("cls");
									for(i = 0; i < 10 ; i++)                               //为求全部路径和最短路径而实现保存原始迷宫
									{
										for(j = 0; j < 26; j++)
										{
											map_1[i][j] = map[i][j];
										}
									}
									means.Display_Path(map_1);            //调用Dispaly_Path函数
									
									break;
								}
							default:
								break;
							}		
							
						}
						
					case 'n':
						break;
						
					default:
						break;					
					}
					break;
				}
				
				else
				{
					cout <<"对不起，您没有在" << time << "秒内完成，请重新游戏!"  << endl;
					m_flag = 0;
					getch();
				}
			}		
		}
		
		means.dMeans = 0;
		means.dWalkLen = 10000;
	}
	
}

int Game::Draw_Map(int map[][26])                  //功能：绘制迷宫；解决问题：为了得到迷宫的简洁界面
{
	int i,j;
	int flag = 0;
	
	for(i = 0; i<10; i++)
	{
		for(j = 0; j < 26; j++)
		{
			if(map[i][j] == 3)                    //map[i][j]==3表示粮仓
			{
				flag = 1;
			}
			
			switch(map[i][j])
			{	
			case 1: cout << "■";                 //map[i][j]==1表示墙和障碍
				break;
				
			case 2: cout << "  ";                 //map[i][j]==2表示无障碍
				break;
				
			case 3: cout << "☆";                 //map[i][j]==3表示粮仓
				break;
				
			case 4: 
				cout << "ζ";                    //map[i][j]==4表示老鼠
				break;
				
			case 5:
				cout << "㊣";                    //map[i][j]==5表示脚印
				break;
			}
		}
		putchar('\n');
	}
	
	cout << endl;
	cout << endl;
	cout << "按方向键(↑ ↓ ← →)移动，按'ESC'建退出游戏!" <<endl;
	
	return flag;
}

void Game::Move_key(int map[][26], int x, int y, int op) //功能：操控小老鼠步骤一； 解决问题：用方向键操控小老鼠
{
	int x1;                                           //记录下一步的坐标
	int y1;
	
	switch(op)                                        //判断方向
	{
	case 1: 
		x1 = x - 1;//←
		y1 = y;		  
		break;
		
	case 2:
		x1 = x;
		y1 = y - 1; //↓			  
		break;
		
	case 3: 
		x1 = x;
		y1 = y + 1;//↑		
		break;
		
	case 4: 
		x1 = x + 1;//→
		y1 = y;	
		break;
	}
	
	switch(map[x1][y1])
	{
	case 1:
		break;                                          //障碍，老鼠无法走动
		
	case 2: 
		map[x1][y1] = 4;
		map[x][y] = 5;
		break;
		
	case 3: 
		map[x1][y1] = 4;
		map[x][y] = 5;
		break;
	case 4:
		map[x1][y1] = 4;
		map[x][y] = 5;
		break;
		
	case 5:
		map[x1][y1] = 4;
		map[x][y] = 5;
		break;
	}
}

int Game::Control_key(int map[][26], int z)//功能：操控小老鼠步骤二； 解决问题：用方向键操控小老鼠，实现不撞墙，找粮仓
{
	
	int i,j;
	int x,y;
	int count;
	char op;
	
	while(1)
	{
		for(i=0;i<10;i++)                 //捕捉当前小老鼠的位置
		{
			for(j=0;j<26;j++)
			{
				if(map[i][j]==4)
				{
					break;
				}   	
			}
			if(map[i][j]==4)
			{
				break;
			}   
		}	
		
		x=i;
		y=j;
		
		system("cls");
		cout << " 欢迎进入第" << z << "关" << endl;
		count=Draw_Map(map);          
		if(count==0)                      //不断显示当前迷宫；count == 0 表示还没有遇到粮仓
		{
			if(z == 2)
			{
				
				return 0;
			}
			else
			{
				
				return 0;
			}
		}
		else
		{
			op=getch();                    //捕捉方向键
			switch(op)
			{
			case 72:
				Move_key(map,x,y,1);//左
				break;
				
			case 75:
				Move_key(map,x,y,2);// 下
				break;
				
			case 77:
				Move_key(map,x,y,3); // 上
				break;
				
			case 80:
				Move_key(map,x,y,4); // 右
				break;
				
			case 27:
				cout << "退出游戏!..." << endl;	
				getch();    
				exit(0);
			}
		}
	}
}

void Game::Change_Map(int map[][26])        //功能：当前迷宫墙变路，路变墙； 解决问题：改变当前迷宫
{
	int i, j;	
	int flag = 0;	
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 25; j++)                   //注意这里j<25
		{
			if(map[i][j] == 3)
			{
				flag = 1;
			}
			
			switch(map[i][j])
			{	
			case 1: 
				if((i>0&&i<9) && (j>0&&i<25))
				{
					map[i][j] = 2; 
				}
				break;
				
			case 2: 	
				if((i>0 && i<9) && (j>0&&i<25))
				{
					map[i][j] = 1;	
				}
				break;
			}
		}				
	}
	cout << "修改成功!" << endl;
}

/*---------------------------------------------------------------------------------------------
行走迷宫函数： void Walk_De(int map[][26], int nx, int ny)
功能：判定是否已经走出迷宫，假如走出则打印路径，假如没有则开始逐个方向判定是否可以行走，
假如都不能行走，或已经返回。则退出该位置，即将该位置的标志写为0表明未走过。
无返回值，形参nx为当前位置的列，ny为当前位置的行。
---------------------------------------------------------------------------------------------*/

void Means::Walk_De(int map[][26], int nx, int ny)//深度递归遍历
{	
	if(map[nx][ny] == 3)                   //判定是否走出迷宫，☆是迷宫出口标志
		Print_Map(map, nx, ny);           //走出则打印出迷宫及行走路径
	else                                  //未走出迷宫
	{
		for(int i=1; i<=4; i++)          //四个方向逐个行走，i=1向右 2向下 3向左 4向上
		{
			if(Judge_De(map, nx, ny, i))   //假如列为nx行为ny的位置向i方向是否可以行走
			{                   
				MazeFlag[nx][ny] = i;       //将标志位置i表明该位置向i方向可行走
				
				if(i == 1)                 //分散处理，根据不同的i来确定下一步的位置，以便行走。
					Walk_De(map, nx, ny+1);
				else if (i == 2)
					Walk_De(map, nx+1, ny);
				else if (i == 3)
					Walk_De(map, nx, ny-1);
				else if (i == 4)
					Walk_De(map, nx-1, ny);
			}
		}		
		MazeFlag[nx][ny] = 0;               //假如4个方向都走不通，或者回朔则清空该点标志位，置为0表明未走过。
	}	
}

/*---------------------------------------------------------------------------------------------
//打印函数：void Print_Map(int map[][26], int a, int b)
//功能：    打印第dMeans种方法的在迷宫中的行走路径,以及通过比较找出目前行走步数最少的行走方法。
//无返回值，无形参。dMeans表示当前行走方法的种类。dCount是用来计算此种方法用了多少步。
---------------------------------------------------------------------------------------------*/

void Means::Print_Map(int map[][26], int a, int b)
{
	int nx, ny;
	double dCount = 0;	
	map[a][b] = 3;
	dMeans++;	
	cout<< "The " << dMeans << " ways is: " << endl;	
	for(nx = 0; nx < 10; nx++)
	{
		for(ny = 0; ny < 26; ny++)
		{
			if(map[nx][ny] == 3)
				cout << "☆";
			else if(map[nx][ny] == 1)
				cout << "■";
			else if(MazeFlag[nx][ny] == 0)     //不是墙但未走过的地方用空格表示
				cout << "  ";
			else                              //不是墙且走过的地方用“ ”表示
			{
				cout << "ζ";
				dCount ++;                     //走一步总步数加1
			}
		}
		cout << endl;
	}	
	cout << "This way used " << dCount << " steps" << endl;
	
	if(dCount < dWalkLen)                      //假如此种方法的步数比以前方法中最少步数还要少，
	{                                         //则将此种方法列为当前最少行走步数
		for(nx = 0; nx < 10; nx++)
		{
			for(ny = 0; ny < 26; ny++)
				MazeMin[nx][ny] = MazeFlag[nx][ny]; 
		}
		//将当前最小的迷宫记录下来
		dWalkLen=dCount;
	}
}

/*--------------------------------------------------------------------------------------------
//判定函数：int Judge_De(int map[][26], int nx, int ny, int i)
//功能：    判定当前位置(nx为列ny为行)向第i方向行走是否可以
//返回值int型 返回1表明可以，0表示不可以
--------------------------------------------------------------------------------------------*/

int Means::Judge_De(int map[][26], int nx, int ny, int i)
{
	if(i == 1)                                  //判定向右可否行走
	{
		if(ny<25 && (map[nx][ny+1]==2 || map[nx][ny+1] == 3) && MazeFlag[nx][ny+1]==0)
			return 1;
		else
			return 0;
	}
	else if(i == 2)                             //判定向下可否行走
	{
		if(nx<9 && (map[nx+1][ny]==2 || map[nx+1][ny]==3) && MazeFlag[nx+1][ny]==0)
			return 1;
		else 
			return 0;
	}
	else if(i == 3)                             //判定向左可否行走
	{
		if(ny>0 && (map[nx][ny-1]==2 || map[nx][ny-1]==3) && MazeFlag[nx][ny-1]==0)
			return 1;
		else
			return 0;
	}
	else if(i == 4)                             //判定向上可否行走
	{
		if(nx>0&&(map[nx-1][ny]==2||map[nx-1][ny]==3)&&MazeFlag[nx-1][ny]==0)
			return 1;
		else
			return 0;
	}
	else
		return 0;
	
}

void Means::Display_Path(int map[][26])
{
	int nx, ny, ni, nj;                          //nx,ny记录起点坐标；ni，ny为当前坐标
	int a, b;                                   //a,b记录粮仓坐标
	cout<<"迷宫游戏: "<<endl;
	
	for(ni = 0; ni < 10; ni++)                       //输出迷宫外形，并且找到迷宫的入口，同时将迷宫标志初始化
	{ 
		for(nj = 0; nj < 26; nj++)
		{
			switch (map[ni][nj])
			{
			case 0:
				cout << "  ";
				break;
				
			case 1:
				cout << "■";
				break;
				
			case 2:
				cout << "  ";
				break;
				
			case 3:
				cout << "☆";
				break;
				
			case 4:
				cout << "ζ";
				break;
			}
			
			MazeFlag[ni][nj] = 0;                   //将迷宫标志初始化为0表示未走过
			if(map[ni][nj] == 4)
			{
				nx = ni;                            //迷宫入口列坐标
				ny = nj;                            //迷宫入口行坐标
			}
			if(map[ni][nj] == 3)
			{
				a = ni;                             //迷宫出口列坐标
				b = nj;                             //迷宫出口行坐标
			}
		}
		cout<<endl;
	}
	
	cout << endl << "入口坐标:" << endl << "nx= " << nx << "   " << "ny= " << ny << endl; 
	
	Walk_De(map, nx, ny);                         //调用行走迷宫函数，从入口处开始行走
	
	cout << endl << "The MinLen way is: " << endl;
	
	map[a][b] = 3;
	
	for(nx = 0; nx < 10; nx++)                         //输出最短路径
	{
		for(ny = 0; ny < 26; ny++ )
		{
			if(map[nx][ny] == 3)
				cout << "☆";
			else if(map[nx][ny] == 1)
				cout << "■";
			else if(MazeMin[nx][ny] == 0)
				cout << "  ";
			else
			{
				cout << "ζ";
			}
		}
		cout << endl;
	}
	
	cout << "This Way used " << dWalkLen << " steps" << endl;//输出最短路径总行走步数
}

void Means::Second_Display(int mg[][N+2])
{
	cout<<"迷宫游戏: "<<endl;
	
	mg[5][11] = 2;
	mg[8][24] = 2;
	
	ALGraph *G = NULL;
	CreateList(G, mg);
	
	cout << "迷宫对应的邻接表为：" << endl;
	DispAdj(G);
	
	int xi=5, yi=11, xe=8, ye=24;
	PathType path;
	path.length = 0;
	cout << endl;
	cout << "采用深度优先非递归方式求该迷宫全部路径" << endl;
	findAllPaths_DFS(G, xi, yi, xe, ye);
	cout << "采用广度优先求该迷宫最短路径" << endl;
	findAllPaths_BFS(G, xi, yi, xe, ye);
}

void Means::CreateList(ALGraph *&G, int mg[][N+2])//建立迷宫数组对应的邻接表G
{ 
	int i,j,i1,j1,di;
	ArcNode *p;
	G = new(ALGraph);
	for(i = 0; i < M+2; i++)                     //给邻接表中所有头节点的指针域置初值
		for(j = 0; j < N+2; j++)
			G->adjlist[i][j].firstarc = NULL;
		
		for(i =1;i<=M;i++)                        //检查mg中每个元素
			for(j = 1; j <= N; j++)
				if(mg[i][j] == 2)
				{ 
					di = 0;
					while(di < 4)                 //找(i,j)方块的四周可走方块
					{ 
						switch(di)
						{
						case 0: 
							i1 = i-1; 
							j1 = j; 
							break;                   //上
							
						case 1: 
							i1 = i; 
							j1 = j+1;
							break;                    //右
							
						case 2: 
							i1 = i+1;
							j1 = j;
							break;                   //下
							
						case 3: 
							i1 = i; 
							j1 = j-1;
							break;                     //左
						}
						
						if(mg[i1][j1] == 2)               //(i1,j1)为可走方块
						{
							p = new(ArcNode);              //创建一个节点*p
							p->i = i1; 
							p->j = j1;
							p->nextarc = G->adjlist[i][j].firstarc; //将*p节点链到链表后
							G->adjlist[i][j].firstarc = p;
						}
						di ++;
					}
				}
}

void Means::DispAdj(ALGraph *G) //输出邻接表G
{
	int i, j;
	ArcNode *p;
	cout << "邻接表：" << endl;
	for(i = 0; i < M+2; i++)
		for(j = 0; j < N+2; j++)
		{ 	
			cout << "[" << i << "," << j << "]" << ":";
			p=G->adjlist[i][j].firstarc;
			while(p != NULL)
			{ 
				cout << "(" << p->i << "," << p->j << ")";
				p = p->nextarc;
			}
			cout<< endl;
		}
}

void Means::InitStack(SqStack *&s)
{
	s = new SqStack;
	s->top = -1;
}

bool Means::Push(SqStack *&s, BOX e)
{
	if(s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Means::Pop(SqStack *&s, BOX &e)
{
	if(s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

bool Means::GetTop(SqStack *&s, BOX &e)
{
	if(s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}

//输出路径函数
void Means::OutputPath(SqStack *S)
{
	int k;
	for(k = 0; k <= S->top; k++)
	{
		cout << "(" << S->data[k].i << "," <<  S->data[k].j << ")";
	}
	cout << endl;
}

//基于非递归的深度优先搜索，找出所有从(xi, yi)至(xe, ye)的简单路径
void Means::findAllPaths_DFS(ALGraph *G,int xi,int yi,int xe,int ye)
{
	int visited[M+2][N+2];
	int numOfTries[M+2][N+2];
	int i, j;
	for(i = 0; i < M+2; i++)
	{
		for(j = 0; j < N+2; j++)
		{
			visited[i][j] = 0;
			numOfTries[i][j] = 0;
		}
	}
	
	SqStack* S = NULL;
	InitStack(S);
	
	BOX box;
	box.i = xi;
	box.j = yi;
	Push(S, box);
	visited[xi][yi] = 1;
	
	while( (S->top) >=0 ) //栈非空
	{
		GetTop(S,box); //取栈顶元素
		int x = box.i;
		int y = box.j;
		
		if(x == xe && y == ye) //已到达出口 
		{ 
			OutputPath(S); //
			Pop(S, box); //出栈
			visited[x][y] = 0; //复位
			continue;
		}
		
		ArcNode *p = (G->adjlist[x][y]).firstarc; //点(x,y)对应的邻接点链表头节点
		int i = 0;
		while(p != NULL && i++ < numOfTries[x][y]) //找下一个可以考虑的邻接点
			p = p->nextarc;
		
		if(p == NULL) //没有邻接点了
		{
			Pop(S, box); //出栈
			visited[x][y] = 0; //复位
			numOfTries[x][y] = 0; //
		}
		else //一个新的邻接点, 考虑探索
		{
			numOfTries[x][y] = numOfTries[x][y] + 1;
			if (visited[p->i][p->j] == 0) //邻接点可以被真正探索
			{
				box.i = p->i;
				box.j = p->j;
				Push(S, box); //进栈
				visited[p->i][p->j] = 1;
			}
		}
	}
}

//基于广度优先搜索，找出所有从(xi, yi)至(xe, ye)的简单路径
void Means::findAllPaths_BFS(ALGraph *G, int xi, int yi, int xe, int ye)
{
	ArcNode *p;
	BOX w;
	int i, j;
	Quere qu[MaxSize];
	int front = -1, rear = -1;
	int visited[M+2][N+2];
	for(i = 0; i <M+2; i++)
	{
		for(j = 0; j <N+2; j++)
		{
			visited[i][j]=0;
		}
	}
	rear++;
	qu[rear].box.i = xi;
	qu[rear].box.j = yi;
	qu[rear].parent = -1;
	visited[xi][yi] = 1;
	while(front != rear)
	{
		front++;
		w = qu[front].box;
		if(w.i==xe&&w.j == ye)
		{
			i = front;
			while(qu[i].parent != -1)
			{
				cout << "(" << qu[i].box.i << "," << qu[i].box.j << ")";
				i = qu[i].parent;
			}
			cout << "(" << qu[i].box.i<< "," << qu[i].box.j<< ")";
			break;
		}
		p = G->adjlist[w.i][w.j].firstarc;
		while(p != NULL)
		{
			if(visited[p->i][p->j] == 0)
			{
				visited[p->i][p->j] = 1;
				rear++;
				qu[rear].box.i = p->i;
				qu[rear].box.j = p->j;
				qu[rear].parent = front;
			}
			p = p->nextarc;
		}
	}
}
