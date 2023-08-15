import re

def parse_top_output(filename):
    with open(filename, 'r') as file:
        top_output = file.read()

    pid_user_list = []

    pattern = r'^\s*(\d+)\s+([^\s]+)'

    matches = re.findall(pattern, top_output, re.MULTILINE)

    for match in matches:
        pid = match[0]
        user = match[1]
        pid_user_list.append((pid, user))

    return pid_user_list

if __name__ == "__main__":
    input_filename = "top_output.txt"  
    pid_user_list = parse_top_output(input_filename)

    print("List of running PIDs and their associated users:")
    for pid, user in pid_user_list:
        print(f"PID: {pid}, User: {user}")