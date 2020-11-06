#include <iostream>
#include <string>

class BaseMenu
{
public:
    BaseMenu() { m_MenuText = "This shouldn't ever be shown!"; } // This is the constructor - we use it to set class-specific information. Here, each menu object has its own menu text.
    virtual ~BaseMenu() { } // This is the virtual destructor. It must be made virtual, else you get memory leaks - it's not a quick explaination, I recommend you read up on it
    virtual BaseMenu *getNextMenu(int iChoice, bool& iIsQuitOptionSelected) = 0; // This is a 'pure virtual method', as shown by the "= 0". It means it doesn't do anything. It's used to set up the framework
    virtual void printText() // This is made virtual, but doesn't *have* to be redefined. In the current code I have written, it is not redefined as we store the menu text as a string in the object
    {
        std::cout << m_MenuText << std::endl;
    }

protected:
    std::string m_MenuText; // This string will be shared by all children (i.e. derived) classes
};

class FirstMenu : public BaseMenu // We're saying that this FirstMenu class is a type of BaseMenu
{
    FirstMenu()
    {
        m_MenuText = "Main Menu\n"                         // What we are doing here is setting up the string to be displayed later
                    + "Please make your selection\n"       // What we are doing here is setting up the string to be displayed later
                    + "1 - Start game\n"                   // What we are doing here is setting up the string to be displayed later
                    + "2 - Options\n"                      // What we are doing here is setting up the string to be displayed later
                    + "3 - Quit\n"                         // What we are doing here is setting up the string to be displayed later
                    + "Selection: ";                       // What we are doing here is setting up the string to be displayed later
    }

    BaseMenu *getNextMenu(int choice, bool& iIsQuitOptionSelected) // This is us actually defining the pure virtual method above
    {
        BaseMenu *aNewMenu = 0; // We're setting up the pointer here, but makin sure it's null (0)

        switch (choice) // Notice - I have only done "options". You would obviously need to do this for all of your menus
        {
            case 2:
            {
                aNewMenu = new SecondMenu; // We're creating our new menu object here, and will send it back to the main function below
            }

            case 3:
            {
                // Ah, they selected quit! Update the bool we got as input
                iIsQuitOptionSelected = true;
            }

            default:
            {
                // Do nothing - we won't change the menu
            }

        }

        return aNewMenu; // Sending it back to the main function
    }

};

class SecondMenu : public BaseMenu
{
    SecondMenu()
    {
        m_MenuText = "OptionsMenu\n"
                    + "Please make your selection\n"
                    + "1 - ????"
                    + "2 - dafuq?";
    }

    BaseMenu *getNextMenu(int choice, bool& iIsQuitOptionSelected) // This is us actually defining the pure virtual method above
    {
        BaseMenu *aNewMenu = 0; // We're setting up the pointer here, but makin sure it's null (0)

        switch (choice) // Notice - I have only done options. You would obviously need to do this for all of your menus
        {
            case 1:
            {
                aNewMenu = new FirstMenu; // We're creating our new menu object here, and will send it back to the main function below
            }
            break;
            case 2:
            {
                aNewMenu = new FirstMenu; // We're creating our new menu object here, and will send it back to the main function below
            }
            break;

            default:
            {
                // Do nothing - we won't change the menu
            }

        }

        return aNewMenu; // Sending it back to the main function
    }
};

int main (int argc, char **argv)
{
    BaseMenu* aCurrentMenu = new FirstMenu; // We have a pointer to our menu. We're using a pointer so we can change the menu seamlessly.
    bool isQuitOptionSelected = false;
    while (!isQuitOptionSelected) // We're saying that, as long as the quit option wasn't selected, we keep running
    {
        aCurrentMenu.printText(); // This will call the method of whichever MenuObject we're using, and print the text we want to display

        int choice = 0; // Always initialise variables, unless you're 100% sure you don't want to.
        cin >> choice;

        BaseMenu* aNewMenuPointer = aBaseMenu.getNextMenu(choice, isQuitOptionSelected); // This will return a new object, of the type of the new menu we want. Also checks if quit was selected

        if (aNewMenuPointer) // This is why we set the pointer to 0 when we were creating the new menu - if it's 0, we didn't create a new menu, so we will stick with the old one
        {
            delete aCurrentMenu; // We're doing this to clean up the old menu, and not leak memory.
            aCurrentMenu = aNewMenuPointer; // We're updating the 'current menu' with the new menu we just created
        }
    }

    return true;    
}
