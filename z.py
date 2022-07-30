# function to check if it is possible to allocate the books such that the
# maximum number of pages assigned to any student is numPages
def isPossible(arr, n, m, curr_min):
    cntStudents = 1
    curSum = 0
# iterate over all the books
    for i in range(n):
        if (arr[i] > curr_min):
            return False
        if (curSum + arr[i] > curr_min):
        # Increment student count by '1'
            cntStudents += 1
        # assign current book to next student and update curSum
        # If count of students becomes greater than
        # given no. of students, return False
            curSum = arr[i]
        if (cntStudents > m):
    # update curSum
            return False
        else:
            curSum += arr[i]
    return True
# function to find minimum pages
def allocateBooks(arr, n, m):
    sum = 0
# If number student is more than number of books
    if (n < m):
        return -1
# Count total number of pages
    for i in range(n):
        sum += arr[i]
# Initialize start with 0 and end with sum
    start, end = 0, sum
    result = 10**9
# Traverse until start <= end , binary search
    while (start <= end):
        mid = (start + end) // 2
        if (isPossible(arr, n, m, mid)):
            result = mid
            end = mid - 1
        else:
            start = mid + 1
    return result

# Number of pages in books
arr = [10, 20, 30, 40]
n = len(arr)
m = 2  # No. of students
print("The minimum value of the maximum number of pages in book allocation is",
      allocateBooks(arr, n, m))
