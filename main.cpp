#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment (lib, "winmm.lib")

using namespace std;

int main(){
    system("color 04");

    //PlaySound(TEXT("spooky.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

    int choice;

cout << "This choose your own adventure experience is an adaptation of '911 Calling' by IndianaJoan." << endl;
cout << "https://jezebel.com/here-are-the-10-scariest-most-bone-chilling-stories-yo-1788293124" << endl << endl;
cout << "When prompted for a choice, enter the number value of your desired choice and press enter." << endl << endl << endl;

cout << "You are 10 years old. Your mom has rather quickly filed for divorce," << endl << "but with only had a part-time job and very little money," << endl;
cout << "finding a place to stay that was affordable and available immediately was tough. " << endl << endl;
cout << "A friend of hers told her that she had a little mobile home that was currently sitting empty" << endl << "and we could rent ";
cout << "it practically for free until we figured out something else." << endl << "It was an impossible offer to pass up." << endl << endl;

cout << "You live in a mountain town, and this mobile home was way up a steep mile-long driveway. " << endl;
cout << "Beautiful pine trees surrounded it, but the house itself looked abandoned and out of place. " << endl << endl;

cout << "Your mom is gone most of the time looking for work, so you are home alone frequently." << endl;
cout << "You are told to never answer the door while alone, but always answer the phone in case it was an emergency." << endl << endl;

cout << "While home alone, the phone rings. What do you do?" << endl << endl;
cout << "(1) Ignore the call." << endl;
cout << "(2) Answer the phone." << endl;
cout << "Your choice: ";
cin >> choice;
cout << endl;

switch (choice) {
    case 1:
        cout << "The police arrive and your mother is incredibly upset." << endl << "The police explain that there was a 911 call placed from your home" ;
        cout << "and that the 911 dispatcher was disconnected." << endl <<"No one was home except you." << endl << endl;
        break;

    case 2:
        cout << "You pick up the phone to hear a concerned woman say, "<< endl <<"\"Hello, this is 911, returning your call. We received your call, but we got disconnected\"" << endl;
        cout << "You explain that there has been no one else at the house and that it was a mistake." << endl << "The dispatcher says that police will still be dispatched just in case." << endl << endl;
        break;
    }

cout << "After explaining the situation to the police officer, he shrugs and says," << endl;
cout << "\"This kind of thing sometimes happens. They say that it can't, that the numbers can't get mixed up, but it happens.\"" << endl;
cout << "You convince yourself that the officer is correct and that everything is fine." << endl << endl;

cout << "--One month later--"<< endl << endl;

cout << "You are home alone again when the phone rings. You pick up." <<endl << "It's the 911 dispatcher calling about the same peculiar occurance." << endl;
cout << "You recieve a lecture on why 911 is for emergencies only." << endl<< endl <<"But you didn't call 911." << endl << endl;
cout << "Now suspicious that someone is in the house do you: " << endl << endl;
cout << "(1) Check around and make sure that all doors are locked." << endl;
cout << "(2) Hide under a blanket and wait for your mom to get home." << endl;
cout << "Your choice: ";
cin >> choice;
cout << endl;

switch (choice) {
    case 1:
        cout << "You check all of the exterior doors. They are locked and the house is empty." << endl;
        cout << "The hallway bathroom door remained closed, and you get an eerie feeling that someone is in there." <<endl << endl;
        break;

    case 2:
        cout << "You sit in the living room terrified waiting for your mom to return home." << endl << endl;
        break;
    }

cout << "While waiting for your mom to come home, you remain fixated on the bathroom door." << endl << "You swear that you hear faint shuffling noises coming from within." << endl << endl;
cout << "When your mom gets home she checks the bathroom and makes you come see that it is empty." << endl << endl;

cout << "The 911 calls continue to happen, and the dispatcher threatens criminal charges if the calls continue." << endl << endl;
cout << "After the most recent call, you have the feeling that someone is in the bathroom again." << endl << "You hear the sound of fingers being dragged across the door, do you:" << endl << endl;
cout << "(1) Call the police." << endl;
cout << "(2) Wait for your mom." << endl;
cout << "(3) Check the bathroom." << endl;
cout << "Your choice: ";
cin >> choice;
cout << endl;

switch (choice) {
    case 1:
        cout << "The police arrive, and no one is found." << endl;
        cout << "The officer speaks to your mom privately about taking you to see a therapist." <<endl << endl;
        break;

    case 2:
        cout << "You sit in the living room terrified waiting for your mom to return home." << endl << endl;
        break;

    case 3:
        cout << "You check inside the bathroom and it is empty." << endl << endl;
        break;
    }

cout << "After this most recent incident, you decide that you're probably just letting your imagination get away." << endl;
cout << "You try to leave the bathroom door open so you won't think someone is in there." << endl << endl;

cout << "---------------------------------------------------------------------------------------------------------" << endl << endl;

cout << "The next evening you get yet another call from the 911 dispatcher." << endl << endl;
cout << "After hanging up the phone, the bathroom door slams shut." << endl << endl;

cout << "You're paralyzed by fear, what do you do next?" << endl << endl;
cout << "(1) Check the bathroom." << endl;
cout << "(2) Run outside." << endl;
cout << "Your choice: ";
cin >> choice;
cout << endl;

switch (choice) {
    case 1:
        cout << "You open the bathroom door and immediately feel two cold hands grasp you." << endl;
        cout << "You can't take another breath, and your world goes black." << endl << endl;
        //cin.ignore();
        return 0;

    case 2:
        break;
    }

cout << "You run all the way down your steep driveway and find a place to wait until your mom pulls into the drive" << endl << endl;

cout << "You refuse to be alone in the house again so arrangements are made to stay late after school, or go to a friends house while your mom is at work." << endl << endl;

cout << "Weeks later, your mom's friend lets your mom know that she needs the house back, so her mother has a place to stay." << endl;
cout << endl << "Do you tell your mom's friend that something is wrong with the house?" << endl << endl;
cout << "(1) Yes" << endl;
cout << "(2) No" << endl;
cout << "Your choice: ";
cin >> choice;
cout << endl;

switch (choice) {
    case 1:
        cout << "Your mom says that's a ridiculous way to pay back someone's generosity." << endl;
        break;

    case 2:
        break;
    }

cout << endl << "--Years Later--" << endl << endl;

cout << "Over the years you've moved from place to place, with these events still in your mind." << endl << endl;
cout << "The anxiety and fear associated with 911 and that house lingered too long, " << endl<< "and you think it would be a good idea to do some research on the house." << endl << endl << "Do you look into the house's history?"<< endl <<endl;
cout << "(1) Yes" << endl;
cout << "(2) No" << endl;
cout << "Your choice: ";
cin >> choice;
cout << endl;

switch (choice) {
    case 1:
        cout << "You get online and search the house's address and discover that a few years before you moved in," << endl << "a woman was killed there in a domestic dispute. " << endl;
        cout << endl << "It was days, though, before she was found, shut up in the bathroom." << endl;
        break;

    case 2:
        cout << "You remain blissfully unaware and move on with your life, hoping to one day forget about that terrible house." << endl;
        break;
    }

cout << endl << "-----THE END-----" << endl << endl;

cin.ignore();

    return 0;
}
