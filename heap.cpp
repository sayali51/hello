#include <iostream>
using namespace std;

class heap
{
	int marks[10];
	int marks1[10];
	int n;
	int num;
	public:
		heap()
		{
			n = 0;
			marks[0] = 0; 
			marks1[0] = 0; // marks[0] stores the count
		}

		void insert_max( int x)
		{
			n = marks[0];
			marks[n + 1] = x;
			marks[0] = n + 1;
			upadjust_max(marks, n + 1);
		}
		
		void insert_min( int x)
		{
			n = marks1[0];
			marks1[n + 1] = x;
			marks1[0] = n + 1;
			upadjust_min(marks1, n + 1);
		}

		void create() 
		{
			
			cout << "Enter number of students: ";
			cin >> num;

			cout << "Enter the marks:\n";
			for (int i = 0; i < num; i++) 
			{
				int val;
				cin >> val;
				insert_max(marks, val); 
				insert_min(marks1, val); 
			}

			cout << "Heap created successfully.\n";
		}

		void upadjust_max(int marks[], int i)
		{
			int temp;  
			while (i > 1 && marks[i] > marks[i / 2])
			{
				temp = marks[i];
				marks[i] = marks[i / 2];
				marks[i / 2] = temp;
				i = i / 2;
			}
		}
		
		void upadjust_min(int marks1[], int i)
		{
			int temp;  
			while (i > 1 && marks1[i] < marks1[i / 2])
			{
				temp = marks1[i];
				marks1[i] = marks1[i / 2];
				marks1[i / 2] = temp;
				i = i / 2;
			}
		}

		void display_max()
		{
			cout << "Max Heap as array : ";
			for (int i = 1; i <= marks[0]; i++)
			{
				cout << marks[i] << " ";
			}
			cout << endl;
		}
		
		void display_min()
		{
			cout << "Min Heap as array : ";
			for (int i = 1; i <= marks1[0]; i++)
			{
				cout << marks1[i] << " ";
			}
			cout << endl;
		}
		
		void menu()
		{
			int ch;
			do{
				cout<<"-----------------Student marks menu----------------- ";
				cout<<"\n1.Insert student marks \n2.Display marks in min heap \n3.Display marks in max heap \n4.Find maximum marks \n5.Find minimum marks \n6.Exit\n";
				cin>>ch;
				switch(ch)
				{
					case 1:
						create();
						break;
						
					case 2:
						display_min();
						break;
						
					case 3:
						display_max();
						break;
						
					case 4:
						cout<<"Maximum marks: "<<marks[1]<<endl;
						break;
						
					case 5:
						cout<<"Minimum marks: "<<marks1[1]<<endl;
						break;
						
					case 6:
						cout<<"Exiting...";
						break;
						
					default:
						break;
				}
			} while( ch!=6);
		}
};

int main()
{
	heap h;
	h.menu();
	return 0;
}

