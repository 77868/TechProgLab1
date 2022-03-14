#include "header.h"

//������� 10: ������� ����� ���������, ������� �������� ��������������� ��������.
template <class T>
T* mergeQ(T q1, T q2)
{
	T* newQueue = new T(q1, q2);
	return newQueue;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "�������� �������� ����� ��� ��������������:\n 1 - public ������������\n 2 - protected ������������\n 3 - private ������������" << std::endl;
	int choise=0;
	std::cin >> choise;
	if (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore();
	}

	while (choise < 1 || choise > 3)
	{
		system("cls");
		std::cout << "������� ����������� ��������. ���������� ��� ���." << std::endl;
		std::cin >> choise;
		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore();
		}
	}
	switch (choise)
	{
	case 1:
		demonstrate<Queue1>();
		break;
	case 2:
		demonstrate<Queue2>();
		break;
	case 3:
		demonstrate<Queue3>();
		break;
	}
	return;
 }

template <typename T>
void demonstrate()
{
	T** list = new T * [10];
	for (size_t i = 0; i < 10; i++)
	{
		list[i] = nullptr;
	}
	

	while(true)
	{
		system("cls");
		showList(list);
		std::cout << "�������� ��������:\n 1 - ������� �������\n 2 - ������� �������\n 3 - ����� ����������� ��������� ������� ��� ������� �������� ������� \n 4 - ��������� ������� � �������\n 5 - ������ ������� �� �������\n 6 - ���������� �������\n 7 - ����� ��� ������� � ����\n 8 - �����" << std::endl;
		int choise = 0;
		std::cin >> choise;
		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore();
		}
		while (choise < 1 || choise > 8)
		{
			
			std::cout << "������� ����������� ��������. ���������� ��� ���." << std::endl;
			std::cin >> choise;
			if (!std::cin.good())
			{
				std::cin.clear();
				std::cin.ignore();
			}
		}
		switch (choise)
		{
		case 1:
			add_queue<T>(list);
			break;
		case 2:
			remove_queue<T>(list);
			break;
		case 3:
			calculateCOA<T>(list);
			break;
		case 4:
			pushing<T>(list);
			break;
		case 5:
			poping<T>(list);
			break;
		case 6:
			copyQueue(list);
			break;
		case 7:
			mergeQueue(list);
			break;
		case 8:

			for (size_t i = 0; i < 10; i++)
			{
				if (list[i] == nullptr)
					delete list[i];
			}
			delete[] list;
			return;
			break;
		}
	}
}

template <typename T>
void showList(T** list)
{
	for (size_t i = 0; i < 10; i++)
	{
		if (list[i] == nullptr)
			std::cout << i << ": ������ ����" << std::endl;
		else
		{
			std::cout << i << ": ";
			list[i]->showQueue();
		}
	}
}

template <typename T>
void add_queue(T** list)
{
	if (listIsFull(list))
		return;
	system("cls");
	showList(list);

	std::cout << "�������� ����" << std::endl;
	int choise = 0;
	std::cin >> choise;
	if (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore();
	}

	while (true)
	{
		if (choise >= 0 && choise <= 9)
		{
			if (list[choise] == nullptr)
			{
				list[choise] = new T;
				return;
			}
		}
		std::cout << "������� ����������� ��������. ���������� ��� ���." << std::endl;
		std::cin >> choise;
		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore();
		}
	}
}

template <typename T>
void remove_queue(T** list)
{
	if (listIsEmpty(list))
		return;
	system("cls");
	showList(list);

	std::cout << "�������� ����" << std::endl;
	int choise = 0;
	std::cin >> choise;
	if (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore();
	}


	while (true)
	{
		if (choise >= 0 && choise <= 9)
		{
			if (list[choise] != nullptr)
			{
				delete list[choise];
				list[choise] = nullptr;
				return;
			}
		}
		std::cout << "������� ����������� ��������. ���������� ��� ���." << std::endl;
		std::cin >> choise;
		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore();
		}
	}
}

template <typename T>
void calculateCOA(T** list)
{
	system("cls");
	std::cout << " ������� ����� ���������, ������� �������� ��������������� �������� ��� ������ �������" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (list[i] == nullptr)
			std::cout << i << ": ������ ����" << std::endl;
		else
		{
			std::cout << i << ": "<< list[i]->countOverAverage()<<std::endl;
		}
	}
	system("pause");
}

