import numpy as np
import pandas as pd
from numpy.random import randn

# Create a 5x4 DataFrame with random numbers, custom row index, and column labels.
df = pd.DataFrame(randn(5, 4), ['a', 'b', 'c', 'd', 'e'], [1, 2, 3, 4])

# --- Filtering Examples ---

# 1. Boolean DataFrame filter:
# Creates a boolean (True/False) DataFrame based on the condition.
bool_df = df > 0
# When filtering with a boolean DataFrame, matching cells (True) are kept,
# non-matching (False) become NaN.
newdf = df[bool_df]

# 2. Boolean Series filter (Single Condition):
# This is the standard way to filter rows.
# (df[1] < 0) creates a boolean Series.
# df[...] selects rows where that Series is True.
newdf = df[df[1] < 0]

# 3. Multiple Conditions:
# --- INCORRECT ATTEMPT ---
# newdf = df[(df[df[1] < 0]) & (df[2] < 8)]
# This fails because `df[df[1] < 0]` evaluates to a *DataFrame*,
# and you can't use '&' between a DataFrame and a Series.

# --- CORRECT WAY ---
# You must combine the *boolean conditions* (Series) first.
# Use () for each condition and '&' (bitwise AND) to combine them.
newdf = df[(df[1] < 0) & (df[2] < 8)]

# --- Resetting the Index ---
# After filtering, 'newdf' might have a non-sequential index (e.g., ['a', 'c', 'e']).
# .reset_index() converts the old index into a new column called 'index'
# and creates a new default integer index (0, 1, 2...).
reset_df = newdf.reset_index()

#Setting a column as index

set_df = newdf.set_index(1)


# Print the final result
print(set_df)