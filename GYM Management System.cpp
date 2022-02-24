#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;

int login()
{
    int key_no;
    string pass="";
    cout <<"\n\n\n\n\t\t\t\t\t GYM MANAGEMENT SYSTEM";
    cout <<"\n\n\n\n\n\t\t\t\t\tEnter Your Password :";
    cin>>pass;
    while(key_no!=10)
    {
        key_no=cin.get();
        if(pass=="Himanshu")
        {
            system("CLS");
        }
        else
        {
            cout << "\nAccess Aborted...\n";
            login();
        }
    }
}

class member
{
private:
    char name[30];
    char id[5];
    char diet[20];
    char age[5];
    char weight[5];
    char exercise[50];
    member *link;

    void waitForEnter(void){
        cout<<"\n\n\n Press enter to go back \n\n";
        cin.get();
        cin.get();
    }

    void add_Newmember()
    {

        member *temp;
        temp=(member*)malloc(sizeof(member));
        temp->link=NULL;
        system("cls");
        cout<<"\n";
        cout<<"\n Enter First Name of member: ";
        cin>>temp->name;
        cout<<"\n";
        cout<<"\n Enter member ID [max 4 digits]: ";
        cin>>temp->id;
        cout<<"\n";
        cout<<"\n Enter diet: ";
        cin>>temp->diet;
        cout<<"\n";
        cout<<"\n Enter member Age: ";
        cin>>temp->age;
        cout<<"\n";
        cout<<"\n Enter member weight: ";
        cin>>temp->weight;
        cout<<"\n";
        cout<<"\n Enter member exercise: ";
        cin>>temp->exercise;
        cout<<"\n";
        char ch;
        cout<<"\nEnter 'y' to save above information\n";
        cin>>ch;
        if(ch=='y'){

            if(root==NULL)
            {
                root=temp;
            }
            else
            {
                member *p;
                p=root;
                while(p->link!=NULL)
                {
                    p=p->link;
                }
                p->link=temp;
                temp->link=NULL;
            }
            cout<<"\nNew member has been added to database\n";

        }
        else
        {
            add_Newmember();
        }

        waitForEnter();

    }
    void listmembers()
    {
        member *t;
        t=root;
        system("cls");
        cout<<"\n\t      List of members\n";
        cout<<"\n";
        cout<<"\n   NAME               |            ID            |         age       \n";
        cout<<" ";
        if(t==NULL)
        {
            printf("\n        list is empty  n");
        }
        else
        {
            while(t!=NULL)
            {
                cout<<"\n"<<setw(15)<<t->name<<setw(15)<<t->id<<setw(25)<<t->age ;
                t=t->link;
            }
        }
        waitForEnter();

    }
    void showDetails()
    {
        char check[5];
        system("cls");
        cout<<"\n\nEnter member Id: ";
        cin>>check;
        member *t;
        t=root;
        if(t==NULL)
        {
            printf("\n       list is empty   \n");
        }
        else
        {
            while(t!=NULL)
            {
                 if(!strcmp(check,t->id)){
                	cout<<"\n";
                    cout<<"\nName: "<<t->name;
                    cout<<"\n";
                    cout<<"\nId: "<<t->id;
                    cout<<"\n";
                    cout<<"\ndiet: "<<t->diet;
                    cout<<"\n";
                    cout<<"\nAge: "<<t->age;
                    cout<<"\n";
                    cout<<"\nweight: "<<t->weight;
                    cout<<"\n";
                    cout<<"\nexercise: "<<t->exercise;
                    cout<<"\n";
                    break;

                 }
                 t=t->link;
            }
        }
        waitForEnter();
    }

    void editExisting()
    {
         system("cls");
         char check[5];
         cout<<"\nEnter member id: ";
         cin>>check;

         member *t;
         t=root;
         if(t==NULL)
         {
             cout<<"\n\n        list is empty  ";
         }
         else
         {
             while(t!=NULL)
             {
                 if(!strcmp(check,t->id))
                 {
                     char new_name[15];
                     char new_diet[10];
                     char new_age[5];
                     char new_weight[15];
                     char new_exercise[3];
                     cout<<"\n";
                     cout<<"\nEnter new Name: ";
                     cin>>new_name;
                     cout<<"\n";
                     cout<<"\nEnter new diet: ";
                     cin>>new_diet;
                     cout<<"\n";
                     cout<<"\nEnter new Age: ";
                     cin>>new_age;
                     cout<<"\n";
                     cout<<"\nEnter new weight: ";
                     cin>>new_weight;
                     cout<<"\n";
                     cout<<"\nEnter new exercise: ";
                     cin>>new_exercise;
                     cout<<"\n";
                     strcpy(t->name,new_name);
                     strcpy(t->age,new_age);
                     strcpy(t->weight,new_weight);
                     strcpy(t->diet,new_diet);
                     strcpy(t->exercise,new_exercise);
                     break;
                 }
                 t=t->link;
             }
         }
         waitForEnter();
    }

