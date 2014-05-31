//----------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
void deletearrayelement(int myarray[], int mysize, int mydatasize, int pos)
{
	int bufarray[mysize]; 
	for (int i=0; i<mysize; i++)
	{
		bufarray[i] = myarray[i];
	}
	
	for (int c=pos; c<mysize; c++)
	{
		myarray[c] = bufarray[c + 1]; 
	}
	myarray[mydatasize] = 0;
}
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------

void deletearrayelement(string myarray[], int mysize, int mydatasize, int pos)
{
	string bufarray[mysize]; 
	for (int i=0; i<mysize; i++)
	{
		bufarray[i] = myarray[i];
	}
	
	for (int c=pos; c<mysize; c++)
	{
		myarray[c] = bufarray[c + 1]; 
	}
	myarray[mydatasize] = "";
}
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
void deltask(int mypos)
{
	deletearrayelement(taskarray,size,taskcount,mypos);
	
	taskcount--;
}
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
void dataexport()
{
	ofstream myfile("data.dat");
	
	for (int i=0; i<taskcount; i++)
	{
		myfile << taskarray[i];
		myfile << ";";
	}
	
	myfile.close();
}
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
string read(ifstream &file)
{
	char buf[1024];
	file.getline(&(buf[0]), 1024, ';');
	return string(buf);
}
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
void dataimport()
{
	ifstream myfile("data.dat");
	bool done = false;
	int counter = 0;
	
		while (!done)
		{		
			if (myfile.eof() == true) //check if end of file reached
			{
				done = true;
				break;
			}
			else
			{
				string words = read(myfile);
				taskarray[counter] = words;
				
				counter++;
				taskcount++;
			}
		}
	
	taskcount--;
	myfile.close();
}
//----------------------------------------------------------------------------------



