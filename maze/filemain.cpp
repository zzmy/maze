/* 2014��3��21��    ������*/
#include "maze.h"

int main()
{
    Game game;                        //Game��ʵ����game��
	Means means;                      //Means��ʵ����means��
//means.visited[10][26]={0};
	int score = 0;                    //��¼�÷����
	int i;
	int j;
	int number = 1;                   //���ع���
	char choice;
	
	system("color 70");               //���ÿ��ӽ���׵׺���
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "           ----------------------------------------------" << endl;
	cout << "           ------------��ӭ���������Թ�ϵͳ------------" << endl;
	cout << "                       ���ֹ���  (��-y ��-n)            " << endl;                      
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
	
	for(number = 1; number < 4; number ++)    //���ؼƷ�,�ļ������ͼ
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
