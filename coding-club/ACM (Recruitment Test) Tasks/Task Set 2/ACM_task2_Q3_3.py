""" Given a positive integer n, print all the ways n can be expressed as
the sum of triangular numbers.
"""
def print_sums_of_triangular_numbers(prefix, target):
    """Print sums totalling to target, each after printing the prefix."""
    if target == 0:
        print(prefix)
        return
    for tri in triangle_num_list:
        if tri > target:
            return
        print_sums_of_triangular_numbers(prefix + [tri], target - tri)

n = 6

# Set up list of triangular numbers not greater than n
triangle_num_list = []
index = 1
tri_sum = 1
while tri_sum <= n:
    triangle_num_list.append(tri_sum)
    index += 1
    tri_sum += index

# Print the sums totalling to n
print_sums_of_triangular_numbers([], n)
