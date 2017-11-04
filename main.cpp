#include <iostream> 
#include <string> 
#include <fstream> 
#include <string> 
#include <iomanip> 
using namespace std;  
//����ṩ50��ѧ�������ݣ��ɸ�����Ҫ���и��� 
const int MAX = 50;     
int count = 0;    
//����ͳ��ѧ������   
class Student
{  
public:   
	void Set();    //��ʼ����Ϣ����һ�ζ���Ϣ��¼��  
	void Add();    //���ѧ����Ϣ   
	//�Ӵ��̶�ȡ�����Ա� ���� ���ݵĲ�������������д������  
	friend void Read(string no[],string name[],string address[],string call[],string wechat[],string mail[],string qq[],string gexing[]);   
	int Judge(string num); //�ж� num �Ƿ���ѧ����Ϣ���ݿ��У�ע������һ��������������һ��int�͵ķ���ֵ��   
	void Delete();   //ɾ��ĳѧ����Ϣ  
	void Change();   //�޸�ĳѧ����Ϣ     
	void Search();   //��ѯĳѧ����Ϣ  
	void Display();   //��ʾȫ��ѧ����Ϣ 
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
	ofstream outfile("student.txt");   //���ļ�  
	if(!outfile)  
	{    
		cerr<<" open error"<<endl;    
		exit(1);  //�˳�����  
	}     
	
