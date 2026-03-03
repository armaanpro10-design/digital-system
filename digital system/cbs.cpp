#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <direct.h>
#include <string.h>
#include <fstream>
#include <ctype.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

//
void gotoxy(int x, int y) {
    COORD coord;
    // Turbo C++ used 1-based coordinates, but Windows uses 0-based.
    // We subtract 1 to make your old code behave exactly the same.
    coord.X = x - 1; 
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// 2. Recreating textcolor()
void textcolor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//function for GRAPHICS slide



int gmode,gdriver,r;

struct products_record{
    float rate;
    int stock;
    int no;
    char name[20];
};

//Global variables

products_record ob1,ob2;
std::fstream pro1, pro2;

struct members_record{
    int no;
    char name[20];
    char add[50];
    long int tel;
    long int card;
    float amt;
};

members_record m1, m2;
std::fstream mem1, mem2;

//structure for store operations

struct tables{
    int no;
    int qty;
    char name[20];
    float rate;
    float total;
};

tables n1, n2;
int i = 0;
float discount = 0.0;

//Welcome screen of billing system

void welcome(){
    gdriver = DETECT; //request auto detection
    initgraph(&gdriver,&gmode,(char *)"c:\\turbo3\\bgi"); //inialising graph

    int errorcode = graphresult();
    if(errorcode != grOk)
        {    /* An error occured*/
        printf("Graphics error: %s\n");
        printf("press any key to halt: ");
        getch();
        return;
        }

    setbkcolor(7);
    setcolor(15);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR,5);
    moveto(60, 100);
    outtext((char *)"COMPUTERIZED");
    moveto(160,210);
    outtext((char *)"BILLING");
    moveto(160,320);
    outtext((char *)"SYSTEM");
    delay(1000);
    setcolor(7);
    int i = 0;
    while(i <= 2*getmaxx() - 460){
        line(0,i,i,0);
        i++;
        delay(0);
    }
    setcolor(RED);
    Beep(1000,10); //
    
    
    for(r = 150; r < 230; r+=15){
        circle(315,239,r);
        Beep(350+2*r ,10); //this line of code determines the number of beeps we get for each circle drawn.
        
        
    }
    settextstyle(8, HORIZ_DIR,1);
    setcolor(BLACK);
    Beep(500,0);
    
    moveto(245, 160);
    outtext((char *)"Copyright (C)");
    Beep(400,23);
    moveto(185,180);
    Beep(350,50);
    outtext((char *)"Arman Singh");
    moveto(240,200);
    Beep(250,40);
    outtext((char *)"62849-74534");
    moveto(210,220);
    outtext((char *)"All Right Reserved");
    Beep(400,0);
    moveto(185,240);
    outtext((char *)"Code By: Arman(ref. c++ by reeta)");
    Beep(450,20);
    moveto(185,260);
    Beep(600,30);
    outtext((char *)"Email: armana@gmail.com");
    // nosound();
    moveto(10,450);
    cin.get();
    closegraph(); // closing the graphics screen.
}

//Function for screen setting

void border(){
    system("cls");
    textcolor(15);
    for(int i = 2;i < 80; i++){
        gotoxy(i,3);
        printf("-");
        gotoxy(i,23);
        printf("-");  // drawing horizontal lines
    }
    for(i = 4; i < 23; i++){
        gotoxy(2,i);
        printf("|");
        gotoxy(79,i);
        printf("|");
    }
}
void products_enter();
//---------------------------
//Main Program
//---------------------------

int main(){
    system("cls");
    void highvideo();
    welcome();
    remove("sale.dat");
    int n; // to get user choice
    char I = 'Y';
    do{
        textcolor(2);
        border();
        textcolor(2);
        gotoxy(30,5);
        printf("Main menu");
        for(int z = 29; z <= 40; z++){
            gotoxy(z,6);
            printf("-");
        }
        gotoxy(20,7);
        printf("1.ADD NEW PRODUCTS ");
        gotoxy(20,8);
        printf("2.ADD NEW MEMEBERS ");
        gotoxy(20,9);
        printf("3.VIEW AN EXISTING PRODUCT RECORD ");
        gotoxy(20,10);
        printf("4.VIEW AN EXISTING MEMBER ");
        gotoxy(20,11);
        printf("5.BILLING ");
        gotoxy(20,12);
        printf("6.TODAY'S SALES ");
        gotoxy(21,13);
        printf("7.MODIFY PRODUCT RECORD ");
        gotoxy(20,14);
        printf("8.MODIFY MEMBER'S RECORD ");
        gotoxy(20,15);
        printf("9.INSTRUCTIONS ");
        gotoxy(20,16);
        printf("0.EXIT ");
        gotoxy(20,17);
        printf("Enter your choice: ");
        cin >> n;

        switch(n){
            case 1:
                products_enter();
                break;
            case 2:
                // members_enter();
                break;
            case 3:
                // readp();
                break;
            case 4:
                // readm();
                break;
            case 5:
                // billing();
                break;
            case 6:
               // sales();
                break;
            case 7:
               // modifyp();
                break;
            case 8:
               // modifym();
                break;
            case 9:
                //instructions();
                break;
            case 0:
                I = 'n';

        }
    }while(I != 'n');
    system("cls");
}

void products_enter(){
    int q = 0;
    char I = 'y';
    pro1.open("prducts.dat",ios::in); //opening the file stream
    pro1.seekg(0,ios::end); //determinig end of file
    q = pro1.tellg()/sizeof(products_record); // finding the size of file
    q += 1255;
    pro1.close();
    pro1.open("products.dat", ios::app);
    do{
        textcolor(LIGHTBLUE);
        system("cls");
        border();
        textcolor(LIGHTBLUE);
        gotoxy(28,2);
        printf("Entering product records ");
        gotoxy(15,6);
        printf("Name: ");
        gets(ob1.name);
        if(!ob1.name[0]){ // to undo entering name if entered
            return;
        }
        gotoxy(15,7);
        printf("Stock: ");
        cin >> ob1.name;
        gotoxy(15,8);
        printf("Rate(Rs.): ");
        cin >> ob1.no;
        ob1.no = q++;
        gotoxy(15,9);
        printf("Number: ");
        cout << ob1.no;
        pro1.write((char*)&ob1,sizeof(products_record));
        gotoxy(10,15);
        printf("do you want to enter more(Y/N): ");
        I = getch();
    }while(tolower(I) == 'y');
}

products_record products_search(int no){
    fstream pro1; // declaring stream
    pro1.open("products.dat", ios::in/* ios::nocreate */);
    while(pro1){
        pro1.read((char*)&ob1,sizeof(products_record)); // reading the file
        if(ob1.no == no){
            return ob1;
        }
    }
    pro1.close();
    ob1.no = 0;
    return ob1;
}

//---------------------------
//Function for modifying records
//---------------------------

void products_modify(int no){
    ob2.no = 0;
    pro1.open("products.dat", ios::in); //opening the file
    pro2.open("product1.dat", ios::app); //opening another file
    pro1.seekg(0,ios::beg);
    pro1.read((char*)&ob1,sizeof(products_record)); //reading from file
    while(!pro1.eof()){
        if(ob1.no != no){
            pro2.write((char*)&ob1,sizeof(products_record));
            //writing in file
        }
        else{
            ob2 = ob1;
        }
        pro1.read((char*)&ob1,sizeof(products_record));
    }
    


}