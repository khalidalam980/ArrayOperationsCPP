#include <iostream>
using namespace std;

class Array
{
private:
	int* A;
	int size;
	int length;
	void swap(int* x, int* y);
public:
	Array()
	{
		size = 10;
		length = 0;
		A = new int[size];
	}
	Array(int sz)
	{
		size = sz;
		length = 0;
		A = new int[size];
	}
	~Array()
	{
		delete[]A;
	}
	void Display();
	void Append(int x);
	void Insert(int index, int x);
	int Delete(int index);
	
	int LinearSearch(int key);
	int BinarySearch(int key);
	//int RBinarySearch(int a[], int l, int h, int key);
	int Get(int index);
	void Set(int index, int x);
	int Max();
	int Min();
	int Sum();
	float Avg();
	void Reverse();
	void LeftShift();
	void LeftRotate();
	void RightShift();
	void RightRotate();
	void InsertSort(int x);
	int IsSorted();
	void Rearrange();
	Array* Merge(Array arr2);
	Array* Union(Array arr2);
	Array* Intersection(Array arr2);
	Array* Difference(Array arr2);
};


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
		for (i = length; i > index; i--)
		{
			A[i] = A[i - 1];
		}
		A[index] = x;
		length++;
	}
}

int Array::Delete(int index)
{
	int x = 0,i;
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

void Array::swap(int* x, int* y)
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
	int l=0, mid, h=length;

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
	int i,sum = 0;
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
	for (i = 0, j = length-1; i < j; i++,j--)
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
	Array* arr3= new Array(length+arr2.length);
	

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
	Array *arr1;
	int ch;
	int x, index, sz;

	cout << "Enter Size of Array: ";
	cin >> sz;
	arr1 = new Array(sz);

	do
	{
		cout << "\n\nMenu\n";
		cout << "1. Insert\n";
		cout << "2. Delete\n";
		cout << "3. Search\n";
		cout << "4. Sum\n";
		cout << "5. Display\n";
		cout << "6. Exit\n";

		cout << "Enter Your Choice: ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			cout << "Enter an element and index ";
			cin >> x >> index;
			arr1->Insert(index, x);
			break;
		case 2:
			cout << "Enter index";
			cin >> index;
			x = arr1->Delete(index);
			cout << "Deleted Element is: " << x;
			break;
		case 3:
			cout << "Enter the element to search ";
			cin >> x;
			index = arr1->LinearSearch(x);
			cout << "Element's index is: " << index;
			break;
		case 4:
			cout << "Sum is: " << arr1->Sum();
			break;
		case 5:
			arr1->Display();
		}
	} while (ch < 6);
	return 0;
}