	cout<<"��ѧ������Ϊ 0 ʱ,ֹͣ����!"<<endl;   
	cout<<"����������ѧ����ѧ��,����,��ͥסַ,�绰,΢�ţ����䣬QQ����������:"<<endl;  
	for(int i=0; i<MAX; i++)  
	{    
		cout<<"��"<<count+1<<"��ѧ��:"<<endl;   
		cin>>no;    
		if(no == "0") break;  //�������ѧ���� 0  ʱ��ֹͣ¼��    
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

//���ѧ����Ϣ  
void Student::Add() 
{   
	string no,name,address,call,wechat,mail,qq,gexing;
	ofstream outfile("student.txt",ios::app);  
	if(!outfile)   
	{   
		cerr<<" open error"<<endl;   
		exit(1);  
	}  
	count++;  //���һ��ѧ����Ϣ����Ȼ count Ҫ  +1   
	cout<<"����������Ҫ��ӵ�ѧ����ѧ��,����,��ͥסַ,�绰,΢��,����,QQ,��������:"<<endl;  
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
	cout<<"����ӳɹ�!"<<endl;
}

//�Ӵ��̶�ȡ����  
void Read(string no[],string name[],string address[],string call[],string wechat[],string mail[],string qq[],string gexing[])  
{   
	ifstream infile("student.txt",ios::in);  
	if(!infile)  
	{   
		cerr<<" open error"<<endl;   
		exit(1); 
	}  
	for(int i=0; i<count; i++)  //ֻ��ȡ����������� �������������ز���   
	{    
		infile>>no[i]>>name[i]>>address[i]>>call[i]>>wechat[i]>>mail[i]>>qq[i]>>gexing[i]; 
	}   
	infile.close();
}   

//�ж�ĳѧ�ŵ�ѧ���Ƿ������ݿ��� 
int Student::Judge(string num) 
{   
	string no[MAX],name[MAX], address[MAX], call[MAX], wechat[MAX], mail[MAX], qq[MAX],gexing[MAX];
	Read(no,name,address,call,wechat,mail,qq,gexing);
	for(int i=0; i<count; i++) 
	{    
		if(num == no[i])   
		{     
			return i;  //������ڣ��������±�    
			break;   
		} 
	}  
	return -1;  //���򣬷���-1 
}     
	
//ɾ��ĳѧ����Ϣ 
void Student::Delete() 
{   
	string num, no[MAX],name[MAX], address[MAX], call[MAX], wechat[MAX], mail[MAX], qq[MAX],gexing[MAX];     
	Read(no,name,address,call,wechat,mail,qq,gexing); //��ȡѧ���������ݣ�    
	cout<<"��������Ҫɾ����ѧ��:";  
	cin>>num;   
	int k = Judge(num);   //����һ��k������Judge()�ķ���ֵ�����������жϸ�num�Ƿ����    
	if(k != -1)  //���k������-1�� ��ʾҪɾ����ѧ������ 
	{  
		ofstream outfile("student.txt");  
		if(!outfile)   
		{     
			cerr<<" open error"<<endl;    
			exit(1);  
		}      
		for(int i=0; i<count; i++)   
		{    
			if(i != k)  //���±겻����K��������Ҫɾ��ѧ���⣩�������������д����̱���    
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
		count--;  //ɾ��һ��ѧ�������� -1  
		cout<<"ɾ���ɹ�!"<<endl; 
	}  
	else   
		cout<<"�����ݿ�û�д�ѧ��!"<<endl;
}  

void Student::Change() 
{       
	string num, no[MAX],name[MAX], address[MAX], call[MAX], wechat[MAX], mail[MAX], qq[MAX],gexing[MAX];
	cout<<"��������Ҫ�޸ĵ�ѧ��ѧ��:";
	cin>>num;  
	int k = Judge(num);
	if(k != -1)  
	{    
		Read(no,name,address,call,wechat,mail,qq,gexing);
		cout<<"�����������޸ĺ��ѧ��ѧ��,����,�Ա�,רҵ,�༶:"<<endl;   
		cin>>no[k]>>name[k]>>address[k]>>call[k]>>wechat[k]>>mail[MAX]>>qq[MAX]>>gexing[MAX];
		ofstream outfile("student.txt",ios::out);  
		if(!outfile)  
		{    
			cerr<<" open error"<<endl;   
			exit(1);   
		}   
		for(int i=0; i<count; i++)  //����󣬻�д�����̱���  
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
		cout<<"�޸ĳɹ�!"<<endl; 
	}  
	else   
		cout<<"�����ݿ�û�д�ѧ��!"<<endl; 
} 

void Student::Search() 
{  
	string num, no[MAX],name[MAX], address[MAX], call[MAX], wechat[MAX], mail[MAX], qq[MAX],gexing[MAX]; 
	Read(no,name,address,call,wechat,mail,qq,gexing);
	cout<<"��������Ҫ���ҵ�ѧ��ѧ��"; 
	cin>>num;  
	int k = Judge(num);  
	if(k != -1)   //�ҵ���ѧ���ʹ�ӡ������Ϣ 
	{   
		cout<<"ѧ��\t����\t��ͥ��ַ\t�绰\t΢��\t����\tQQ\t����ǩ��"<<endl;   
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
		cout<<"�����ݿ�û�д�ѧ��!"<<endl;
} 

//��ʾѧ����������Ϣ
void Student::Display()
{    
	string num, no[MAX],name[MAX], address[MAX], call[MAX], wechat[MAX], mail[MAX], qq[MAX],gexing[MAX];
	Read(no,name,address,call,wechat,mail,qq,gexing); 
	cout<<"ѧ��\t����\t��ͥ��ַ\t�绰\t΢��\t����\tQQ\t����ǩ��"<<endl;
	for(int i=0; i<count; i++)  //���ӡ 
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
	while(choice != 0) //������ѡ���˳�������һֱѭ�� 
	{  
		cout<<"\n\t\t\t-------ͬѧ¼-------\n\n"; 
		cout<<"\t\t\t|  1.¼��ѧ����Ϣ  |\n"; 
		cout<<"\t\t\t|  2.���һ����Ϣ  |\n";  
		cout<<"\t\t\t|  3.ɾ��һ����Ϣ  |\n";  
		cout<<"\t\t\t|  4.�޸�ѧ����Ϣ  |\n"; 
		cout<<"\t\t\t|  5.��ѯѧ����Ϣ  |\n"; 
		cout<<"\t\t\t|  6.��ʾѧ����Ϣ  |\n";  
		cout<<"\t\t\t|  0.�˳�    ϵͳ  |\n";   
		cout<<"��ѡ������Ҫ�Ĳ���:";  
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
				  cout<<"���ѡ������!������ѡ��!"<<endl;   
				  break;  
			  }   
	}   
	return 0; 
}