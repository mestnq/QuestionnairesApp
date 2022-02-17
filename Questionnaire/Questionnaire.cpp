/*Написать приложение, позволяющее работать с анкетами в режиме совместного доступа (содержимое анкеты придумать самостоятельно,
например фамилия, год рождения, стаж работы и т.д.). Анкеты должны храниться в бинарном файле. Необходимо обеспечить следующий 
функционал:
Просмотр анкеты. Пользователю необходимо выбрать номер анкеты. После выбора содержимое анкеты выводится на экран для просмотра. 
После команды пользователя просмотр заканчивается. Необходимо обеспечить защиту от редактирования анкеты во время просмотра.
Редактирование анкеты. Пользователю необходимо выбрать номер анкеты. После выбора содержимое анкеты выводится на экран и 
предлагается ввести новые значения полей. После завершения ввода всех данных процесс редактирования завершается. Необходимо 
обеспечить эксклюзивный доступ к анкете во время ее редактирования.
Добавление новой анкеты.*/


#include <iostream>
//#include <fstream>
#include <list>
#include <string>

using namespace std;

int main()
{
	BaseQuestionnaires questionnaires;
	std::cout << "Выберите номер анкеты. Всего их: " << questionnaires.amountQuestionnaire() << std::endl;
	int num;
	std::cin >> num;
	std::cout << "Выберите действие: w-просмотр анкет, a-добавление, r-редактирование" << std::endl;
	char key;
	std::cin >> key;
	questionnaires.menu(key, num);
}

int _id = 0;

class Question //вопросы
{
public:
	string name;
	string surname;	
	int workExperience;
	int telephoneNumber;
	string city;
	int id = _id;
};

class BaseQuestionnaires //база анкет
{
public:
	void menu(char key, int numberQuestionnaire) //выбор действий: просмотр, добавление редактирование
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
	int amountQuestionnaire() //кол-во анкет
	{
		return questionnaires.size();
	}
private:
	void OutputInfo(int numberQuestionnaire) //вывод информации по id
	{
		Question q = searchQuestionnarie(numberQuestionnaire);
		std::cout << q.name << std::endl;
		std::cout << q.surname << std::endl;
		std::cout << q.workExperience << std::endl;
		std::cout << q.telephoneNumber << std::endl;
		std::cout << q.city << std::endl;
	}
	void RefactorQuestionnaire(int numberQuestionnaire) //рефактор анкеты по id
	{
		Question q = searchQuestionnarie(numberQuestionnaire);
		std::cout << "Что вы хотите отредактировать?\nНапишите:\nn-имя, s-фамилия, w-место работы, t-номер телефона, c-город" << std::endl;
		char key;
		std::cin >> key;
		std::cout << "На что вы хотите изменить данное поле." << std::endl;
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
	void AddQuestionnaire() //добавление анкеты
	{
		_id++;
		string name, surname, city;
		int workExperience, telephoneNumber;
		std::cout << "Введите имя, фамилию, стаж работы, номер телефона и город. После каждого ввода нажать <Enter>" << std::endl;
		std::cin >> name;
		std::cin >> surname;
		std::cin >> workExperience;
		std::cin >> telephoneNumber;
		std::cin >> city;
		Question q{name, surname, workExperience, telephoneNumber, city};
		questionnaires.push_back(q);
	}
	list<Question> questionnaires;
	Question searchQuestionnarie(int number) //находим анкету по id
	{
		for (Question q : questionnaires)
		{
			if (q.id == number)
			{
				return q;
			}
		}
		std::cout << "Такой анкеты нет. Возможно вы ошиблись id. Закройте консоль.";
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