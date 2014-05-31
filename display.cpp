//----------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------
const int size = 50;
int taskcount = 0;
//----------------------------------------------------------------------------------
string taskarray[size];
//----------------------------------------------------------------------------------
void input();
void deletetask();
void about();
int exit();

//----------------------------------------------------------------------------------
void deletearrayelement(int myarray[], int mysize, int mydatasize, int pos);
void deletearrayelement(string myarray[], int mysize, int mydatasize, int pos);
void deltask(int mypos);
void dataexport();
string read(ifstream &file);
void dataimport();
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
void display()
{
	system("CLS");
	
	cout << "\t \t \t   ---[Retro Task Manager]---" << endl;
	
	cout << left;
	
	cout << "\t \t ===========================================" << endl;
	cout << "\t \t |" << setw(10) << "Task no" << "|" << setw(30) << "Task" << "|" << endl;
	cout << "\t \t ===========================================" << endl;

	for (int i=0; i<taskcount; i++)
	{
		cout << "\t \t |" << setw(10) << (i+1) << "|" << setw(30) << taskarray[i] << "|" << endl;
	}
	
	cout << endl;
	cout << endl;
	
	cout << "[1. New Task] [2. Delete Task] [3. Refresh] [4. About] [5. Save & Exit]" << endl;
	
	cout << endl;
	cout << endl;
	cout << endl;
	
	cout << "[Option---->";
	
	int var;
	cin >> var;
	
	if (var == 1)
	{
		input();
	}
	else if (var == 2)
	{
		deletetask();
	}
	else if (var == 3)
	{
		display();
	}
	else if (var == 4)
	{
		about();
	}
	else if (var == 5)
	{
		exit();
	}
	else
	{
		cout << "Invalid Option" << endl;
		exit();
	}
	cout << endl;
	cout << endl;
	cout << endl; 
}
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
void input()
{
	cout << endl;
	cin.ignore();
	
	cout << "    [New Task]" << endl;
	cout << endl;
	// cout << "|---------------" << endl;
	
	cout << "[Task Name--> ";
	
	char charvar[100];
	cin.getline(charvar,100);
	
	taskarray[taskcount] = charvar;
	
	cout << endl;
	
	taskcount++;
	
	display();
}
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
void deletetask()
{	
	cout << "    [Delete Task]" << endl;
	cout << endl;
	cout << "[Task No--> ";
	
	int pos;
	cin >> pos;
	
	pos -= 1;
	
	deltask(pos);
	
	display();
}
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
void about()
{
	system("cls");
	cout << "Created by Saud Saldulkar" << endl;
	system("PAUSE");
	display();
}
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
int exit()
{
	dataexport();
	return 0;
}
//----------------------------------------------------------------------------------