# ArrayOperationsCPP
This repository contains a C++ implementation of a dynamic array class with various operations. The Array class provides methods for performing common array operations, such as appending, inserting, deleting, searching, sorting, and manipulating arrays. It also includes functions for finding the maximum and minimum elements, calculating the sum and average, reversing the array, and more. The implementation showcases the use of dynamic memory allocation and basic array algorithms.

The code is well-commented and organized, making it easy to understand and modify. It serves as a helpful reference for anyone learning about arrays and their operations in C++. The repository can be a valuable resource for beginners and intermediate programmers looking to explore array manipulation in C++.

#### The provided code defines a class called "Array" that represents a dynamic array. Here is a brief description of each function in the code
1. **`swap(int* x, int* y)`:** A helper function to swap the values of two elements.

2. **`Display()`:** Displays all the elements of the array.

3. **`Append(int x)`:** Appends an element at the end of the array.

4. **`Insert(int index, int x)`:** Inserts an element at a given index in the array.

5. **`Delete(int index)`:** Deletes an element at a given index from the array.

6. **`LinearSearch(int key)`:** This function performs a linear search for an element 'key' in the array and returns the index of the first occurrence of the key. It uses the swap function to move the found element to the beginning of the array (optimization technique called "transposition").
7. **`BinarySearch(int key)`:** This function performs a binary search for an element 'key' in a sorted array and returns the index of the key if found; otherwise, it returns -1.

8. **`Get(int index)`:** Retrieves the element at a given index.

9. **`Set(int index, int x)`:** Sets the value of an element at a given index.

10. **`Max()`:** Finds the maximum element in the array.

11. **`Min()`:** Finds the minimum element in the array.

12. **`Sum()`:** Calculates the sum of all elements in the array.

13. **`Avg()`:** Calculates the average of all elements in the array.

14. **`Reverse()`:** Reverses the order of elements in the array.

15. **`LeftShift()`:** Shifts all elements of the array to the left.

16. **`LeftRotate()`:** Rotates all elements of the array to the left.

17. **`RightShift()`:** Shifts all elements of the array to the right.

18. **`RightRotate()`:** Rotates all elements of the array to the right.

19. **`InsertSort(int x)`:** Inserts an element in a sorted array while maintaining the sorted order.

20. **`IsSorted()`:** This function checks if the array is sorted in ascending order and returns 1 if true; otherwise, it returns 0.

21. **`Rearrange()`:** Rearranges the elements of the array so that negative elements come before positive elements.

22. **`Merge(Array arr2)`:** This function merges the current array with another sorted array 'arr2' and returns a new array containing the merged elements.

23. **`Union(Array arr2)`:** This function finds the union of the current array and another sorted array 'arr2' (assuming both arrays are sorted) and returns a new array containing the union elements.

24. **`Intersection(Array arr2)`:** This function finds the intersection of the current array and another sorted array 'arr2' (assuming both arrays are sorted) and returns a new array containing the intersection elements.

25. **`Difference(Array arr2)`:** Finds the difference of two arrays, assuming both arrays are sorted.

#### The above code utilizes the class "Array" to encapsulate various functions and data related to array operations.
The class has two constructors, a default constructor that initializes the array with a default size of 10, and a parameterized constructor that allows the user to specify the size of the array. The class also has a destructor to deallocate the memory used by the array. By using a class, the code achieves several benefits:

**`Encapsulation:`** The class encapsulates the array data and related functions within a single entity, making it easier to manage and manipulate the array as a whole.

**`Abstraction:`** The class provides a higher-level abstraction for working with arrays. Users can simply interact with the class interface (functions) without worrying about the internal implementation details.

**`Code Organization:`** The class helps organize the code by grouping related functions and data together. This improves code readability and maintainability, as it is easier to locate and understand the array-related operations within the class.

**`Reusability:`** The class can be instantiated multiple times to create separate instances of arrays, allowing for reusability of the code. Each instance represents a distinct array object with its own set of data and functions.

**`Modularity:`** The class promotes modularity by encapsulating each array operation within its own function. This allows for easy modification or extension of specific operations without affecting the entire codebase.

**`Data Hiding:`** The class provides encapsulation and access control mechanisms (private and public members) to hide the internal array representation and limit access to certain operations. This ensures data integrity and prevents direct manipulation of array elements without proper checks and validation.

**Note:** In addition to the class, the code also includes a menu-driven main function. This main function presents a menu to the user, allowing them to choose from different array operations by entering corresponding options. The menu provided in limited to only 5 functionality but it can be modified to more available functions from the code or you can add more operations on array. Also, update the main function(if you are confident enough) to include the new menu options. Modify the menu display to reflect the added functionalities. Ensure that the menu is user-friendly and easy to navigate.
