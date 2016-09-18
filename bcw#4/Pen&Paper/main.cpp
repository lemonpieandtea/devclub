#include <iostream>
#include <string>
#include "pen.h"
#include "paper.h"

using namespace std;

int main() {
    Pen pen(25);
    Paper paper(50);
    string message1 = "Hello! This is a pen!";
    char message2[] = " What a shame for you!";
    
    cout << "Initial:" << endl;
    cout << "Pen   - capacity: " << pen.getCapacity() << " Ink: " << pen.getInk() << endl;
    cout << "Paper - capacity: " << paper.getCapacity() << endl;
    
    pen.write(paper, message1);
    
    cout << "Write #1:" << endl;
    paper.showText();
    cout << "Pen   - capacity: " << pen.getCapacity() << " Ink: " << pen.getInk() << endl;
    cout << "Paper - capacity: " << paper.getCapacity() << endl;
    
    try {
        pen.write(paper, message2);
    } catch (PenException obj) {
        cout << "Pen Exception #" << obj.code << endl;
    }
    
    cout << "Write #2:" << endl;
    cout << paper << endl;
    cout << "Pen   - capacity: " << pen.getCapacity() << " Ink: " << pen.getInk() << endl;
    cout << "Paper - capacity: " << paper.getCapacity() << endl;
    
    pen.fillInk(21);
    pen.write(paper, (char*) "me for you!");
    
    cout << "Refill:" << endl;
    cout << paper << endl;
    cout << "Pen   - capacity: " << pen.getCapacity() << " Ink: " << pen.getInk() << endl;
    cout << "Paper - capacity: " << paper.getCapacity() << endl;
    
    cout << "Exceptions:" << endl;
    try {
        Paper badPaper(-50);
    } catch (PaperException obj) {
        cout << "Paper Exception #" << obj.code << endl;
    }
    
    Paper anotherPaper(10);
    
    try {
        Pen badPen(-50);
    } catch (PenException obj) {
        cout << "Pen Exception #" << obj.code << endl;
    }
    
    try {
        Pen anotherPen(0);
        anotherPen.write(anotherPaper, (char*) "Something");
    } catch (PenException obj) {
        cout << "Pen Exception #" << obj.code << endl;
    }
    
    Pen anotherPen(50);
    
    try {
        anotherPen.fillInk(100);
    } catch (PenException obj) {
        cout << "Pen Exception #" << obj.code << endl;
    }
    
    try {
        anotherPen.write(anotherPaper, (char*) "A huuuuuuuuuuuuuge sentence");
    } catch (PaperException obj) {
        cout << "Paper Exception #" << obj.code << endl;
    }
    
    return 0;
}
