/**
 * @file C_Language.cpp
 * Реалізація класу C_Language
 * @author Naimytenko Serhiy
 * @version 1.0
 * @date 2020.04.05
 */
#include "C_Library.h"  /**< підключення файлу C_Library.h*/
#include "C_List.h" /**< підключення файлу C_List.h*/
#include "Test.h"/**< підключення файлу Test.h*/

bool A_more(int a, int b) { return a > b; }
bool B_more(int a, int b) { return b > a; }
/**
 * Функція Test_Add
 *
 * Короткий опис дій:
 * <ul>
 * <li> Перевіряє метод додавання нового елементу методом перевірки розміру масиву після виконання дії </li>
 * </ul>
 * @return повертає результат виконання тесту
 */
bool Test_Add(C_List& list)
{
	Capabilities new_lib; /**< створення обьекту класу Capabilities*/

	list.Add(new_lib, 4); /**< виклик методу Add*/

	int size = list.getSize_array();  /**< отримаємо значення розміру масиву*/

	if (size == 4) /**< перевірка чи збігається розмір з очікуваним результатом*/
		return true;
	else
		return false;
}
/**
 * Функція Test_Delete
 *
 * Короткий опис дій:
 * <ul>
 * <li> Перевіряє метод видалення  елементу методом перевірки розміру масиву після виконання дії</li>
 * </ul>
 * @return повертає результат виконання тесту
 */
bool Test_Delete(C_List& list)
{

	list.Delete(1); /**< виклик методу Delete*/

	int size = list.getSize_array(); /**< отримаємо значення розміру масиву*/

	if (size == 3)  /**< перевірка чи збігається розмір з очікуваним результатом*/
		return true;
	else
		return false;

}
/**
 * Функція Test_Index_return
 *
 * Короткий опис дій:
 * <ul>
 * <li> В методі створюється обьект котрий вставляється в масив, далі визивається метод повернення по індексу що повертає нібито очікуваний обьект котрий зг0дом перевіряється</li>
 * </ul>
 * @return повертає результат виконання тесту
 */
bool Test_Index_return(C_List& list)
{

	string dynamically = "yes"; /**< створення змінних з інформацією*/
	string name = "math";
	string func = "sqrt";
	string lang = "C";
	string expansion = ".dll";
	string capabilities = "using this library you can do something";
	C_Expansion new_el_e(expansion, dynamically, name, 3 , 1999, 20, func, lang);
	Capabilities new_el_c(capabilities, dynamically, name, 3 , 1999, 20, func, lang, new_el_e); /**< створення обьекту на базі цієї інформації*/
	list.list[1] = new_el_c; /**< занесення обьекту в масив*/

	dynamically = "", name = "", func = "", lang = "", expansion = "", capabilities = ""; /**< обнуляємо змінні*/

	Capabilities return_lib = list.Index_return(3); /**< виклик методу Index_return*/

	dynamically = return_lib.getDynamically(); /**< зчитуємоінформацію з обьекту*/
	name = return_lib.getName();
	func = return_lib.getFunction();
	lang = return_lib.getLanguage_programming();
	expansion = return_lib.getExpansion_file();
	capabilities = return_lib.getCapabilities();

	int count = 0;

	if (dynamically == "yes") /**< перевіряємо всі поля на відповідність*/
		count++; 
	if (name == "math")
		count++; 
	if (func == "sqrt")
		count++;
	if (lang == "C")
		count++; 
	if (expansion == ".dll")
		count++;
	if (capabilities == "using this library you can do something")
		count++;
	if (return_lib.getID() == 3)
		count++;
	if (return_lib.getNumber_of_function() == 20)
		count++;
	if (return_lib.getYear_Creating() == 1999)
		count++; 

	if (count == 9) /**< перевіряємо чи дорівнює кількість вірних полів з загальною кількість */
		return true;
	else
		return false;

}
/**
 * Функція Test_Difference
 *
 * Короткий опис дій:
 * <ul>
 * <li> В методі створюєть 1 обьект який не підключається динамічно,далі викликається метод Difference і превіряється результат</li>
 * </ul>
 * @return повертає результат виконання тесту
 */
bool Test_Difference(C_List& list)
{
	string dynamically = "no";  
	Capabilities new_el_c; /**< створення обьекту класу Capabilities*/
	new_el_c.setDynamically(dynamically); /**< замінюємо значення поля dynamically для данного обьекту (по замовчуванню завжди "yes")*/
	list.list[1] = new_el_c; /**< вставляємо обьект в масив*/

	float diff = list.Difference(); /**< виклик методу Difference*/

	if (diff == 1.5) /**< перевіряємо чи збігається очікуваний результат з отриманим*/
		return true;
	else
		return false;
}
/**
 * Функція Test_Sort
 *
 * Короткий опис дій:
 * <ul>
 * <li> </li>
 * </ul>
 * @return повертає результат виконання тесту
 */
bool Test_Sort(C_List& list)
{
	int count=0;  
	Capabilities new_el_1; /**< створюємо 3 обьекта класу Capabilities*/
	Capabilities new_el_2;  
	Capabilities new_el_3;  
	new_el_1.setID(1); /**< присваюємо цим обьектам ідентифікатори */
	new_el_2.setID(2); 
	new_el_3.setID(3);
	list.list[0] = new_el_1; /**< заносимо обьекти до масиву*/
	list.list[1] = new_el_2;
	list.list[2] = new_el_3; 
	list.Sort(A_more); /**< виклик методу Sort де число А більше*/
	int id_1 = list.list[0].getID();  /**< помістимо ідентифікатори в відповідні змінні*/
	int id_2 = list.list[1].getID();
	int id_3 = list.list[2].getID();
	if (id_1 == 3 && id_2 == 2 && id_3 == 1) /**< перевіримо чи відбулося сортування*/
		count++;
	list.Sort(B_more); /**< виклик методу Sort де число В більше*/
	id_1 = list.list[0].getID(); /**< знову помістимо ідентифікатори в відповідні змінні*/
	id_2 = list.list[1].getID();
	id_3 = list.list[2].getID();
	if (id_1 == 1 && id_2 == 2 && id_3 == 3) /**< перевіримо чи відбулося сортування*/
		count++;
	if (count == 2)/**< перевіримо чи збігається результати тестів з очікуваним результатом*/
		return true;
	else
		return false;
}