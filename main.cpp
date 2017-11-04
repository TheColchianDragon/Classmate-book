#include <iostream> 
#include <string> 
#include <fstream> 
#include <string> 
#include <iomanip> 
using namespace std;  
//最多提供50个学生的数据，可根据需要进行更改 
const int MAX = 50;     
int count = 0;    
//用来统计学生人数   
class Student
{  
public:   
	void Set();    //初始化信息，第一次对信息的录入  
	void Add();    //添加学生信息   
	//从磁盘读取数据以便 进行 数据的操作，方便再重写进磁盘  
	friend void Read(string no[],string name[],string address[],string call[],string wechat[],string mail[],string qq[],string gexing[]);   
	int Judge(string num); //判断 num 是否在学生信息数据库中（注意它有一个参数，并且有一个int型的返回值）   
	void Delete();   //删除某学生信息  
	void Change();   //修改某学生信息     
	void Search();   //查询某学生信息  
	void Display();   //显示全部学生信息 
private:   
	string m_no;  
	string m_name; 
	string m_address;
	string m_call;
	string m_wechat;
	string m_mail;
	string m_qq;
	string m_gexing;
};   

void Student::Set() 
{  
	string no,name,address,call,wechat,mail,qq,gexing;
	ofstream outfile("student.txt");   //打开文件  
	if(!outfile)  
	{    
		cerr<<" open error"<<endl;    
		exit(1);  //退出程序  
	}     
	
	cout<<"当学号输入为 0 时,停止输入!"<<endl;   
	cout<<"请依次输入学生的学号,姓名,家庭住址,电话,微信，邮箱，QQ，个性语言:"<<endl;  
	for(int i=0; i<MAX; i++)  
	{    
		cout<<"第"<<count+1<<"个学生:"<<endl;   
		cin>>no;    
		if(no == "0") break;  //当输入的学号是 0  时，停止录入    
		cin>>name>>address>>call>>wechat>>mail>>qq>>gexing;
		count++;    
		m_no = no;      
		outfile<<m_no<<"\t";        
		m_name = name;    
		outfile<<m_name<<"\t";   
		m_address = address;
		outfile<<m_address<<"\t";
		m_call = call;
		outfile<<m_call<<"\t";
		m_wechat = wechat;
		outfile<<m_wechat<<"\t";
		m_mail = mail;
		outfile<<m_mail<<"\t";
		m_qq = qq;
		outfile<<m_qq<<"\t";
		m_gexing = gexing;
		outfile<<m_gexing<<endl;
	}   
	outfile.close();
}   

//添加学生信息  
void Student::Add() 
{   
	string no,name,address,call,wechat,mail,qq,gexing;
	ofstream outfile("student.txt",ios::app);  
	if(!outfile)   
	{   
		cerr<<" open error"<<endl;   
		exit(1);  
	}  
	count++;  //添加一个学生信息，当然 count 要  +1   
	cout<<"请依次输入要添加的学生的学号,姓名,家庭住址,电话,微信,邮箱,QQ,个性语言:"<<endl;  
	cin>>no>>name>>address>>call>>wechat>>mail>>qq>>gexing;
	m_no = no;
	outfile<<m_no<<"\t";
	m_name = name;    
	outfile<<m_name<<"\t";   
	m_address = address;
	outfile<<m_address<<"\t";
	m_call = call;
	outfile<<m_call<<"\t";
	m_wechat = wechat;
	outfile<<m_wechat<<"\t";
	m_mail = mail;
	outfile<<m_mail<<"\t";
	m_qq = qq;
	outfile<<m_qq<<"\t";
	m_gexing = gexing;
	outfile<<m_gexing<<endl;  
	outfile.close();  
	cout<<"已添加成功!"<<endl;
}

//从磁盘读取数据  
void Read(string no[],string name[],string address[],string call[],string wechat[],string mail[],string qq[],string gexing[])  
{   
	ifstream infile("student.txt",ios::in);  
	if(!infile)  
	{   
		cerr<<" open error"<<endl;   
		exit(1); 
	}  
	for(int i=0; i<count; i++)  //只读取存放在数组中 但不对其进行相关操作   
	{    
		infile>>no[i]>>name[i]>>address[i]>>call[i]>>wechat[i]>>mail[i]>>qq[i]>>gexing[i]; 
	}   
	infile.close();
}   

//判断某学号的学生是否在数据库中 
int Student::Judge(string num) 
{   
	string no[MAX],name[MAX], address[MAX], call[MAX], wechat[MAX], mail[MAX], qq[MAX],gexing[MAX];
	Read(no,name,address,call,wechat,mail,qq,gexing);
	for(int i=0; i<count; i++) 
	{    
		if(num == no[i])   
		{     
			return i;  //如果存在，返回其下标    
			break;   
		} 
	}  
	return -1;  //否则，返回-1 
}     
	
