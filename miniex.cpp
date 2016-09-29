
#include<fstream>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int i=0;
	char s[80],k[80],m[80];
	
	int scount=0;
	
	ofstream sefile;
	sefile.open("Search.txt");
	
	cout<<"enter search word:";
	gets(k);
	
	sefile<<k;		//storing search phrase in a separate file
	sefile.close();
	
	ifstream sfile,file;
	sfile.open("Search.txt");
	
	while(!sfile.eof())
	{
		sfile>>k;		
		scount++;		//counting no of words in the search phrase by no of words stored in Search.txt file
	}
	
	sfile.close();
	i=0;
	int word=0;;
	char sm[scount][80];
	char ch;
	
	file.open("Search.txt");
	while(!file.eof())
	{
		file>>k;			//storing a word from Search.txt
		strcpy(sm[i],k);	//storing each word from Search.txt for matching in string array
		i++;
	}
	file.close();

	int count=0,flag=0;
	i=0;
	
	ifstream infile;
	infile.open("file.txt");
	while(!infile.eof())
	{
		infile>>k;		//storing a word from file.txt i.e file in which searching will be done
		count++;
		ch=k[strlen(k)-1];
		if(ch=='.' || ch==',' || ch==':' || ch=='-' || ch==';' || ch=='!')
		k[strlen(k)-1]='\0';
		if(strcmpi(k,sm[i])==0)	//matching word of search phrase with word of search file
		{
			i++;		//increasing the value of i so that next word present in search phrase will be matched with next of search file
			flag++;		//Checking no of words in file.txt that matched with the search phrase consecutively
		}
		else
		{
			i=0;		//going back to the start word of the search phrase after unsuccessful search
			flag=0;
		}
		if(flag==scount)
		{
			cout<<"found at word no:"<<(count-flag+1)<<"\n";
			i=0;			//going back to the start word of the search phrase after successful search
			flag=0;
			word++;			//counting no of occurrrences
		}
	}
	infile.close();
	cout<<"No of occourences="<<word<<"\n";
	
	return 0;
}
