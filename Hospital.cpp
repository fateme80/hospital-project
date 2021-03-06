// بیمارستان.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;

class Person
{
protected:
	string Name,Family,NCode;
	int Age;
public:
	Person(){}
	Person(string Name,string Family,string NCode,int Age)
	{
		this->Name=Name;
		this->Family=Family;
		this->NCode=NCode;
		this->Age=Age;
	}
	void SetName(string Name)
	{
		this->Name=Name;
	}
	void SetFamily(string Family)
	{
		this->Family=Family;
	}
	void SetNCode(string NCode)
	{
		this->NCode=NCode;
	}
	void SetAge(int Age)
	{
		this->Age=Age;
	}
	string GetName()
	{
		return Name;
	}
	string GetFamily()
	{
		return Family;
	}
	string GetNCode()
	{
		return NCode;
	}
	int GetAge()
	{
		return Age;
	}
	virtual void Print()
	{
		cout<<setw(4)<<Name<<"  "<<setw(4)<<Family<<"  "<<setw(4)<<NCode<<"  "<<setw(4)<<Age<<endl;
	}
};

class Doctor:public Person
{
private:
	string Skill;
public:
	Doctor(){countDr++;}
	Doctor(string Name,string Family,string NCode,int Age,string Skill):Person(Name,Family,NCode,Age)
	{
		this->Skill=Skill;
	    countDr++;
	}
	void SetSkill(string Skill)
	{
		this ->Skill=Skill;

	}
	string GetSkill()
	{
		return Skill;
	}
	void Print()
	{
		cout<<setw(4)<<Name<<"  "<<setw(4)<<Family<<"  "<<setw(4)<<NCode<<"  "<<setw(4)<<Age<<"  "<<setw(4)<<Skill<<endl;
	}
	static int countDr;
	static int GetCountD(){return countDr;}
};
int Doctor::countDr=0;
class Patient:public Person
{
private:
	string Illness,DoctorName;
public:
	Patient(){countP++;}
	Patient(string Name,string Family,string NCode,int Age,string Illness,string DoctorName):Person(Name,Family,NCode,Age)
	{
		this->Illness=Illness;
		this->DoctorName=DoctorName;
		countP++;
	}
	void SetIllness(string Illness)
	{
		this ->Illness=Illness;

	}
	string GetIllness()
	{
		return Illness;
	}
	void SetDoctorName(string DoctorName)
	{
		this ->DoctorName=DoctorName;

	}
	string GetDoctorName()
	{
		return DoctorName;
	}
	void Print()
	{
		cout<<setw(4)<<Name<<"  "<<setw(4)<<Family<<"  "<<setw(4)<<NCode<<"  "<<setw(4)<<Age<<"  "<<setw(4)<<Illness<<"  "<<setw(4)<<DoctorName<<endl;
	}
	static int countP;
	static int GetCountP(){return countP;}
};
int Patient::countP=0;
//______________________DOCTOR___________________________
vector<Doctor>data,data2;
fstream DrFile;
void InsertDr()
{
	string Name, Family, NCode, Skill;
	int Age;
	cout<<"Enter name : ";
	cin>>Name;
	cout<<"Enter family : ";
	cin>>Family;
	cout<<endl<<"Enter nat code : ";
	cin>>NCode;
	cout<<endl<<"Enter age : ";
	cin>>Age;
	cout<<endl<<"Enter skill : ";
	cin>>Skill;
	data.push_back(Doctor(Name,Family,NCode,Age,Skill));
	DrFile.open("doctor.csv",ios::app);
	DrFile<<Name + "," + Family + "," + NCode + "," + to_string(Age) + "," + Skill<<endl;
}
void DisplayDr()
{
	for(int i=0;i<data.size();i++)
		data[i].Print();
}
void DisplayOneDr(string code)
{
	for(int i=0;i<data.size();i++)
	{
		if(data[i].GetNCode() == code)
		data[i].Print();
	}
}
void ModifyDr(string code)
{
	int choice,age;
	string name,family,ncode,skill;
	for(int i=0;i<data.size();i++)
	{
		if(data[i].GetNCode() == code)
		{
		cout<<"Which change? "<<endl;
		cout<<"1)Name"<<endl;
		cout<<"2)Family"<<endl;
		cout<<"3)NCode"<<endl;
		cout<<"4)Age"<<endl;
		cout<<"5)Skill"<<endl;
		cin>>choice;
		switch (choice)
		{
		case 1:
			cout<<"Enter new name : ";
			cin>>name;
			data[i].SetName(name);
			break;
			case 2:
			cout<<"Enter new family : ";
			cin>>family;
			data[i].SetFamily(family);
			break;
			case 3:
			cout<<"Enter new nat code : ";
			cin>>ncode;
			data[i].SetNCode(ncode);
			break;
			case 4:
			cout<<"Enter new age : ";
			cin>>age;
			data[i].SetAge(age);
			break;
			case 5:
			cout<<"Enter new skill : ";
			cin>>skill;
			data[i].SetSkill(skill);
			break;
		default:
			break;
		}
	}
	}
}
void DeletDr()
{
	data.clear();
	Doctor::countDr=0;
}
void DeletOneDr(string ncode)
{
  for(int i=0;i<data.size();i++)
	{
		if(data[i].GetNCode() != ncode)
			data2.push_back(data[i]);
	}
  data=data2;
  data2.clear();
  Doctor::countDr --;
}
//______________________PATIENT___________________________
vector<Patient>list,list2;
fstream PFile;
void InsertP()
{
	string Name, Family, NCode, Illness,DoctorName;
	int Age;
	cout<<"Enter name : ";
	cin>>Name;
	cout<<"Enter family : ";
	cin>>Family;
	cout<<endl<<"Enter nat code : ";
	cin>>NCode;
	cout<<endl<<"Enter age : ";
	cin>>Age;
	cout<<endl<<"Enter illness : ";
	cin>>Illness;
	cout<<endl<<"Enter doctor name : ";
	cin>>DoctorName;
	list.push_back(Patient(Name,Family,NCode,Age,Illness,DoctorName));
	PFile.open("patient.csv",ios::app);
	PFile<<Name + "," + Family + "," + NCode + "," + to_string(Age) + "," + Illness + "," + DoctorName<<endl;
}
void DisplayP()
{
	for(int i=0;i<list.size();i++)
		list[i].Print();
}
void DisplayOneP(string code)
{
	for(int i=0;i<list.size();i++)
	{
		if(list[i].GetNCode() == code)
		list[i].Print();
	}
}
void ModifyP(string code)
{
	int choice,age;
	string name,family,ncode,illness,doctorname;
	for(int i=0;i<list.size();i++)
	{
		if(list[i].GetNCode() == code)
		{
		cout<<"Which change? "<<endl;
		cout<<"1)Name"<<endl;
		cout<<"2)Family"<<endl;
		cout<<"3)NCode"<<endl;
		cout<<"4)Age"<<endl;
		cout<<"5)Illness"<<endl;
		cout<<"6)DoctorName"<<endl;
		cin>>choice;
		switch (choice)
		{
		case 1:
			cout<<"Enter new name : ";
			cin>>name;
			list[i].SetName(name);
			break;
			case 2:
			cout<<"Enter new family : ";
			cin>>family;
			list[i].SetFamily(family);
			break;
			case 3:
			cout<<"Enter new nat code : ";
			cin>>ncode;
			list[i].SetNCode(ncode);
			break;
			case 4:
			cout<<"Enter new age : ";
			cin>>age;
			list[i].SetAge(age);
			break;
			case 5:
			cout<<"Enter new illness : ";
			cin>>illness;
			list[i].SetIllness(illness);
			break;
			case 6:
			cout<<"Enter new doctor name : ";
			cin>>doctorname;
			list[i].SetDoctorName(doctorname);
			break;
		default:
			break;
		}
	}
	}
}
void DeletP()
{
	list.clear();
	Patient::countP=0;
}
void DeletOneP(string ncode)
{
  for(int i=0;i<list.size();i++)
	{
		if(list[i].GetNCode() != ncode)
			list2.push_back(list[i]);
	}
  list=list2;
  list2.clear();
  Patient::countP --;
}
void Pateints(string Dname)
{
	for(int i=0;i<list.size();i++)
	{
		if(list[i].GetDoctorName()==Dname)
			cout<<list[i].GetName()<<"  "<<list[i].GetFamily()<<"  "<<list[i].GetIllness()<<endl;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a,b,c,d;
	string ncode,name;
	do{cout<<"------------------------------"<<endl;
	cout<<"           MENU"<<endl;
	cout<<"______________________________"<<endl;
	cout<<"1)REPORT"<<endl;
	cout<<"2)INSERT"<<endl;
	cout<<"3)MODIFY"<<endl;
	cout<<"4)EXIT"<<endl;
	cin>>a;
	switch (a)
	{
	case 1:
		cout<<"1)DISPLAY ALL DOCTORS"<<endl;
		cout<<"2)DISPLAY A DOCTOR"<<endl;
		cout<<"3)DISPLAY ALL PATIENTS"<<endl;
		cout<<"4)DISPLAY A PATIENT"<<endl;
		cout<<"5)DISPLAY NUMBER OF DOCTORS"<<endl;
		cout<<"6)DISPLAY NUMBER OF PATIENTS"<<endl;
		cout<<"7)DISPLAY PATIENTS OF A DOCTOR"<<endl;
		cin>>b;
		switch (b)
		{
		case 1:
			DisplayDr();
			break;
		case 2:
			cout<<"Enter doctor nat cod : "<<endl;
			cin>>ncode;
			DisplayOneDr(ncode);
			break;
		case 3:
			DisplayP();
			break;
		case 4:
			cout<<"Enter patient nat cod : "<<endl;
			cin>>ncode;
			DisplayOneP(ncode);
			break;
		case 5:
			cout<<"The number of doctors : "<<Doctor::GetCountD()<<endl;
			break;
		case 6:
			cout<<"The number of patients : "<<Patient::GetCountP()<<endl;
			break;
		case 7:
			cout<<"Enter doctor name : "<<endl;
			cin>>name;
			Pateints(name);
			break;
		default:
			break;
		}
		break;
	case 2:
		cout<<"1)INSERT A NEW DOCTOR"<<endl;
		cout<<"2)INSERT A NEW PATIENT"<<endl;
		cin>>c;
		switch (c)
		{
		case 1:
			InsertDr();
			break;
		case 2:
			InsertP();
				break;
		default:
			break;
		}
		break;
	case 3:
		cout<<"1)MODIFY A DOCTOR"<<endl;
		cout<<"2)MODIFY A PATIENT"<<endl;
		cout<<"3)DELET A DOCTOR"<<endl;
		cout<<"4)DELET A PATIENT"<<endl;
		cout<<"5)DELET ALL DOCTORS"<<endl;
		cout<<"6)DELET ALL PATIENTS"<<endl;
		cin>>d;
		switch (d)
		{
		case 1:
			cout<<"Enter doctor nat code"<<endl;
			cin>>ncode;
			ModifyDr(ncode);
			break;
		case 2:
			cout<<"Enter patient nat code"<<endl;
			cin>>ncode;
			ModifyP(ncode);
			break;
		case 3:
			cout<<"Enter doctor nat code"<<endl;
			cin>>ncode;
			DeletOneDr(ncode);
			break;
	    case 4:
			cout<<"Enter patient nat code"<<endl;
			cin>>ncode;
			DeletOneP(ncode);
			break;
		case 5:
			DeletDr();
			break;
		case 6:
			DeletP();
			break;
		default:
			break;
		}
		break;
	case 4:
		return 0;
	default:
		break;
	}
	}while(a!=4);
	return 0;
}

