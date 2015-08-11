/* 2014年3月21日    钟明媛*/
#include "maze.h"

int main()
{
    Game game;                        //Game类实例化game；
	Means means;                      //Means类实例化means；
//means.visited[10][26]={0};
	int score = 0;                    //记录得分情况
	int i;
	int j;
	int number = 1;                   //闯关关数
	char choice;
	
	system("color 70");               //设置可视界面白底黑字
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "           ----------------------------------------------" << endl;
	cout << "           ------------欢迎进入老鼠闯迷宫系统------------" << endl;
	cout << "                       新手攻略  (是-y 否-n)            " << endl;                      
	cout << "           ----------------------------------------------" << endl;
	cout << endl;
	cout << endl;
	cout << ">>>";
	cin >> choice;
	
	switch(choice)
	{
	case 'y' :
		{	
			game.Help_You();
			break;		
		}
		
	case 'n' :
		{	
			break;		
		}
		
	default:
		break;
	}
	
	for(number = 1; number < 4; number ++)    //闯关计分,文件导入地图
	{
		cout << endl;
		
		int map[10][26];
		
		switch(number)
		{
		case 1 :
			{	
				ifstream fin("map1.txt");
				for(i = 0; i < 10; i++)
				{
					for(j = 0; j < 26; j++)
					{
						fin >> map[i][j];
					}			
				}
				break;
			}
			
		case 2 :
			{
				ifstream fin("map2.txt");
				for(i = 0; i < 10; i++)
				{
					for(j = 0; j < 26; j++)
					{
						fin >> map[i][j];
					}			
				}
				break;			
			}
			
		case 3 :
			{
				ifstream fin("map3.txt");
				for(i = 0; i < 10; i++)
				{
					for(j=0; j<26; j++)
					{
						fin >> map[i][j];
					}			
				}
				break;			
			}		
		}
		
		game.Play_Map(map, number, score);
		
		score = score + 10;
	}
	
	return 0;	
}