template <typename T>
void pushing(T** list)
{

	if (listIsEmpty(list))
		return;
	system("cls");
	showList(list);

	std::cout << "�������� ����" << std::endl;
	int choise = 0;
	std::cin >> choise;
	if (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore();
	}


	while (true)
	{
		if (choise >= 0 && choise <= 9)
		{
			if (list[choise] != nullptr)
			{
				std::cout << "������� ��������:" << std::endl;
				int value = 0;
				std::cin >> value;
				while(!std::cin.good())
				{
					std::cin.clear();
					std::cin.ignore();
					std::cout << "������� ����������� ��������. ���������� ��� ���." << std::endl;
					std::cin >> value;
				}
				list[choise]->push(value);
				return;
			}
		}
		std::cout << "������� ����������� ��������. ���������� ��� ���." << std::endl;
		std::cin >> choise;
		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore();
		}
	}

}

template <typename T>
void poping(T** list)
{
	if (listIsEmpty(list))
		return;
	system("cls");
	showList(list);

	std::cout << "�������� ����" << std::endl;
	int choise = 0;
	std::cin >> choise;
	if (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore();
	}


	while (true)
	{
		if (choise >= 0 && choise <= 9)
		{
			if (list[choise] != nullptr)
			{
				system("cls");
				if (list[choise]->isEmpty())
				{
					std::cout << "������� �����" << std::endl;
				}
				else
				{
					std::cout<<"������� ��������: "<< list[choise]->pop()<<std::endl;
				}
				system("pause");
				return;
			}
		}
		std::cout << "������� ����������� ��������. ���������� ��� ���." << std::endl;
		std::cin >> choise;
		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore();
		}
	}

}

template <typename T>
void copyQueue(T** list)
{
	if (listIsFull(list))
		return;
	system("cls");
	showList(list);
	std::cout << "�������� ����" << std::endl;
	int choise = 0;
	std::cin >> choise;
	if (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore();
	}
	while (true)
	{
		if (choise >= 0 && choise <= 9)
		{
			if (list[choise] != nullptr)
			{
				for (size_t i = 0; i < 10; i++)
				{
					if (list[i] == nullptr)
					{
						list[i] = list[choise]->copy();
						return;
					}
				}
			}
		}
		std::cout << "������� ����������� ��������. ���������� ��� ���." << std::endl;
		std::cin >> choise;
		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore();
		}
	}
}

template <typename T>
void mergeQueue(T** list)
{
	if (listIsFull(list))
		return;
	
	system("cls");
	showList(list);

	std::cout << "�������� ������ ����" << std::endl;
	int choise1 = 0;
	std::cin >> choise1;
	if (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore();
	}
	while (true)
	{
		if (choise1 >= 0 && choise1 <= 9)
		{
			if (list[choise1] != nullptr)
			{
				break;
			}
		}
		std::cout << "������� ����������� ��������. ���������� ��� ���." << std::endl;
		std::cin >> choise1;
		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore();
		}
	}
	system("cls");
	showList(list);
	std::cout << "�������� ������ ����" << std::endl;
	int choise2 = 0;
	std::cin >> choise2;
	if (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore();
	}
	while (true)
	{
		if (choise2 >= 0 && choise2 <= 9)
		{
			if (list[choise2] != nullptr)
			{
				break;
			}
		}
		std::cout << "������� ����������� ��������. ���������� ��� ���." << std::endl;
		std::cin >> choise2;
		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore();
		}
	}

	for (size_t i = 0; i < 10; i++)
	{
		if (list[i] == nullptr)
		{
			list[i] = mergeQ(*list[choise1], *list[choise2]);
			return;
		}
	}
}

template <typename T>
int listIsEmpty(T** list)
{
	for (size_t i = 0; i < 10; i++)
	{
		if (list[i] != nullptr)
			return 0;
	}
	return 1;
}
template <typename T>
int listIsFull(T** list)
{
	for (size_t i = 0; i < 10; i++)
	{
		if (list[i] == nullptr)
			return 0;
	}
	return 1;
}
