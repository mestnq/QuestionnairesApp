/*�������� ����������, ����������� �������� � �������� � ������ ����������� ������� (���������� ������ ��������� ��������������,
�������� �������, ��� ��������, ���� ������ � �.�.). ������ ������ ��������� � �������� �����. ���������� ���������� ��������� 
����������:
�������� ������. ������������ ���������� ������� ����� ������. ����� ������ ���������� ������ ��������� �� ����� ��� ���������. 
����� ������� ������������ �������� �������������. ���������� ���������� ������ �� �������������� ������ �� ����� ���������.
�������������� ������. ������������ ���������� ������� ����� ������. ����� ������ ���������� ������ ��������� �� ����� � 
������������ ������ ����� �������� �����. ����� ���������� ����� ���� ������ ������� �������������� �����������. ���������� 
���������� ������������ ������ � ������ �� ����� �� ��������������.
���������� ����� ������.*/


#include <iostream>
//#include <fstream>
#include <list>
#include <string>

using namespace std;

int main()
{
	BaseQuestionnaires questionnaires;
	std::cout << "�������� ����� ������. ����� ��: " << questionnaires.amountQuestionnaire() << std::endl;
	int num;
	std::cin >> num;
	std::cout << "�������� ��������: w-�������� �����, a-����������, r-��������������" << std::endl;
	char key;
	std::cin >> key;
	questionnaires.menu(key, num);
}

int _id = 0;

class Question //�������
{
public:
	string name;
	string surname;	
	int workExperience;
	int telephoneNumber;
	string city;
	int id = _id;
};

class BaseQuestionnaires //���� �����
{
public:
	void menu(char key, int numberQuestionnaire) //����� ��������: ��������, ���������� ��������������
	{
		switch (key)
		{
		case 'w':
			OutputInfo(numberQuestionnaire);
			break;
		case 'a':
			AddQuestionnaire();
			break;
		case 'r': 
			RefactorQuestionnaire(numberQuestionnaire);
			break;
		}
	}
	int amountQuestionnaire() //���-�� �����
	{
		return questionnaires.size();
	}
private:
	void OutputInfo(int numberQuestionnaire) //����� ���������� �� id
	{
		Question q = searchQuestionnarie(numberQuestionnaire);
		std::cout << q.name << std::endl;
		std::cout << q.surname << std::endl;
		std::cout << q.workExperience << std::endl;
		std::cout << q.telephoneNumber << std::endl;
		std::cout << q.city << std::endl;
	}
	void RefactorQuestionnaire(int numberQuestionnaire) //�������� ������ �� id
	{
		Question q = searchQuestionnarie(numberQuestionnaire);
		std::cout << "��� �� ������ ���������������?\n��������:\nn-���, s-�������, w-����� ������, t-����� ��������, c-�����" << std::endl;
		char key;
		std::cin >> key;
		std::cout << "�� ��� �� ������ �������� ������ ����." << std::endl;
		string changedInfo;
		std::cin >> changedInfo;
		switch (key)
		{
		case 'n':
			q.name = changedInfo;
			break;
		case 's':
			q.surname = changedInfo;
			break;
		case 'w':
			q.workExperience = std::stoi(changedInfo);
			break;
		case 't':
			q.telephoneNumber = std::stoi(changedInfo);
			break;
		case 'c':
			q.city = changedInfo;
			break;
		}
	}
	void AddQuestionnaire() //���������� ������
	{
		_id++;
		string name, surname, city;
		int workExperience, telephoneNumber;
		std::cout << "������� ���, �������, ���� ������, ����� �������� � �����. ����� ������� ����� ������ <Enter>" << std::endl;
		std::cin >> name;
		std::cin >> surname;
		std::cin >> workExperience;
		std::cin >> telephoneNumber;
		std::cin >> city;
		Question q{name, surname, workExperience, telephoneNumber, city};
		questionnaires.push_back(q);
	}
	list<Question> questionnaires;
	Question searchQuestionnarie(int number) //������� ������ �� id
	{
		for (Question q : questionnaires)
		{
			if (q.id == number)
			{
				return q;
			}
		}
		std::cout << "����� ������ ���. �������� �� �������� id. �������� �������.";
	}
};

class WorkWithFile
{
	void WriteFile(list<Question> questionnaires)
	{
		//const char* path = "../../../TheAdjacencyMatrixOfAGraph.txt";
		//CreateFileA("QuestionnairesApplication.bin", );
		int numberQuestionnaire = 0;
		for (Question n : questionnaires)
		{
			
			numberQuestionnaire++;
		}
	}

	void ReadFile(list<Question> questionnaires)
	{

	}
};