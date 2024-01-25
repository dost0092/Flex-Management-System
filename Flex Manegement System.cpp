//libraries

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<string>
#include<fstream>
#include <iomanip>
#include<cstdio>
#include <Windows.h>

using namespace std;
using namespace sf;

//Base Class Admin
class Admin {

protected:

	string user_name;
	string password;
	string T_First_name;
	string T_Last_name;
	int T_Department;
	int T_std_number;

	string S_First_name;
	string S_Last_name;
	int S_Department;
	int S_std_number;
	string Blood_Group;
	string Fee_status;
	string Marks;

	string T_user_name;
	string T_password;
	string Reg_date;
	string Gender;
	string Cont_no;
	string qualification;
	string address;

	ofstream write_file;
	ifstream read_file;

	//constructor
	Admin()
	{
		user_name = "";
		password = "";
		T_First_name = "";
		T_Last_name = "";

		T_Department = 0;
		T_std_number = 1000;
		S_std_number = 1000;

		string T_user_name;
		string T_password = "";
		string Reg_date = "";
		string Gender = "";
		string Cont_no = "";
		string qualification = "";
		string address = "";

		string user_name = "";
		string password = "";
		string S_First_name = "";
		string S_Last_name = "";
		int S_Department = 0;
		int S_std_number = 0;
		string Blood_Group = "";
		string Fee_status = "";
		string Marks = "";
	}


public:

	//virtual functions
	virtual void sign_in() {}
	virtual void Add_new_Teacher() {}
	virtual void Add_new_Student() {}
	virtual void Edit_Teacher() {}
	virtual void Edit_Student() {}
	virtual void View_all_Student() {}
	virtual void View_all_Teacher() {}
	virtual void Time_Table() {}
	virtual void T_Marks() {}
	virtual void Student_SignIn() {}

};


//Derived class Sign In 
class Sign_in :public Admin {

public:

	//overriding
	void sign_in()override
	{
		string f_user_name;
		string f_password;

		read_file.open("Admin.txt");

		while (1)
		{
			cout << "\n\n\n\t\t\t\tEnter User_name: ";
			cin >> user_name;
			cout << "\n\n\t\t\t\tEnter Password: ";
			cin >> password;

			read_file >> f_user_name;
			read_file >> f_password;


			if (f_user_name == user_name && f_password == password)
			{
				break;
			}

			else
			{
				cout << "\n\n\t\t\t\tx----(You Have Entered Wrong ID Password)----x \n\n\t\t\t\tPlease Try Again" << endl;

			}
		}
		read_file.close();

	}
};

//Derived class Add Teacher
class Add_Teacher :public Admin {

public:

	//overriding
	void Add_new_Teacher()override
	{
		write_file.open("Teacher.txt",ios::app);

		if (!write_file)
		{
			cout << "Fil Not Created" << endl;
		}

		else
		{

			cout << "\n\t1) Add_Teacher Portal" << endl;
			cout << "\nEnter Teacher First Name: ";

			cin >> T_First_name;
			cout << "Enter Teacher Last Name: ";
			cin >> T_Last_name;

			cout << "\n==========================  Enter Department  ===============================" << endl;
			cout << "==============================\n";

			cout << " #1: Computer Science        # \n";
			cout << " #2: Electrical Engineering  # \n";
			cout << " #3: Software Engineering    # \n";
			cout << " #4: Business                #\n";
			cout << " #5: Social Sciences         #\n";
			cout << "==============================\n";
			cout << "You Choose: ";
			cin >> T_Department;

			cout << "Enter Registration Date: ";
			cin >> Reg_date;

			cout << "Your ID is: ";
			if (T_Department == 1)
			{
				cout << "CS-" << T_std_number + 1 << endl;
			}

			else if (T_Department = 2)
			{
				cout << "EE-" << T_std_number + 1 << endl;
			}

			else if (T_Department = 3)
			{
				cout << "SE-" << T_std_number + 1 << endl;
			}

			else if (T_Department = 4)
			{
				cout << "B-" << T_std_number + 1 << endl;
			}

			else if (T_Department = 5)
			{
				cout << "SS-" << T_std_number + 1 << endl;
			}

			cout << "\nEnter Teacher User Name: ";
			cin >> T_user_name;
			cout << "Enter Password: ";
			cin >> T_password;

			cout << "Enter Gender: ";
			cin >> Gender;
			cout << "Enter Contact Number: ";
			cin >> Cont_no;
			cout << "Enter Qualification: ";
			cin >> qualification;
			cout << "Enter Address: ";
			cin >> address;

			write_file << T_First_name << endl;

			write_file << T_Last_name << endl;

			write_file << Reg_date << endl;


			if (T_Department == 1)
			{
				write_file << "CS-" << T_std_number + 1 << endl;
			}

			else if (T_Department = 2)
			{
				write_file << "EE-" << T_std_number + 1 << endl;
			}

			else if (T_Department = 3)
			{
				write_file << "SE-" << T_std_number + 1 << endl;
			}

			else if (T_Department = 4)
			{
				write_file << "B-" << T_std_number + 1 << endl;
			}

			else if (T_Department = 5)
			{
				write_file << "SS-" << T_std_number + 1 << endl;
			}


			write_file << T_user_name << endl;

			write_file << T_password << endl;


			write_file << Gender << endl;

			write_file << Cont_no << endl;

			write_file << qualification << endl;

			write_file << address << endl;

		}
		write_file.close();
	}


};