//删除某学生信息 
void Student::Delete() 
{   
	string num, no[MAX],name[MAX], address[MAX], call[MAX], wechat[MAX], mail[MAX], qq[MAX],gexing[MAX];     
	Read(no,name,address,call,wechat,mail,qq,gexing); //读取学生所有数据，    
	cout<<"请输入你要删除的学生:";  
	cin>>num;   
	int k = Judge(num);   //定义一个k来接收Judge()的返回值，等下用来判断该num是否存在    
	if(k != -1)  //如果k不等于-1， 表示要删除的学生存在 
	{  
		ofstream outfile("student.txt");  
		if(!outfile)   
		{     
			cerr<<" open error"<<endl;    
			exit(1);  
		}      
		for(int i=0; i<count; i++)   
		{    
			if(i != k)  //把下标不等于K（即除了要删的学生外）其余的数据重新写入磁盘保存    
			{     
				outfile<<no[i]<<"\t";    
				outfile<<name[i]<<"\t";  
				outfile<<address[i]<<"\t";
				outfile<<call[i]<<"\t";
				outfile<<wechat[i]<<"\t";
				outfile<<mail[i]<<"\t";
				outfile<<qq[i]<<"\t";
				outfile<<gexing[i]<<"\t";   
			} 
		}   
		outfile.close();  
		count--;  //删除一个学生，人数 -1  
		cout<<"删除成功!"<<endl; 
	}  
	else   
		cout<<"该数据库没有此学生!"<<endl;
}  

void Student::Change() 
{       
	string num, no[MAX],name[MAX], address[MAX], call[MAX], wechat[MAX], mail[MAX], qq[MAX],gexing[MAX];
	cout<<"请输入你要修改的学生学号:";
	cin>>num;  
	int k = Judge(num);
	if(k != -1)  
	{    
		Read(no,name,address,call,wechat,mail,qq,gexing);
		cout<<"请依次输入修改后的学生学号,姓名,性别,专业,班级:"<<endl;   
		cin>>no[k]>>name[k]>>address[k]>>call[k]>>wechat[k]>>mail[MAX]>>qq[MAX]>>gexing[MAX];
		ofstream outfile("student.txt",ios::out);  
		if(!outfile)  
		{    
			cerr<<" open error"<<endl;   
			exit(1);   
		}   
		for(int i=0; i<count; i++)  //改完后，回写进磁盘保存  
		{    
			outfile<<no[i]<<"\t";    
			outfile<<name[i]<<"\t";  
			outfile<<address[i]<<"\t";
			outfile<<call[i]<<"\t";
			outfile<<wechat[i]<<"\t";
			outfile<<mail[i]<<"\t";
			outfile<<qq[i]<<"\t";
			outfile<<gexing[i]<<"\t"; 
		}   
		outfile.close();  
		cout<<"修改成功!"<<endl; 
	}  
	else   
		cout<<"该数据库没有此学生!"<<endl; 
} 

void Student::Search() 
{  
	string num, no[MAX],name[MAX], address[MAX], call[MAX], wechat[MAX], mail[MAX], qq[MAX],gexing[MAX]; 
	Read(no,name,address,call,wechat,mail,qq,gexing);
	cout<<"请输入你要查找的学生学号"; 
	cin>>num;  
	int k = Judge(num);  
	if(k != -1)   //找到该学生就打印出其信息 
	{   
		cout<<"学号\t姓名\t家庭地址\t电话\t微信\t邮箱\tQQ\t个性签名"<<endl;   
		cout<<no[k]<<"\t"; 
		cout<<name[k]<<"\t";
		cout<<address[k]<<"\t";
		cout<<call[k]<<"\t";
		cout<<wechat[k]<<"\t";
		cout<<mail[k]<<"\t";
		cout<<qq[k]<<"\t";
		cout<<gexing[k]<<"\t";
	}  
	else  
		cout<<"该数据库没有此学生!"<<endl;
} 

//显示学生的所有信息
void Student::Display()
{    
	string num, no[MAX],name[MAX], address[MAX], call[MAX], wechat[MAX], mail[MAX], qq[MAX],gexing[MAX];
	Read(no,name,address,call,wechat,mail,qq,gexing); 
	cout<<"学号\t姓名\t家庭地址\t电话\t微信\t邮箱\tQQ\t个性签名"<<endl;
	for(int i=0; i<count; i++)  //后打印 
	{   
		cout<<no[i]<<"\t";   
		cout<<name[i]<<"\t"; 
		cout<<address[i]<<"\t"; 
		cout<<call[i]<<"\t"; 
		cout<<wechat[i]<<"\t"; 
		cout<<mail[i]<<"\t"; 
		cout<<qq[i]<<"\t"; 
		cout<<gexing[i]<<"\t"; 
	} 
}   

int main() 
{   
	int choice = -1; 
	Student s;   
	while(choice != 0) //除非你选择退出，否则一直循环 
	{  
		cout<<"\n\t\t\t-------同学录-------\n\n"; 
		cout<<"\t\t\t|  1.录入学生信息  |\n"; 
		cout<<"\t\t\t|  2.添加一个信息  |\n";  
		cout<<"\t\t\t|  3.删除一个信息  |\n";  
		cout<<"\t\t\t|  4.修改学生信息  |\n"; 
		cout<<"\t\t\t|  5.查询学生信息  |\n"; 
		cout<<"\t\t\t|  6.显示学生信息  |\n";  
		cout<<"\t\t\t|  0.退出    系统  |\n";   
		cout<<"请选择所需要的操作:";  
		cin>>choice;
		      switch(choice)   
			  {    
			  case 1:   
				  s.Set();  
				  break;  
			  case 2:    
				  s.Add();   
				  break;  
			  case 3:   
				  s.Delete();  
				  break;  
			  case 4:   
				  s.Change();    
				  break;  
			  case 5:     
				  s.Search(); 
				  break; 
			  case 6:     
				  s.Display();  
				  break; 
			  case 0:   
				  break; 
			  default:    
				  cout<<"你的选择有误!请重新选择!"<<endl;   
				  break;  
			  }   
	}   
	return 0; 
}