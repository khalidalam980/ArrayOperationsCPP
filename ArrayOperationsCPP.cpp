#include <iostream>
using namespace std;

// Class to represent an Array
class Array
{
private:
	int* A;       // Pointer to dynamically allocated array
	int size;     // Size of the array
	int length;   // Number of elements currently stored in the array

	// Helper function to swap two elements
	void swap(int* x, int* y);

public:
	// Default constructor
	Array()
	{
		size = 10;   // Default size of the array is 10
		length = 0;  // Initially, no elements in the array
		A = new int[size];  // Allocate memory for the array
	}

	// Parameterized constructor
	Array(int sz)
	{
		size = sz;   // Set the size of the array
		length = 0;  // Initially, no elements in the array
		A = new int[size];  // Allocate memory for the array
	}

	// Destructor
	~Array()
	{
		delete[] A;  // Deallocate the memory used by the array
	}

	// Function to display the elements of the array
	void Display();

	// Function to append an element at the end of the array
	void Append(int x);

	// Function to insert an element at a given index in the array
	void Insert(int index, int x);

	// Function to delete an element at a given index from the array
	int Delete(int index);

	// Function to perform linear search for an element in the array
	int LinearSearch(int key);

	// Function to perform binary search for an element in the sorted array
	int BinarySearch(int key);

	// Function to retrieve the element at a given index
	int Get(int index);

	// Function to set the value of an element at a given index
	void Set(int index, int x);

	// Function to find the maximum element in the array
	int Max();

	// Function to find the minimum element in the array
	int Min();

	// Function to calculate the sum of all elements in the array
	int Sum();

	// Function to calculate the average of all elements in the array
	float Avg();

	// Function to reverse the elements of the array
	void Reverse();

	// Function to shift all elements of the array to the left
	void LeftShift();

	// Function to rotate all elements of the array to the left
	void LeftRotate();

	// Function to shift all elements of the array to the right
	void RightShift();

	// Function to rotate all elements of the array to the right
	void RightRotate();

	// Function to insert an element in a sorted array
	void InsertSort(int x);

	// Function to check if the array is sorted in ascending order
	int IsSorted();

	// Function to rearrange the elements of the array in such a way that negative elements come before positive elements
	void Rearrange();

	// Function to merge two sorted arrays into a new array
	Array* Merge(Array arr2);

	// Function to find the union of two arrays (assuming both arrays are sorted)
	Array* Union(Array arr2);

	// Function to find the intersection of two arrays (assuming both arrays are sorted)
	Array* Intersection(Array arr2);

	// Function to find the difference of two arrays (assuming both arrays are sorted)
	Array* Difference(Array arr2);
};

// Helper function to swap two elements
void Array::swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// Function to display the elements of the array
void Array::Display()
{
	int i;
	cout << endl << "Elements are:";
	for (i = 0; i < length; i++)
		cout << A[i] << " ";
}

void Array::Append(int x)
{
	if (length < size)
		A[length++] = x;
}

void Array::Insert(int index, int x)
{
	int i;
	if (index >= 0 && index <= length)
	{
		for (i = length - 1; i >= index; i--)
		{
			A[i + 1] = A[i];
		}
		A[index] = x;
		length++;
	}
}

int Array::Delete(int index)
{
	int x = 0, i;
	if (index >= 0 && index < length)
	{
		x = A[index];
		for (i = index; i < length - 1; i++)
		{
			A[i] = A[i + 1];
		}
		length--;
		return x;
	}

	return 0;
}

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int Array::LinearSearch(int key)
{
	int i;
	for (i = 0; i < length; i++)
	{
		if (key == A[i])
		{
			swap(&A[i], &A[0]);
			return i;
		}
	}

	return -1;
}

