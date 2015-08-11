#include "maze.h"


void Game::Help_You()
{
	system("cls");
	cout << endl;
	cout << endl;
	
	cout << "                                ���ֹ���                   "<< endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "               1.ÿһ�ش���ǰ��Ҫ�Լ��涨����ʱ��; ת��2                     "<< endl;
	cout << "               2.��������Ϸʱ���ɿ������ɵĵ�ͼ; ת��3                     "<< endl;
	cout << "               3.���޸ĵ�ͼ~~~~~~~��y,ת��4;  ��n, ת��5                     "<< endl;
	cout << "               4.���޸ĵ�ͼ~~~~~~~·��ǽ,  ǽ��·; ת��6                     "<< endl;
	cout << "               5.���޸ĵ�ͼ~~~~~~~����ʹ�õ�ǰ��ͼ;ת��6                     "<< endl;
	cout << "               6.��ʼ������Ϸ;                     ת��7                     "<< endl;
	cout << "               7.�������(�� �� �� ��)�ƶ�����'ESC'���˳���Ϸ;ת��8          "<< endl;
	cout << "               8.���ҵ�����,��ʾ����ʱ��,�ж��Ƿ񴳹سɹ�;ת��9              "<< endl;
	cout << "               9.����ʱ��ʾ����ʧ��,������Ϸ,ת��6;����ת��10;               "<< endl;
	cout << "               10.�ҵ�����,�Ƿ���Ҫ��ʾȫ��·�������·��;��(y)ת��11;��(n)ת12;"<< endl;
	cout << "               11.��ʾȫ��·�������·��;ת��12                              "<< endl;
	cout << "               12.������һ��;ת��6                                           "<< endl;
    
    getch();
	cout << endl;
	cout << endl;
	cout << "                     ���ع�����.������Ϸ������ʼ......                             "<< endl;
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
	double time;                                    //�û��涨ʱ��
	double  duration;                               //ʵ������ʱ��
	clock_t start, finish;                          //�ֱ��¼����ʼ�����ʱ���ϵͳʱ��
	int map_1[10][26];
	int map_11[10][26];
	int map_run[10][26];             
	
	while(m_flag != 1)                              //ʵ��û�ڹ涨ʱ�����ҵ����ֶ����õ�while���  
	{                                           
		cout << "���������С�����ҵ����ֵĹ涨ʱ��!" << endl;
		cout << "�������ʵ���������" << p <<"�ع涨ʱ���!  ʱ�䣺";
		cin  >> time;
		system ("cls");
		cout << "Ŀǰ�÷�Ϊ" << s << "��" << " ��" << p <<"�ع涨ʱ��Ϊ" << time <<"��" << endl;
		cout << "δ�޸�ǰ�Թ����£�" << endl;  
		
		Draw_Map(map);                          //��ʾδ�޸�ǰ���Թ�������Draw_Map����
		
		cout << "�������ɼȶ��Թ����Ƿ�Ҫ�޸�" << endl;
		cout << "�ǣ��밴y�� ���밴n��" << endl;
		//�ж��Ƿ��޸��Թ�
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
				cout << "����ʹ���޸ĵ�ǰ�Թ�!" <<endl;
				getch();
				break;
			}
		}
		
		for(i = 0; i < 10 ; i++)                               //Ϊ��ȫ��·�������·����ʵ�ֱ���ԭʼ�Թ�
		{
			for(j = 0; j < 26; j++)
			{
				map_1[i][j] = map[i][j];
			}
		}
		for(i_mx = 0; i_mx < 10; i_mx++)           //Ϊ���泬���涨ʱ���ʵ���ظ���Ϸ������ԭʼ�Թ�
		{
			for(j_my = 0; j_my < 26; j_my++)
			{
				map_run[i_mx][j_my] = map[i_mx][j_my];
			}
		}
		
		start = clock();                                //��׽��ʼ���Թ�ʱ��ϵͳʱ��
		Control_key(map_run,p);                         //����Circle��������ʼ���������С��
		finish = clock();                               //��׽�ҵ�����ʱ��ϵͳʱ��
		duration = (double)(finish - start) / CLOCKS_PER_SEC; //�������㵽�յ��ʱ��� 
		cout << duration << "seconds" << endl;          //������ķ�ʱ��
		
		if (duration <= time)                           //����ֱ���ҵ����ֵ�ʱ�䣬�ж��Ƿ񴳹سɹ�������������Ϸ
		{
			if(p != 3)
			{
				cout << "�ڱ��ع涨" << time << "�������!��ϲ�㣬�������һ��!..." << endl;
				
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
				cout << "�ڱ��ع涨" << time << "�������!��ϲ��,���سɹ�!..." << endl;
				s = s + 10;                              //�涨ʱ��������������ۼӷ���
				cout << "         �ܷ�Ϊ" << s <<  "��" << endl;
				m_flag = 1;		
				system("pause"); 
			}
			
			system("color 70"); 
			
			cout << "----��ʾȫ��·�������·�� y-----����ʾ n-----" << endl;	
			cin >> m;
			
			switch(m)
			{
			case 'y':
				{
					char way;
					cout << "��ʽ1:ֻ��ͼ��չʾ(��ȱ����ݹ���ȫ��·��,��ٱȽ������·��)" << endl;
					cout << "��ʽ2:������չʾ��ͼ��չʾ(���ǵݹ���ȫ��·��,��ȱ��������·��)" << endl;
					cout << "ѡ��ʽ:";
					cin >> way;
					switch(way)
					{
					case '1':
						{
							means.Display_Path(map_1);            //����Display_Path����
							getch();
							system("cls");
							break;
						}
					case '2':
						{
							means.Second_Display(map_1);            //����Dispaly_Path����
							getch();
							system("cls");
							for(i = 0; i < 10 ; i++)                               //Ϊ��ȫ��·�������·����ʵ�ֱ���ԭʼ�Թ�
							{
								for(j = 0; j < 26; j++)
								{
									map_1[i][j] = map[i][j];
								}
							}
							means.Display_Path(map_1);            //����Dispaly_Path����
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
			cout << "�Բ�����û����" << time << "������ɣ���������Ϸ!" << endl;
			getch();
			m_flag = 0;
			
			for (i = 0; i < 100; i++)                        //�ٴ�ʹ��ԭʼ�Թ�
			{	
				for(i_mx = 0; i_mx < 10; i_mx++)           //Ϊ���泬���涨ʱ���ʵ���ظ���Ϸ������ԭʼ�Թ�
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
						cout << "�ڱ��ع涨" << time << "�������!��ϲ�㣬�������һ��!..." << endl;
						
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
						cout << "�ڱ��ع涨" << time << "�������!��ϲ��,���سɹ�!..." << endl;
						s = s + 10;
						cout << "         �ܷ�Ϊ" << s <<  "��" << endl;
						m_flag = 1;
						system("pause"); 
					}
					
					system("color 70");
					cout << "----��ʾȫ��·�������·�� y-----����ʾ n-----" << endl;
					cin >> m;
					
					switch(m)
					{
					case 'y':	
						{
							char way;
							cout << "��ʽ1:ͼ��չʾ(��ȱ����ݹ���ȫ��·��,��ٱȽ������·��)" << endl;
							cout << "��ʽ2:����չʾ(��ȱ����ǵݹ���ȫ��·��,��ȱ��������·��)" << endl;
							cout << "ѡ��ʽ:";
							cin >> way;
							switch(way)
							{
							case '1':
								{
									means.Display_Path(map_1);            //����Dispaly_Path����
									getch();
									system("cls");
									break;
								}
							case '2':
								{
									means.Second_Display(map_1);            //����Dispaly_Path����
									getch();
									system("cls");
									for(i = 0; i < 10 ; i++)                               //Ϊ��ȫ��·�������·����ʵ�ֱ���ԭʼ�Թ�
									{
										for(j = 0; j < 26; j++)
										{
											map_1[i][j] = map[i][j];
										}
									}
									means.Display_Path(map_1);            //����Dispaly_Path����
									
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
					cout <<"�Բ�����û����" << time << "������ɣ���������Ϸ!"  << endl;
					m_flag = 0;
					getch();
				}
			}		
		}
		
		means.dMeans = 0;
		means.dWalkLen = 10000;
	}
	
}

int Game::Draw_Map(int map[][26])                  //���ܣ������Թ���������⣺Ϊ�˵õ��Թ��ļ�����
{
	int i,j;
	int flag = 0;
	
	for(i = 0; i<10; i++)
	{
		for(j = 0; j < 26; j++)
		{
			if(map[i][j] == 3)                    //map[i][j]==3��ʾ����
			{
				flag = 1;
			}
			
			switch(map[i][j])
			{	
			case 1: cout << "��";                 //map[i][j]==1��ʾǽ���ϰ�
				break;
				
			case 2: cout << "  ";                 //map[i][j]==2��ʾ���ϰ�
				break;
				
			case 3: cout << "��";                 //map[i][j]==3��ʾ����
				break;
				
			case 4: 
				cout << "��";                    //map[i][j]==4��ʾ����
				break;
				
			case 5:
				cout << "�I";                    //map[i][j]==5��ʾ��ӡ
				break;
			}
		}
		putchar('\n');
	}
	
	cout << endl;
	cout << endl;
	cout << "�������(�� �� �� ��)�ƶ�����'ESC'���˳���Ϸ!" <<endl;
	
	return flag;
}

void Game::Move_key(int map[][26], int x, int y, int op) //���ܣ��ٿ�С������һ�� ������⣺�÷�����ٿ�С����
{
	int x1;                                           //��¼��һ��������
	int y1;
	
	switch(op)                                        //�жϷ���
	{
	case 1: 
		x1 = x - 1;//��
		y1 = y;		  
		break;
		
	case 2:
		x1 = x;
		y1 = y - 1; //��			  
		break;
		
	case 3: 
		x1 = x;
		y1 = y + 1;//��		
		break;
		
	case 4: 
		x1 = x + 1;//��
		y1 = y;	
		break;
	}
	
	switch(map[x1][y1])
	{
	case 1:
		break;                                          //�ϰ��������޷��߶�
		
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

int Game::Control_key(int map[][26], int z)//���ܣ��ٿ�С��������� ������⣺�÷�����ٿ�С����ʵ�ֲ�ײǽ��������
{
	
	int i,j;
	int x,y;
	int count;
	char op;
	
	while(1)
	{
		for(i=0;i<10;i++)                 //��׽��ǰС�����λ��
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
		cout << " ��ӭ�����" << z << "��" << endl;
		count=Draw_Map(map);          
		if(count==0)                      //������ʾ��ǰ�Թ���count == 0 ��ʾ��û����������
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
			op=getch();                    //��׽�����
			switch(op)
			{
			case 72:
				Move_key(map,x,y,1);//��
				break;
				
			case 75:
				Move_key(map,x,y,2);// ��
				break;
				
			case 77:
				Move_key(map,x,y,3); // ��
				break;
				
			case 80:
				Move_key(map,x,y,4); // ��
				break;
				
			case 27:
				cout << "�˳���Ϸ!..." << endl;	
				getch();    
				exit(0);
			}
		}
	}
}

void Game::Change_Map(int map[][26])        //���ܣ���ǰ�Թ�ǽ��·��·��ǽ�� ������⣺�ı䵱ǰ�Թ�
{
	int i, j;	
	int flag = 0;	
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 25; j++)                   //ע������j<25
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
	cout << "�޸ĳɹ�!" << endl;
}

/*---------------------------------------------------------------------------------------------
�����Թ������� void Walk_De(int map[][26], int nx, int ny)
���ܣ��ж��Ƿ��Ѿ��߳��Թ��������߳����ӡ·��������û����ʼ��������ж��Ƿ�������ߣ�
���綼�������ߣ����Ѿ����ء����˳���λ�ã�������λ�õı�־дΪ0����δ�߹���
�޷���ֵ���β�nxΪ��ǰλ�õ��У�nyΪ��ǰλ�õ��С�
---------------------------------------------------------------------------------------------*/

void Means::Walk_De(int map[][26], int nx, int ny)//��ȵݹ����
{	
	if(map[nx][ny] == 3)                   //�ж��Ƿ��߳��Թ��������Թ����ڱ�־
		Print_Map(map, nx, ny);           //�߳����ӡ���Թ�������·��
	else                                  //δ�߳��Թ�
	{
		for(int i=1; i<=4; i++)          //�ĸ�����������ߣ�i=1���� 2���� 3���� 4����
		{
			if(Judge_De(map, nx, ny, i))   //������Ϊnx��Ϊny��λ����i�����Ƿ��������
			{                   
				MazeFlag[nx][ny] = i;       //����־λ��i������λ����i���������
				
				if(i == 1)                 //��ɢ�������ݲ�ͬ��i��ȷ����һ����λ�ã��Ա����ߡ�
					Walk_De(map, nx, ny+1);
				else if (i == 2)
					Walk_De(map, nx+1, ny);
				else if (i == 3)
					Walk_De(map, nx, ny-1);
				else if (i == 4)
					Walk_De(map, nx-1, ny);
			}
		}		
		MazeFlag[nx][ny] = 0;               //����4�������߲�ͨ�����߻�˷����ոõ��־λ����Ϊ0����δ�߹���
	}	
}

/*---------------------------------------------------------------------------------------------
//��ӡ������void Print_Map(int map[][26], int a, int b)
//���ܣ�    ��ӡ��dMeans�ַ��������Թ��е�����·��,�Լ�ͨ���Ƚ��ҳ�Ŀǰ���߲������ٵ����߷�����
//�޷���ֵ�����βΡ�dMeans��ʾ��ǰ���߷��������ࡣdCount������������ַ������˶��ٲ���
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
				cout << "��";
			else if(map[nx][ny] == 1)
				cout << "��";
			else if(MazeFlag[nx][ny] == 0)     //����ǽ��δ�߹��ĵط��ÿո��ʾ
				cout << "  ";
			else                              //����ǽ���߹��ĵط��á� ����ʾ
			{
				cout << "��";
				dCount ++;                     //��һ���ܲ�����1
			}
		}
		cout << endl;
	}	
	cout << "This way used " << dCount << " steps" << endl;
	
	if(dCount < dWalkLen)                      //������ַ����Ĳ�������ǰ���������ٲ�����Ҫ�٣�
	{                                         //�򽫴��ַ�����Ϊ��ǰ�������߲���
		for(nx = 0; nx < 10; nx++)
		{
			for(ny = 0; ny < 26; ny++)
				MazeMin[nx][ny] = MazeFlag[nx][ny]; 
		}
		//����ǰ��С���Թ���¼����
		dWalkLen=dCount;
	}
}

/*--------------------------------------------------------------------------------------------
//�ж�������int Judge_De(int map[][26], int nx, int ny, int i)
//���ܣ�    �ж���ǰλ��(nxΪ��nyΪ��)���i���������Ƿ����
//����ֵint�� ����1�������ԣ�0��ʾ������
--------------------------------------------------------------------------------------------*/

int Means::Judge_De(int map[][26], int nx, int ny, int i)
{
	if(i == 1)                                  //�ж����ҿɷ�����
	{
		if(ny<25 && (map[nx][ny+1]==2 || map[nx][ny+1] == 3) && MazeFlag[nx][ny+1]==0)
			return 1;
		else
			return 0;
	}
	else if(i == 2)                             //�ж����¿ɷ�����
	{
		if(nx<9 && (map[nx+1][ny]==2 || map[nx+1][ny]==3) && MazeFlag[nx+1][ny]==0)
			return 1;
		else 
			return 0;
	}
	else if(i == 3)                             //�ж�����ɷ�����
	{
		if(ny>0 && (map[nx][ny-1]==2 || map[nx][ny-1]==3) && MazeFlag[nx][ny-1]==0)
			return 1;
		else
			return 0;
	}
	else if(i == 4)                             //�ж����Ͽɷ�����
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
	int nx, ny, ni, nj;                          //nx,ny��¼������ꣻni��nyΪ��ǰ����
	int a, b;                                   //a,b��¼��������
	cout<<"�Թ���Ϸ: "<<endl;
	
	for(ni = 0; ni < 10; ni++)                       //����Թ����Σ������ҵ��Թ�����ڣ�ͬʱ���Թ���־��ʼ��
	{ 
		for(nj = 0; nj < 26; nj++)
		{
			switch (map[ni][nj])
			{
			case 0:
				cout << "  ";
				break;
				
			case 1:
				cout << "��";
				break;
				
			case 2:
				cout << "  ";
				break;
				
			case 3:
				cout << "��";
				break;
				
			case 4:
				cout << "��";
				break;
			}
			
			MazeFlag[ni][nj] = 0;                   //���Թ���־��ʼ��Ϊ0��ʾδ�߹�
			if(map[ni][nj] == 4)
			{
				nx = ni;                            //�Թ����������
				ny = nj;                            //�Թ����������
			}
			if(map[ni][nj] == 3)
			{
				a = ni;                             //�Թ�����������
				b = nj;                             //�Թ�����������
			}
		}
		cout<<endl;
	}
	
	cout << endl << "�������:" << endl << "nx= " << nx << "   " << "ny= " << ny << endl; 
	
	Walk_De(map, nx, ny);                         //���������Թ�����������ڴ���ʼ����
	
	cout << endl << "The MinLen way is: " << endl;
	
	map[a][b] = 3;
	
	for(nx = 0; nx < 10; nx++)                         //������·��
	{
		for(ny = 0; ny < 26; ny++ )
		{
			if(map[nx][ny] == 3)
				cout << "��";
			else if(map[nx][ny] == 1)
				cout << "��";
			else if(MazeMin[nx][ny] == 0)
				cout << "  ";
			else
			{
				cout << "��";
			}
		}
		cout << endl;
	}
	
	cout << "This Way used " << dWalkLen << " steps" << endl;//������·�������߲���
}

void Means::Second_Display(int mg[][N+2])
{
	cout<<"�Թ���Ϸ: "<<endl;
	
	mg[5][11] = 2;
	mg[8][24] = 2;
	
	ALGraph *G = NULL;
	CreateList(G, mg);
	
	cout << "�Թ���Ӧ���ڽӱ�Ϊ��" << endl;
	DispAdj(G);
	
	int xi=5, yi=11, xe=8, ye=24;
	PathType path;
	path.length = 0;
	cout << endl;
	cout << "����������ȷǵݹ鷽ʽ����Թ�ȫ��·��" << endl;
	findAllPaths_DFS(G, xi, yi, xe, ye);
	cout << "���ù����������Թ����·��" << endl;
	findAllPaths_BFS(G, xi, yi, xe, ye);
}

void Means::CreateList(ALGraph *&G, int mg[][N+2])//�����Թ������Ӧ���ڽӱ�G
{ 
	int i,j,i1,j1,di;
	ArcNode *p;
	G = new(ALGraph);
	for(i = 0; i < M+2; i++)                     //���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
		for(j = 0; j < N+2; j++)
			G->adjlist[i][j].firstarc = NULL;
		
		for(i =1;i<=M;i++)                        //���mg��ÿ��Ԫ��
			for(j = 1; j <= N; j++)
				if(mg[i][j] == 2)
				{ 
					di = 0;
					while(di < 4)                 //��(i,j)��������ܿ��߷���
					{ 
						switch(di)
						{
						case 0: 
							i1 = i-1; 
							j1 = j; 
							break;                   //��
							
						case 1: 
							i1 = i; 
							j1 = j+1;
							break;                    //��
							
						case 2: 
							i1 = i+1;
							j1 = j;
							break;                   //��
							
						case 3: 
							i1 = i; 
							j1 = j-1;
							break;                     //��
						}
						
						if(mg[i1][j1] == 2)               //(i1,j1)Ϊ���߷���
						{
							p = new(ArcNode);              //����һ���ڵ�*p
							p->i = i1; 
							p->j = j1;
							p->nextarc = G->adjlist[i][j].firstarc; //��*p�ڵ����������
							G->adjlist[i][j].firstarc = p;
						}
						di ++;
					}
				}
}

void Means::DispAdj(ALGraph *G) //����ڽӱ�G
{
	int i, j;
	ArcNode *p;
	cout << "�ڽӱ�" << endl;
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

//���·������
void Means::OutputPath(SqStack *S)
{
	int k;
	for(k = 0; k <= S->top; k++)
	{
		cout << "(" << S->data[k].i << "," <<  S->data[k].j << ")";
	}
	cout << endl;
}

//���ڷǵݹ����������������ҳ����д�(xi, yi)��(xe, ye)�ļ�·��
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
	
	while( (S->top) >=0 ) //ջ�ǿ�
	{
		GetTop(S,box); //ȡջ��Ԫ��
		int x = box.i;
		int y = box.j;
		
		if(x == xe && y == ye) //�ѵ������ 
		{ 
			OutputPath(S); //
			Pop(S, box); //��ջ
			visited[x][y] = 0; //��λ
			continue;
		}
		
		ArcNode *p = (G->adjlist[x][y]).firstarc; //��(x,y)��Ӧ���ڽӵ�����ͷ�ڵ�
		int i = 0;
		while(p != NULL && i++ < numOfTries[x][y]) //����һ�����Կ��ǵ��ڽӵ�
			p = p->nextarc;
		
		if(p == NULL) //û���ڽӵ���
		{
			Pop(S, box); //��ջ
			visited[x][y] = 0; //��λ
			numOfTries[x][y] = 0; //
		}
		else //һ���µ��ڽӵ�, ����̽��
		{
			numOfTries[x][y] = numOfTries[x][y] + 1;
			if (visited[p->i][p->j] == 0) //�ڽӵ���Ա�����̽��
			{
				box.i = p->i;
				box.j = p->j;
				Push(S, box); //��ջ
				visited[p->i][p->j] = 1;
			}
		}
	}
}

//���ڹ�������������ҳ����д�(xi, yi)��(xe, ye)�ļ�·��
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
