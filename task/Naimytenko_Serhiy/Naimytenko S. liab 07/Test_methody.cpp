/**
 * @file C_Language.cpp
 * ��������� ����� C_Language
 * @author Naimytenko Serhiy
 * @version 1.0
 * @date 2020.04.05
 */
#include "C_Library.h"  /**< ���������� ����� C_Library.h*/
#include "C_List.h" /**< ���������� ����� C_List.h*/
#include "Test.h"/**< ���������� ����� Test.h*/

bool A_more(int a, int b) { return a > b; }
bool B_more(int a, int b) { return b > a; }
/**
 * ������� Test_Add
 *
 * �������� ���� ��:
 * <ul>
 * <li> �������� ����� ��������� ������ �������� ������� �������� ������ ������ ���� ��������� 䳿 </li>
 * </ul>
 * @return ������� ��������� ��������� �����
 */
bool Test_Add(C_List& list)
{
	Capabilities new_lib; /**< ��������� ������� ����� Capabilities*/

	list.Add(new_lib, 4); /**< ������ ������ Add*/

	int size = list.getSize_array();  /**< �������� �������� ������ ������*/

	if (size == 4) /**< �������� �� �������� ����� � ���������� �����������*/
		return true;
	else
		return false;
}
/**
 * ������� Test_Delete
 *
 * �������� ���� ��:
 * <ul>
 * <li> �������� ����� ���������  �������� ������� �������� ������ ������ ���� ��������� 䳿</li>
 * </ul>
 * @return ������� ��������� ��������� �����
 */
bool Test_Delete(C_List& list)
{

	list.Delete(1); /**< ������ ������ Delete*/

	int size = list.getSize_array(); /**< �������� �������� ������ ������*/

	if (size == 3)  /**< �������� �� �������� ����� � ���������� �����������*/
		return true;
	else
		return false;

}
/**
 * ������� Test_Index_return
 *
 * �������� ���� ��:
 * <ul>
 * <li> � ����� ����������� ������ ������ ������������ � �����, ��� ���������� ����� ���������� �� ������� �� ������� ����� ���������� ������ ������ ��0��� ������������</li>
 * </ul>
 * @return ������� ��������� ��������� �����
 */
bool Test_Index_return(C_List& list)
{

	string dynamically = "yes"; /**< ��������� ������ � �����������*/
	string name = "math";
	string func = "sqrt";
	string lang = "C";
	string expansion = ".dll";
	string capabilities = "using this library you can do something";
	C_Expansion new_el_e(expansion, dynamically, name, 3 , 1999, 20, func, lang);
	Capabilities new_el_c(capabilities, dynamically, name, 3 , 1999, 20, func, lang, new_el_e); /**< ��������� ������� �� ��� ���� ����������*/
	list.list[1] = new_el_c; /**< ��������� ������� � �����*/

	dynamically = "", name = "", func = "", lang = "", expansion = "", capabilities = ""; /**< ��������� ����*/

	Capabilities return_lib = list.Index_return(3); /**< ������ ������ Index_return*/

	dynamically = return_lib.getDynamically(); /**< ���������������� � �������*/
	name = return_lib.getName();
	func = return_lib.getFunction();
	lang = return_lib.getLanguage_programming();
	expansion = return_lib.getExpansion_file();
	capabilities = return_lib.getCapabilities();

	int count = 0;

	if (dynamically == "yes") /**< ���������� �� ���� �� ����������*/
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

	if (count == 9) /**< ���������� �� ������� ������� ����� ���� � ��������� ������� */
		return true;
	else
		return false;

}
/**
 * ������� Test_Difference
 *
 * �������� ���� ��:
 * <ul>
 * <li> � ����� ��������� 1 ������ ���� �� ����������� ��������,��� ����������� ����� Difference � ����������� ���������</li>
 * </ul>
 * @return ������� ��������� ��������� �����
 */
bool Test_Difference(C_List& list)
{
	string dynamically = "no";  
	Capabilities new_el_c; /**< ��������� ������� ����� Capabilities*/
	new_el_c.setDynamically(dynamically); /**< �������� �������� ���� dynamically ��� ������� ������� (�� ������������ ������ "yes")*/
	list.list[1] = new_el_c; /**< ���������� ������ � �����*/

	float diff = list.Difference(); /**< ������ ������ Difference*/

	if (diff == 1.5) /**< ���������� �� �������� ���������� ��������� � ���������*/
		return true;
	else
		return false;
}
/**
 * ������� Test_Sort
 *
 * �������� ���� ��:
 * <ul>
 * <li> </li>
 * </ul>
 * @return ������� ��������� ��������� �����
 */
bool Test_Sort(C_List& list)
{
	int count=0;  
	Capabilities new_el_1; /**< ��������� 3 ������� ����� Capabilities*/
	Capabilities new_el_2;  
	Capabilities new_el_3;  
	new_el_1.setID(1); /**< ���������� ��� �������� �������������� */
	new_el_2.setID(2); 
	new_el_3.setID(3);
	list.list[0] = new_el_1; /**< �������� ������� �� ������*/
	list.list[1] = new_el_2;
	list.list[2] = new_el_3; 
	list.Sort(A_more); /**< ������ ������ Sort �� ����� � �����*/
	int id_1 = list.list[0].getID();  /**< �������� �������������� � ������� ����*/
	int id_2 = list.list[1].getID();
	int id_3 = list.list[2].getID();
	if (id_1 == 3 && id_2 == 2 && id_3 == 1) /**< ��������� �� �������� ����������*/
		count++;
	list.Sort(B_more); /**< ������ ������ Sort �� ����� � �����*/
	id_1 = list.list[0].getID(); /**< ����� �������� �������������� � ������� ����*/
	id_2 = list.list[1].getID();
	id_3 = list.list[2].getID();
	if (id_1 == 1 && id_2 == 2 && id_3 == 3) /**< ��������� �� �������� ����������*/
		count++;
	if (count == 2)/**< ��������� �� �������� ���������� ����� � ���������� �����������*/
		return true;
	else
		return false;
}