int Array::BinarySearch(int key)
{
	int l = 0, mid, h = length;

	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == A[mid])
			return mid;
		else if (key < A[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int RBinarySearch(int a[], int l, int h, int key)
{
	int mid;

	if (l <= h)
	{
		mid = (l + h) / 2;
		if (key == a[mid])
			return mid;
		else if (key < a[mid])
			return RBinarySearch(a, l, mid - 1, key);
		else
			return RBinarySearch(a, mid + 1, h, key);
	}
	return -1;
}

int Array::Get(int index)
{
	if (index >= 0 && index < length)
		return A[index];
	return -1;
}

void Array::Set(int index, int x)
{
	if (index >= 0 && index < length)
		A[index] = x;
}

int Array::Max()
{
	int max = A[0];
	int i;
	for (i = 0; i < length; i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

int Array::Min()
{
	int min = A[0];
	int i;
	for (i = 0; i < length; i++)
	{
		if (A[i] < min)
			min = A[i];
	}

	return min;
}

int Array::Sum()
{
	int i, sum = 0;
	for (i = 0; i < length; i++)
		sum = sum + A[i];
	return sum;
}

float Array::Avg()
{
	return (float)Sum() / (length);
}

void Array::Reverse()
{
	int i, j;
	for (i = 0, j = length - 1; i < j; i++, j--)
		swap(&A[i], &A[j]);
}

void Array::LeftShift()
{
	int i;
	for (i = 0; i < length - 1; i++)
		A[i] = A[i + 1];
	A[i] = 0;
}

void Array::LeftRotate()
{
	int i, temp;
	temp = A[0];
	for (i = 0; i < length - 1; i++)
		A[i] = A[i + 1];
	A[i] = temp;
}

void Array::RightShift()
{
	int i;
	for (i = length - 1; i > 0; i--)
		A[i] = A[i - 1];
	A[i] = 0;
}

void Array::RightRotate()
{
	int i, temp;
	temp = A[length - 1];
	for (i = length - 1; i > 0; i--)
		A[i] = A[i - 1];
	A[i] = temp;
}

void Array::InsertSort(int x)
{
	int i;
	if (length == size)
		return;
	i = length - 1;
	while (i >= 0 && A[i] > x)
	{
		A[i + 1] = A[i];
		i--;
	}
	A[i + 1] = x;
	length++;
}

int Array::IsSorted()
{
	int i;
	for (i = 0; i < length - 1; i++)
	{
		if (A[i] > A[i + 1])
			return 0;
	}
	return 1;
}

void Array::Rearrange()
{
	int i, j;
	i = 0;
	j = length - 1;

	while (i < j)
	{
		while (A[i] < 0)
			i++;
		while (A[j] > 0)
			j--;
		if (i < j)
			swap(&A[i], &A[j]);
	}
}

Array* Array::Merge(Array arr2)
{
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = new Array(length + arr2.length);


	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else
			arr3->A[k++] = arr2.A[j++];
	}

	for (; i < length; i++)
		arr3->A[k++] = A[i];
	for (; j < arr2.length; j++)
		arr3->A[k++] = arr2.A[j];
	arr3->length = length + arr2.length;

	return arr3;
}

Array* Array::Union(Array arr2)
{
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = new Array(length + arr2.length);

	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else if (A[i] > arr2.A[j])
			arr3->A[k++] = arr2.A[j++];
		else
		{
			arr3->A[k++] = A[i++];
			j++;
		}
		for (; i < length; i++)
			arr3->A[k++] = A[i];
		for (; j < arr2.length; j++)
			arr3->A[k++] = arr2.A[j];

		arr3->length = k;
	}
	return arr3;
}

Array* Array::Intersection(Array arr2)
{
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = new Array(length + arr2.length);

	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			i++;
		else if (A[i] > arr2.A[j])
			j++;
		else
		{
			arr3->A[k++] = A[i++];
			j++;
		}
	}
	arr3->length = k;

	return arr3;
}

Array* Array::Difference(Array arr2)
{
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = new Array(length + arr2.length);

	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else if (A[i] > arr2.A[j])
			j++;
		else
			i++;
	}
	arr3->length = k;

	return arr3;
}

int main()
{
	// Create an instance of the Array class
	Array* arr1;

	// Declare variables for user input and choice
	int ch;
	int x, index, sz;

	// Prompt the user to enter the size of the array
	cout << "Enter Size of Array: ";
	cin >> sz;

	// Create an array object with the specified size
	arr1 = new Array(sz);

	// Display the menu and perform operations based on user's choice
	do
	{
		// Display the menu options to the user
		cout << "\n\nMenu\n";
		cout << "1. Insert\n";
		cout << "2. Delete\n";
		cout << "3. Search\n";
		cout << "4. Sum\n";
		cout << "5. Display\n";
		cout << "6. Exit\n";

		// Prompt the user to enter their choice
		cout << "Enter Your Choice: ";
		cin >> ch;

		// Perform the corresponding operation based on the user's choice
		switch (ch)
		{
		case 1:
			// Prompt the user to enter an element and index
			cout << "Enter an element and index: ";
			cin >> x >> index;
			// Call the Insert function to insert the element at the specified index
			arr1->Insert(index, x);
			break;
		case 2:
			// Prompt the user to enter the index of the element to delete
			cout << "Enter index: ";
			cin >> index;
			// Call the Delete function to delete the element at the specified index
			x = arr1->Delete(index);
			cout << "Deleted Element is: " << x;
			break;
		case 3:
			// Prompt the user to enter the element to search
			cout << "Enter the element to search: ";
			cin >> x;
			// Call the LinearSearch function to search for the element in the array
			index = arr1->LinearSearch(x);
			cout << "Element's index is: " << index;
			break;
		case 4:
			// Call the Sum function to calculate the sum of all elements in the array
			cout << "Sum is: " << arr1->Sum();
			break;
		case 5:
			// Call the Display function to display the elements of the array
			arr1->Display();
			break;
		}
	} while (ch < 6);

	// Free the memory allocated for the array object
	delete arr1;

	// Inform the user that the program has exited
	cout << "Program exited successfully.";

	// Return 0 to indicate successful execution of the program
	return 0;
}