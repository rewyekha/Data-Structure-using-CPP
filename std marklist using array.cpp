#include<iostream.h>
#include<string.h>
#include<conio.h>
void create(int);
void display(int);
void cal(int);

/* 1. Struct Definition
Defines a structure student to hold student information.
name: Holds the name of the student.
res: Possibly intended for result or grade, but not used in the provided code.
sno: Student roll number.
m1, m2, m3: Marks for three subjects.
tot: Total marks.
avg: Average marks.

*/
struct student
{
    char name[10], res[5];
    int sno, m1, m2, m3, tot;
    float avg;
} s[10];

/* 2. Function Prototypes and main() Function
Main() function initiates the program.
It allows the user to choose between creating student records (CREATE) or displaying them (DISPLAY).
Uses a loop (do-while) to repeat the menu until the user chooses to exit (t != 0).
*/
void create(int);
void display(int);
void cal(int);

void main()
{
    int n, ch, t;
    clrscr();
    cout << "Enter the number of students: ";
    cin >> n;
    do
    {
        cout << "\n\t1. CREATE\n\t2. DISPLAY\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
            case 1:
                create(n);
                break;
            case 2:
                display(n);
                break;
            default:
                cout << "WRONG CHOICE";
                break;
        }
        cout << "\nDo you want to continue? Press (1/0): ";
        cin >> t;
    } while (t != 0);
}

/* 3. create(int n) Function
- create(int n) function allows the user to input details for n students.
- Prompts for student name, roll number, and marks for three subjects (m1, m2, m3). 
*/

void create(int n)
{
    cout << "\nCREATE\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Student Name: ";
        cin >> s[i].name;
        cout << "Enter Student Roll No: ";
        cin >> s[i].sno;
        cout << "Enter Mark1: ";
        cin >> s[i].m1;
        cout << "Enter Mark2: ";
        cin >> s[i].m2;
        cout << "Enter Mark3: ";
        cin >> s[i].m3;
    }
}

/* 4. display(int n) Function
- Display(int n) function displays student records.
- Calls cal(n) to calculate total marks and average for each student.
- Outputs student details including name, roll number, marks for three subjects, total marks (tot), and average marks (avg).
*/

void display(int n)
{
    clrscr();
    cal(n);
    cout << "\nDISPLAY\n";
    cout << "\nNAME\tROLLNO\tMARK1\tMARK2\tMARK3\tTOTAL\tAVERAGE\n";
    for (int i = 0; i < n; i++)
    {
        cout << s[i].name << "\t" << s[i].sno << "\t" << s[i].m1 << "\t" << s[i].m2 << "\t" << s[i].m3 << "\t" << s[i].tot << "\t" << s[i].avg << "\n";
    }
}

/* 5. cal(int n) Function
- cal(int n) function calculates total marks (tot) and average marks (avg) for each student.
- Sorts the student records based on total marks (tot) in descending order using bubble sort logic.
*/
void cal(int n)
{
    for (int i = 0; i < n; i++)
    {
        s[i].tot = s[i].m1 + s[i].m2 + s[i].m3;
        s[i].avg = s[i].tot / 3.0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (s[i].tot <= s[j + 1].tot)
            {
                char temp7[10];
                int temp1, temp2, temp3, temp4, temp5;
                float temp6;

                temp5 = s[i].tot; s[i].tot = s[j + 1].tot; s[j + 1].tot = temp5;
                strcpy(temp7, s[i].name); strcpy(s[i].name, s[j + 1].name); strcpy(s[j + 1].name, temp7);
                temp1 = s[i].sno; s[i].sno = s[j + 1].sno; s[j + 1].sno = temp1;
                temp2 = s[i].m1; s[i].m1 = s[j + 1].m1; s[j + 1].m1 = temp2;
                temp3 = s[i].m2; s[i].m2 = s[j + 1].m2; s[j + 1].m2 = temp3;
                temp4 = s[i].m3; s[i].m3 = s[j + 1].m3; s[j + 1].m3 = temp4;
                temp6 = s[i].avg; s[i].avg = s[j + 1].avg; s[j + 1].avg = temp6;
            }
        }
    }
}

/*
Notes:
Data Handling: The program uses arrays of structures (student s[10]) to store student information.
Sorting: Bubble sort is used to sort student records based on total marks (tot).
User Interaction: Inputs are taken directly from the console (cin).
Output Formatting: Displays student details in a tabular format.
*/