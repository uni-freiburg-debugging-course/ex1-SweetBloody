import z3
import argparse

def parse_and_evaluate(expression):
    try:
        expression = expression.strip()

        if expression.startswith('(simplify'):
            inner_expression = expression[10:-1].strip()

            if inner_expression.startswith('(') and inner_expression.endswith(')'):
                inner_expression = inner_expression[1:-1].strip()
                parts = inner_expression.split()
                operation = parts[0]
                a, b = int(parts[1]), int(parts[2])

                a_z3 = z3.IntVal(a)
                b_z3 = z3.IntVal(b)

                if operation == '+':
                    return z3.simplify(a_z3 + b_z3)
                elif operation == '-':
                    return z3.simplify(a_z3 - b_z3)
                elif operation == '*':
                    return z3.simplify(a_z3 * b_z3)
                elif operation == '/':
                    return z3.simplify(a_z3 / b_z3)
                else:
                    print(f"Error: undefined operation '{operation}' in expression '{inner_expression}'")
            else:
                print(f"Error: wrong fromat of the expression '{inner_expression}'")
        else:
            print(f"Error: expression doesnt start with (simplify: '{expression}'")
    except Exception as e:
        print(f"Error in expression '{expression}': {e}")
    return None

def evaluate_expressions(filename):
    try:
        with open(filename, 'r') as file:
            for line in file:
                result = parse_and_evaluate(line)
                if result is not None:
                    print(f"{line.strip()} = {result}")
                else:
                    print(f"Error processing in line: {line.strip()}")
    except FileNotFoundError:
        print(f"File '{filename}' doesnt exist.")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Process a file with SMT expressions.")
    parser.add_argument('filename', type=str, help='The name of the file containing expressions')
    args = parser.parse_args()
    evaluate_expressions(args.filename)
