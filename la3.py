import numpy as np
A = np.array(
    [
        [150, 120, 70, 100, 180],  # Calories
        [5, 8, 6, 1, 7],  # Protein
        [27, 12, 1, 26, 6],  # Carbohydrates
        [3, 5, 5, 0, 16],  # Fat
        [20, 300, 25, 5, 40],  # Calcium
    ],
    dtype=float,
)
foods = ["Oats", "Milk", "Egg", "Banana", "Peanut Butter"]
b1 = np.array([840, 38, 100, 37, 435], dtype=float)
x1 = np.linalg.solve(A, b1)
print("Part 1: Original Targets Solution")
for food, serv in zip(foods, x1):
    print(f"  {food:14s}: {serv:.2f} servings")
print(
    f"Physically realistic: {'Yes' if all(s >= 0 for s in x1) else 'No'}\n"
)
b2 = np.array([840, 44, 100, 37, 435], dtype=float)
x2 = np.linalg.solve(A, b2)
print("Part 2: Protein Target Increased to 44g")
for food, serv in zip(foods, x2):
    print(f"  {food:14s}: {serv:.2f} servings")
is_practical = all(s >= 0 for s in x2)
print(
    f"Physically practical: {'Yes' if is_practical else 'No (requires negative food quantities)'}\n"
)
A_reduced = A[:4, :]
rank_A = np.linalg.matrix_rank(A_reduced)
print("Part 3: Remove Calcium Requirement")
print(f"  Equations: {A_reduced.shape[0]}, Unknowns: {A_reduced.shape[1]}")
print(f"  Matrix Rank: {rank_A}")
print("  Unique recipe: No, infinitely many solutions exist.")
print(
    "  Interpretation: 1 degree of freedom allows flexible portion sizing for remaining targets."
)