//Derived class Add student
class Add_Student :public Admin {

public:

	//overriding
	void Add_new_Student()override
	{
		write_file.open("student.txt",ios::app);


		if (!write_file)
		{
			cout << "Fil Not Created" << endl;
		}

		else
		{
			cout << "\n\t2)Add_Student Portal " << endl;
			cout << "\nEnter Student First Name: ";
			cin >> S_First_name;
			cout << "Enter Student Last Name: ";
			cin >> S_Last_name;

			cout << "\n==========================  Enter Department  ===============================" << endl;
			cout << "==============================\n";

			cout << " #1: Computer Science        # \n";
			cout << " #2: Electrical Engineering  # \n";
			cout << " #3: Software Engineering    # \n";
			cout << " #4: Business                #\n";
			cout << " #5: Social Sciences         #\n";
			cout << "==============================\n";
			cout << "Enter Your Choose: ";
			cin >> S_Department;


			cout << "Your ID is: ";
			switch (S_Department)
			{
			case 1:
				cout << "CS-" << S_std_number + 1 << endl;
				break;
			case 2:
				cout << "EE-" << S_std_number + 1 << endl;
				break;
			case 3:
				cout << "SE-" << S_std_number + 1 << endl;
				break;
			case 4:
				cout << "B-" << S_std_number + 1 << endl;
				break;
			case 5:
				cout << "SS-" << S_std_number + 1 << endl;
				break;

			default:
				cout << "Invalid input\n";
				break;
			}


			cout << "Enter Gender: ";
			cin >> Gender;
			cout << "Enter Contact Number: ";
			cin >> Cont_no;
			cout << "Enter Blood Group: ";
			cin >> Blood_Group;
			cout << "Enter Address: ";
			cin >> address;
			cout << "Enter Fee Status: ";
			cin >> Fee_status;
			cout << "Enter Qualification: ";
			cin >> qualification;
			cout << "Enter Marks: ";
			cin >> Marks;


			write_file << S_First_name << endl;

			write_file << S_Last_name << endl;


			if (S_Department == 1)
			{
				write_file << "CS-" << S_std_number + 1 << endl;
			}

			else if (S_Department = 2)
			{
				write_file << "EE-" << S_std_number + 1 << endl;
			}

			else if (S_Department = 3)
			{
				write_file << "SE-" << S_std_number + 1 << endl;
			}

			else if (S_Department = 4)
			{
				write_file << "B-" << S_std_number + 1 << endl;
			}

			else if (S_Department = 5)
			{
				write_file << "SS-" << S_std_number + 1 << endl;
			}

			write_file << Gender << endl;

			write_file << Cont_no << endl;

			write_file << Blood_Group << endl;

			write_file << address << endl;

			write_file << Fee_status << endl;

			write_file << qualification << endl;

			write_file << address << endl;

			write_file << Marks << endl;

			write_file.close();

		}
	}

};

//Derived class Upadate Teacher 
class Edit_Teacher_Detail :public Admin{

public:

	//overriding
	void Edit_Teacher()override
	{
		cout << "\n\t3)Edit Teacher Portal" << endl;
		string Edit_withpass;
		cout << "\nEnter the password of the Person: ";
		cin >> Edit_withpass;

		fstream file2, file3;


		file3.open("Teacher.txt", ios::in);
		if (!file3)
		{
			cout << "File Not found\n";
			file3.close();
			file2.close();

		}

		file2.open("Teachernew.txt", ios::out | ios::app);

		while (!file3.eof())
		{

			if (Edit_withpass != T_password)
			{
				cout << "\nEnter new record\n";


				cout << "\nEnter Address: ";
				cin >> address;
				cout << "Enter Contact Number: ";
				cin >> Cont_no;
				cout << "Enter your Qualification: ";
				cin >> qualification;
				cout << "\nRecord is updated\n";

				file2 << address << endl;
				file2 << Cont_no << endl;
				file2 << qualification << endl;

			}
			else {

				file2 << address << "\n" << Cont_no << " \n" << qualification << endl;
			}

			file3 >> address >> Cont_no >> qualification;

			break;
		}

		file2.close();
		file3.close();

		remove("Teacher.txt");
		rename("Teachernew.txt", "Teacher.txt");

	}

};

//Derived class Update Student
class Edit_Student_Detail : public Admin {

public:

	//overriding
	void Edit_Student()override
	{
		cout << "\n========================   Edit Student Portal   ================" << endl;
		string Edit_std_name;
		cout << "\nEnter Name of a Person: ";
		cin >> Edit_std_name;

		fstream file, file1;


		file1.open("student.txt", ios::in);
		if (!file1)
		{
			cout << "File Not found\n";
			file1.close();
			file.close();

		}

		file.open("studentnew.txt", ios::out | ios::app);

		while (!file1.eof())
		{
			if (Edit_std_name == S_First_name)
			{
				cout << "\nEnter New Record\n";

				cout << "\nEnter First Name: ";
				cin >> S_First_name;
				cout << "Enter Second Name: ";
				cin >> S_Last_name;
				cout << "Enter Fee Status: ";
				cin >> Fee_status;
				cout << "Enter Address: ";
				cin >> address;
				cout << "Enter Contact Number: ";
				cin >> Cont_no;
				cout << " +------------------------------+\n";
				cout << "\n  | Your Record is updated|\n";
				cout << " +------------------------------+\n";
				file << S_First_name << endl;
				file << S_Last_name << endl;
				file << Fee_status << endl;
				file << address << endl;
				file << Cont_no << endl;

			}

			else
			{

				file << S_First_name << "\n" << S_Last_name << "\n" << Fee_status << "\n" << address << "\n" << Cont_no << endl;
			}

			file1 >> S_First_name >> S_Last_name >> Fee_status >> address >> Cont_no;

		}

		file.close();
		file1.close();

		remove("student.txt");
		rename("studentnew.txt", "student.txt");

	}

};

