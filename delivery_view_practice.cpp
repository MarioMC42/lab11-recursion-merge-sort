/*
 * Course: COEN 2220 - Programming 2
 * Name: Mario A. Marrero Colón
 * Lab: Lab 11 - Recursion and Merge Sort
 * Description: Independent implementation example for final proyect
 * Due date: 04/nov/2026
 */
#include <iostream>
#include <string>

using namespace std;

struct OrderPreview
{
    int orderId, priority;
    string orderType, OrderStatus, building;
};
const int CAP = 4;

int main()
{
    OrderPreview orders[CAP] = 
    {
        {101, 3, "Delivery", "Pending", "A"},
        {102, 1, "Dine-in", "In Progress", "B"},
        {103, 2, "Delivery", "Pending", "C"},
        {104, 1, "Delivery", "Completed", "D"}
    };

    OrderPreview *view[CAP];
    int logicalCount = 0;

    cout << "Original orders before building view: \n"; 
    for (int count = 0; count < CAP; count++)
    {
        cout << "Order ID: " << orders[count].orderId
             << " | Priority: " << orders[count].priority
             << " | Type: " << orders[count].orderType
             << " | Status: " << orders[count].OrderStatus
             << " | Building: " << orders[count].building << endl;
    }

    cout << endl;

    for (int count = 0; count < CAP; count++)
    {
        if (orders[count].orderType == "Delivery" &&
            (orders[count].OrderStatus == "Pending" ||
             orders[count].OrderStatus == "In Progress"))
        {
            view[logicalCount] = &orders[count];
            logicalCount++;
        }
    }
    
    cout << "Selected View (Delivery active only): \n";
    for (int count = 0; count < logicalCount; count++)
    {
         cout << "Order ID: " << view[count]->orderId
             << " | Status: " << view[count]->OrderStatus
             << " | Building: " << view[count]->building << endl;
    }

    cout << endl;

    cout << "Original orders after building view:\n";
    for (int count = 0; count < CAP; count++)
    {
        cout << "Order ID: " << orders[count].orderId
             << " | Priority: " << orders[count].priority
             << " | Type: " << orders[count].orderType
             << " | Status: " << orders[count].OrderStatus
             << " | Building: " << orders[count].building << endl;
    }
    return 0;
}