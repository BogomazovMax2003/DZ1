// DZ1.v3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<fstream>
#include<string>
#include<random>
#include<ctime>
#include<vector>
#include<algorithm>
#include<Windows.h>
//write	Записывает заданное число байт из памяти в файл

std::ostream& operator<<(std::ofstream& of, std::string& a)
{
    of  << a;
    return of;
}
std::ostream& operator<<(std::ofstream& of, std::vector<char>& a)
{
    for (int i = 0; i < a.size(); i++) {
        of << a[i];
    }
    return of;
}

std::istream& operator>>(std::istream& is, std::string& a)
{
    is >> a;
    return is;
}
// Функция которая создает ключ.
auto gammirovanie(  std::vector<char>& myVec) {
    srand(4514);
    for (int i = 0; i < myVec.size(); i++) {
        myVec[i]=(rand() % 10)^myVec[i];
    } 
}

int main()
{
    //Введите 
    setlocale(LC_ALL, "ru");
    std::cout << "Введите текст" << std::endl;
    std::string str;
    std::getline(std::cin, str);
    std::vector<std::string> text;
    std::vector<std::string> parol;
    std::vector<std::string> resultat;
    std::string myfile = "Myfile.txt";
    std::fstream  fs;
    fs.open("Myfile.txt", std::ios::out);
    if (!fs.is_open())
    {
        std::cout << "Ошибка" << std::endl;
    }

    else {
        fs << str;
    }
    fs.close();
    std::vector<char> myVec;
    std::vector<std::string> otvet;
    for (int i = 0; i < str.length(); i++) {
        myVec.push_back(str[i]);
    }
    gammirovanie(myVec);
    char a1, a2, a3, a4;
    int k = myVec.size();
    a1 = myVec[k - 4];
    a2 = myVec[k - 3];
    a3 = myVec[k - 2];
    a4 = myVec[k - 1];
    myVec.pop_back();
    myVec.pop_back();
    myVec.pop_back();
    myVec.pop_back();
    myVec.insert(myVec.begin(), a4);
    myVec.insert(myVec.begin(), a3);
    myVec.insert(myVec.begin(), a2);
    myVec.insert(myVec.begin(), a1);

    std::string myfile2 = "Myfile2.txt";
    std::fstream  fs2;
    fs2.open("Myfile2.txt", std::ios::out);
    if (!fs2.is_open())
    {
        std::cout << "Ошибка" << std::endl;
    }

    else {
        for (int i = 0; i < myVec.size(); i++) {
            fs2 << myVec[i];
        }
    }
    fs2.close();
    a1 = myVec[0];
    a2 = myVec[1];
    a3 = myVec[2];
    a4 = myVec[3];
    myVec.erase(myVec.begin());
    myVec.erase(myVec.begin());
    myVec.erase(myVec.begin());
    myVec.erase(myVec.begin());
    myVec.push_back(a1);
    myVec.push_back(a2);
    myVec.push_back(a3);
    myVec.push_back(a4);
    gammirovanie(myVec);
    std::string myfile3 = "Myfile3.txt";
    std::fstream  fs3;
    fs3.open("Myfile3.txt", std::ios::out);
    if (!fs3.is_open())
    {
        std::cout << "Ошибка" << std::endl;
    }

    else {
        for (int i = 0; i < myVec.size(); i++) {
            fs3 << myVec[i];
        }
    }
    fs3.close();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