//Derived class  Display Student 
class View_Student :public Admin {

public:

	//overriding
	void View_all_Student()
	{
		fstream std_file;
		string arr[12];
		std_file.open("student.txt", ios::in);

		for (int i = 0; i < 12; i++)
		{
			std_file >> arr[i];
		}

		cout << "\n===========================  STUDENT RECORD  =============================\n";
		cout << endl;

		cout << "  \t\t          +-------------+          \n";
		for (int i = 0; i < 11; i++)
		{
			cout << "\t\t\t  |  " << arr[i] << "  \t|" << endl;

			cout << "   \t\t          +-------------+          \n";
		}

		std_file.close();
	}

};

// Derived class Display Teacher
class View_teacher :public Admin {

public:

	//override
	void View_all_Teacher()override
	{
		fstream Teacher_file;
		Teacher_file.open("teacher.txt", ios::in);

		string arr[12];
		for (int i = 0; i < 12; i++)
		{
			Teacher_file >> arr[i];
		}


		cout << "\n===========================  TEACHER RECORD  =============================\n";

		cout << endl;

		cout << "  \t\t          +-------------+          \n";

		for (int i = 0; i < 12; i++)
		{
			cout << "\t\t\t  |  " << arr[i] << "  \t|" << endl;

			cout << "   \t\t          +-------------+          \n";
		}

		Teacher_file.close();
	}

};

// Display Sign In Function
void Display_signIn()
{
	system("cls");
	cout << "\n\n\n";
	cout << setw(32) << setfill(' ') << "";
	cout << "+";

	for (int i = 0; i < 47; i++) {

		cout << "-";
		Sleep(15);
	}

	cout << "+";
	cout << "\n\t\t\t\t|          Welcome To Admin Portal\t\t|" << endl;
	Sleep(15);
	cout << "\t\t\t\t| \t\t\t\t\t\t|" << endl;
	Sleep(15);
	cout << "\t\t\t\t| \t\t  SIGN IN\t\t\t|" << endl;
	Sleep(15);
	cout << "\t\t\t\t| \t\t\t\t\t\t|" << endl;
	Sleep(15);
	cout << "\t\t\t\t+-----------------------------------------------+" << endl;

}

// Display Admin Portal Function
void Display_Admin()
{
	cout << "\n\n\n";
	cout << setw(32) << setfill(' ') << "";
	cout << "+";

	for (int i = 0; i < 47; i++) {

		cout << "-";
		Sleep(15);
	}

	cout << "+";
	cout << "\n\t\t\t\t|\tPRESS --> '1' To Add New Teacher\t |" << endl;
	Sleep(15);
	cout << "\t\t\t\t|\tPRESS-- > '2' To Add New Student\t |" << endl;
	Sleep(15);
	cout << "\t\t\t\t|\tPress-- > '3' To Edit Teacher\t\t |" << endl;
	Sleep(15);
	cout << "\t\t\t\t|\tPRESS-- > '4' To Edit Student\t\t |" << endl;
	Sleep(15);
	cout << "\t\t\t\t|\tPRESS-- > '5' To View Student\t\t |" << endl;
	Sleep(15);
	cout << "\t\t\t\t|\tPRESS-- > '6' To View Teacher\t\t |" << endl;
	Sleep(15);
	cout << "\t\t\t\t|\tPRESS-- > '7' To EXIT\t\t\t |" << endl;
	Sleep(15);
	cout << "\t\t\t\t+------------------------------------------------+" << endl;

}

//Base class Teacher
class Teacher {

protected:

	string t_name;
	string t_password;
	fstream data_out;
	string name;
	string password;

public:
	//constructor
	Teacher()
	{
		t_name = "";
		t_password = "";
		name = "";
		password = "";
	}

	virtual void T_Sign_in() {}
	virtual void T_Time_table() {}

	virtual void Attendance() {}
	virtual void Grade() {}
	virtual void T_Marks() {}

};

//Base class Teacher SignIN
class Teacher_Sign :public Teacher {

public:

	//overriding
	void T_Sign_in()override
	{
		data_out.open("TeacherSignIn.txt");

		while (1)
		{
			cout << "\n\n\n\t\t\t\tEnter User_name: ";
			cin >> name;
			cout << "\n\n\t\t\t\tEnter Password: ";
			cin >> password;

			data_out >> t_name;
			data_out >> t_password;

			if (t_name == name && t_password == password)
			{
				break;
			}

			else
			{
				cout << "\n\n\t\t\t\tx----(You Have Entered Wrong ID Password)----x \n\n\t\t\t\tPlease Try Again" << endl;
				cout << endl;
			
			}

		}
	}
};

//Base class Teacher Time Table
class Teacher_TimeTable :public Teacher {

public:

