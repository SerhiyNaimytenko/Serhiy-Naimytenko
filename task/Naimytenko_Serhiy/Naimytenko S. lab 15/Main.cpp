#include"First_heir.h"
#include"Second_heir.h"
#include"smartPointer.h"


 
int Interface();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    int res = Interface();
    if (res == 1)
    {        return 1;

    }

    if (_CrtDumpMemoryLeaks())
        cout << endl << "Есть утечка памяти" << endl;
    else
        cout << endl << "Нет утечки памяти" << endl;
    return 0;
}

int Interface()
{

    vector<Base_class*> conteiner; 
    int variableForPrint = 1; 
    try
    {
        auto_ptr<First_heir> autoPtrObj(new First_heir);
        shared_ptr<Second_heir> sharedPtrObj = std::make_shared <Second_heir>( );
        unique_ptr<First_heir> uniquePtrObj = std::make_unique <First_heir>( );
        smart_ptr <First_heir> smartPtrObj = new First_heir();
        weak_ptr <Second_heir> weakPtrObj = sharedPtrObj;
        shared_ptr<Second_heir> sharedPtrObjCreatedFromWeaPtr = weakPtrObj.lock();
        smart_ptr <First_heir> copyOfSmartPtrObj = smartPtrObj;
        cout << "Adress of created object with smart pointer - " << smartPtrObj.operator->() << endl;
        cout << "Adress of copy of our created object - " << copyOfSmartPtrObj.operator->() << endl;
        //throw exception("Some exeception");
        conteiner.emplace_back(autoPtrObj.get());
        conteiner.emplace_back(sharedPtrObj.get());
        conteiner.emplace_back(uniquePtrObj.get());
        conteiner.emplace_back(smartPtrObj.operator->());
        conteiner.emplace_back(sharedPtrObjCreatedFromWeaPtr.get());
        for_each(conteiner.begin(), conteiner.end(), [&variableForPrint](const Base_class* object) {
            cout << variableForPrint << ") " << *object << endl;
            variableForPrint++;
            });
    }
    catch (const std::exception& ex)
    {
        cout << ex.what() << endl << endl;
    }
}  
 