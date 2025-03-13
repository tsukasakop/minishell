#! /usr/bin/env python3

import subprocess
import re
import glob
from collections import defaultdict, OrderedDict

CTAGS_FILE = "tags"  # ctags output file
SOURCE_FILES = glob.glob("./src/**/*.c", recursive=True)  # Find all C files recursively
MAX_DEPTH = 15  # Limit recursion depth

# Function to get highlight functions from `gh pr diff`
def get_highlight_functions():
    """Runs the shell command and extracts function names for highlighting"""
    try:
        result = subprocess.run(
            ["gh", "pr", "diff", "--name-only"],
            text=True,
            capture_output=True,
            check=True
        )
        # Extract function names from matching file paths
        highlight_funcs = set()
        for line in result.stdout.splitlines():
            if line.startswith("src"):
                parts = re.split(r"[\./]", line)
                if len(parts) > 2:
                    highlight_funcs.add(parts[2])  # Extract function name part

        return highlight_funcs
    except subprocess.CalledProcessError:
        print("Error: Failed to run gh pr diff")
        return set()

# Get dynamically highlighted functions
HIGHLIGHT_FUNCTIONS = get_highlight_functions()

# ANSI escape codes for colors
RED = "\033[31m"
RESET = "\033[0m"

def generate_ctags():
    """Generate ctags file for all C source files"""
    if not SOURCE_FILES:
        print("Error: No C files found in ./src")
        exit(1)

    try:
        subprocess.run(["ctags", "--fields=+neK", "--languages=C", "-o", CTAGS_FILE] + SOURCE_FILES, check=True)
    except subprocess.CalledProcessError:
        print("Error: Failed to generate ctags.")
        exit(1)

def parse_ctags():
    """Parse ctags output to extract function definitions and locations"""
    function_locations = OrderedDict()  # Maintain order
    try:
        with open(CTAGS_FILE, "r") as f:
            for line in f:
                parts = line.strip().split("\t")

                if len(parts) < 5:
                    continue

                name = parts[0]  # Function name
                filename = parts[1]  # File path
                kind = parts[4]  # Type of symbol (should be 'function')

                if kind != "function":
                    continue  # Ignore non-function symbols

                # Extracting line number from additional fields
                line_number = None
                for part in parts[4:]:
                    if part.startswith("line:"):
                        line_number = int(part.split(":")[1])

                if line_number:
                    function_locations[name] = (filename, line_number)
    except FileNotFoundError:
        print("Error: ctags output file not found.")
        exit(1)
    return function_locations

def parse_function_calls(function_locations):
    """Parse source files line-by-line to track function calls in execution order"""
    call_graph = defaultdict(list)  # Use a list to preserve order

    for filename in set(f[0] for f in function_locations.values()):  # Process per file
        try:
            with open(filename, "r") as f:
                current_function = None
                for i, line in enumerate(f, start=1):
                    # Check if this line marks the start of a function
                    for func, (file, line_number) in function_locations.items():
                        if file == filename and i == line_number:
                            current_function = func
                            break  # Start tracking calls for this function

                    if current_function:
                        # Detect function calls in the order they appear
                        match = re.findall(r'\b([a-zA-Z_][a-zA-Z0-9_]*)\s*\(', line)
                        for called_func in match:
                            if called_func in function_locations:  # Only track known functions
                                if not call_graph[current_function] or call_graph[current_function][-1] != called_func:
                                    call_graph[current_function].append(called_func)

        except FileNotFoundError:
            print(f"Warning: File {filename} not found.")

    return call_graph

def colorize(func_name):
    """Apply color to dynamically highlighted functions"""
    if func_name in HIGHLIGHT_FUNCTIONS:
        return f"{RED}{func_name}{RESET}"
    return func_name

def print_tree(call_graph, func, depth=0, visited=None):
    """Recursively print function call tree in the order of execution"""
    if visited is None:
        visited = set()

    if func in visited:
        return

    if depth >= MAX_DEPTH:
        print(" " * (depth * 4) + "[...] (depth limit reached)")
        return

    visited.add(func)
    print(" " * (depth * 4) + colorize(func))

    for child in call_graph.get(func, []):  # Keep original order
        print_tree(call_graph, child, depth + 1, visited.copy())

def main():
    generate_ctags()
    function_locations = parse_ctags()
    call_graph = parse_function_calls(function_locations)

    if "main" not in call_graph:
        print("Error: main function not found.")
        return

    print("\nFunction Call Tree:\n")
    print_tree(call_graph, "main")

if __name__ == "__main__":
    main()