	//overriding
    void T_Time_table()override
	{
		cout << "\n\t1) Teacher TimeTable " << endl;
		cout << "\n\t+==+======================================================================================================+" << endl;
		cout << "\t|  |08:45 | 09:15 | 09:45 | 10:15 | 10:45 | 11:15 | 11:45 | 12:15 | 12:45 | 01:10 | 01:45 | 02:15 | 02:45 |" << endl;
		cout << "\t|  |09:15 | 09:45 | 10:10 | 10:45 | 11:15 | 11:40 | 12:15 | 12:45 | 01:10 | 01:45 | 02:15 | 02:45 | 03:15 |" << endl;
		cout << "\t==========================================================================================================|" << endl;
		cout << "\t|MO|      |        |      |        Room-6         |       |       |       |        Room-11        |       |" << endl;
		cout << "\t|---------------------------------------------------------------------------------------------------------|" << endl;
		cout << "\t|TU|       Room-2         |       |       |       |       |       |       |        |      |       |       |" << endl;
		cout << "\t|---------------------------------------------------------------------------------------------------------|" << endl;
		cout << "\t|WE|      |        |      |       |       |            LAB-4              |        |      |       |       |" << endl;
		cout << "\t|---------------------------------------------------------------------------------------------------------|" << endl;
		cout << "\t|TH|      |        |      |        Room-4         |       |       |       |        |      |       |       |" << endl;
		cout << "\t|---------------------------------------------------------------------------------------------------------|" << endl;
		cout << "\t|FR|      |             LAB-7             |       |       |       |       |        |       Room-5         |" << endl;
		cout << "\t+==+======================================================================================================+" << endl;

		system("pause");
	}

};

//Base class Assign Marks
class Assign_Marks : public Teacher {

public:

	//overiding
	void T_Marks()override
	{
		cout << "\n\t2)	Assign Marks " << endl;

		int marks[2];
		string name[2];
		string section[2];
		int roll_no[2];

		cout << "\n\t------>>>ENTER MARKS OF THESE STUDENTS<<<------" << endl;

		for (int i = 0; i < 2; i++)
		{
			cout << "\nEnter Name of " << i + 1 << " Student: ";
			cin >> name[i];
			cout << "Enter Section of " << i + 1 << " Student: ";
			cin >> section[i];
			cout << "Enter Roll Number of " << i + 1 << " Student: ";
			cin >> roll_no[i];
			cout << "Enter Marks of " << i + 1 << " Student: ";
			cin >> marks[i];
		}


		data_out.open("Marks.txt", ios::out|ios::app);

		if (!data_out)
		{
			cout << "File not Created" << endl;
			data_out.close();
		}
		
		system("cls");

		cout << "\n\tSTUDENTS MARKS UPLOADED" << endl;

		cout << "\n\t+------------------------------------------------------------------------+" << endl;
		cout << "\t|\t" << "Name         " << " Section     " << "      Roll No " << "         Marks       " << endl;

		data_out << "\n\tSTUDENTS MARKS UPLOADED" << endl;

		data_out << "\n\t+------------------------------------------------------------------------+" << endl;
		data_out << "\t|\t" << "Name         " << " Section     " << "      Roll No " << "         Marks       " << endl;

		for (int i = 0; i < 2; i++)
		{
			cout << "\t|\t" << name[i] << "\t|" << "\t" << section[i] << " \t  |   " << roll_no[i] << "   \t" << " |\t" << marks[i] << "\t\t|\n";
			data_out << "\t|\t" << name[i] << "\t|" << "\t" << section[i] << " \t  |   " << roll_no[i] << "   \t" << " |\t" << marks[i] << "\t\t|\n";

		}

		cout << "\n\t+------------------------------------------------------------------------+" << endl;

		data_out << "\n\t+------------------------------------------------------------------------+" << endl;

		data_out.close();
		system("pause");
	}

};

//Derived Class Marking Attendance
class Marking_Attendance :public Teacher {

public:

	//overriding
	void Attendance()override
	{
		cout << "\n\t3) Mark Attendance" << endl;

		string attendace[2];
		string name[2];
		string section[2];
		int roll_no[2];

		data_out.open("Attendance.txt", ios::out);

		if (!data_out)
		{
			cout << "File not Created" << endl;
			data_out.close();
		}

		cout << "\n\t------>>>ENTER ATTENDANCE OF THESE STUDENTS<<<------" << endl;

		for (int i = 0; i < 2; i++)
		{
			cout << "\nEnter Name of " << i + 1 << " Student: ";
			cin >> name[i];
			cout << "Enter Section of " << i + 1 << " Student: ";
			cin >> section[i];
			cout << "Enter Roll Number of " << i + 1 << " Student: ";
			cin >> roll_no[i];
			cout << "Enter Attendance of " << i + 1 << " Student: ";
			cin >> attendace[i];
		}

		cout << "\n\tSTUDENTS ATTENDANCE UPLOADED" << endl;
		cout << "\n\t+------------------------------------------------------------------------+" << endl;
		cout << "\t|\t" << "Name         " << " Section     " << "      Roll No " << "         Attendace       " << endl;

		data_out << "\n\tSTUDENTS ATTENDANCE UPLOADED" << endl;
		data_out << "\n\t+------------------------------------------------------------------------+" << endl;
		data_out << "\t|\t" << "Name         " << " Section     " << "      Roll No " << "         Attendace       " << endl;

		for (int i = 0; i < 2; i++)
		{
			cout << "\t|\t" << name[i] << "\t|" << "\t" << section[i] << " \t  |   " << roll_no[i] << "   \t" << " |\t" << attendace[i] << "\t\t|\n";
			data_out << "\t|\t" << name[i] << "\t|" << "\t" << section[i] << " \t  |   " << roll_no[i] << "   \t" << " |\t" << attendace[i] << "\t\t|\n";

		}

		cout << "\n\t+------------------------------------------------------------------------+" << endl;
		data_out << "\n\t+------------------------------------------------------------------------+" << endl;

		data_out.close();
		system("pause");
	}

};

