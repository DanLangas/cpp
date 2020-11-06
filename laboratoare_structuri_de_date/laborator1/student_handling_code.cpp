// StudentFileHandling.cpp : Defines the entry point for the console application.

//

 

#include <conio.h>

#include <process.h>

#include <dos.h>

#include <iostream>

#include <windows.h>

#include <stdio.h>

#include <string.h>

#include <tchar.h>

 

#pragma pack(2)

struct CStudent

{

public:

    char name[64];

    long age;

    char dept[64];

};

 

struct CStudents

{

    static const int MaxSz = 100;

    char m_fileName[1024];

    int m_nMaxStudents;

    CStudent m_studList[MaxSz];

 

    CStudents(const char *filename)

    {

        m_nMaxStudents = 0;

        strcpy(m_fileName, filename);

    }

 

    void AddRecord(const char *name, int age, const char *dept)

    {

        int pos = m_nMaxStudents;

        strcpy(m_studList[pos].name,name);

        strcpy(m_studList[pos].dept,dept);

        m_studList[pos].age = age;

        m_nMaxStudents++;

        WriteRecords();

    }

 

    void EditRecord(int pos, const char *name, int age, const char *dept)

    {

        strcpy(m_studList[pos].name,name);

        strcpy(m_studList[pos].dept,dept);

        m_studList[pos].age = age;

        WriteRecords();

    }

 

    void DeleteRecord(int pos)

    {

        m_nMaxStudents--;

 

        for(int i = pos; i < m_nMaxStudents; i++)

        {

            m_studList[i] = m_studList[i + 1];

        }

        WriteRecords();

    }

 

    int ReadRecords()

    {

        FILE *istream = fopen(m_fileName, "rb");

    

        if (istream == 0)

            return false;

 

        char buf[4096];

        int nTotalRecordsRead = 0;

 

        for(int i = 0; i < MaxSz; i++)

        {

            if(feof(istream))

                break;

            int nBytesRead = fread(buf, 1, sizeof(CStudent), istream);

            if(nBytesRead < sizeof(CStudent))

                break;

            char *p = reinterpret_cast<char*>(&m_studList[i]);

            memcpy(p, buf, sizeof(CStudent));

            nTotalRecordsRead++;

        }

       

        fclose(istream);

        m_nMaxStudents = nTotalRecordsRead;

 

        return nTotalRecordsRead;

    }

 

    int WriteRecords()

    {

        FILE *ostream = fopen(m_fileName, "wb");

 

        if (ostream == 0)

            return false;

 

        int nTotalRecordsWritten = 0;

        char buf[4096];

        for(int i = 0; i < m_nMaxStudents; i++)

        {

            fwrite((char*)&m_studList[i], 1, sizeof(CStudent), ostream);

            nTotalRecordsWritten++;

        }

 

        fclose(ostream);

 

        return nTotalRecordsWritten;

    }

};

 

CStudents theStudents("c:\\students.bin");

 

void gotoxy(int x, int y)

{

    COORD ord;

    ord.X = x;

    ord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ord);

}

 

 

int DisplayMainMenu()

{

    ::system("cls");

   

    gotoxy(10,4);

    std::cout << "Welcome to Student Database Application";

 

    gotoxy(10,5);

    std::cout << "___________________________________________";

 

    gotoxy(10,6);

    std::cout << "1. Add Student Record";

 

    gotoxy(10,7);

    std::cout << "2. Edit Student Record";

 

    gotoxy(10,8);

    std::cout << "3. View Student Record";

 

    gotoxy(10,9);

    std::cout << "4. Delete Student Record";

 

    gotoxy(10,10);

    std::cout << "5. Exit";

 

    gotoxy(10,11);

    std::cout << "___________________________________________";

 

    gotoxy(10,13);

    std::cout << "Enter your Selection: ";

    int m = -1;

    std::cin >> m;

 

    return m;

}

 

void ViewRecords()

