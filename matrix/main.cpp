// 1
//#include <iostream>
//
//void fillArray(int** array, int rows, int cols) {
//	int value = 1;
//	for (size_t i = 0; i < rows; i++)
//	{
//		for (size_t j = 0; j < cols; j++)
//		{
//			array[i][j] = value++;
//		}
//	}
//}
//
//void transp(int** array, int** trs, int rows, int cols) {
//	for (size_t i = 0; i < rows; i++)
//	{
//		for (size_t j = 0; j < cols; j++)
//		{
//			trs[j][i] = array[i][j];
//		}
//	}
//}
//
//void print(int** array, int rows, int cols) {
//	for (size_t i = 0; i < rows; i++)
//	{
//		for (size_t j = 0; j < cols; j++)
//		{
//			std::cout << array[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//}
//
//void deleteArr(int** array, int rows) {
//	for (size_t i = 0; i < rows; i++)
//	{
//		delete[] array[i];
//	}
//	delete[] array;
//}
//
//int main() {
//	const int rows = 3, cols = 4;
//	int** array = new int* [rows];
//	for (size_t i = 0; i < rows; i++)
//	{
//		array[i] = new int[cols];
//	}
//
//	int** trs = new int* [cols];
//	for (size_t i = 0; i < cols; i++)
//	{
//		trs[i] = new int[rows];
//	}
//
//	fillArray(array, rows, cols);
//	print(array, rows, cols);
//	std::cout << std::endl;
//	transp(array, trs, rows, cols);
//	print(trs, cols, rows);
//	deleteArr(array, rows);
//	deleteArr(trs, rows);
//
//
//	return 0;
//}

// 2
#include <iostream>
#include <string>

class Contact {
private:
    std::string name;
    std::string phone;

public:
    void setName(const std::string& newName) {
        name = newName;
    }

    void setPhone(const std::string& newPhone) {
        phone = newPhone;
    }

    std::string getName() const {
        return name;
    }

    std::string getPhone() const {
        return phone;
    }
};

void add(Contact*& contacts, int& size, const std::string& name, const std::string& phone) {
    Contact* newContacts = new Contact[size + 1];

    for (int i = 0; i < size; ++i) {
        newContacts[i] = contacts[i];
    }

    newContacts[size].setName(name);
    newContacts[size].setPhone(phone);

    delete[] contacts;
    contacts = newContacts;
    ++size;
}

void searchName(Contact* contacts, int size, const std::string& name) {
    for (int i = 0; i < size; ++i) {
        if (contacts[i].getName() == name) {
            std::cout << "Name: " << contacts[i].getName() << ", Phone: " << contacts[i].getPhone() << std::endl;
            return;
        }
    }
    std::cout << "Contact not found." << std::endl;
}

void searchPhone(Contact* contacts, int size, const std::string& phone) {
    for (int i = 0; i < size; ++i) {
        if (contacts[i].getPhone() == phone) {
            std::cout << "Name: " << contacts[i].getName() << ", Phone: " << contacts[i].getPhone() << std::endl;
            return;
        }
    }
    std::cout << "Contact not found." << std::endl;
}

void editContact(Contact* contacts, int size, const std::string& name) {
    for (int i = 0; i < size; ++i) {
        if (contacts[i].getName() == name) {
            std::cout << "Enter new phone number: ";
            std::string newPhone;
            std::getline(std::cin, newPhone);
            contacts[i].setPhone(newPhone);
            std::cout << "Phone number updated." << std::endl;
            return;
        }
    }
    std::cout << "Contact not found." << std::endl;
}

void show(Contact* contacts, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << i + 1 << ". Name: " << contacts[i].getName() << ", Phone: " << contacts[i].getPhone() << std::endl;
    }
}

int main() {
    Contact* contacts = nullptr;
    int size = 0;

    int choice;
    std::string name, phone;

    do {
        std::cout << "Menu:\n"
            << "[1] Add name & phone\n"
            << "[2] Search by name\n"
            << "[3] Search by phone\n"
            << "[4] Edit name & phone\n"
            << "[5] Show\n"
            << "[6] Exit\n"
            << "Enter: ";
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice) {
        case 1:
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            std::cout << "Enter phone: ";
            std::getline(std::cin, phone);
            add(contacts, size, name, phone);
            break;
        case 2:
            std::cout << "Enter name to search: ";
            std::getline(std::cin, name);
            searchName(contacts, size, name);
            break;
        case 3:
            std::cout << "Enter phone to search: ";
            std::getline(std::cin, phone);
            searchPhone(contacts, size, phone);
            break;
        case 4:
            std::cout << "Enter name to edit: ";
            std::getline(std::cin, name);
            editContact(contacts, size, name);
            break;
        case 5:
            show(contacts, size);
            break;
        case 6:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 6);

    delete[] contacts; 

    return 0;
}