//Derived class Assign Grade
class Assign_Grades :public Teacher {

public:

	//overriding
	void Grade()override
	{

		cout << "\n\t4) Assign Grade" << endl;
		string grade[2];
		string name[2];
		string section[2];
		int roll_no[2];

		cout << "\n\t------>>>ENTER GRADE OF THESE STUDENTS<<<------" << endl;

		for (int i = 0; i < 2; i++)
		{
			cout << "\nEnter Name of " << i + 1 << " Student: ";
			cin >> name[i];
			cout << "Enter Section of " << i + 1 << " Student: ";
			cin >> section[i];
			cout << "Enter Roll Number of " << i + 1 << " Student: ";
			cin >> roll_no[i];
			cout << "Enter Grade of " << i + 1 << " Student: ";
			cin >> grade[i];
		}

		data_out.open("Grade.txt", ios::out);

		if (!data_out)
		{
			cout << "File not Created" << endl;
			data_out.close();
		}

		system("cls");

		cout << "\n\tSTUDENTS GRADES UPLOADED" << endl;
		cout << "\n\t+------------------------------------------------------------------------+" << endl;
		cout << "\t|\t" << "Name         " << " Section     " << "      Roll No " << "         Grade       " << endl;

		data_out << "\n\tSTUDENTS GRADES UPLOADED" << endl;
		data_out << "\n\t+------------------------------------------------------------------------+" << endl;
		data_out << "\t|\t" << "Name         " << " Section     " << "      Roll No " << "         Grade       " << endl;

		for (int i = 0; i < 2; i++)
		{
			cout << "\t|\t" << name[i] << "\t|" << "\t" << section[i] << " \t  |   " << roll_no[i] << "   \t" << " |\t" << grade[i] << "\t\t|\n";
			data_out << "\t|\t" << name[i] << "\t|" << "\t" << section[i] << " \t  |   " << roll_no[i] << "   \t" << " |\t" << grade[i] << "\t\t|\n";
		}

		cout << "\n\t+------------------------------------------------------------------------+" << endl;

		data_out << "\n\t+------------------------------------------------------------------------+" << endl;

		data_out.close();
		system("pause");
	}

};

//Display Teacher unction
void Display_Teacher()
{
	cout << "\n\n\n";
	cout << setw(32) << setfill(' ') << "";
	cout << "+";

	for (int i = 0; i < 48; i++) {

		cout << "-";
		Sleep(15);
	}

	cout << "+";
	cout << "\n\t\t\t\t|\tPRESS --> '1' To See Teacher Time Table\t |" << endl;
	Sleep(15);
	cout << "\t\t\t\t|\tPRESS-- > '2' To Assign Marks\t\t |" << endl;
	Sleep(15);
	cout << "\t\t\t\t|\tPress-- > '3' To Mark Attendance\t |" << endl;
	Sleep(15);
	cout << "\t\t\t\t|\tPRESS-- > '4' To Assign Grades \t\t |" << endl;
	Sleep(15);
	cout << "\t\t\t\t|\tPRESS-- > '5' To EXIT\t\t\t |" << endl;
	Sleep(15);
	cout << "\t\t\t\t+------------------------------------------------+" << endl;

}

//Teacher Sign function 
void Teacher_SignIn()
{
	system("cls");
	cout << "\n\n\n";
	cout << setw(32) << setfill(' ') << "";
	cout << "+";

	for (int i = 0; i < 47; i++) {

		cout << "-";
		Sleep(15);
	}

	cout << "+";
	cout << "\n\t\t\t\t|        Welcome To Teacher Portal\t\t|" << endl;
	Sleep(15);
	cout << "\t\t\t\t| \t\t\t\t\t\t|" << endl;
	Sleep(15);
	cout << "\t\t\t\t| \t\tSIGN IN\t\t\t\t|" << endl;
	Sleep(15);
	cout << "\t\t\t\t| \t\t\t\t\t\t|" << endl;
	Sleep(15);
	cout << "\t\t\t\t+-----------------------------------------------+" << endl;

}

//Base Class student
class Student {

protected:

	string S_name;
	string S_password;
	fstream S_file;

	string name;
	string password;

	string course[10];
	string mid_1[10];
	string mid_2[10];
	string grand[10];

	string course_g[5];
	string Grade_g[5];

	string reg_course[5];
	string registered[5];

	string first_name;
	string last_name;
	string status;
	string id;

public:

	Student()
	{
		S_name = "";
		S_password = "";

		name = "";
		password = "";

		course[10] = "";
		mid_1[10] = "";
		mid_2[10] = "";
		grand[10] = "";

		course_g[5] = "";
		Grade_g[5] = "";

		reg_course[5] = "";
		registered[5] = "";

		first_name = "";
		last_name = "";
		status = "";
		id = "";
	}

	virtual  void view_attendance() {}
	virtual void Student_SignIn() {}
	virtual  void View_Marks() {}
	virtual void view_grade() {}
	virtual void view_Registered() {}
	virtual void view_Fee() {}

};