{

    theStudents.ReadRecords();

   

    ::system("cls");

       

    gotoxy(10,4);

    std::cout << "Welcome to Student Database Application";

 

    gotoxy(10,5);

    std::cout << "___________________________________________";

 

    gotoxy(10,6);

    std::cout << "SNo Student Name       Age    Department   ";

 

    gotoxy(10,7);

    std::cout << "___________________________________________";

 

    int pos = 8;

    // Enable Paging

    for(int i = 0; i < theStudents.m_nMaxStudents; i++)

    {

        gotoxy(10,pos);

        std::cout << i + 1;

        gotoxy(14,pos);

        std::cout << theStudents.m_studList[i].name;

        gotoxy(33,pos);

        std::cout << theStudents.m_studList[i].age;

        gotoxy(42,pos);

        std::cout << theStudents.m_studList[i].dept;

        pos++;

    }

    gotoxy(10,pos++);

    std::cout << "___________________________________________";

    pos++;

    gotoxy(10,pos++);

}

 

 

void InputRecords()

{

    while(1)

    {

        ::system("cls");

       

        gotoxy(10,4);

        std::cout << "Welcome to Student Database Application";

 

        gotoxy(10,5);

        std::cout << "___________________________________________";

 

        gotoxy(10,6);

        std::cout << "Student Name: ";

 

        gotoxy(10,7);

        std::cout << "Age: ";

 

        gotoxy(10,8);

        std::cout << "Departement: ";

 

        gotoxy(10,9);

        std::cout << "___________________________________________";

 

        gotoxy(23,6);

        char name[64];

        std::cin >> name;

 

        gotoxy(17,7);

        int age;

        std::cin >> age;

 

        gotoxy(23,8);

        char dept[64];

        std::cin >> dept;

 

        theStudents.AddRecord(name, age, dept);

 

        gotoxy(10,11);

        std::cout << "Do you want to add another record (Y/N)? ";

        char ch = getch();

 

        if(ch == 'Y' || ch == 'y')

            continue;

        else

            break;

    }

}

 

 

void EditRecords()

{

    ViewRecords();

    std::cout << "Enter the serial number you want to edit: ";

    int m;

    std::cin >> m;

 

    if(m >= 1 && m <= theStudents.m_nMaxStudents)

    {

        ::system("cls");

        gotoxy(10,4);

        std::cout << "Welcome to Student Database Application";

 

        gotoxy(10,5);

        std::cout << "___________________________________________";

 

        gotoxy(10,6);

        std::cout << "Student Name: ";

 

        gotoxy(10,7);

        std::cout << "Age: ";

 

        gotoxy(10,8);

        std::cout << "Departement: ";

 

        gotoxy(10,9);

        std::cout << "___________________________________________";

 

        gotoxy(23,6);

        char name[64];

        std::cin >> name;

 

        gotoxy(17,7);

        int age;

        std::cin >> age;

 

        gotoxy(23,8);

        char dept[64];

        std::cin >> dept;

 

        theStudents.EditRecord(m - 1, name, age, dept);       

        gotoxy(10,12);

        std::cout << "Record updated. Press any key to return to Main Menu";

        char ch = getch();

    }

    else

    {

        gotoxy(10,12);

        std::cout << "Invalid Entry. Press any key to return to Main Menu";

        char ch = getch();

    }

 

}

 

void DeleteRecords()

{

    ViewRecords();

    std::cout << "Enter the serial number you want to delete: ";

    int m;

    std::cin >> m;

    if(m >= 1 && m <= theStudents.m_nMaxStudents)

    {

        theStudents.DeleteRecord(m - 1);

        std::cout << "          Record deleted. Press any key to return to Main Menu";

        char ch = getch();

    }

    else

    {

        std::cout << "          Invalid Entry. Press any key to return to Main Menu";

        char ch = getch();

    }

}

 

int _tmain(int argc, _TCHAR* argv[])

{

    theStudents.ReadRecords();

    while(1)

    {

        int selection = DisplayMainMenu();

 

        switch(selection)

        {

        case 1:

            InputRecords();

            break;

        case 2:

            EditRecords();

            break;

        case 3:

            {

            ViewRecords();

            std::cout << "Press any key to return to Main Manu: ";

            char ch = getch();

            }

            break;

        case 4:

            DeleteRecords();

            break;

 

        case 5:

        default:

            return 0;

        };

    }

      return 0;

}
