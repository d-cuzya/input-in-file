#include <iostream>

//библиотека для работы с файлами
#include <fstream>

int main() {
	std::string line;
	bool infinity = true;
	system("chcp 1251 > nul"); //русский язык
	setlocale(LC_ALL, "Russian"); //ещё русский язык

	//open(путь, режим)
	//open(путь)
	//Если указать название файла то он будет создавать в директории с файлом .exe/.cpp 

	//Создаём name и открываем его присваивая отрибуты
	std::fstream name;
	name.open("Test.txt", std::ios::app);

	//Если отрибут будет только на чтение, то файл может не создаться!

	//Список всех отрибутов
	//std::ios::in : файл открывается для чтения
	//std::ios::out : файл открывается для записи. При этом старые данные удаляются
	//std::ios::app : файл открывается для дозаписи. Старые данные не удаляются.
	//std::ios::ate : после открытия файла перемещает указатель в конец файла
	//std::ios::trunc : файл усекается при открытии. Может быть установлен, если также установлен режим out |?|
	//std::ios::binary : файл открывается в бинарном режиме |?|

	//Проверяет открыт ли файл
	//name.is_open() = 1 , т.е. true. 0 = false
	if (name.is_open())
	{
		std::cout << "Введите \"exit\" для выхода" << std::endl;

		while (infinity) {
			std::cout << "Введите что-то:" << std::endl;
			std::cin >> line;

			if (line == "exit") {
				infinity = false;
			}

			name << line << std::endl;
		}
		
		name.close();
	}
	else {
		std::cout << "Вы забыли открыть файл!";
	}
}