//Derived Class Student Sign In
class S_Sign_In :public Student {

public:

	//overriding
	void Student_SignIn()override
	{

		S_file.open("StudentSignIn.txt");

		while (1)
		{
			cout << "\n\n\n\t\t\t\tEnter User_name: ";
			cin >> name;
			cout << "\n\n\t\t\t\tEnter Password: ";
			cin >> password;

			S_file >> S_name;
			S_file >> S_password;


			if (S_name == name && S_password == password)
			{
				break;
			}

			else
			{
				cout << "\n\n\t\t\t\tx----(You Have Entered Wrong ID Password)----x \n\n\t\t\t\tPlease Try Again" << endl;
			
			}
		}

		S_file.close();
	}

};

//Derived class Student Attendance
class S_Attendace :public Student {

public:

	string date[10];
	string day[10];
	string attandance[10];
	
	void view_attendance()override
	{

		S_file.open("Student_Attandance.txt");

		if (!S_file)
		{
			cout << "File Not CCreated" << endl;
		}

		cout << "\n\t1)Atteendance" << endl;

		if (S_file.is_open())
		{
			for (int i = 0; i < 10; i++)
			{
				S_file >> date[i];
				S_file >> day[i];
				S_file >> attandance[i];

				cout << "\n\t" << date[i] << "\t" << day[i] << "\t" << attandance[i] << endl;
			}
		}

		S_file.close();
	}
};

//Derived Class Marks of Student
class Marks :public Student {

public:

	//overriding
	void View_Marks()override
	{
		S_file.open("Student_Marks.txt");

		if (!S_file)
		{
			cout << "File Not CCreated" << endl;
		}

		for (int i = 0; i < 10; i++)
		{
			S_file >> course[i];
			S_file >> mid_1[i];
			S_file >> grand[i];


		}

		cout << "\n\t2)Marks" << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << "\n\n\t" << course[i] << "\n " << mid_1[i] << "\n " << mid_2[i] << "\n " << grand[i] << endl;
		}

		S_file.close();

	}

};

//Deriveed class Grade 
class Grade :public Student {

public:

	//overriding
	void view_grade()override
	{

		S_file.open("Student_Grade.txt");

		if (!S_file)
		{
			cout << "File Not CCreated" << endl;
		}

		for (int i = 0; i < 5; i++)
		{
			S_file >> course_g[i];
			S_file >> Grade_g[i];

		}

		cout << "\n\t3)Grades" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "\n\n" << course_g[i] << "\n " << Grade_g[i] << endl;
		}

		S_file.close();

	}

};

//Derived class Registered
class Registered :public Student {

public:

	//overriding
	void view_Registered()override
	{

		S_file.open("Registered_Courses.txt");

		if (!S_file)
		{
			cout << "File Not CCreated" << endl;
		}

		for (int i = 0; i < 5; i++)
		{
			S_file >> reg_course[i];
			S_file >> registered[i];

		}

		cout << "\n\t4)Registered Courses" << endl;

		for (int i = 0; i < 5; i++)
		{
			cout << "\n\n" << reg_course[i] << "\n " << registered[i] << endl;
		}

		S_file.close();
	}

};

//Derived Class Fee Status
class Fee_Status :public Student {

public:

	//overriding
	void view_Fee()override
	{
		S_file.open("Fee_status.txt");

		if (!S_file)
		{
			cout << "File Not CCreated" << endl;
		}


		S_file >> first_name;

		S_file >> last_name;

		S_file >> id;

		S_file >> status;

		cout << "\n\t5)Fee Status" << endl;

		cout << "\n\n" << first_name << "\n" << last_name << "\n" << id << "\n" << status << endl;

		S_file.close();

	}
};

//Display Student Sign Function
void Student_Sign_in()
{
	system("cls");
	cout << "\n\n\n";
	cout << setw(32) << setfill(' ') << "";
	cout << "+";

	for (int i = 0; i < 47; i++) {

		cout << "-";
		Sleep(15);
	}

	cout << "+";
	cout << "\n\t\t\t\t|        Welcome To Student Portal\t\t|" << endl;
	Sleep(15);
	cout << "\t\t\t\t| \t\t\t\t\t\t|" << endl;
	Sleep(15);
	cout << "\t\t\t\t| \t\tSIGN IN\t\t\t\t|" << endl;
	Sleep(15);
	cout << "\t\t\t\t| \t\t\t\t\t\t|" << endl;
	Sleep(15);
	cout << "\t\t\t\t+-----------------------------------------------+" << endl;

}

//Display Student Function
void Display_Student()
{
	cout << "\n\n\n";
	cout << setw(32) << setfill(' ') << "";
	cout << "+";

	for (int i = 0; i < 48; i++) {

		cout << "-";
		Sleep(15);
	}

	cout << "+";
	cout << "\n\t\t\t\t|\tPRESS --> '1' To View Attendance\t |" << endl;
	Sleep(15);
	cout << "\t\t\t\t|\tPRESS-- > '2' To View Marks\t\t |" << endl;
	Sleep(15);
	cout << "\t\t\t\t|\tPress-- > '3' To View Grades\t\t |" << endl;
	Sleep(15);
	cout << "\t\t\t\t|\tPRESS-- > '4' To View Registered Courses |" << endl;
	Sleep(15);
	cout << "\t\t\t\t|\tPRESS-- > '5' To View Fee Status  \t |" << endl;
	Sleep(15);
	cout << "\t\t\t\t|\tPRESS-- > '6' To EXIT\t\t\t |" << endl;
	Sleep(15);
	cout << "\t\t\t\t+------------------------------------------------+" << endl;

}

