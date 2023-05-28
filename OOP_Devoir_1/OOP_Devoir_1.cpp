#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include<iterator>

class Frazione {
private:
	double _numeratore;
	double _denominatore;
public:
	Frazione(double numer, double denom) :_numeratore(numer), _denominatore(denom){}
	
	void ShowCifre() {
		std::cout <<"Числитель : "<< _numeratore << '\n';
		std::cout << "Знаменатель : " << _denominatore << '\n';
	}
	void GetNumer(double numer) {
		_numeratore = numer;
	}
	void GetDenom(double denom) {
		_denominatore = denom;
	}
	double SetNumer() {
		return _numeratore;
	}
	double SetDenom() {
		return _denominatore;
	}
};
class Utente {
private:
	std::string _FIO;
	long int _numero_di_tel;
	long int _numero_di_casa;
	long int _numero_di_lavoro;
	std::string _altre_info;
public:
	Utente(std::string FIO, long int tel, long int casa, long int lavoro, std::string info) {
		this->_FIO = FIO;
		this->_numero_di_tel = tel;
		this->_numero_di_casa = casa;
		this->_numero_di_lavoro = lavoro;
		this->_altre_info = info;
	}

	void Mostrare() {
		std::cout << "ФИО : " << _FIO << '\n';
		std::cout << "Номер телефона : " << _numero_di_tel << '\n';
		std::cout << "Домашний номер : " << _numero_di_casa << '\n';
		std::cout << "Рабочий номер : " << _numero_di_lavoro << '\n';
		std::cout << "Дополнительная информация : \n" << _altre_info << '\n';
	}
	std::string Mos() {
		return _FIO;
	}
};
int main() {
	setlocale(LC_ALL, "Russian");

	// Задача 1.
	std::cout << "Задача 1.\n";
	Frazione fra1(23,10);
	Frazione fra2(7, 5);
	Frazione fra3(86, 4);
	fra1.ShowCifre();
	std::cout << fra1.SetNumer() << " / " << fra1.SetDenom() << " = " << fra1.SetNumer() / fra1.SetDenom() << '\n';
	fra2.ShowCifre();
	std::cout << fra2.SetNumer() << " * " << fra2.SetDenom() << " = " << fra2.SetNumer() * fra2.SetDenom() << '\n';
	fra3.ShowCifre();
	std::cout << fra3.SetNumer() << " + " << fra3.SetDenom() << " = " << fra3.SetNumer() + fra3.SetDenom() << '\n';
	std::cout << '\n';
	system("pause");
	// Задача 2.
	std::cout << "Задача 2.\n";
	std::vector<Utente*>ut{};
	std::vector<Utente*>::const_iterator it;
	Utente* utent1 = new Utente("Alex", 4346, 4545, 434, "niente");
	Utente* utent2 = new Utente("Kami", 45466, 54, 454, "niente");
	Utente* utent3 = new Utente("Boris", 123, 987, 870, "niente");
	Utente* utent4 = new Utente("Oleg", 876,6666, 7805, "niente");
	ut.push_back(utent1);
	ut.push_back(utent2);
	ut.push_back(utent3);
	ut.push_back(utent4);
	int a = 1, b = 0; std::string FIO; long int tel = 0; long int casa = 0; long int lavoro = 0; std::string info; std::string str;
	Utente* utent = new Utente(FIO, tel, casa, lavoro, info); std::string stro;
	auto it2 = ut.cend();
	while (a != 9) {
		system("cls");
		std::cout << "Телефонная книга \n\n";
		std::cout << "1.Добавить абонента\n2.Удалить абонента\n3.Показать всех\n4.Поиск по фамилии.\n";
		std::cin >> a;
		switch (a) {
		case 1:system("cls");
			std::cout << "Введите ФИО абонента : ";
			std::cin.ignore();
			std::getline(std::cin, FIO);
			std::cout << "\nВведите номер телефона : ";
			std::cin >> tel;
			std::cout << "\nВведите домашний номер : ";
			std::cin >> casa;
			std::cout << "\nВведите рабочий номер : ";
			std::cin >> lavoro;
			std::cout << "Введите дополнительную информацию : ";
			std::cin.ignore();
			std::getline(std::cin, info); break;
			ut.insert(it2,utent);
		case 2:system("cls"); std::cout << "Введите индекс абонента : "; std::cin >> b; ut.erase(ut.begin() + b); break;
		case 3:system("cls"); for (it = ut.begin(); it != ut.end(); it++)
			(*it)->Mostrare(); system("pause");
			; break;
		case 4:std::cout << "Введите начало фамилии : "; std::cin.ignore(); std::getline(std::cin, str);
			for (it = ut.begin(); it != ut.end(); it++) {
				stro=(*it)->Mos();
				if (!stro.find(str))
					(*it)->Mostrare(); 
			} system("pause"); break;
		}
	}





	return 0;
}