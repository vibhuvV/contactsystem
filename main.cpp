/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: vaibh
 *
 * Created on 6 October, 2018, 4:27 PM
 */

#include <cstdlib>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<iostream>
#include<stdlib.h>

#include "contacts.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
system("cls");
	system("color 03");

    for(;;)
    {
		    int ch;
    cout<<"\n\t **** Welcome to Contact Management System ****";
    cout<<"\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t";
    cout<<"Enter the choice: ";

    cin>>ch;

    switch(ch)
    {
    	case 0: cout<<"\n\n\t\tThank you for using CMS...";
    		exit(0);
    			break;
        break;
    	     break;
    	case 1:save_contact();
    		break;
    	case 2:show_all_contacts();
    		break;
   		case 3:
		    int num;
            system("cls");
            cout<<"\n\n\tPhone: ";
            cin>>num;
			display_contact(num);
    		break;
    	case 4:edit_contact();
    		break;
    	case 5:delete_contact();
    		break;
    	default:
    		break;
    }




	int opt;
   cout<<"\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n";

   cin>>opt;

    switch (opt)

    {

    case 1:
		system("cls");
        continue;

    case 0:

       exit(0);

}
	}
	return 0;

}