//Main Display Function
void Main_Display()
{

	system("cls");
	system("color B");
	cout << "\n\n\n";
	cout << setw(32) << setfill(' ') << "";
	cout << "+";

	for (int i = 0; i < 47; i++) {

		cout << "-";
		Sleep(15);
	}

	cout << "+";
	cout << "\n\t\t\t\t|   Welcome To FAST FLEX Academic Portal\t|" << endl;
	Sleep(15);
	cout << "\t\t\t\t| \t\t\t\t\t\t|" << endl;
	Sleep(15);
	cout << "\t\t\t\t| \tPRESS ---> '1' For Admin\t\t|" << endl;
	Sleep(15);
	cout << "\t\t\t\t| \tPRESS ---> '2' For Student\t\t|" << endl;
	Sleep(15);
	cout << "\t\t\t\t| \tPRESS ---> '3' For Teacher\t\t|" << endl;
	Sleep(15);
	cout << "\t\t\t\t| \tPRESS ---> '4' For EXIT\t\t\t|" << endl;
	Sleep(15);
	cout << "\t\t\t\t+-----------------------------------------------+" << endl;

}


// Main Function
int main()
{
	//SFML
	RenderWindow window(VideoMode(756, 367), "Wellcome");
	Music music;
	if (!music.openFromFile("flexaudio.ogg"))
	{
		cout << "file not loaded\n";

	}
	music.setVolume(70);
	music.play();

	Texture texture;
	//Login
	if (!texture.loadFromFile("welcome.jpg"))
	{
		cout << "Error Loading\n";
	}

	Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(0.f, 0.f));

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.clear();
		window.draw(sprite);
		window.display();
		system("pause");
		window.close();

	}


	int main_choice;

	while (true)
	{
		// Choice SFML
		RenderWindow window(VideoMode(756, 367), "Portal Page");

		if (!music.openFromFile("moduleaudio.ogg"))
		{
			cout << "file not loaded\n";

		}
		music.setVolume(70);
		music.play();


		Texture texture;
		//Login
		if (!texture.loadFromFile("admin.png"))
		{
			cout << "Error Loading\n";
		}

		Sprite sprite;
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(0.f, 0.f));

		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}

			window.clear();
			window.draw(sprite);
			window.display();
			system("pause");
			window.close();

		}

  //Main Display Function Calling
		Main_Display();

		cout << "\n\n\t\t\tYou Choose: ";
		cin >> main_choice;

		if (main_choice == 1)
		{
			//ADMIN MODULE
			while (true)
			{

				{
					//SFML
					RenderWindow window(VideoMode(756, 367), "Admin Username Page");
					Texture texture;

					if (!music.openFromFile("adminaudio.ogg"))
					{
						cout << "file not loaded\n";

					}

					music.setVolume(70);
					music.play();

					//Login
					if (!texture.loadFromFile("adminusername.png"))
					{
						cout << "Error Loading\n";
					}

					Sprite sprite;
					sprite.setTexture(texture);
					sprite.setPosition(sf::Vector2f(0.f, 0.f));

					while (window.isOpen())
					{
						Event event;
						while (window.pollEvent(event))
						{
							switch (event.type)

							{
							case sf::Event::Closed:
								window.close();
								break;
							}
						}

						window.clear();
						window.draw(sprite);
						window.display();
						system("pause");
						window.close();

					}

					Sign_in obj1;
					Display_signIn();
					obj1.sign_in();

				}

				system("cls");


				//Admin Display SFML
				RenderWindow window(VideoMode(756, 367), "Display Option");
				Texture texture;

				//Login
				if (!texture.loadFromFile("admindisplay.jpg"))
				{
					cout << "Error Loading\n";
				}

				Sprite sprite;
				sprite.setTexture(texture);
				sprite.setPosition(sf::Vector2f(0.f, 0.f));

				while (window.isOpen())
				{
					Event event;
					while (window.pollEvent(event))
					{
						switch (event.type)
						{
						case sf::Event::Closed:
							window.close();
							break;
						}
					}

					window.clear();
					window.draw(sprite);
					window.display();
					system("pause");
					window.close();

				}

				//Admin Display Function Calling
				Display_Admin();

				int option;
				cout << "\n\n\n\t\t\t\tYou Choose: ";
				cin >> option;
				system("cls");

				//Creating objects and calling function on choice
				if (option == 1)
				{
					Add_Teacher obj2;
					obj2.Add_new_Teacher();
					system("pasue");
					system("cls");

				}

				else if (option == 2)
				{
					Add_Student obj3;
					obj3.Add_new_Student();
					system("pasue");
					system("cls");

				}

				else if (option == 3)
				{
					Edit_Teacher_Detail obj4;
					obj4.Edit_Teacher();
					system("pasue");
					system("cls");
				}

				else if (option == 4)
				{
					Edit_Student_Detail obj5;
					obj5.Edit_Student();
					system("pasue");
					system("cls");
				}

				else if (option == 5)
				{
					View_Student obj6;
					obj6.View_all_Student();
					system("pause");
					system("cls");

				}

				else if (option == 6)
				{
					View_teacher obj7;
					obj7.View_all_Teacher();
					system("pause");
					system("cls");
				}

				else if (option == 7)
				{
					break;

				}
			}
		}

		else if (main_choice == 2)
		{
			//SFML
			RenderWindow window(VideoMode(756, 367), "Teacher Display");

			if (!music.openFromFile("studentaudio.ogg"))
			{
				cout << "file not loaded\n";

			}
			music.setVolume(70);
			music.play();

			Texture texture;

			//Login
			if (!texture.loadFromFile("studentusername.jpg"))
			{
				cout << "Error Loading\n";
			}

			Sprite sprite;
			sprite.setTexture(texture);
			sprite.setPosition(sf::Vector2f(0.f, 0.f));

			while (window.isOpen())
			{
				Event event;
				while (window.pollEvent(event))
				{
					switch (event.type)
					{
					case sf::Event::Closed:
						window.close();
						break;
					}
				}

				window.clear();
				window.draw(sprite);
				window.display();
				system("pause");
				window.close();

			}

			//STUDENT MODULE
			while (true)
			{
				//Student Sign In function
				Student_Sign_in();

				S_Sign_In obj;
				obj.Student_SignIn();

				
				system("cls");

				//Student Display SFML
				string a;
				RenderWindow window(VideoMode(756, 367), "Student Display");
				Texture texture;

				//Login
				if (!texture.loadFromFile("studentdisplay.jpg"))
				{
					cout << "Error Loading\n";
				}
				Sprite sprite;
				sprite.setTexture(texture);
				sprite.setPosition(sf::Vector2f(0.f, 0.f));

				while (window.isOpen())
				{
					Event event;
					while (window.pollEvent(event))
					{
						switch (event.type)
						{
						case sf::Event::Closed:


							window.close();

							//window.close();

						}
					}

					window.clear();
					window.draw(sprite);
					window.display();
					system("pause");
					window.close();
				}

				//Display Student Function Calling
				Display_Student();

				int option;
				cout << "\n\n\n\t\t\t\tYou Choose: ";
				cin >> option;
				system("cls");

				//Creating objects and calling function on choice
				if (option == 1)
				{
					S_Attendace obj1;
					obj1.view_attendance();

					system("pause");
					system("cls");

				}

				else if (option == 2)
				{

					Marks obj2;
					obj2.View_Marks();

					system("pause");
					system("cls");

				}

				else if (option == 3)
				{
					Grade obj3;
					obj3.view_grade();

					system("pause");
					system("cls");
				}

				else if (option == 4)
				{

					Registered obj4;
					obj4.view_Registered();

					system("pause");
					system("cls");
				}

				else if (option == 5)
				{

					Fee_Status obj5;
					obj5.view_Fee();


					system("pause");
					system("cls");
				}

				else if (option == 6)
				{
					break;
				}
			}
		}

		if (main_choice == 3)
		{
			RenderWindow window(VideoMode(756, 367), "Teacher Display");

			if (!music.openFromFile("teacheraudio.ogg"))
			{
				cout << "file not loaded\n";

			}
			music.setVolume(70);
			music.play();

			Texture texture;

			//Login
			if (!texture.loadFromFile("teacherusername.jpg"))
			{
				cout << "Error Loading\n";
			}
			Sprite sprite;
			sprite.setTexture(texture);
			sprite.setPosition(sf::Vector2f(0.f, 0.f));

			while (window.isOpen())
			{
				Event event;
				while (window.pollEvent(event))
				{
					switch (event.type)
					{
					case sf::Event::Closed:
						window.close();
						break;
					}
				}
				window.clear();
				window.draw(sprite);
				window.display();
				system("pause");
				window.close();
			}

			//TEACHER MODULE
			while (true)
			{
				//Display Teacher Sign in function
				Teacher_SignIn();

				Teacher_Sign obj1;
				Teacher_Sign();
				obj1.T_Sign_in();

				system("cls");

				//Teacher Display SFML

				RenderWindow window(VideoMode(756, 367), "Teacher Display");
				Texture texture;


				//Login
				if (!texture.loadFromFile("teacherdisplay.jpg"))
				{
					cout << "Error Loading\n";
				}

				Sprite sprite;
				sprite.setTexture(texture);
				sprite.setPosition(sf::Vector2f(0.f, 0.f));

				while (window.isOpen())
				{
					Event event;
					while (window.pollEvent(event))
					{
						switch (event.type)
						{
						case sf::Event::Closed:
							window.close();
							break;
						}
					}

					window.clear();
					window.draw(sprite);
					window.display();
					system("pause");
					window.close();

				}

				//Dsiplay Teacher Function Calling
				Display_Teacher();

				int option;
				cout << "\n\n\n\t\t\t\tYou Choose: ";
				cin >> option;
				system("cls");

				//creating objects and calling fuctions on choice
				if (option == 1)
				{
					Teacher_TimeTable obj2;
					obj2.T_Time_table();

					system("pause");
					system("cls");

				}

				else if (option == 2)
				{
					Assign_Marks obj3;
					obj3.T_Marks();

					system("pause");
					system("cls");

				}

				else if (option == 3)
				{
					Marking_Attendance obj4;
					obj4.Attendance();

					system("pause");
					system("cls");
				}

				else if (option == 4)
				{
					Assign_Grades obj5;
					obj5.Grade();

					system("pause");
					system("cls");
				}

				else if (option == 5)
				{
					break;

				}
			}
		}

		else if (main_choice == 4)
		{
			exit(0);
		}
	}

	system("pause");
	return 0;

}