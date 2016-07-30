#include "Pich.h"

//delay(unsigned int mseconds);

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int getpassword(char *password)
{
    char txt;
    int i=0,n;
    char pass[10];

    while(1)
        {
            txt=getch();
            if (txt==13)
            {
                break;
            }
            if (txt==8)
            {
                if (i>0)
                {
                    i--;
                    printf("%s", "\b \b");
                }
                continue;
            }
            if (txt==27)
            {
                return 1;
            }
            pass[i++]=txt;
            n=i;
            printf("%c", 254);
        }
        pass[i]='\0';
        for(i=0;i<n;i++)
            {
                *password=pass[i];
                password++;
            }

    return 0;
}
/*
int numchoice()
{
    int ch;
    gotoxy(1,29);
    printf("--> ");
    getnum(&ch);
    if(ch==27)return -1;
    return ch;
}*/

int gettxt(char *t)
{
    char txt;
    int i=0,n;
    char pass[10];

    while(1)
        {
            txt=getch();
            if (txt==13)
            {
                break;
            }
            if (txt==8)
            {
                if (i>0)
                {
                    i--;
                    printf("%s", "\b \b");
                }
                continue;
            }
            if (txt==27)
            {
                return 1;
            }

            pass[i++]=txt;
            n=i;
            printf("%c", txt);
        }
        pass[i]='\0';
        for(i=0;i<n;i++)
            {
                *t=pass[i];
                t++;
            }
    return 0;
}

int getnum(int *t)
{
    char txt;
    int i=0,n;
    char pass[10];

    while(1)
        {
            txt=getch();
            if (txt==13)
            {
                break;
            }
            if (txt==8)
            {
                if (i>0)
                {
                    i--;
                    printf("%s", "\b \b");
                }
                continue;
            }
            if (txt==27)
            {
                return 1;
            }

            pass[i++]=txt;
            n=i;
            printf("%c", txt);
        }
        pass[i]='\0';
        /*for(i=0;i<n;i++)
            {
                *t=pass[i];
                t++;
            }*/
        *t=atoi(pass);
    return 0;
}

int highlight_option(int n , char menu[][20])
{
    int i,st=0;
    int ch;
    //char menu[4][10] = {"Input", "Output", "Delete", "Update"};
    do{
        clrscr();
        for (i = 0; i < n; i++) 
        {
            if (i == st) 
            {
                textbackground(WHITE);
                textcolor(BLACK);
                gotoxy(50,i+11);
                cprintf("%s", menu[i]);
                textbackground(BLACK);
                textcolor(WHITE);
            } 
            else 
            {
                gotoxy(50,i+11);
                printf("%s", menu[i]);
            }
        }
        ch=getch();
        if(ch==72 && st>0)st--;
        if(ch==80 && st<n-1)st++;
        if(ch==13) return st;
    }while(ch!=27);
    return 0;
}
        