/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   contacts.h
 * Author: vaibh
 *
 * Created on 6 October, 2018, 4:28 PM
 */

#ifndef CONTACTS_H
#define CONTACTS_H
#include <fstream>
#include <string.h>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;
 
class contact
{
	long ph;
    char name[20], add[100], email[60];

	public:

	void create_contact()
	{
            cout<<"Phone: ";
            cin>>ph;

            cout<<"Name: ";
            cin.ignore();
            cin>>name;

			cout<<"Address: ";
            cin.ignore();
            cin>>add;

            cout<<"Email address: ";
            cin.ignore();
            cin>>email;

            cout<<"\n";
	}

	void show_contact()
	{
		cout<<endl<<"Phone #: "<<ph;
		cout<<endl<<"Name: "<<name;
		cout<<endl<<"Address: "<<add;
		cout<<endl<<"Email Address : "<<email;
	}

	long getPhone()
	{
		return ph;
	}

	char* getName()
	{
		return name;
	}

	char* getAddress()
	{
		return add;
	}

	char* getEmail()
	{
		return email;
	}
};

fstream fp;
contact cont;

void save_contact()
{
	fp.open("contactBook.dat",ios::out|ios::app);
	cont.create_contact();
	fp.write((char*)&cont,sizeof(contact));
	fp.close();
	cout<<endl<<endl<<"Contact Has Been Sucessfully Created...";
	getchar();
}

void show_all_contacts()
{
	system("cls");
	 cout<<"\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n";
	fp.open("contactBook.dat",ios::in);
	while(fp.read((char*)&cont,sizeof(contact)))
	{
		cont.show_contact();
		cout<<endl<<"=================================================\n"<<endl;
	}
	fp.close();
}


void display_contact(int num)
{
	bool found;
	int ch;

		 found=false;
	fp.open("contactBook.dat",ios::in);
	while(fp.read((char*)&cont,sizeof(contact)))
	{
		if(cont.getPhone()==num)
		{
			system("cls");
			cont.show_contact();
			found=true;
		}
	}

	fp.close();
	if(found == false){
	cout<<"\n\nNo record found...";}


	getchar();
}


void edit_contact()
{
	int num;
	bool found=false;
	system("cls");
	cout<<"..::Edit contact\n===============================\n\n\t..::Enter the number of contact to edit:";
    cin>>num;

	fp.open("contactBook.dat",ios::in|ios::out);
	while(fp.read((char*)&cont,sizeof(contact)) && found==false)
	{
		if(cont.getPhone()==num)
		{
			cont.show_contact();
            cout<<"\nPlease Enter The New Details of Contact: "<<endl;
			cont.create_contact();
			int pos=-1*sizeof(cont);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&cont,sizeof(cont));
			cout<<endl<<endl<<"\t Contact Successfully Updated...";
			found=true;
		}
	}
	fp.close();
	if(found==false)
		cout<<endl<<endl<<"Contact Not Found...";


}


void delete_contact()
{
	int num;
	system("cls");
	cout<<endl<<endl<<"Please Enter The contact #: ";
	cin>>num;
	fp.open("contactBook.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&cont,sizeof(contact)))
	{
		if(cont.getPhone()!=num)
		{
			fp2.write((char*)&cont,sizeof(contact));
		}
	}
	fp2.close();
	fp.close();
	remove("contactBook.dat");
	rename("Temp.dat","contactBook.dat");
	cout<<endl<<endl<<"\tContact Deleted...";
}


#endif /* CONTACTS_H */