    void deletememberDetails()
    {
        char check[5];
        system("cls");
        cout<<"\n\nEnter member Id: ";
        cin>>check;
        member *t,*p,*q,*s;
        t=root;
        s=root;
        if(t==NULL)
        {
            printf("\n       list is empty  \n");
        }
        else
        {
            while(t->link!=NULL)
            {
                 p=t;

                 if(!strcmp(check,t->link->id)){
                        q=t->link;
                        t->link=p->link->link;
                        q->link=NULL;
                        free(q);
                        cout<<"\n member  deleted from database\n";
                        break;

                 }
                 t=t->link;
             }
             if(!strcmp(check,root->id))
             {
                	    root=s->link;
                	    s->link=NULL;
                	    free(s);
                	    cout<<"\n member gg  deleted from database\n";
             }
        }

        waitForEnter();
    }

void bloaddata()
{
    char name2[60];
    char name1[30];
    char id1[20];
    char diet1[20];
    char age1[10];
    char weight1[15];
    char exercise1[5];
    fstream MyExcelFile;
    MyExcelFile.open("E:\member.csv");
    MyExcelFile>>name2;
    while(MyExcelFile)
    {
         char *token = strtok(name2, ",");
         int i=0;
         while (token != NULL)
         {
              switch(i)
              {
                  case 0:strcpy(name1,token);
                         break;
                  case 1:strcpy(id1,token);
                          break;
                  case 2:strcpy(diet1,token);
                          break;
                  case 3:strcpy(age1,token);
                          break;
                  case 4:strcpy(weight1,token);
                          break;
                  case 5:strcpy(exercise1,token);
                          break;
              }
              token = strtok(NULL, ",");
              i++;
         }

     member *temp;
     temp=(member*)malloc(sizeof(member));
     temp->link=NULL;
     strcpy(temp->name,name1);
     strcpy(temp->id,id1);
     strcpy(temp->diet,diet1);
     strcpy(temp->age,age1);
     strcpy(temp->weight,weight1);
     strcpy(temp->exercise,exercise1);
            if(root==NULL)
            {
                root=temp;
            }
            else
            {
                member *p;
                p=root;
                while(p->link!=NULL)
                {
                    p=p->link;
                }
                p->link=temp;
                temp->link=NULL;
            }

     MyExcelFile>>name2;
    }
    MyExcelFile.close();

}

void eloaddata()
{
     fstream MyExcelFile;
     MyExcelFile.open("E:\member.csv",ios::out | ios::trunc);

     member *t;
     t=root;
     if(t==NULL)
     {

     }
     else
     {
         while(t!=NULL)
         {
                MyExcelFile<<t->name<<","<<t->id<<","<<t->diet<<","<<t->age<<","<<t->weight<<","<<t->exercise<<"\n";
                t=t->link;
         }
     }
     MyExcelFile.close();

}

public:
    member *root=NULL;
    void option()
    {
        int login();
        login();
        bloaddata();
        while(1){
                system("cls");

                cout<<"\n\t\t\t         GYM MANAGEMENT SYSTEM   ";
                cout<<"\n";
                cout<<"\n";
                cout<<"\n\t\t\t     1:   View List of members";
                cout<<"\n";
                cout<<"\n\t\t\t     2:   View member Details";
                cout<<"\n";
                cout<<"\n\t\t\t     3:   Modify Existing member Details";
                cout<<"\n";
                cout<<"\n\t\t\t     4:   Add New member Details";
                cout<<"\n";
                cout<<"\n\t\t\t     5:   Remove an member Details";
                cout<<"\n";
                cout<<"\n\t\t\t     0:   Exit     ";
                cout<<"\n";
                cout<<"\n\n\t\t\t   Please Enter Your Choice: ";

                int choice;
                cin>>choice;
                switch (choice) {
                    case 0:
                    	system("CLS");
                    	eloaddata();
                        cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t        THANK YOU  \n\n ";
                        Sleep(10);
                        return;
                    case 1:
                        listmembers();
                        break;
                    case 2:
                        showDetails();
                        break;
                    case 3:
                        editExisting();
                        break;
                    case 4:add_Newmember();
                        break;
                    case 5:
                        deletememberDetails();
                        break;
                    default:
                        cout<<"\n Sorry! Invalid Option! \n";
                        waitForEnter();
                        break;
                }
        }
    }

};

int main()
{
    member e;
    e.option();
}
