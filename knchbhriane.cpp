#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Item {
    string name;
    double price;
    int stock;
};

void showItems(Item pastries[], int size) {
    cout << "\n====== WELCOME TO BHRIANE'S PASTRY ======\n";
    cout << "\n----------- AVAILABLE PASTRIES -----------\n";
    cout << left << setw(5) << "No."
         << setw(25) << "Item"
         << setw(12) << "Price"
         << setw(10) << "Stock" << endl;

    for (int i = 0; i < size; i++) {
        cout << setw(5) << (i + 1)
             << setw(25) << pastries[i].name
             << "PHP " << fixed << setprecision(2) << setw(8) << pastries[i].price
             << setw(10) << pastries[i].stock << endl;
    }
}

int main() {
    Item pastries[5] = {
        {"Croissant", 45, 20},
        {"Blueberry Muffin", 55, 15},
        {"Cinnamon Roll", 60, 12},
        {"Chocolate Chip Cookie", 35, 30},
        {"Cheesecake Slice", 75, 10}
    };

    int choice, qty;
    char cont;
    int orderNumber = 1;

    do {
        showItems(pastries, 5);

        cout << "\nEnter item number to order: ";
        cin >> choice;

        if (choice < 1 || choice > 5) {
            cout << "Invalid item number!\n";
            continue;
        }

        Item &selected = pastries[choice - 1];
        int invalidCount = 0; // Count invalid quantity attempts

        while (true) {
            cout << "Enter quantity: ";
            cin >> qty;

            // INVALID QUANTITY (0 or negative)
            if (qty <= 0) {
                invalidCount++;
                cout << "Invalid quantity!\n";

                if (invalidCount == 2) {
                    cout << "\nGoodbye! Have a sweet day!\n";
                    return 0;
                }

                continue;
            }

            // QUANTITY MORE THAN STOCK
            if (qty > selected.stock) {
                invalidCount++;
                cout << "Sorry, only " << selected.stock << " " << selected.name
                     << "(s) available.\n";

                if (invalidCount == 2) {
                    cout << "\nGoodbye! Have a sweet day!\n";
                    return 0;
                }

                char retry;
                cout << "Do you want to enter a different quantity? (Y/N): ";
                cin >> retry;
                retry = toupper(retry);

                if (retry == 'Y') {
                    continue;  // Retry, but now invalidCount is 1
                } else {
                    cout << "\nGoodbye! Have a sweet day!\n";
                    return 0;
                }
            }

            // VALID QUANTITY
            double total = qty * selected.price;
            selected.stock -= qty;

            cout << "\n=========== RECEIPT (Order #" << orderNumber << ") ===========\n";
            cout << "BHRIANE'S PASTRY\n";
            cout << "-------------------------------\n";
            cout << "Item: " << selected.name << endl;
            cout << "Quantity: " << qty << endl;
            cout << "Price each: PHP " << fixed << setprecision(2) << selected.price << endl;
            cout << "Total Amount: PHP " << fixed << setprecision(2) << total << endl;
            cout << "Remaining Stock: " << selected.stock << endl;
            cout << "-------------------------------\n";
            cout << "Thank you for ordering at BHRIANE'S PASTRY!\n";
            cout << "===========================================\n";

            orderNumber++;
            break;
        }

        cout << "\nDo you want to order another item? (Y/N): ";
        cin >> cont;
        cont = toupper(cont);

    } while (cont == 'Y');

    cout << "\nGoodbye! Have a sweet day!\n";
    return 0;
}

