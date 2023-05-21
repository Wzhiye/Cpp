#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

//struct for contact
struct person
{
    string m_name; //name
    int m_sex; // gender
    int m_age;
    string m_phone;
    string m_addr;
};

//struct for address boox
struct addressBooks
{
    //saved contact struct
    struct person personArray[MAX];

    //the nummer of contact
    int m_size;
};

//display menu
void showMenu()
{   
    cout << "********************" <<endl;
    cout << "1.Add contact" << endl;
    cout << "2.Display contact" << endl;
    cout << "3.Delete contact" << endl;
    cout << "4.Search contact" << endl;
    cout << "5.Edit contact" << endl;
    cout << "6.Delete All" <<endl;
    cout << "0.Exit" << endl;
    cout << "********************" <<endl;
}

//1.add contact
void addPerson(addressBooks * abs)
{
    //if book is full, no more adding
    if (abs->m_size == MAX)
    {
        cout << "Address book is full!" << endl;
        return;
    }
    else
    {
        //add detail
        string name;
        cout << "Please input the name: " << endl;
        cin >> name;
        abs->personArray[abs->m_size].m_name = name;

        int sex = 0;
        cout << "Please input the gender: " << endl;
        cout << "1-male 2-female" << endl;
        while(true)
        {
            cin >> sex;
            if (sex == 1 || sex ==2)
            {
                abs->personArray[abs->m_size].m_sex = sex;
                break;
            }
            cout << "Please check your input, input again: " << endl;
        }
        
        cout << "Please input the age: " << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_size].m_age = age;

        cout << "Please input phone number: " << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_size].m_phone = phone;

        cout << "Please input the address: " << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_size].m_addr = address;

        //update the nummer of contact
        abs->m_size++;
        cout << "Contact added!" << endl;
        system("read -p 'Press Enter to continue...' var");//对应windows系统里的system("pause")
        system("clear"); //对应windows系统里的system("cls")
    }
}

//2.display contact
void showPerson(addressBooks * abs)
{
    //check the number of book
    if (abs->m_size == 0)
    {
        cout << "Address book is empty!" <<endl;

    }
    else
    {
        for (int i=0; i < abs->m_size; i++)
        {
            cout << "name: " << abs->personArray[i].m_name << "\t";
            cout << "gender: " << (abs->personArray[i].m_sex == 1 ?"male":"female")<< "\t";
            cout << "age: " << abs->personArray[i].m_age << "\t";
            cout << "phone: " << abs->personArray[i].m_phone << "\t";
            cout << "adress: " << abs->personArray[i].m_addr << endl;
        }
    }
    system("read -p 'Press Enter to continue...' var");//对应windows系统里的system("pause")
    system("clear"); //对应windows系统里的system("cls")
}

//check if given contact is in the book, if not return -1
//parameter1 addressBook parammeter2 compareName
int isExist(addressBooks * abs, string name)
{
    for(int i=0; i<abs->m_size; i++ )
    {
        if (abs->personArray[i].m_name == name)
        {
            return i;
        }
    }
    return -1;
}


//delete contact
void deletePerson(addressBooks * abs)
{
    cout << "Please input the name: " <<endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);

    if  (ret != -1)
    {
        for(int i=ret; i < abs->m_size; i++)
        {
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_size--;
        cout << "Contact is deleted!" << endl;
        
    }
    else
    {
        cout << "Contact is not found!" << endl;
    }
    system("read -p 'Press Enter to continue...' var");//对应windows系统里的system("pause")
    system("clear"); //对应windows系统里的system("cls")
}

//search contact
void findPerson(addressBooks * abs)
{
    cout << "Please input the name: " << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name); 
    if (ret != -1)
    {
        cout << "name: " << abs->personArray[ret].m_name << "\t";
        cout << "gender: " << (abs->personArray[ret].m_sex == 1?"male":"female") << "\t";
        cout << "age: " << abs->personArray[ret].m_age << "\t";
        cout << "phone: " << abs->personArray[ret].m_phone << "\t";
        cout << "address: " << abs->personArray[ret].m_addr << endl;

    }
    else
    {
        cout << "Contact not found!" << endl;
    }
    system("read -p 'Press Enter to continue...' var");//对应windows系统里的system("pause")
    system("clear"); //对应windows系统里的system("cls")
}

//modify contact info
void modifyPerson(addressBooks * abs)
{
    cout << "Please input the name: " << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);

    if (ret != -1)
    {
        string name;
        cout << "Please input the name: " <<endl;
        cin >> name;
        abs->personArray[ret].m_name = name;

        cout << "Please input the gender: " <<endl;
        cout << "1-male 2-female" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex ==2)
            {
                abs->personArray[ret].m_sex = sex;
                break;
            }
            cout << "Error, check the input!" <<endl;
        }

        cout << "Please input the age" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[ret].m_age = age;

        cout << "Please input the phone" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_phone = phone;

        cout << "Please input the address" << endl;
        string address;
        cin >> address;
        abs->personArray[ret].m_addr = address;

        cout << "Contact is changed!" <<endl;
        
    } 
    else
    {
        cout << "Contact not found!" << endl;
    }
    system("read -p 'Press Enter to continue...' var");//对应windows系统里的system("pause")
    system("clear"); //对应windows系统里的system("cls")
}

//clean up address book
void cleanPerson(addressBooks * abs)
{
    abs->m_size = 0;
    cout << "Address bood is cleaned" << endl;
    system("read -p 'Press Enter to continue...' var");//对应windows系统里的system("pause")
    system("clear"); //对应windows系统里的system("cls")
}

int main()
{

    addressBooks abs;
    abs.m_size = 0;

    int select =0;

    while(true)
    {
        //Menu display
        showMenu();
        cin >> select;
        switch (select)
        {
            case 1: //Add contact
                addPerson(&abs); //函数无法传递实参，所以这里需要用地址作为参数
                break;
            case 2: //Display contact
                showPerson(&abs);
                break;
            case 3: //Delete contact            
                deletePerson(&abs);
                break;               
            case 4: //Search contact
                findPerson(&abs);
                break;
            case 5: //Edit contact
                modifyPerson(&abs);
                break;
            case 6: //Delete All
                cleanPerson(&abs);
                break;
            case 0: //Exit
                cout << "Good Bye!" << endl;
                system("read -p 'Press Enter to continue...' var");
                return 0;
                break;

        }
    }
    

}