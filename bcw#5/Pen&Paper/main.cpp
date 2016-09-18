#include <iostream>
#include <string>
#include "pen.h"
#include "paper.h"
#include "autopen.h"

using namespace std;

void fastWrite(Paper& paper, Pen& pen, const string& message) {
    pen.write(paper, message);
}

int main() {
    AutoPen pen(50);
    Paper paper(100);
    
    fastWrite(paper, pen, "Test message");
    
    paper.showText();
    cout << endl;
    cout << "Pen:" << endl;
    cout << "-- capacity: " << pen.getCapacity() << endl << "-- ink: " << pen.getInk() << endl;
    cout << "Paper:" << endl << "-- capacity: " << paper.getCapacity() << endl;
    
    cout << endl;
    
    pen.click();
    pen.write(paper, "\nHello! This is a pen!");
    
    paper.showText();
    cout << endl;
    cout << "Pen:" << endl;
    cout << "-- capacity: " << pen.getCapacity() << endl << "-- ink: " << pen.getInk() << endl;
    cout << "Paper:" << endl << "-- capacity: " << paper.getCapacity() << endl;
    
    return 0;
}
