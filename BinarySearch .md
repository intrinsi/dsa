# Binary Search Working
Binary Search Algorithm can be implemented in two ways which are discussed below.

* Iterative Method
* bRecursive Method
* The recursive method follows the divide and conquer approach.

The general steps for both methods are discussed below.
1) The array in which searching is to be performed is:

![image](https://user-images.githubusercontent.com/83773953/195037826-f9725919-097c-4f01-8e12-ce7b3b0a35ea.png)

* Let x = 4 be the element to be searched.
2) Set two pointers low and high at the lowest and the highest positions respectively.
![image](https://user-images.githubusercontent.com/83773953/195038113-f97218be-f56f-4ca3-8468-aeeb6a20bea9.png)
3) Find the middle element mid of the array ie. arr[(low + high)/2] = 6.
![image](https://user-images.githubusercontent.com/83773953/195038220-413ed418-bae2-4261-879f-515fd94fafe1.png)
4) If x == mid, then return mid.Else, compare the element to be searched with m.
5) If x > mid, compare x with the middle element of the elements on the right side of mid. This is done by setting low to low = mid + 1.
6) Else, compare x with the middle element of the elements on the left side of mid. This is done by setting high to high = mid - 1.

![image](https://user-images.githubusercontent.com/83773953/195038350-40a83c76-c4aa-43a8-b0c5-58c058462092.png)

7) Repeat steps 3 to 6 until low meets high.

![image](https://user-images.githubusercontent.com/83773953/195038514-3265348a-e0b0-4635-b66f-f06382d75718.png)

8) x = 4 is found

![image](https://user-images.githubusercontent.com/83773953/195038700-5d1271df-7eee-4ae3-97da-01d7b34b63a1.png)

# Binary Search Algorithm
## Iteration Method
```c
do until the pointers low and high meet each other.
    mid = (low + high)/2
    if (x == arr[mid])
        return mid
    else if (x > arr[mid]) // x is on the right side
        low = mid + 1
    else                       // x is on the left side
        high = mid - 1
    
```
## Recursive Method
```c
binarySearch(arr, x, low, high)
    if low > high
        return False 
    else
        mid = (low + high) / 2 
        if x == arr[mid]
            return mid
        else if x > arr[mid]        // x is on the right side
            return binarySearch(arr, x, mid + 1, high)
        else                               // x is on the right side
            return binarySearch(arr, x, low, mid - 1)
```

