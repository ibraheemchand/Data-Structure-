/*
 * Task 4: Dynamic Array ADT
 * ---------------------------------------------------------
 * Implements a Dynamic Array class using raw dynamic memory
 * (new[] / delete[]), tracking current size (N) and capacity.
 *
 * ASYMPTOTIC COMPLEXITY SUMMARY (N = number of elements currently stored)
 * ---------------------------------------------------------------------
 * DynamicArray(int capacity)   -> O(1)            (just allocates array, no init loop needed)
 * insert(int value)            -> O(1) amortized best/average case, O(N) worst case
 *                                  (worst case occurs when array is full and must
 *                                   double + copy all N existing elements)
 * search(int value)            -> O(N) worst case, O(1) best case (found at index 0)
 *                                  (linear search, array is unsorted)
 * remove(int index)            -> O(1) best case (removing last element),
 *                                  O(N) worst case (removing index 0, shifts N-1 elements)
 * display()                    -> O(N)            (must visit every element)
 * ~DynamicArray()               -> O(1)            (single delete[] call, no per-element work)
 * copy constructor / operator= -> O(N)            (must copy all N elements to new memory)
 * ---------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;      // pointer to dynamically allocated array
    int size;       // current number of elements stored (N)
    int capacity;   // current allocated capacity

    // Helper: doubles capacity and copies existing elements. O(N).
    void resize() {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    /*
     * Constructor: DynamicArray(int capacity)
     * Specification:
     *   Pre-condition : capacity >= 0 (if capacity <= 0, we allocate a default of 1
     *                    to keep the array usable).
     *   Post-condition: allocates a raw int array of the given capacity, size is
     *                    set to 0 (no elements stored yet).
     *   Complexity    : O(1) — allocation itself is constant time; we do not need
     *                    to initialize elements since size starts at 0.
     */
    DynamicArray(int cap) {
        capacity = (cap > 0) ? cap : 1;
        size = 0;
        data = new int[capacity];
    }

    /*
     * Copy Constructor
     * Specification:
     *   Pre-condition : 'other' is a valid, already-constructed DynamicArray.
     *   Post-condition: creates a completely independent deep copy of 'other'
     *                    (separate memory block, same size/capacity/elements).
     *   Complexity    : O(N) — must copy all N currently stored elements.
     */
    DynamicArray(const DynamicArray& other) {
        capacity = other.capacity;
        size = other.size;
        data = new int[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Copy assignment operator (needed alongside copy constructor for a proper deep copy).
    // Complexity: O(N)
    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) return *this; // self-assignment guard

        delete[] data; // free existing memory

        capacity = other.capacity;
        size = other.size;
        data = new int[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }

    /*
     * void insert(int value)
     * Specification:
     *   Pre-condition : none (array may or may not be full).
     *   Post-condition: 'value' is appended at index 'size'; size increases by 1.
     *                    If the array was full before insertion, capacity is
     *                    doubled and existing elements are copied over first.
     *   Complexity    : Best/average case O(1) — space available, direct write.
     *                    Worst case O(N) — array full, must resize (allocate +
     *                    copy N elements) before inserting.
     *                    (Amortized cost over a sequence of N inserts is O(1) per insert.)
     */
    void insert(int value) {
        if (size == capacity) {
            resize(); // O(N) worst case
        }
        data[size] = value;
        size++;
    }

    /*
     * int search(int value)
     * Specification:
     *   Pre-condition : none.
     *   Post-condition: returns the index of the first occurrence of 'value';
     *                    returns -1 if 'value' is not present. Array is unchanged.
     *   Complexity    : Best case O(1) — value found at index 0.
     *                    Worst case O(N) — value at the end or not present at all
     *                    (unsorted array requires linear scan).
     */
    int search(int value) const {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }

    /*
     * bool remove(int index)
     * Specification:
     *   Pre-condition : 0 <= index < size for a successful removal.
     *   Post-condition: element at 'index' is removed, all subsequent elements
     *                    are shifted one position left, size decreases by 1.
     *                    Returns true if removal succeeded, false if index was
     *                    out of bounds (array unchanged in that case).
     *   Complexity    : Best case O(1) — removing the last element (index = size-1),
     *                    no shifting needed.
     *                    Worst case O(N) — removing index 0 requires shifting the
     *                    remaining N-1 elements left by one position.
     */
    bool remove(int index) {
        if (index < 0 || index >= size) {
            return false; // out of bounds
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        return true;
    }

    /*
     * void display()
     * Specification:
     *   Pre-condition : none.
     *   Post-condition: prints all 'size' elements currently stored, in order.
     *                    Array is unchanged.
     *   Complexity    : O(N) — must visit every stored element exactly once.
     */
    void display() const {
        cout << "[ ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << "] (size=" << size << ", capacity=" << capacity << ")" << endl;
    }

    /*
     * ~DynamicArray()  (Destructor)
     * Specification:
     *   Pre-condition : object is being destroyed / goes out of scope.
     *   Post-condition: all dynamically allocated memory owned by this object
     *                    is released; no memory leak.
     *   Complexity    : O(1) — a single delete[] call frees the whole block
     *                    regardless of how many elements it holds (the elements
     *                    are plain ints, so there is no per-element destructor
     *                    work required).
     */
    ~DynamicArray() {
     ;
    }
};

// ---------------------------------------------------------
// Simple driver / test program to demonstrate all operations
// ---------------------------------------------------------
int main() {
    cout << "Creating DynamicArray with initial capacity 2" << endl;
    DynamicArray arr(2);
    arr.display();

    cout << "\nInserting values: 10, 20, 30, 40 (capacity will grow)" << endl;
    arr.insert(10);
    arr.insert(20);
    arr.insert(30); // triggers resize (capacity 2 -> 4)
    arr.insert(40);
    arr.display();

    cout << "\nSearching for 30: index = " << arr.search(30) << endl;
    cout << "Searching for 99: index = " << arr.search(99) << endl;

    cout << "\nRemoving element at index 1 (value 20)" << endl;
    bool ok = arr.remove(1);
    cout << "Remove success: " << (ok ? "true" : "false") << endl;
    arr.display();

    cout << "\nRemoving out-of-bounds index 10" << endl;
    ok = arr.remove(10);
    cout << "Remove success: " << (ok ? "true" : "false") << endl;

    cout << "\nTesting copy constructor" << endl;
    DynamicArray copyArr(arr);
    copyArr.insert(100); // should not affect 'arr' (deep copy check)
    cout << "Original: ";
    arr.display();
    cout << "Copy:     ";
    copyArr.display();

    cout << "\nTesting copy assignment operator" << endl;
    DynamicArray assignedArr(1);
    assignedArr = arr;
    assignedArr.display();

    cout << "\nEnd of scope: destructors will run automatically." << endl;
    return 0;
}