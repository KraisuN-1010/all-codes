import time
current_time = time.time()
print(f"Script started at: {current_time}\n")

# Write your code below 👇

def speed_calc_decorator(function):
    # This 'wrapper' function is what actually gets run
    def wrapper():
        # 1. Get time *before* running the original function
        start_time = time.time()
        
        # 2. Run the original function
        function()
        
        # 3. Get time *after* running the function
        end_time = time.time()
        
        # 4. Print the difference
        print(f"'{function.__name__}' ran in: {end_time - start_time:.4f}s")
        
    # The decorator returns the new, enhanced 'wrapper' function
    return wrapper
# --- APPLY the decorator to each function ---

@speed_calc_decorator
def fast_function():
  for i in range(1000000):
    i * i
@speed_calc_decorator
def slow_function():
  for i in range(10000000):
    i * i
# --- Now, call the decorated functions ---
fast_function()
slow_function()