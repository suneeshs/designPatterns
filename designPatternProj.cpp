// designPatternProj.cpp : Defines the entry point for the application.
//

#include "designPatternProj.h"
#include "Observer.hpp"

using namespace std;

/**
 * Observer Design Pattern
 *
 * Intent: Lets you define a subscription mechanism to notify multiple objects
 * about any events that happen to the object they're observing.
 *
 * Note that there's a lot of different terms with similar meaning associated
 * with this pattern. Just remember that the Subject is also called the
 * Publisher and the Observer is often called the Subscriber and vice versa.
 * Also the verbs "observe", "listen" or "track" usually mean the same thing.
 */


int main() {
    //ClientCode();
    ObserverClient();
    return 0;
}
